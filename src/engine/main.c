#include "log.h"
#include "messagebox.h"
#include "notification.h"
#include "configfile.h"
#include "indexkeeper.h"
#include "file.h"
#include "directory.h"

#include "marathoner/engine.h"

void RequireEngineFuncs(uint8_t plugin)
{
    mtrRequireLogWrite = (mtrRequireLogWriteFunc)mtrLoadSymbolName(mtrPluginData[plugin].dll,
     "mtrRequireLogWrite");
    if (mtrRequireLogWrite != NULL)
        mtrRequireLogWrite(mtrLogWrite);
    else
        mtrLogWrite("Module are not contain declaration for 'mtrLogWrite' function",
         1, MTR_LMT_WARNING);

    mtrRequireLogWrite_s = (mtrRequireLogWrite_sFunc)mtrLoadSymbolName(mtrPluginData[plugin].dll,
     "mtrRequireLogWrite_s");
    if (mtrRequireLogWrite_s != NULL)
        mtrRequireLogWrite_s(mtrLogWrite_s);
    else
        mtrLogWrite("Module are not contain declaration for 'mtrLogWrite_s' function",
         1, MTR_LMT_WARNING);

    mtrRequireLogWrite_i = (mtrRequireLogWrite_iFunc)mtrLoadSymbolName(mtrPluginData[plugin].dll,
     "mtrRequireLogWrite_i");
    if (mtrRequireLogWrite_i != NULL)
        mtrRequireLogWrite_i(mtrLogWrite_i);
    else
        mtrLogWrite("Module are not contain declaration for 'mtrLogWrite_i' function",
         1, MTR_LMT_WARNING);

    mtrRequireLogWrite_d = (mtrRequireLogWrite_dFunc)mtrLoadSymbolName(mtrPluginData[plugin].dll,
     "mtrRequireLogWrite_d");
    if (mtrRequireLogWrite_d != NULL)
        mtrRequireLogWrite_d(mtrLogWrite_d);
    else
        mtrLogWrite("Module are not contain declaration for 'mtrLogWrite_d' function",
         1, MTR_LMT_WARNING);

    mtrRequireNotify = (mtrRequireNotifyFunc)mtrLoadSymbolName(mtrPluginData[plugin].dll,
     "mtrRequireNotify");
    if (mtrRequireNotify != NULL)
        mtrRequireNotify(mtrNotify);
    else
        mtrLogWrite("Module are not contain declaration for 'mtrNotify' function",
         1, MTR_LMT_WARNING);

    mtrRequireIndexkeeperCreate = (mtrRequireIndexkeeperCreateFunc)mtrLoadSymbolName(mtrPluginData[plugin].dll,
     "mtrRequireIndexkeeperCreate");
    if (mtrRequireIndexkeeperCreate != NULL)
        mtrRequireIndexkeeperCreate(mtrIndexkeeperCreate);
    else
        mtrLogWrite("Module are not contain declaration for 'mtrIndexkeeperCreate' function",
         1, MTR_LMT_WARNING);

    mtrRequireIndexkeeperGetFreeIndex = (mtrRequireIndexkeeperGetFreeIndexFunc)mtrLoadSymbolName(mtrPluginData[plugin].dll,
     "mtrRequireIndexkeeperGetFreeIndex");
    if (mtrRequireIndexkeeperGetFreeIndex != NULL)
        mtrRequireIndexkeeperGetFreeIndex(mtrIndexkeeperGetFreeIndex);
    else
        mtrLogWrite("Module are not contain declaration for 'mtrIndexkeeperGetFreeIndex' function",
         1, MTR_LMT_WARNING);

    mtrRequireIndexkeeperFreeIndex = (mtrRequireIndexkeeperFreeIndexFunc)mtrLoadSymbolName(mtrPluginData[plugin].dll,
     "mtrRequireIndexkeeperFreeIndex");
    if (mtrRequireIndexkeeperFreeIndex != NULL)
        mtrRequireIndexkeeperFreeIndex(mtrIndexkeeperFreeIndex);
    else
        mtrLogWrite("Module are not contain declaration for 'mtrIndexkeeperFreeIndex' function",
         1, MTR_LMT_WARNING);

    mtrRequireIndexkeeperDestroy = (mtrRequireIndexkeeperDestroyFunc)mtrLoadSymbolName(mtrPluginData[plugin].dll,
     "mtrRequireIndexkeeperDestroy");
    if (mtrRequireIndexkeeperDestroy != NULL)
        mtrRequireIndexkeeperDestroy(mtrIndexkeeperDestroy);
    else
        mtrLogWrite("Module are not contain declaration for 'mtrIndexkeeperDestroy' function",
         1, MTR_LMT_WARNING);

    mtrRequireFileWriteLine = (mtrRequireFileWriteLineFunc)mtrLoadSymbolName(mtrPluginData[plugin].dll,
     "mtrRequireFileWriteLine");
    if (mtrRequireFileWriteLine != NULL)
        mtrRequireFileWriteLine(mtrFileWriteLine);
    else
        mtrLogWrite("Module are not contain declaration for 'mtrFileWriteLine' function",
         1, MTR_LMT_WARNING);
}

