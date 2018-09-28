#include "ogg.h"

#ifdef MTR_MOD_PLUGIN
#include "marathoner/plugin_common.c"

MTR_DCLSPC mtrReport* MTR_CALL MTR_CreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    if (report == NULL)
        return NULL;
    report->moduleID = "OGG_libvorbisfile";
    report->version = MTR_VERSION_OGG_LIBVORBISFILE;
    report->subsystem = "ogg";
    report->prereqsCount = 0;
    report->prereqs = NULL;
    report->prereqSubsystemsCount = 0;
    report->prereqSubsystems = NULL;
    return report;
}
#endif

MTR_SUBSYSTEM_FUNCTION_SUPPORTED_FUNC(Ogg, FA_FUNCTIONS_COUNT)

size_t MTR_OggFreadCallback(void *buffer, size_t size, size_t count, void *file)
{
    return MTR_OggStdio.Fread(buffer, size, count, file);
}

int MTR_OggFseekCallback(void *file, ogg_int64_t offset, int origin)
{
    return MTR_OggStdio.Fseek(file, offset, origin);
}

int MTR_OggFcloseCallback(void *file)
{
    return MTR_OggStdio.Fclose(file);
}

long MTR_OggFtellCallback(void *file)
{
    return MTR_OggStdio.Fclose(file);
}

/*fa MTR_OggInit yes */
MTR_DCLSPC void MTR_CALL MTR_OggInit(void)
{
    MTR_LogWrite("Initializing OGG format support", 0, MTR_LMT_INFO);

    if (!mtrOggInited) {
        MTR_LogWrite_s("Reporting libvorbis version:", 1, MTR_LMT_INFO,
         vorbis_version_string());

        MTR_OggStdio.Fopen = MTR_FileGetStdFopen();
        MTR_OggStdio.Fclose = MTR_FileGetStdFclose();
        MTR_OggStdio.Feof = MTR_FileGetStdFeof();
        MTR_OggStdio.Ftell = MTR_FileGetStdFtell();
        MTR_OggStdio.Fseek = MTR_FileGetStdFseek();
        MTR_OggStdio.Rewind = MTR_FileGetStdRewind();
        MTR_OggStdio.Fread = MTR_FileGetStdFread();
        MTR_OggStdio.Fwrite = MTR_FileGetStdFwrite();
        MTR_OggStdio.Fprintf = MTR_FileGetStdFprintf();

        MTR_OggStdioExt.Freadable = MTR_FileGetStdFreadable();
        MTR_OggStdioExt.Fwritable = MTR_FileGetStdFwritable();

        mtrOggCallbacks.read_func = MTR_OggFreadCallback;
        mtrOggCallbacks.seek_func = MTR_OggFseekCallback;
        mtrOggCallbacks.close_func = MTR_OggFcloseCallback;
        mtrOggCallbacks.tell_func = MTR_OggFtellCallback;

        mtrOggTempPcm.samples = 0;
        mtrOggTempPcm.channels = 0;
        mtrOggTempPcm.data = NULL;

        MTR_LogWrite("OGG format support initialized", 0, MTR_LMT_INFO);
    } else
        MTR_LogWrite("OGG format support already initialized", 0,
         MTR_LMT_INFO);
}

