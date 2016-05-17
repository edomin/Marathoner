#include "marathoner.h"
#include "log.h"
#include "messagebox.h"
#include "notification.h"

int main(int argc, char** argv)
{
    WIN32_FIND_DATA FindFileData;
    HANDLE          hf;
    char           *fullPluginFileName;
    int             i;
    uint8_t         mtrPluginsFound;
    uint8_t         currentPlugin;
    char           *temp; /* Read config result */
    bool            ok;

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
                /* Plugin requiring some engine functions */
                mtrRequireEngineFuncs = (mtrRequireEngineFuncsFunc)GetProcAddress(mtrPluginData[currentPlugin].dll,
                  "mtrRequireEngineFuncs");
                mtrRequireEngineFuncs(mtrLogWrite, mtrLogWrite_s, mtrLogWrite_i,
                  mtrLogWrite_d, mtrNotify);

                /* Plugin requiring information about every other plugin */
                mtrRequirePluginData = (mtrRequirePluginDataFunc)GetProcAddress(mtrPluginData[currentPlugin].dll,
                  "mtrRequirePluginData");
                mtrRequirePluginData(mtrPluginData, mtrPluginsFound);

                currentPlugin++;
                /* freing temporary allocated structures */
                free(fullPluginFileName);
            }
        }
        while(FindNextFile(hf, &FindFileData) !=0 );
        FindClose(hf);
    }

//    for (i = 0; i < mtrPluginsFound; i++)
//    {
//
//    }
    mtrLogWrite("Reading 'Marathoner.cfg' for autorun options", 0,
      MTR_LMT_INFO);
    ok = false;
    temp = mtrConfigfileReadString("Marathoner.cfg", "Autorun", "action",
      "none");
    if (strcmp(temp, "runScript") == 0)
    {
        free(temp);
        temp = mtrConfigfileReadString("Marathoner.cfg", "Autorun", "plugin",
          "none");
        for (i = 0; i < mtrPluginsFound; i++)
        {
            if (strcmp(mtrPluginData[i].report->moduleID, temp) == 0)
            {
                ok = true;
                currentPlugin = i;
                break;
            }
        }
        if (ok)
        {
            free(temp);
            temp = mtrConfigfileReadString("Marathoner.cfg", "Autorun",
              "script", "none");
            if (strcmp(temp, "none") != 0)
            {
                mtrScriptsAutorun = (mtrScriptsAutorunFunc)GetProcAddress(mtrPluginData[currentPlugin].dll, "mtrScriptsAutorun");
                if (mtrScriptsAutorun == NULL)
                    mtrNotify("Unable to load autorun plugin function", 1,
                      MTR_LMT_ERROR);
                else
                {
                    mtrLogWrite_s("Running autorun function with file:", 0,
                      MTR_LMT_INFO, temp);
                    mtrScriptsAutorun(temp);
                }
                free(temp);
            }
            else
            {
                mtrNotify("Unable to read autorun script filename", 1,
                  MTR_LMT_ERROR);
                free(temp);
            }
        }
        else
        {
            mtrNotify("Ivalid autorun plugin", 1, MTR_LMT_ERROR);
            free(temp);
        }
    }
    else
    {
        mtrNotify("Invalid autorun action command", 1, MTR_LMT_ERROR);
        free(temp);
    }

    mtrLogWrite("Quiting Engine", 0, MTR_LMT_INFO);
    /* Freing allocated structures and unloading libraries */
    for (i = 0; i < mtrPluginsFound; i++)
        FreeLibrary(mtrPluginData[i].dll);
    free(mtrPluginData);

    return 0;
}
