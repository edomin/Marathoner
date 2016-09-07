#include "log.h"
#include "messagebox.h"
#include "notification.h"
#include "configfile.h"
#include "indexkeeper.h"
#include "file.h"

#include "marathoner/engine.h"

void RequireEngineFuncs(uint8_t plugin)
{
    mtrRequireLogWrite = (mtrRequireLogWriteFunc)mtrLoadSymbolName(mtrPluginData[plugin].dll,
     "mtrRequireLogWrite");
    if (mtrRequireLogWrite != NULL)
        mtrRequireLogWrite(mtrLogWrite);
    else
        mtrLogWrite("Module are not contain declaration for 'mtrLogWrite' function", 1, MTR_LMT_WARNING);

    mtrRequireLogWrite_s = (mtrRequireLogWrite_sFunc)mtrLoadSymbolName(mtrPluginData[plugin].dll,
     "mtrRequireLogWrite_s");
    if (mtrRequireLogWrite_s != NULL)
        mtrRequireLogWrite_s(mtrLogWrite_s);
    else
        mtrLogWrite("Module are not contain declaration for 'mtrLogWrite_s' function", 1, MTR_LMT_WARNING);

    mtrRequireLogWrite_i = (mtrRequireLogWrite_iFunc)mtrLoadSymbolName(mtrPluginData[plugin].dll,
     "mtrRequireLogWrite_i");
    if (mtrRequireLogWrite_i != NULL)
        mtrRequireLogWrite_i(mtrLogWrite_i);
    else
        mtrLogWrite("Module are not contain declaration for 'mtrLogWrite_i' function", 1, MTR_LMT_WARNING);

    mtrRequireLogWrite_d = (mtrRequireLogWrite_dFunc)mtrLoadSymbolName(mtrPluginData[plugin].dll,
     "mtrRequireLogWrite_d");
    if (mtrRequireLogWrite_d != NULL)
        mtrRequireLogWrite_d(mtrLogWrite_d);
    else
        mtrLogWrite("Module are not contain declaration for 'mtrLogWrite_d' function", 1, MTR_LMT_WARNING);

    mtrRequireNotify = (mtrRequireNotifyFunc)mtrLoadSymbolName(mtrPluginData[plugin].dll,
     "mtrRequireNotify");
    if (mtrRequireNotify != NULL)
        mtrRequireNotify(mtrNotify);
    else
        mtrLogWrite("Module are not contain declaration for 'mtrNotify' function", 1, MTR_LMT_WARNING);

    mtrRequireIndexkeeperCreate = (mtrRequireIndexkeeperCreateFunc)mtrLoadSymbolName(mtrPluginData[plugin].dll,
     "mtrRequireIndexkeeperCreate");
    if (mtrRequireIndexkeeperCreate != NULL)
        mtrRequireIndexkeeperCreate(mtrIndexkeeperCreate);
    else
        mtrLogWrite("Module are not contain declaration for 'mtrIndexkeeperCreate' function", 1, MTR_LMT_WARNING);

    mtrRequireIndexkeeperGetFreeIndex = (mtrRequireIndexkeeperGetFreeIndexFunc)mtrLoadSymbolName(mtrPluginData[plugin].dll,
     "mtrRequireIndexkeeperGetFreeIndex");
    if (mtrRequireIndexkeeperGetFreeIndex != NULL)
        mtrRequireIndexkeeperGetFreeIndex(mtrIndexkeeperGetFreeIndex);
    else
        mtrLogWrite("Module are not contain declaration for 'mtrIndexkeeperGetFreeIndex' function", 1, MTR_LMT_WARNING);

    mtrRequireIndexkeeperFreeIndex = (mtrRequireIndexkeeperFreeIndexFunc)mtrLoadSymbolName(mtrPluginData[plugin].dll,
     "mtrRequireIndexkeeperFreeIndex");
    if (mtrRequireIndexkeeperFreeIndex != NULL)
        mtrRequireIndexkeeperFreeIndex(mtrIndexkeeperFreeIndex);
    else
        mtrLogWrite("Module are not contain declaration for 'mtrIndexkeeperFreeIndex' function", 1, MTR_LMT_WARNING);

    mtrRequireIndexkeeperDestroy = (mtrRequireIndexkeeperDestroyFunc)mtrLoadSymbolName(mtrPluginData[plugin].dll,
     "mtrRequireIndexkeeperDestroy");
    if (mtrRequireIndexkeeperDestroy != NULL)
        mtrRequireIndexkeeperDestroy(mtrIndexkeeperDestroy);
    else
        mtrLogWrite("Module are not contain declaration for 'mtrIndexkeeperDestroy' function", 1, MTR_LMT_WARNING);

    mtrRequireFileWriteLine = (mtrRequireFileWriteLineFunc)mtrLoadSymbolName(mtrPluginData[plugin].dll,
     "mtrRequireFileWriteLine");
    if (mtrRequireFileWriteLine != NULL)
        mtrRequireFileWriteLine(mtrFileWriteLine);
    else
        mtrLogWrite("Module are not contain declaration for 'mtrFileWriteLine' function", 1, MTR_LMT_WARNING);
}

