#include <windows.h>
#include <stdint.h>
#include <stdlib.h>

#include "marathoner.h"
#include "log.h"
#include "messagebox.h"
#include "notification.h"

typedef mtrReport* (__stdcall * mtrReportFunc)(void);
mtrReportFunc mtrCreateReport;

typedef struct mtrPlugin{
    mtrReport *report;
    char      *filename;
    HMODULE    dll;
} mtrPlugin;

int main(int argc, char** argv)
{
    WIN32_FIND_DATA FindFileData;
    HANDLE          hf;
    char           *fullPluginFileName;
    int             i;
    uint8_t         mtrPluginsFound;
    mtrPlugin      *mtrPluginData;
    uint8_t         currentPlugin;

    mtrLogInit();
    mtrLogWrite("Searching available plugins", 0, MTR_LMT_INFO);

    mtrPluginsFound = 0;
    /* Counting available plugins */
    hf = FindFirstFile("plugin/*", &FindFileData);
    if(hf != INVALID_HANDLE_VALUE)
    {
        do
        {
            if(FindFileData.dwFileAttributes != FILE_ATTRIBUTE_DIRECTORY)
                mtrPluginsFound++;
        }
        while(FindNextFile(hf, &FindFileData) !=0 );
        FindClose(hf);
    }
    /* Allocating plugin data structures */
    if (mtrPluginsFound != 0)
        mtrPluginData = malloc(sizeof(mtrPlugin) * mtrPluginsFound);
    else
    {
        mtrNotify("Plugins not Found", 0, MTR_LMT_FATAL);
        return 1;
    }
    /* Getting plugins data */
    hf = FindFirstFile("plugin/*", &FindFileData);
    if(hf != INVALID_HANDLE_VALUE)
    {
        currentPlugin = 0;
        do
        {
            if(FindFileData.dwFileAttributes != FILE_ATTRIBUTE_DIRECTORY)
            {
                mtrLogWrite_s("Plugin found:", 0, MTR_LMT_INFO,
                  FindFileData.cFileName);
                /* file name in plugin/ directory */
                mtrPluginData[currentPlugin].filename = FindFileData.cFileName;
                /* temporary plugin file name with relative path */
                fullPluginFileName = malloc(strlen("plugin/") +
                  strlen(FindFileData.cFileName) + 1);
                strcpy(fullPluginFileName, "plugin/");
                strcat(fullPluginFileName, FindFileData.cFileName);
                /* Loading plugin library */
                mtrPluginData[currentPlugin].dll = LoadLibrary(fullPluginFileName);
                if (mtrPluginData[currentPlugin].dll == NULL)
                    mtrNotify("Library not loaded", 1, MTR_LMT_ERROR);
                mtrCreateReport = (mtrReportFunc)GetProcAddress(mtrPluginData[currentPlugin].dll,
                  "mtrCreateReport");
                if (mtrCreateReport == NULL)
                    mtrNotify("Library not contain mtrCreateReport function", 1,
                      MTR_LMT_ERROR);
                mtrPluginData[currentPlugin].report = mtrCreateReport();
                mtrLogWrite_s("Module ID:", 1, MTR_LMT_INFO,
                  mtrPluginData[currentPlugin].report->moduleID);
                if (mtrPluginData[currentPlugin].report->prereqsCount > 0)
                {
                    mtrLogWrite("Requirements:", 1, MTR_LMT_INFO);
                    for (i = 0; i < mtrPluginData[currentPlugin].report->prereqsCount; i++)
                        mtrLogWrite(mtrPluginData[currentPlugin].report->prereqs[i],
                          2, MTR_LMT_INFO);
                }

                currentPlugin++;
                /* freing temporary allocated structures */
                free(fullPluginFileName);
            }
        }
        while(FindNextFile(hf, &FindFileData) !=0 );
        FindClose(hf);
    }
    /* Freing allocated structures and unload libraries */
    for (i = 0; i < mtrPluginsFound; i++)
        FreeLibrary(mtrPluginData[i].dll);
    free(mtrPluginData);

    return 0;
}