int CountPlugins(char *directoryName)
{
    mtrDirectory_t *pluginDirectory;
    int mtrPluginsFound;

    mtrPluginsFound = 0;
    pluginDirectory = mtrDirectoryOpen(directoryName);
    if (pluginDirectory == NULL)
        return -1;
    else
    {
        while (mtrDirectoryNextFile(pluginDirectory))
        {
            if (!mtrDirectoryFileIsDir(pluginDirectory))
                mtrPluginsFound++;
        }
        mtrDirectoryClose(pluginDirectory);
    }
    return mtrPluginsFound;
}

int main(int argc, char** argv)
{
    mtrDirectory_t *pluginDirectory;
    char           *tempFilename;
    char           *fullPluginFileName;
    int             mtrPluginsFound;
    uint8_t         currentPlugin;
    int             i;
    int             j;
    int             k;
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
    mtrPluginsFound = CountPlugins("./plugin/");
    if (mtrPluginsFound == -1)
    {
        mtrNotify("Unable to open 'plugin/' directory for counting files",
         0, MTR_LMT_FATAL);
        return 1;
    }
    /* Allocating plugin data structures */
    if (mtrPluginsFound != 0)
        mtrPluginData = malloc(sizeof(mtrPlugin) * mtrPluginsFound);
    else
    {
        mtrNotify("Plugins not Found", 0, MTR_LMT_FATAL);
        return 2;
    }
    /* Getting plugins data */
    pluginDirectory = mtrDirectoryOpen("./plugin/");
    if (pluginDirectory != NULL)
    {
        currentPlugin = 0;
        while (mtrDirectoryNextFile(pluginDirectory))
        {
            tempFilename = mtrDirectoryGetFilename(pluginDirectory);
            if (!mtrDirectoryFileIsDir(pluginDirectory))
            {
                mtrLogWrite_s("Plugin found:", 0, MTR_LMT_INFO, tempFilename);
                /* file name in plugin/ directory */
                mtrPluginData[currentPlugin].filename = tempFilename;
                /* temporary plugin file name with relative path */
                fullPluginFileName = malloc(strlen("plugin/") +
                 strlen(tempFilename) + 1);
                strcpy(fullPluginFileName, "plugin/");
                strcat(fullPluginFileName, tempFilename);
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
                  (mtrPluginData[currentPlugin].report->version & 0xFF0000) >> 16);
                mtrLogWrite_i("Minor:", 2, MTR_LMT_INFO,
                  (mtrPluginData[currentPlugin].report->version & 0x00FF00) >> 8);
                mtrLogWrite_i("Patch:", 2, MTR_LMT_INFO,
                  mtrPluginData[currentPlugin].report->version & 0x0000FF);
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
        mtrDirectoryClose(pluginDirectory);
    }
    mtrLogWrite("Processing modules' reports", 0, MTR_LMT_INFO);
    ok = false;
    i = 0;
    while (i < mtrPluginsFound)
    {
        if (!mtrConfigfileReadBool("Marathoner.cfg", "Module", mtrPluginData[i].report->moduleID, true))
        {
            mtrLogWrite_s("Module are disabled by configfile: ", 1,
             MTR_LMT_NOTE, mtrPluginData[i].report->moduleID);

            mtrCloseLibrary(mtrPluginData[i].dll);
            free(mtrPluginData[i].filename);

            for (j = i; j < mtrPluginsFound - 1; j++)
                mtrPluginData[j] = mtrPluginData[j + 1];
            mtrPluginsFound--;
            i = 0;
            continue;
        }

        ok = true;
        /* searching conflicting subsystems */
        if ((strcmp(mtrPluginData[i].report->subsystem, "binding") != 0) &&
         (strcmp(mtrPluginData[i].report->subsystem, "utils") != 0) &&
         (strcmp(mtrPluginData[i].report->subsystem, "abstraction") != 0))
        {
            for (j = 0; j < mtrPluginsFound; j++)
            {
                temp = mtrConfigfileReadString("Marathoner.cfg",
                 "Subsystem", mtrPluginData[i].report->subsystem,
                "none");
                if (strcmp(temp, "none") == 0)
                {
                    mtrLogWrite_s("Subsystem of module are disabled by configfile:",
                     1, MTR_LMT_NOTE, mtrPluginData[i].report->moduleID);
                    mtrCloseLibrary(mtrPluginData[i].dll);
                    free(mtrPluginData[i].filename);
                    free(temp);
                    ok = false;
                    break;
                }

                if ((strcmp(mtrPluginData[i].report->subsystem, mtrPluginData[j].report->subsystem) == 0) &&
                   (i != j))
                {
                    ok = false;
                    temp = mtrConfigfileReadString("Marathoner.cfg",
                     "Subsystem", mtrPluginData[i].report->subsystem,
                    "none");

                    if (strcmp(temp, mtrPluginData[i].report->moduleID) == 0)
                    {
                        mtrLogWrite_s("Module will not loaded:", 1,
                         MTR_LMT_NOTE, mtrPluginData[j].report->moduleID);
                        mtrCloseLibrary(mtrPluginData[j].dll);
                        free(mtrPluginData[j].filename);
                        i = j;
                        free(temp);
                        break;
                    }
                    if (strcmp(temp, mtrPluginData[j].report->moduleID) == 0)
                    {
                        mtrLogWrite_s("Module will not loaded:", 1,
                         MTR_LMT_NOTE, mtrPluginData[i].report->moduleID);
                        mtrCloseLibrary(mtrPluginData[i].dll);
                        free(mtrPluginData[i].filename);
                        free(temp);
                        break;
                    }

                    mtrLogWrite_s("Conflicting modules of subsystem:", 1,
                     MTR_LMT_ERROR, mtrPluginData[i].report->subsystem);
                    mtrLogWrite_s("First module:", 2, MTR_LMT_INFO,
                     mtrPluginData[i].report->moduleID);
                    mtrLogWrite_s("Second module:", 2, MTR_LMT_INFO,
                     mtrPluginData[j].report->moduleID);
                    mtrLogWrite_s("Module will not loaded:", 1,
                     MTR_LMT_WARNING, mtrPluginData[i].report->moduleID);
                    mtrCloseLibrary(mtrPluginData[i].dll);
                    free(mtrPluginData[i].filename);

                    free(temp);
                    break;
                }
            }
            if (!ok)
            {

                for (j = i; j < mtrPluginsFound - 1; j++)
                    mtrPluginData[j] = mtrPluginData[j + 1];
                mtrPluginsFound--;
                i = 0;
                continue;
            }
        }
        /* searching existing of prerequied subsystems */
        if (mtrPluginData[i].report->prereqSubsystemsCount > 0)
        {
            for (j = 0; j < mtrPluginData[i].report->prereqSubsystemsCount; j++)
            {
                ok = false;
                for (k = 0; k < mtrPluginsFound; k++)
                {
                    if (strcmp(mtrPluginData[i].report->prereqSubsystems[j], mtrPluginData[k].report->subsystem) == 0)
                    {
                        ok = true;
                        break;
                    }
                }
                if (!ok)
                {
                    mtrLogWrite_s("Missing Prerequired subsystem module:", 1,
                     MTR_LMT_ERROR,
                     mtrPluginData[i].report->prereqSubsystems[j]);
                    mtrLogWrite_s("Module will not loaded:", 1,
                     MTR_LMT_WARNING, mtrPluginData[i].report->moduleID);
                    mtrCloseLibrary(mtrPluginData[i].dll);
                    free(mtrPluginData[i].filename);
                    for (j = i; j < mtrPluginsFound - 1; j++)
                        mtrPluginData[j] = mtrPluginData[j + 1];
                    mtrPluginsFound--;
                    i = 0;
                    continue;
                }
            }
        }
        /* checking existing of prerequisites */
        if (mtrPluginData[i].report->prereqsCount > 0)
        {
            for (j = 0; j < mtrPluginData[i].report->prereqsCount; j++)
            {
                ok = false;
                for (k = 0; k < mtrPluginsFound; k++)
                {
                    if (strcmp(mtrPluginData[i].report->prereqs[j], mtrPluginData[k].report->moduleID) == 0)
                    {
                        ok = true;
                        break;
                    }
                }
                if (!ok)
                {
                    mtrLogWrite_s("Missing Prerequisite module:", 1,
                     MTR_LMT_ERROR, mtrPluginData[i].report->prereqs[j]);
                    mtrLogWrite_s("Module will not loaded:", 1,
                     MTR_LMT_WARNING, mtrPluginData[i].report->moduleID);
                    mtrCloseLibrary(mtrPluginData[i].dll);
                    free(mtrPluginData[i].filename);
                    for (j = i; j < mtrPluginsFound - 1; j++)
                        mtrPluginData[j] = mtrPluginData[j + 1];
                    mtrPluginsFound--;
                    i = 0;
                    continue;
                }
            }
        }
        i++;
    }

    /* Plugins updating information about every other plugin */
    for (i = 0; i < mtrPluginsFound; i++)
    {
        mtrRequirePluginData = (mtrRequirePluginDataFunc)mtrLoadSymbolName(mtrPluginData[i].dll,
         "mtrRequirePluginData");
        mtrRequirePluginData(mtrPluginData, mtrPluginsFound);
    }

    mtrLogWrite("Modules' reports processed", 0, MTR_LMT_INFO);
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
