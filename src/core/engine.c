#include "log.h"
#include "messagebox.h"
#include "notification.h"
#include "configfile.h"
#include "indexkeeper.h"
#include "file.h"
#include "directory.h"
#include "encoding.h"
#include "clipboard.h"
#include "string_buffer.h"
#include "plugin_loader.h"
#include "options.h"
#include "version.h"

#include "marathoner/engine.h"

void RequireEngineFuncs(uint8_t plugin)
{
    MTR_REQUIRE_ENGINE_FUNC(mtrRequireMarathonerGetVersion,
     mtrMarathonerGetVersion);
    MTR_REQUIRE_ENGINE_FUNC(mtrRequireMarathonerGetModuleVersion,
     mtrMarathonerGetModuleVersion);
    MTR_REQUIRE_ENGINE_FUNC(mtrRequireConfigfileGetKeyName,
     mtrConfigfileGetKeyName);
    MTR_REQUIRE_ENGINE_FUNC(mtrRequireConfigfileGetSectionName,
     mtrConfigfileGetSectionName);
    MTR_REQUIRE_ENGINE_FUNC(mtrRequireConfigfileDeleteKey,
     mtrConfigfileDeleteKey);
    MTR_REQUIRE_ENGINE_FUNC(mtrRequireConfigfileDeleteSection,
     mtrConfigfileDeleteSection);
    MTR_REQUIRE_ENGINE_FUNC(mtrRequireConfigfileReadBool,
     mtrConfigfileReadBool);
    MTR_REQUIRE_ENGINE_FUNC(mtrRequireConfigfileReadInt,
     mtrConfigfileReadInt);
    MTR_REQUIRE_ENGINE_FUNC(mtrRequireConfigfileReadSingle,
     mtrConfigfileReadSingle);
    MTR_REQUIRE_ENGINE_FUNC(mtrRequireConfigfileReadString,
     mtrConfigfileReadString);
    MTR_REQUIRE_ENGINE_FUNC(mtrRequireConfigfileWriteBool,
     mtrConfigfileWriteBool);
    MTR_REQUIRE_ENGINE_FUNC(mtrRequireConfigfileWriteInt,
     mtrConfigfileWriteInt);
    MTR_REQUIRE_ENGINE_FUNC(mtrRequireConfigfileWriteSingle,
     mtrConfigfileWriteSingle);
    MTR_REQUIRE_ENGINE_FUNC(mtrRequireConfigfileWriteString,
     mtrConfigfileWriteString);
    MTR_REQUIRE_ENGINE_FUNC(mtrRequireConfigfileCreateSection,
     mtrConfigfileCreateSection);
    MTR_REQUIRE_ENGINE_FUNC(mtrRequireLogWrite, mtrLogWrite);
    MTR_REQUIRE_ENGINE_FUNC(mtrRequireLogWrite_s, mtrLogWrite_s);
    MTR_REQUIRE_ENGINE_FUNC(mtrRequireLogWrite_i, mtrLogWrite_i);
    MTR_REQUIRE_ENGINE_FUNC(mtrRequireLogWrite_d, mtrLogWrite_d);
    MTR_REQUIRE_ENGINE_FUNC(mtrRequireShowSimpleMessageBox,
     mtrShowSimpleMessageBox);
    MTR_REQUIRE_ENGINE_FUNC(mtrRequireShowYesNoMessageBox,
     mtrShowYesNoMessageBox);
    MTR_REQUIRE_ENGINE_FUNC(mtrRequireShowOkCancelMessageBox,
     mtrShowOkCancelMessageBox);
    MTR_REQUIRE_ENGINE_FUNC(mtrRequireShowInputDialog, mtrShowInputDialog);
    MTR_REQUIRE_ENGINE_FUNC(mtrRequireShowPasswordDialog,
     mtrShowPasswordDialog);
    MTR_REQUIRE_ENGINE_FUNC(mtrRequireAddFileFilter,
     mtrAddFileFilter);
    MTR_REQUIRE_ENGINE_FUNC(mtrRequireClearFileFilters,
     mtrClearFileFilters);
    MTR_REQUIRE_ENGINE_FUNC(mtrRequireShowSaveFileDialog,
     mtrShowSaveFileDialog);
    MTR_REQUIRE_ENGINE_FUNC(mtrRequireShowOpenFileDialog,
     mtrShowOpenFileDialog);
    MTR_REQUIRE_ENGINE_FUNC(mtrRequireShowSelectFolderDialog,
     mtrShowSelectFolderDialog);
    MTR_REQUIRE_ENGINE_FUNC(mtrRequireNotify, mtrNotify);
    MTR_REQUIRE_ENGINE_FUNC(mtrRequireIndexkeeperCreate, mtrIndexkeeperCreate);
    MTR_REQUIRE_ENGINE_FUNC(mtrRequireIndexkeeperGetFreeIndex,
     mtrIndexkeeperGetFreeIndex);
    MTR_REQUIRE_ENGINE_FUNC(mtrRequireIndexkeeperFreeIndex,
     mtrIndexkeeperFreeIndex);
    MTR_REQUIRE_ENGINE_FUNC(mtrRequireIndexkeeperIndexIsEmpty,
     mtrIndexkeeperIndexIsEmpty);
    MTR_REQUIRE_ENGINE_FUNC(mtrRequireIndexkeeperGetReservedDataCount,
     mtrIndexkeeperGetReservedDataCount);
    MTR_REQUIRE_ENGINE_FUNC(mtrRequireIndexkeeperDestroy,
     mtrIndexkeeperDestroy);
    MTR_REQUIRE_ENGINE_FUNC(mtrRequireEncodingUtf8ToUcs4,
     mtrEncodingUtf8ToUcs4);
    MTR_REQUIRE_ENGINE_FUNC(mtrRequireEncodingUtf8Codepoints,
     mtrEncodingUtf8Codepoints);
    MTR_REQUIRE_ENGINE_FUNC(mtrRequireFileOpen, mtrFileOpen);
    MTR_REQUIRE_ENGINE_FUNC(mtrRequireFileClose, mtrFileClose);
    MTR_REQUIRE_ENGINE_FUNC(mtrRequireFileRead, mtrFileRead);
    MTR_REQUIRE_ENGINE_FUNC(mtrRequireFileWrite, mtrFileWrite);
    MTR_REQUIRE_ENGINE_FUNC(mtrRequireFileWriteLine, mtrFileWriteLine);
    MTR_REQUIRE_ENGINE_FUNC(mtrRequireFileWriteFast, mtrFileWriteFast);
    MTR_REQUIRE_ENGINE_FUNC(mtrRequireFileWriteLineFast, mtrFileWriteLineFast);
    MTR_REQUIRE_ENGINE_FUNC(mtrRequireClipboardPutText, mtrClipboardPutText);
    MTR_REQUIRE_ENGINE_FUNC(mtrRequireClipboardGetText, mtrClipboardGetText);
    MTR_REQUIRE_ENGINE_FUNC(mtrRequireStringBufferAdd, mtrStringBufferAdd);
    MTR_REQUIRE_ENGINE_FUNC(mtrRequireStringBufferDelete,
     mtrStringBufferDelete);
    MTR_REQUIRE_ENGINE_FUNC(mtrRequireStringBufferSetString,
     mtrStringBufferSetString);
    MTR_REQUIRE_ENGINE_FUNC(mtrRequireStringBufferGetString,
     mtrStringBufferGetString);
    MTR_REQUIRE_ENGINE_FUNC(mtrRequireStringBufferGetMaxLen,
     mtrStringBufferGetMaxLen);
    MTR_REQUIRE_ENGINE_FUNC(mtrRequireOptionsAlias, mtrOptionsAlias);
    MTR_REQUIRE_ENGINE_FUNC(mtrRequireOptionsGet, mtrOptionsGet);
    MTR_REQUIRE_ENGINE_FUNC(mtrRequireOptionsGet_i, mtrOptionsGet_i);
    MTR_REQUIRE_ENGINE_FUNC(mtrRequireOptionsGet_l, mtrOptionsGet_l);
    MTR_REQUIRE_ENGINE_FUNC(mtrRequireOptionsGet_f, mtrOptionsGet_f);
    MTR_REQUIRE_ENGINE_FUNC(mtrRequireOptionsGet_d, mtrOptionsGet_d);
}

