#include "formats.h"

#include "plugin_common.c"

__declspec(dllexport) mtrReport* __stdcall mtrCreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    report->moduleID = "Formats_sdl_gpu";
    report->prereqsCount = 0;
    report->prereqs = NULL;
    return report;
}

__declspec(dllexport) GPU_Image* __stdcall mtrLoadJPEG(char *filename)
{
    GPU_LoadImage((const char *)filename);
}

__declspec(dllexport) GPU_Image* __stdcall mtrLoadPNG(char *filename)
{
    GPU_LoadImage((const char *)filename);
}

__declspec(dllexport) GPU_Image* __stdcall mtrLoadTGA(char *filename)
{
    GPU_LoadImage((const char *)filename);
}

__declspec(dllexport) GPU_Image* __stdcall mtrLoadBMP(char *filename)
{
    GPU_LoadImage((const char *)filename);
}

__declspec(dllexport) GPU_Image* __stdcall mtrLoadPSD(char *filename)
{
    GPU_LoadImage((const char *)filename);
}

__declspec(dllexport) GPU_Image* __stdcall mtrLoadGIF(char *filename)
{
    GPU_LoadImage((const char *)filename);
}

__declspec(dllexport) GPU_Image* __stdcall mtrLoadHDR(char *filename)
{
    GPU_LoadImage((const char *)filename);
}

__declspec(dllexport) GPU_Image* __stdcall mtrLoadPIC(char *filename)
{
    GPU_LoadImage((const char *)filename);
}

__declspec(dllexport) GPU_Image* __stdcall mtrLoadPNM(char *filename)
{
    GPU_LoadImage((const char *)filename);
}
