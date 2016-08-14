#include "log.h"
#include "messagebox.h"
#include "notification.h"
#include "configfile.h"
#include "indexkeeper.h"

#include "marathoner/engine.h"

void RequireEngineFuncs(uint8_t plugin)
{
    mtrRequireLogWrite = (mtrRequireLogWriteFunc)GetProcAddress(mtrPluginData[plugin].dll,
     "mtrRequireLogWrite");
    if (mtrRequireLogWrite != NULL)
        mtrRequireLogWrite(mtrLogWrite);
    else
        mtrLogWrite("Module are not contain declaration for 'mtrLogWrite' function", 1, MTR_LMT_WARNING);

    mtrRequireLogWrite_s = (mtrRequireLogWrite_sFunc)GetProcAddress(mtrPluginData[plugin].dll,
     "mtrRequireLogWrite_s");
    if (mtrRequireLogWrite_s != NULL)
        mtrRequireLogWrite_s(mtrLogWrite_s);
    else
        mtrLogWrite("Module are not contain declaration for 'mtrLogWrite_s' function", 1, MTR_LMT_WARNING);

    mtrRequireLogWrite_i = (mtrRequireLogWrite_iFunc)GetProcAddress(mtrPluginData[plugin].dll,
     "mtrRequireLogWrite_i");
    if (mtrRequireLogWrite_i != NULL)
        mtrRequireLogWrite_i(mtrLogWrite_i);
    else
        mtrLogWrite("Module are not contain declaration for 'mtrLogWrite_i' function", 1, MTR_LMT_WARNING);

    mtrRequireLogWrite_d = (mtrRequireLogWrite_dFunc)GetProcAddress(mtrPluginData[plugin].dll,
     "mtrRequireLogWrite_d");
    if (mtrRequireLogWrite_d != NULL)
        mtrRequireLogWrite_d(mtrLogWrite_d);
    else
        mtrLogWrite("Module are not contain declaration for 'mtrLogWrite_d' function", 1, MTR_LMT_WARNING);

    mtrRequireNotify = (mtrRequireNotifyFunc)GetProcAddress(mtrPluginData[plugin].dll,
     "mtrRequireNotify");
    if (mtrRequireNotify != NULL)
        mtrRequireNotify(mtrNotify);
    else
        mtrLogWrite("Module are not contain declaration for 'mtrNotify' function", 1, MTR_LMT_WARNING);

    mtrRequireIndexkeeperCreate = (mtrRequireIndexkeeperCreateFunc)GetProcAddress(mtrPluginData[plugin].dll,
     "mtrRequireIndexkeeperCreate");
    if (mtrRequireIndexkeeperCreate != NULL)
        mtrRequireIndexkeeperCreate(mtrIndexkeeperCreate);
    else
        mtrLogWrite("Module are not contain declaration for 'mtrIndexkeeperCreate' function", 1, MTR_LMT_WARNING);

    mtrRequireIndexkeeperGetFreeIndex = (mtrRequireIndexkeeperGetFreeIndexFunc)GetProcAddress(mtrPluginData[plugin].dll,
     "mtrRequireIndexkeeperGetFreeIndex");
    if (mtrRequireIndexkeeperGetFreeIndex != NULL)
        mtrRequireIndexkeeperGetFreeIndex(mtrIndexkeeperGetFreeIndex);
    else
        mtrLogWrite("Module are not contain declaration for 'mtrIndexkeeperGetFreeIndex' function", 1, MTR_LMT_WARNING);

    mtrRequireIndexkeeperFreeIndex = (mtrRequireIndexkeeperFreeIndexFunc)GetProcAddress(mtrPluginData[plugin].dll,
     "mtrRequireIndexkeeperFreeIndex");
    if (mtrRequireIndexkeeperFreeIndex != NULL)
        mtrRequireIndexkeeperFreeIndex(mtrIndexkeeperFreeIndex);
    else
        mtrLogWrite("Module are not contain declaration for 'mtrIndexkeeperFreeIndex' function", 1, MTR_LMT_WARNING);

    mtrRequireIndexkeeperDestroy = (mtrRequireIndexkeeperDestroyFunc)GetProcAddress(mtrPluginData[plugin].dll,
     "mtrRequireIndexkeeperDestroy");
    if (mtrRequireIndexkeeperDestroy != NULL)
        mtrRequireIndexkeeperDestroy(mtrIndexkeeperDestroy);
    else
        mtrLogWrite("Module are not contain declaration for 'mtrIndexkeeperDestroy' function", 1, MTR_LMT_WARNING);
}

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

    mtrLogWrite("Reporting Marathoner version:", 0, MTR_LMT_INFO);
    mtrLogWrite_i("Majon:", 1, MTR_LMT_INFO,
     MTR_MARATHONER_VERSION >> 16);
    mtrLogWrite_i("Minor:", 1, MTR_LMT_INFO,
     (MTR_MARATHONER_VERSION << 8) >> 16);
    mtrLogWrite_i("Patch:", 1, MTR_LMT_INFO,
     (MTR_MARATHONER_VERSION << 16) >> 16);

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
                mtrLogWrite("Version:", 1, MTR_LMT_INFO);
                mtrLogWrite_i("Majon:", 2, MTR_LMT_INFO,
                  mtrPluginData[currentPlugin].report->version >> 16);
                mtrLogWrite_i("Minor:", 2, MTR_LMT_INFO,
                  (mtrPluginData[currentPlugin].report->version << 8) >> 16);
                mtrLogWrite_i("Patch:", 2, MTR_LMT_INFO,
                  (mtrPluginData[currentPlugin].report->version << 16) >> 16);
                if (mtrPluginData[currentPlugin].report->prereqsCount > 0)
                {
                    mtrLogWrite("Requirements:", 1, MTR_LMT_INFO);
                    for (i = 0; i < mtrPluginData[currentPlugin].report->prereqsCount; i++)
                        mtrLogWrite(mtrPluginData[currentPlugin].report->prereqs[i],
                          2, MTR_LMT_INFO);
                }
                /* Plugin requiring some engine functions */
                RequireEngineFuncs(currentPlugin);

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

    mtrLogWrite("Engine stopped", 0, MTR_LMT_INFO);

    return 0;
}