/* Check if module disabled and process it */
bool mtrProcessModuleDisabled(int moduleNum)
{
    int i;

    if (!mtrConfigfileReadBool("Marathoner.cfg", "Module",
     mtrPluginData[moduleNum].report->moduleID, true))
    {
        mtrLogWrite_s("Module are disabled by configfile:", 1,
         MTR_LMT_NOTE, mtrPluginData[moduleNum].report->moduleID);
        free(mtrPluginData[moduleNum].filename);
        for (i = moduleNum; i < mtrPluginsFound - 1; i++)
            mtrPluginData[i] = mtrPluginData[i + 1];
        mtrPluginsFound--;
        return true;
    }
    return false;
}

bool mtrIsSubsystem(int moduleNum)
{
    if ((strcmp(mtrPluginData[moduleNum].report->subsystem, "binding") != 0) &&
     (strcmp(mtrPluginData[moduleNum].report->subsystem, "utils") != 0) &&
     (strcmp(mtrPluginData[moduleNum].report->subsystem, "abstraction") != 0))
        return true;
    else
        return false;
}

int main(int argc, char** argv)
{
    uint8_t i;
    uint8_t j;
    uint8_t k;
    char   *temp; /* Read config result */
    bool    ok;
    int     error;
    char *autorunAction = NULL;
    char *autorunPlugin = NULL;
    char *autorunScript = NULL;
    char *currentArgument = NULL;

    mtrLogInit("Marathoner.log");

    mtrLogWrite("Reporting Marathoner version:", 0, MTR_LMT_INFO);
    mtrLogWrite_i("Majon:", 1, MTR_LMT_INFO,
     (MTR_VERSION_MARATHONER & 0xFF0000) >> 16);
    mtrLogWrite_i("Minor:", 1, MTR_LMT_INFO,
     (MTR_VERSION_MARATHONER & 0x00FF00) >> 8);
    mtrLogWrite_i("Patch:", 1, MTR_LMT_INFO,
     MTR_VERSION_MARATHONER & 0x0000FF);
    mtrLogWrite("Searching available plugins", 0, MTR_LMT_INFO);

    mtrOptionsProcess(argc, argv);
    mtrOptionsAlias("help", "h");
    if (strcmp(mtrOptionsGet("help"), "") == 0)
    {
        /* Print help to log */
    }

    autorunAction = mtrOptionsGet("autorun-action");
    autorunPlugin = mtrOptionsGet("autorun-plugin");
    autorunScript = mtrOptionsGet("autorun-script");

    if (autorunAction == NULL)
        autorunAction = mtrConfigfileReadString("Marathoner.cfg", "Autorun",
         "action", "none");
    if (autorunPlugin == NULL)
        autorunPlugin = mtrConfigfileReadString("Marathoner.cfg", "Autorun",
         "plugin", "none");
    if (autorunScript == NULL)
        autorunScript = mtrConfigfileReadString("Marathoner.cfg", "Autorun",
         "script", "none");

    error = mtrLoadAllPlugins(RequireEngineFuncs);
    if (error != 0)
        return error;

    mtrLogWrite("Processing modules' reports", 0, MTR_LMT_INFO);
    ok = false;
    i = 0;
    while (i < mtrPluginsFound)
    {
        if (mtrProcessModuleDisabled(i))
        {
            i = 0;
            continue;
        }
        ok = true;
        /* searching conflicting subsystems */
        if (mtrIsSubsystem(i))
        {
            for (j = 0; j < mtrPluginsFound; j++)
            {
                currentArgument = mtrOptionsGet(
                 mtrPluginData[i].report->subsystem);
                if (currentArgument == NULL)
                    temp = mtrConfigfileReadString("Marathoner.cfg",
                     "Subsystem", mtrPluginData[i].report->subsystem, "none");
                else
                    temp = currentArgument;
                if (strcmp(temp, "none") == 0)
                {
                    mtrLogWrite_s("Subsystem of module are disabled by "
                     "configfile:", 1, MTR_LMT_NOTE,
                     mtrPluginData[i].report->moduleID);
                    mtrCloseLibrary(mtrPluginData[i].dll);
                    free(mtrPluginData[i].filename);
                    if (temp != currentArgument)
                        free(temp);
                    currentArgument = NULL;
                    ok = false;
                    break;
                }

                if (
                    (strcmp(mtrPluginData[i].report->subsystem,
                     mtrPluginData[j].report->subsystem) == 0) &&
                    (i != j)
                   )
                {
                    ok = false;

                    currentArgument = mtrOptionsGet(
                     mtrPluginData[i].report->subsystem);
                    if (currentArgument == NULL)
                        temp = mtrConfigfileReadString("Marathoner.cfg",
                         "Subsystem", mtrPluginData[i].report->subsystem, "none");
                    else
                        temp = currentArgument;

                    if (strcmp(temp, mtrPluginData[i].report->moduleID) == 0)
                    {
                        mtrLogWrite_s("Module will not loaded:", 1,
                         MTR_LMT_NOTE, mtrPluginData[j].report->moduleID);
                        mtrCloseLibrary(mtrPluginData[j].dll);
                        free(mtrPluginData[j].filename);
                        i = j;
                        if (temp != currentArgument)
                            free(temp);
                        currentArgument = NULL;
                        break;
                    }
                    if (strcmp(temp, mtrPluginData[j].report->moduleID) == 0)
                    {
                        mtrLogWrite_s("Module will not loaded:", 1,
                         MTR_LMT_NOTE, mtrPluginData[i].report->moduleID);
                        mtrCloseLibrary(mtrPluginData[i].dll);
                        free(mtrPluginData[i].filename);
                        if (temp != currentArgument)
                            free(temp);
                        currentArgument = NULL;
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

                    if (temp != currentArgument)
                        free(temp);
                    currentArgument = NULL;
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
                    if (strcmp(mtrPluginData[i].report->prereqSubsystems[j],
                     mtrPluginData[k].report->subsystem) == 0)
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
                    if (strcmp(mtrPluginData[i].report->prereqs[j],
                     mtrPluginData[k].report->moduleID) == 0)
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
        mtrRequirePluginData = (mtrRequirePluginDataFunc)mtrLoadSymbolName(
         mtrPluginData[i].dll, "mtrRequirePluginData");
        mtrRequirePluginData(mtrPluginData, mtrPluginsFound);
    }

    mtrLogWrite("Modules' reports processed", 0, MTR_LMT_INFO);

    if (!mtrFileInit(MTR_IKDM_SMALL, 32))
        return 4;

    if (!mtrStringBufferInit(MTR_IKDM_MEDIUM, 32))
        return 5;

    mtrLogWrite("Reading 'Marathoner.cfg' for autorun options", 0,
     MTR_LMT_INFO);
    ok = false;
    if (strcmp(autorunAction, "runScript") == 0)
    {
        for (i = 0; i < mtrPluginsFound; i++)
        {
            if (strcmp(mtrPluginData[i].report->moduleID, autorunPlugin) == 0)
            {
                ok = true;
                currentPlugin = i;
                break;
            }
        }
        if (ok)
        {
            if (strcmp(autorunScript, "none") != 0)
            {
                mtrScriptsAutorun = (mtrScriptsAutorunFunc)mtrLoadSymbolName(
                 mtrPluginData[currentPlugin].dll, "mtrScriptsAutorun");
                if (mtrScriptsAutorun == NULL)
                    mtrNotify("Unable to load autorun plugin function", 1,
                     MTR_LMT_ERROR);
                else
                {
                    mtrLogWrite_s("Running autorun function with file:", 0,
                     MTR_LMT_INFO, autorunScript);
                    mtrScriptsAutorun(autorunScript);
                }
            }
            else
            {
                mtrNotify("Unable to read autorun script filename", 1,
                 MTR_LMT_ERROR);
            }
        }
        else
        {
            mtrNotify("Ivalid autorun plugin", 1, MTR_LMT_ERROR);
        }
    }
    else
    {
        mtrNotify("Invalid autorun action command", 1, MTR_LMT_ERROR);
    }

    mtrLogWrite("Quiting Engine", 0, MTR_LMT_INFO);
    /* Freing allocated structures and unloading libraries */
    for (i = 0; i < mtrPluginsFound; i++)
    {
        mtrLogWrite_s("Unloading plugin", 0, MTR_LMT_INFO,
         mtrPluginData[i].report->moduleID);
        mtrCloseLibrary(mtrPluginData[i].dll);
    }
    free(mtrPluginData);

    mtrLogWrite("Engine stopped", 0, MTR_LMT_INFO);

    return 0;
}