long int MTR_CALL MTR_OggSamplesCount(const char *filename, int format)
{
    int             vorbisOpened;
    FILE           *file = NULL;
    OggVorbis_File *vorbisFile = NULL;
    long int        samplesReaded;
    long int        samplesCount = 0;
    float         **pcmChannelsSingle;
    char           *pcmChannelsInterleaved = NULL;

    if (filename == NULL)
        return 0;

    file = MTR_OggStdio.Fopen(filename, "rb");
    if (file == NULL)
        return 0;

    vorbisOpened = ov_test_callbacks(file, vorbisFile, NULL, 0,
     mtrOggCallbacks);
    if (!vorbisOpened) {
        MTR_OggStdio.Fclose(file);
        return 0;
    }

    vorbisOpened = ov_test_open(vorbisFile);
    if (!vorbisOpened) {
        ov_clear(vorbisFile);
        return 0;
    }

    switch (format) {
        case MTR_PCM_SINGLE:
            do {
                samplesReaded = ov_read_float(vorbisFile, &pcmChannelsSingle,
                 4096, NULL);
                samplesCount += samplesReaded;
            } while (samplesReaded > 0);
            break;
        case MTR_PCM_SINT8_INTERLEAVED:
            do {
                samplesReaded = ov_read(vorbisFile, pcmChannelsInterleaved,
                 sizeof(int8_t) * 4096, MTR_ENDIANNESS, 1, 1, NULL);
                samplesCount += samplesReaded;
            } while (samplesReaded > 0);
            break;
        case MTR_PCM_UINT8_INTERLEAVED:
            do {
                samplesReaded = ov_read(vorbisFile, pcmChannelsInterleaved,
                 sizeof(uint8_t) * 4096, MTR_ENDIANNESS, 1, 0, NULL);
                samplesCount += samplesReaded;
            } while (samplesReaded > 0);
            break;
        case MTR_PCM_SINT16_INTERLEAVED:
            do {
                samplesReaded = ov_read(vorbisFile, pcmChannelsInterleaved,
                 sizeof(int16_t) * 4096, MTR_ENDIANNESS, 2, 1, NULL);
                samplesCount += samplesReaded;
            } while (samplesReaded > 0);
            samplesCount /= 2;
            break;
        case MTR_PCM_UINT16_INTERLEAVED:
            do {
                samplesReaded = ov_read(vorbisFile, pcmChannelsInterleaved,
                 sizeof(uint16_t) * 4096, MTR_ENDIANNESS, 2, 0, NULL);
                samplesCount += samplesReaded;
            } while (samplesReaded > 0);
            samplesCount /= 2;
            break;
        default:
            break;
    }

    ov_clear(vorbisFile); /* returns 0 on success */

    return samplesCount;
}

void MTR_OggFreeTempPcm(void)
{
    int buffersCount;
    int i;
    if (mtrOggTempPcm.data != NULL) {
        if (mtrOggTempPcm.interleaved)
            buffersCount = 1;
        else
            buffersCount = mtrOggTempPcm.channels;
        for (i = 0; i < buffersCount; i++) {
            if (mtrOggTempPcm.data[i] == NULL) {
                free(mtrOggTempPcm.data[i]);
                mtrOggTempPcm.data[i] = NULL;
            }
        }
        free(mtrOggTempPcm.data);
        mtrOggTempPcm.data = NULL;
    }
}

void MTR_OggFillTempPcmInterleaved(int format, OggVorbis_File *vorbisFile,
 char *pcmChannelsInterleaved, vorbis_info *vorbisInfo, size_t sampleSize,
 long int samplesCount)
{
    long int samplesReaded;
    mtrOggTempPcm.format = format;

    switch (format) {
        case MTR_PCM_SINT8_INTERLEAVED:
            samplesReaded = ov_read(vorbisFile, pcmChannelsInterleaved,
             sampleSize * samplesCount, MTR_ENDIANNESS, 1, 1, NULL);
            break;
        case MTR_PCM_UINT8_INTERLEAVED:
            samplesReaded = ov_read(vorbisFile, pcmChannelsInterleaved,
             sampleSize * samplesCount, MTR_ENDIANNESS, 1, 0, NULL);
            break;
        case MTR_PCM_SINT16_INTERLEAVED:
            samplesReaded = ov_read(vorbisFile, pcmChannelsInterleaved,
             sampleSize * samplesCount, MTR_ENDIANNESS, 2, 1, NULL) / 2;
            break;
        case MTR_PCM_UINT16_INTERLEAVED:
            samplesReaded = ov_read(vorbisFile, pcmChannelsInterleaved,
             sampleSize * samplesCount, MTR_ENDIANNESS, 2, 0, NULL) / 2;
            break;
        default:
            samplesReaded = 0;
            break;
    }

    if (samplesReaded <= 0) {
        ov_clear(vorbisFile);
        return;
    }

    mtrOggTempPcm.channels = vorbisInfo->channels;
    mtrOggTempPcm.data = malloc(sizeof(void *));
    if (mtrOggTempPcm.data == NULL) {
        ov_clear(vorbisFile);
        return;
    }

    mtrOggTempPcm.samples = samplesCount;
    mtrOggTempPcm.data[0] = malloc(
     sampleSize * mtrOggTempPcm.channels * mtrOggTempPcm.samples);
    if (mtrOggTempPcm.data[0] == NULL) {
        ov_clear(vorbisFile);
        MTR_OggFreeTempPcm();
        return;
    }

    memcpy(mtrOggTempPcm.data[0], pcmChannelsInterleaved,
     sampleSize * mtrOggTempPcm.channels * mtrOggTempPcm.samples);

    mtrOggTempPcm.sampleRate = vorbisInfo->rate;
    mtrOggTempPcm.interleaved = true;
}