int main(int argc, char** argv)
{
    #ifdef __MINGW32__
        WIN32_FIND_DATA FindFileData;
        HANDLE          hf;
    #else
        DIR           *d;
        struct dirent *dir;
    #endif
    char           *fullPluginFileName;
    int             i;
    uint8_t         mtrPluginsFound;
    uint8_t         currentPlugin;
    char           *temp; /* Read config result */
    bool            ok;

    mtrLogInit();

    mtrLogWrite("Reporting Marathoner version:", 0, MTR_LMT_INFO);
    mtrLogWrite_i("Majon:", 1, MTR_LMT_INFO,
     (MTR_VERSION_MARATHONER & 0xFF0000) >> 16);
    mtrLogWrite_i("Minor:", 1, MTR_LMT_INFO,
     (MTR_VERSION_MARATHONER & 0x00FF00) >> 8);
    mtrLogWrite_i("Patch:", 1, MTR_LMT_INFO,
     MTR_VERSION_MARATHONER & 0x0000FF);

    mtrLogWrite("Searching available plugins", 0, MTR_LMT_INFO);

    mtrPluginsFound = 0;
    /* Counting available plugins */
    #ifdef __MINGW32__
        hf = FindFirstFile("plugin/*", &FindFileData);
        if(hf == INVALID_HANDLE_VALUE)
        {
            mtrNotify("Unable to open 'plugin/*' directory for counting files",
             0, MTR_LMT_FATAL);
            return 1;
        }
        else
        {
            do
            {
                if(FindFileData.dwFileAttributes != FILE_ATTRIBUTE_DIRECTORY)
                    mtrPluginsFound++;
            }
            while(FindNextFile(hf, &FindFileData) != 0);
            FindClose(hf);
        }
    #else
        d = opendir("./plugin/");
        if (d == NULL)
        {
            mtrNotify("Unable to open './plugin' directory for counting files",
             0, MTR_LMT_FATAL);
            return 1;
        }
        else
        {
            while ((dir = readdir(d)) != NULL)
            {
                if((strcmp(dir->d_name, "..") != 0) &&
                 (strcmp(dir->d_name, ".") != 0))
                    mtrPluginsFound++;
            }
            closedir(d);
        }
    #endif
    /* Allocating plugin data structures */
    if (mtrPluginsFound != 0)
        mtrPluginData = malloc(sizeof(mtrPlugin) * mtrPluginsFound);
    else
    {
        mtrNotify("Plugins not Found", 0, MTR_LMT_FATAL);
        return 1;
    }
    /* Getting plugins data */
    #ifdef __MINGW32__
    hf = FindFirstFile("plugin/*", &FindFileData);
    if(hf == INVALID_HANDLE_VALUE)
    #else
    d = opendir("./plugin/");
    if (d != NULL)
    #endif
    {
        currentPlugin = 0;
        #ifdef __MINGW32__
        do
        #else
        while ((dir = readdir(d)) != NULL)
        #endif
        {
            #ifdef __MINGW32__
            if(FindFileData.dwFileAttributes != FILE_ATTRIBUTE_DIRECTORY)
            #else
            if((strcmp(dir->d_name, "..") != 0) &&
             (strcmp(dir->d_name, ".") != 0))
            #endif
            {
                #ifdef __MINGW32__
                    mtrLogWrite_s("Plugin found:", 0, MTR_LMT_INFO,
                     FindFileData.cFileName);
                    /* file name in plugin/ directory */
                    mtrPluginData[currentPlugin].filename = FindFileData.cFileName;
                    /* temporary plugin file name with relative path */
                    fullPluginFileName = malloc(strlen("plugin/") +
                     strlen(FindFileData.cFileName) + 1);
                    strcpy(fullPluginFileName, "plugin/");
                    strcat(fullPluginFileName, FindFileData.cFileName);
                #else
                    mtrLogWrite_s("Plugin found:", 0, MTR_LMT_INFO,
                     dir->d_name);
                    /* file name in plugin/ directory */
                    mtrPluginData[currentPlugin].filename = dir->d_name;
                    /* temporary plugin file name with relative path */
                    fullPluginFileName = malloc(strlen("plugin/") +
                     strlen(dir->d_name) + 1);
                    strcpy(fullPluginFileName, "plugin/");
                    strcat(fullPluginFileName, dir->d_name);
                #endif
                /* Loading plugin library */
                mtrPluginData[currentPlugin].dll = mtrLoadLibrary(fullPluginFileName);
                if (mtrPluginData[currentPlugin].dll == NULL)
                {
                    mtrNotify("Library not loaded", 1, MTR_LMT_ERROR);
                    #ifdef __EMSCRIPTEN__
                    mtrLogWrite(dlerror(), 1, MTR_LMT_ERROR);
                    #endif
                }
                mtrCreateReport = (mtrReportFunc)mtrLoadSymbolName(mtrPluginData[currentPlugin].dll,
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
                mtrRequirePluginData = (mtrRequirePluginDataFunc)mtrLoadSymbolName(mtrPluginData[currentPlugin].dll,
                  "mtrRequirePluginData");
                mtrRequirePluginData(mtrPluginData, mtrPluginsFound);

                currentPlugin++;
                /* freing temporary allocated structures */
                free(fullPluginFileName);
            }
        }
        #ifdef __MINGW32__
        while(FindNextFile(hf, &FindFileData) !=0 );
        FindClose(hf);
        #else
        closedir(d);
        #endif
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
                mtrScriptsAutorun = (mtrScriptsAutorunFunc)mtrLoadSymbolName(mtrPluginData[currentPlugin].dll, "mtrScriptsAutorun");
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
        mtrCloseLibrary(mtrPluginData[i].dll);
    free(mtrPluginData);

    mtrLogWrite("Engine stopped", 0, MTR_LMT_INFO);

    return 0;
}
