#include "wav.h"

#ifdef MTR_MOD_PLUGIN
#include "marathoner/plugin_common.c"

MTR_DCLSPC mtrReport* MTR_CALL MTR_CreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    if (report == NULL)
        return NULL;
    report->moduleID = "WAV_dr_wav";
    report->version = MTR_VERSION_WAV_DR_WAV;
    report->subsystem = "wav";
    report->prereqsCount = 0;
    report->prereqs = NULL;
    report->prereqSubsystemsCount = 0;
    report->prereqSubsystems = NULL;
    return report;
}
#endif

MTR_SUBSYSTEM_FUNCTION_SUPPORTED_FUNC(Wav, FA_FUNCTIONS_COUNT)

/*fa MTR_WavInit yes */
MTR_DCLSPC void MTR_CALL MTR_WavInit(void)
{
    MTR_LogWrite("Initializing WAV format support", 0, MTR_LMT_INFO);

    if (!mtrWavInited) {
        MTR_WavStdio.Fopen = MTR_FileGetStdFopen();
        MTR_WavStdio.Fclose = MTR_FileGetStdFclose();
        MTR_WavStdio.Feof = MTR_FileGetStdFeof();
        MTR_WavStdio.Ftell = MTR_FileGetStdFtell();
        MTR_WavStdio.Fseek = MTR_FileGetStdFseek();
        MTR_WavStdio.Rewind = MTR_FileGetStdRewind();
        MTR_WavStdio.Fread = MTR_FileGetStdFread();
        MTR_WavStdio.Fwrite = MTR_FileGetStdFwrite();
        MTR_WavStdio.Fprintf = MTR_FileGetStdFprintf();

        MTR_WavStdioExt.Freadable = MTR_FileGetStdFreadable();
        MTR_WavStdioExt.Fwritable = MTR_FileGetStdFwritable();

        mtrWavTempPcm.samples = 0;
        mtrWavTempPcm.channels = 0;
        mtrWavTempPcm.data = NULL;

        MTR_LogWrite("WAV format support initialized", 0, MTR_LMT_INFO);
    } else
        MTR_LogWrite("WAV format support already initialized", 0,
         MTR_LMT_INFO);
}

void MTR_CALL MTR_WavFreeTempPcm(void)
{
    int buffersCount;
    int i;
    if (mtrWavTempPcm.data != NULL) {
        if (mtrWavTempPcm.interleaved)
            buffersCount = 1;
        else
            buffersCount = mtrWavTempPcm.channels;
        for (i = 0; i < buffersCount; i++) {
            if (mtrWavTempPcm.data[i] == NULL) {
                free(mtrWavTempPcm.data[i]);
                mtrWavTempPcm.data[i] = NULL;
            }
        }
        free(mtrWavTempPcm.data);
        mtrWavTempPcm.data = NULL;
    }
}

size_t WavReadCallback(void* file, void* buffer, size_t bytesToRead)
{
    return MTR_WavStdio.Fread(buffer, 1U, bytesToRead, file);
}

size_t WavWriteCallback(void* file, const void* buffer, size_t bytesToWrite)
{
    return MTR_WavStdio.Fwrite(buffer, 1U, bytesToWrite, file);
}

drwav_bool32 WavSeekCallback(void* file, int offset, drwav_seek_origin origin)
{
    int result;

    switch (origin) {
        case drwav_seek_origin_start:
            result = MTR_WavStdio.Fseek(file, offset, SEEK_SET);
            break;
        case drwav_seek_origin_current:
            result = MTR_WavStdio.Fseek(file, offset, SEEK_CUR);
            break;
        default:
            result = -1;
            break;
    }

    if (result == 0)
        return DRWAV_TRUE;
    else
        return DRWAV_FALSE;
}

bool MTR_CALL MTR_WavFillTempPcm(int format, size_t sampleSize, drwav *Wav,
 FILE *file)
{
    drwav_uint64 samplesReaded;

    mtrWavTempPcm.format = format;

    mtrWavTempPcm.data = malloc(sizeof(void *));
    if (mtrWavTempPcm.data == NULL) {
        drwav_close(Wav);
        MTR_WavStdio.Fclose(file);
        return false;
    }
    mtrWavTempPcm.data[0] = malloc(
     sampleSize * mtrWavTempPcm.samples);
    if (mtrWavTempPcm.data[0] == NULL) {
        drwav_close(Wav);
        MTR_WavStdio.Fclose(file);
        free(mtrWavTempPcm.data);
        return false;
    }

    switch (format) {
        case MTR_PCM_SINT16_INTERLEAVED:
            samplesReaded = drwav_read_s16(Wav, mtrWavTempPcm.samples,
             ((int16_t **)mtrWavTempPcm.data)[0]);
            break;
        case MTR_PCM_SINT32_INTERLEAVED:
            samplesReaded = drwav_read_s32(Wav, mtrWavTempPcm.samples,
             ((int32_t **)mtrWavTempPcm.data)[0]);
            break;
        case MTR_PCM_SINGLE_INTERLEAVED:
            samplesReaded = drwav_read_f32(Wav, mtrWavTempPcm.samples,
             ((float **)mtrWavTempPcm.data)[0]);
            break;
        default:
            samplesReaded = 0;
            break;
    }

    if (samplesReaded == 0) {
        drwav_close(Wav);
        MTR_WavStdio.Fclose(file);
        free(mtrWavTempPcm.data[0]);
        free(mtrWavTempPcm.data);
        return false;
    }

    mtrWavTempPcm.channels = Wav->fmt.channels;
    mtrWavTempPcm.sampleRate = Wav->fmt.sampleRate;
    mtrWavTempPcm.interleaved = true;

    return true;
}

/*fa MTR_WavLoadSimple yes */
MTR_DCLSPC mtrPcm_t *MTR_CALL MTR_WavLoadSimple(const char *filename,
 int format)
{
    drwav       *Wav = NULL;
    FILE        *file = NULL;

    if (filename == NULL)
        return 0;

    file = MTR_WavStdio.Fopen(filename, "rb");
    if (file == NULL)
        return NULL;

    Wav = drwav_open(WavReadCallback, WavSeekCallback, file);
    if (Wav == NULL) {
        MTR_WavStdio.Fclose(file);
        return NULL;
    }

    MTR_WavFreeTempPcm();

    mtrWavTempPcm.samples = Wav->totalSampleCount;

    switch (format) {
        case MTR_PCM_SINT16_INTERLEAVED:
            if (!MTR_WavFillTempPcm(format, sizeof(int16_t), Wav, file))
                return NULL;
            break;
        case MTR_PCM_SINT32_INTERLEAVED:
            if (!MTR_WavFillTempPcm(format, sizeof(int32_t), Wav, file))
                return NULL;
            break;
        case MTR_PCM_SINGLE_INTERLEAVED:
            if (!MTR_WavFillTempPcm(format, sizeof(float), Wav, file))
                return NULL;
            break;
        default:
            MTR_LogWrite("Unknown sample format", 0, MTR_LMT_ERROR);
            drwav_close(Wav);
            MTR_WavStdio.Fclose(file);
            return NULL;
            break;
    }

    drwav_close(Wav);
    MTR_WavStdio.Fclose(file);
    return &mtrWavTempPcm;
}