/*fa MTR_OggLoadSimple yes */
MTR_DCLSPC mtrPcm_t *MTR_CALL MTR_OggLoadSimple(const char *filename,
 int format)
{
    int             vorbisOpened;
    FILE           *file = NULL;
    OggVorbis_File *vorbisFile = NULL;
    long int        samplesCount;
    long int        samplesReaded;
    float         **pcmChannelsSingle;
    char           *pcmChannelsInterleaved = NULL;
    int             i;
    vorbis_info    *vorbisInfo;

    if (filename == NULL)
        return NULL;

    samplesCount = MTR_OggSamplesCount(filename, format);

    file = MTR_OggStdio.Fopen(filename, "rb");
    if (file == NULL)
        return NULL;

    vorbisOpened = ov_test_callbacks(file, vorbisFile, NULL, 0,
     mtrOggCallbacks);
    if (!vorbisOpened) {
        MTR_OggStdio.Fclose(file);
        return NULL;
    }

    vorbisOpened = ov_test_open(vorbisFile);
    if (!vorbisOpened) {
        ov_clear(vorbisFile);
        return NULL;
    }

    MTR_OggFreeTempPcm();

    vorbisInfo = ov_info(vorbisFile, -1);

    switch (format) {
        case MTR_PCM_SINGLE:
            mtrOggTempPcm.format = MTR_PCM_SINGLE;

            samplesReaded = ov_read_float(vorbisFile, &pcmChannelsSingle,
             samplesCount, NULL);
            if (samplesReaded <= 0) {
                ov_clear(vorbisFile);
                return NULL;
            }

            mtrOggTempPcm.channels = vorbisInfo->channels;
            mtrOggTempPcm.data = malloc(
             sizeof(float *) * mtrOggTempPcm.channels);
            if (mtrOggTempPcm.data == NULL) {
                ov_clear(vorbisFile);
                return NULL;
            }

            mtrOggTempPcm.samples = samplesCount;
            for (i = 0; i < mtrOggTempPcm.channels; i++) {
                mtrOggTempPcm.data[i] = malloc(
                 sizeof(float) * mtrOggTempPcm.samples);
                if (mtrOggTempPcm.data[i] == NULL) {
                    ov_clear(vorbisFile);
                    MTR_OggFreeTempPcm();
                    return NULL;
                }
            }

            for (i = 0; i < mtrOggTempPcm.channels; i++) {
                memcpy(mtrOggTempPcm.data[i], pcmChannelsSingle[i],
                 sizeof(float) * mtrOggTempPcm.samples);
            }

            mtrOggTempPcm.sampleRate = vorbisInfo->rate;
            mtrOggTempPcm.interleaved = false;
            break;
        case MTR_PCM_SINT8_INTERLEAVED:
            MTR_OggFillTempPcmInterleaved(format, vorbisFile,
             pcmChannelsInterleaved, vorbisInfo, sizeof(int8_t), samplesCount);
            break;
        case MTR_PCM_UINT8_INTERLEAVED:
            MTR_OggFillTempPcmInterleaved(format, vorbisFile,
             pcmChannelsInterleaved, vorbisInfo, sizeof(uint8_t), samplesCount);
            break;
        case MTR_PCM_SINT16_INTERLEAVED:
            MTR_OggFillTempPcmInterleaved(format, vorbisFile,
             pcmChannelsInterleaved, vorbisInfo, sizeof(int16_t), samplesCount);
            break;
        case MTR_PCM_UINT16_INTERLEAVED:
            MTR_OggFillTempPcmInterleaved(format, vorbisFile,
             pcmChannelsInterleaved, vorbisInfo, sizeof(uint16_t),
             samplesCount);
            break;
        default:
            MTR_LogWrite("Unknown sample format", 0, MTR_LMT_ERROR);
            ov_clear(vorbisFile);
            return NULL;
            break;
    }

    ov_clear(vorbisFile); /* returns 0 on success */

    return &mtrOggTempPcm;
}
