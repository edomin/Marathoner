#include "plugin_loader.h"

int CountPlugins(char *directoryName)
{
    mtrDirectory_t *directory;
    int pluginsFound;

    pluginsFound = 0;
    directory = MTR_DirectoryOpen(directoryName);
    if (directory == NULL)
        return -1;
    else
    {
        while (MTR_DirectoryNextFile(directory))
        {
            if (!MTR_DirectoryFileIsDir(directory))
                pluginsFound++;
        }
        MTR_DirectoryClose(directory);
    }
    return pluginsFound;
}

int MTR_LoadAllPlugins(RequireEngineFuncsFunc RequireEngineFuncs)
{
    char   *fullPluginFileName;
    uint8_t i;

    mtrPluginsFound = 0;
    /* Counting available plugins */
    mtrPluginsFound = CountPlugins("./plugin/");
    if (mtrPluginsFound == -1)
    {
        MTR_Notify("Unable to open 'plugin/' directory for counting files",
         0, MTR_LMT_FATAL);
        return 1;
    }
    /* Allocating plugin data structures */
    if (mtrPluginsFound != 0)
    {
        mtrPluginData = malloc(sizeof(mtrPlugin) * mtrPluginsFound);
        if (mtrPluginData == NULL)
        {
            MTR_Notify("Unable to allocate memory for plugin data", 0,
             MTR_LMT_FATAL);
            return 2;
        }
    }
    else
    {
        MTR_Notify("Plugins not Found", 0, MTR_LMT_FATAL);
        return 3;
    }
    /* Getting plugins data */
    pluginDirectory = MTR_DirectoryOpen("./plugin/");
    if (pluginDirectory != NULL)
    {
        currentPlugin = 0;
        while (MTR_DirectoryNextFile(pluginDirectory))
        {
            tempFilename = MTR_DirectoryGetFilename(pluginDirectory);
            if (!MTR_DirectoryFileIsDir(pluginDirectory))
            {
                MTR_LogWrite_s("Plugin found:", 0, MTR_LMT_INFO, tempFilename);
                /* file name in plugin/ directory */
                mtrPluginData[currentPlugin].filename = malloc(
                 strlen(tempFilename) + 1);
                strcpy(mtrPluginData[currentPlugin].filename, tempFilename);
                /* temporary plugin file name with relative path */
                fullPluginFileName = malloc(strlen("plugin/") +
                 strlen(mtrPluginData[currentPlugin].filename) + 1);
                if (fullPluginFileName == NULL)
                {
                    MTR_Notify(
                     "Unable to allocate memory for plugin's full filename: ",
                     1, MTR_LMT_ERROR);
                    continue;
                }
                strcpy(fullPluginFileName, "plugin/");
                strcat(fullPluginFileName,
                 mtrPluginData[currentPlugin].filename);
                /* Loading plugin library */
                mtrPluginData[currentPlugin].dll = MTR_LoadLibrary(
                 fullPluginFileName);
                if (mtrPluginData[currentPlugin].dll == NULL)
                {
                    MTR_Notify("Library not loaded", 1, MTR_LMT_ERROR);
                    #ifdef __EMSCRIPTEN__
                    MTR_LogWrite(dlerror(), 1, MTR_LMT_ERROR);
                    #endif
                    continue;
                }
                MTR_CreateReport = (MTR_ReportFunc)MTR_LoadSymbolName(
                 mtrPluginData[currentPlugin].dll, "MTR_CreateReport");
                if (MTR_CreateReport == NULL)
                    MTR_Notify("Library not contain MTR_CreateReport function",
                     1, MTR_LMT_ERROR);
                mtrPluginData[currentPlugin].report = MTR_CreateReport();
                if (mtrPluginData[currentPlugin].report == NULL)
                {
                    MTR_Notify("Module are not returned report", 1,
                     MTR_LMT_ERROR);
                    free(fullPluginFileName);
                    MTR_CloseLibrary(mtrPluginData[currentPlugin].dll);
                    continue;
                }
                MTR_LogWrite_s("Module ID:", 1, MTR_LMT_INFO,
                  mtrPluginData[currentPlugin].report->moduleID);
                MTR_LogWrite("Version:", 1, MTR_LMT_INFO);
                MTR_LogWrite_i("Majon:", 2, MTR_LMT_INFO,
                  (mtrPluginData[currentPlugin].report->version & 0xFF0000) >> 16);
                MTR_LogWrite_i("Minor:", 2, MTR_LMT_INFO,
                  (mtrPluginData[currentPlugin].report->version & 0x00FF00) >> 8);
                MTR_LogWrite_i("Patch:", 2, MTR_LMT_INFO,
                  mtrPluginData[currentPlugin].report->version & 0x0000FF);
                if (mtrPluginData[currentPlugin].report->prereqSubsystemsCount > 0)
                {
                    MTR_LogWrite("Requirement subsystems:", 1, MTR_LMT_INFO);
                    for (i = 0; i < mtrPluginData[currentPlugin].report->prereqSubsystemsCount; i++)
                        MTR_LogWrite(mtrPluginData[currentPlugin].report->prereqSubsystems[i],
                          2, MTR_LMT_INFO);
                }
                if (mtrPluginData[currentPlugin].report->prereqsCount > 0)
                {
                    MTR_LogWrite("Requirement modules:", 1, MTR_LMT_INFO);
                    for (i = 0; i < mtrPluginData[currentPlugin].report->prereqsCount; i++)
                        MTR_LogWrite(mtrPluginData[currentPlugin].report->prereqs[i],
                          2, MTR_LMT_INFO);
                }
                /* Plugin requiring some engine functions */
                if (RequireEngineFuncs != NULL)
                    RequireEngineFuncs(currentPlugin);

                /* Plugin requiring information about every other plugin */
                MTR_RequirePluginData = (MTR_RequirePluginDataFunc)MTR_LoadSymbolName(mtrPluginData[currentPlugin].dll,
                 "MTR_RequirePluginData");
                MTR_RequirePluginData(mtrPluginData, mtrPluginsFound);

                currentPlugin++;
                /* freing temporary allocated structures */
                free(fullPluginFileName);
            }
        }
        MTR_DirectoryClose(pluginDirectory);
    }
    return 0;
}
