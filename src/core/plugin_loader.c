#include "plugin_loader.h"

int CountPlugins(char *directoryName)
{
    mtrDirectory_t *directory;
    int pluginsFound;

    pluginsFound = 0;
    directory = mtrDirectoryOpen(directoryName);
    if (directory == NULL)
        return -1;
    else
    {
        while (mtrDirectoryNextFile(directory))
        {
            if (!mtrDirectoryFileIsDir(directory))
                pluginsFound++;
        }
        mtrDirectoryClose(directory);
    }
    return pluginsFound;
}

int mtrLoadAllPlugins(RequireEngineFuncsFunc RequireEngineFuncs)
{
    char   *fullPluginFileName;
    uint8_t i;

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
    {
        mtrPluginData = malloc(sizeof(mtrPlugin) * mtrPluginsFound);
        if (mtrPluginData == NULL)
        {
            mtrNotify("Unable to allocate memory for plugin data", 0,
             MTR_LMT_FATAL);
            return 2;
        }
    }
    else
    {
        mtrNotify("Plugins not Found", 0, MTR_LMT_FATAL);
        return 3;
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
                mtrPluginData[currentPlugin].filename = malloc(strlen(tempFilename) + 1);
                strcpy(mtrPluginData[currentPlugin].filename, tempFilename);
                //mtrPluginData[currentPlugin].filename = tempFilename;
                /* temporary plugin file name with relative path */
                fullPluginFileName = malloc(strlen("plugin/") +
                 strlen(mtrPluginData[currentPlugin].filename) + 1);
                if (fullPluginFileName == NULL)
                {
                    mtrNotify("Unable to allocate memory for plugin's full filename: ",
                     1, MTR_LMT_ERROR);
                    continue;
                }
                strcpy(fullPluginFileName, "plugin/");
                strcat(fullPluginFileName, mtrPluginData[currentPlugin].filename);
                /* Loading plugin library */
                mtrPluginData[currentPlugin].dll = mtrLoadLibrary(fullPluginFileName);
                if (mtrPluginData[currentPlugin].dll == NULL)
                {
                    mtrNotify("Library not loaded", 1, MTR_LMT_ERROR);
                    #ifdef __EMSCRIPTEN__
                    mtrLogWrite(dlerror(), 1, MTR_LMT_ERROR);
                    #endif
                    continue;
                }
                mtrCreateReport = (mtrReportFunc)mtrLoadSymbolName(mtrPluginData[currentPlugin].dll,
                  "mtrCreateReport");
                if (mtrCreateReport == NULL)
                    mtrNotify("Library not contain mtrCreateReport function", 1,
                     MTR_LMT_ERROR);
                mtrPluginData[currentPlugin].report = mtrCreateReport();
                if (mtrPluginData[currentPlugin].report == NULL)
                {
                    mtrNotify("Module are not returned report", 1,
                     MTR_LMT_ERROR);
                    free(fullPluginFileName);
                    mtrCloseLibrary(mtrPluginData[currentPlugin].dll);
                    continue;
                }
                mtrLogWrite_s("Module ID:", 1, MTR_LMT_INFO,
                  mtrPluginData[currentPlugin].report->moduleID);
                mtrLogWrite("Version:", 1, MTR_LMT_INFO);
                mtrLogWrite_i("Majon:", 2, MTR_LMT_INFO,
                  (mtrPluginData[currentPlugin].report->version & 0xFF0000) >> 16);
                mtrLogWrite_i("Minor:", 2, MTR_LMT_INFO,
                  (mtrPluginData[currentPlugin].report->version & 0x00FF00) >> 8);
                mtrLogWrite_i("Patch:", 2, MTR_LMT_INFO,
                  mtrPluginData[currentPlugin].report->version & 0x0000FF);
                if (mtrPluginData[currentPlugin].report->prereqSubsystemsCount > 0)
                {
                    mtrLogWrite("Requirement subsystems:", 1, MTR_LMT_INFO);
                    for (i = 0; i < mtrPluginData[currentPlugin].report->prereqSubsystemsCount; i++)
                        mtrLogWrite(mtrPluginData[currentPlugin].report->prereqSubsystems[i],
                          2, MTR_LMT_INFO);
                }
                if (mtrPluginData[currentPlugin].report->prereqsCount > 0)
                {
                    mtrLogWrite("Requirement modules:", 1, MTR_LMT_INFO);
                    for (i = 0; i < mtrPluginData[currentPlugin].report->prereqsCount; i++)
                        mtrLogWrite(mtrPluginData[currentPlugin].report->prereqs[i],
                          2, MTR_LMT_INFO);
                }
                /* Plugin requiring some engine functions */
                if (RequireEngineFuncs != NULL)
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
    return 0;
}
