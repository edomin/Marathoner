#ifndef MTR_SCRIPT_COMMON_C
#define MTR_SCRIPT_COMMON_C

#include "marathoner/script_func.h"

MTR_SCRIPT_FUNC_I_S1(mtrSF_ScriptsFunctionSupported,
 mtrScriptsFunctionSupported)
MTR_SCRIPT_FUNC_S_V(mtrSF_ScriptsGetAutorunPath,
 mtrScriptsGetAutorunPath)
MTR_SCRIPT_FUNC_B_S1B1(mtrSF_ScriptsRegisterVariable_b,
 mtrScriptsRegisterVariable_b)
MTR_SCRIPT_FUNC_B_S1I1(mtrSF_ScriptsRegisterVariable_i,
 mtrScriptsRegisterVariable_i)
MTR_SCRIPT_FUNC_B_S1U1(mtrSF_ScriptsRegisterVariable_u,
 mtrScriptsRegisterVariable_u)
MTR_SCRIPT_FUNC_B_S1F1(mtrSF_ScriptsRegisterVariable_f,
 mtrScriptsRegisterVariable_f)
MTR_SCRIPT_FUNC_B_S1D1(mtrSF_ScriptsRegisterVariable_d,
 mtrScriptsRegisterVariable_d)
MTR_SCRIPT_FUNC_B_S2(mtrSF_ScriptsRegisterVariable_s,
 mtrScriptsRegisterVariable_s)
MTR_SCRIPT_FUNC_U32t_V(mtrSF_MarathonerGetVersion, mtrMarathonerGetVersion)
MTR_SCRIPT_FUNC_U32t_S1(mtrSF_MarathonerGetModuleVersion,
 mtrMarathonerGetModuleVersion)
MTR_SCRIPT_FUNC_S_S2I1(mtrSF_ConfigfileGetKeyName, mtrConfigfileGetKeyName)
MTR_SCRIPT_FUNC_S_S1I1(mtrSF_ConfigfileGetSectionName,
 mtrConfigfileGetSectionName)
MTR_SCRIPT_FUNC_B_S3(mtrSF_ConfigfileDeleteKey, mtrConfigfileDeleteKey)
MTR_SCRIPT_FUNC_B_S2(mtrSF_ConfigfileDeleteSection, mtrConfigfileDeleteSection)
MTR_SCRIPT_FUNC_B_S3B1(mtrSF_ConfigfileReadBool, mtrConfigfileReadBool)
MTR_SCRIPT_FUNC_I_S3I1(mtrSF_ConfigfileReadInt, mtrConfigfileReadInt)
MTR_SCRIPT_FUNC_F_S3F1(mtrSF_ConfigfileReadSingle, mtrConfigfileReadSingle)
MTR_SCRIPT_FUNC_S_S4(mtrSF_ConfigfileReadString, mtrConfigfileReadString)
MTR_SCRIPT_FUNC_B_S3B1(mtrSF_ConfigfileWriteBool, mtrConfigfileWriteBool)
MTR_SCRIPT_FUNC_B_S3I1(mtrSF_ConfigfileWriteInt, mtrConfigfileWriteInt)
MTR_SCRIPT_FUNC_B_S3F1(mtrSF_ConfigfileWriteSingle, mtrConfigfileWriteSingle)
MTR_SCRIPT_FUNC_B_S4(mtrSF_ConfigfileWriteString, mtrConfigfileWriteString)
MTR_SCRIPT_FUNC_B_S2(mtrSF_ConfigfileCreateSection, mtrConfigfileCreateSection)
MTR_SCRIPT_FUNC_V_S1U8t2(mtrSF_LogWrite, mtrLogWrite)
MTR_SCRIPT_FUNC_V_S1U8t2S1(mtrSF_LogWrite_s, mtrLogWrite_s)
MTR_SCRIPT_FUNC_V_S1U8t2I1(mtrSF_LogWrite_i, mtrLogWrite_i)
MTR_SCRIPT_FUNC_V_S1U8t2D1(mtrSF_LogWrite_d, mtrLogWrite_d)
MTR_SCRIPT_FUNC_V_U8t1S2(mtrSF_ShowSimpleMessageBox, mtrShowSimpleMessageBox)
MTR_SCRIPT_FUNC_B_S2(mtrSF_ShowYesNoMessageBox, mtrShowYesNoMessageBox)
MTR_SCRIPT_FUNC_B_S2(mtrSF_ShowOkCancelMessageBox, mtrShowOkCancelMessageBox)
MTR_SCRIPT_FUNC_S_S3(mtrSF_ShowInputDialog, mtrShowInputDialog)
MTR_SCRIPT_FUNC_S_S2(mtrSF_ShowPasswordDialog, mtrShowPasswordDialog)
MTR_SCRIPT_FUNC_V_S1(mtrSF_AddFileFilter, mtrAddFileFilter)
MTR_SCRIPT_FUNC_V_V(mtrSF_ClearFileFilters, mtrClearFileFilters)
MTR_SCRIPT_FUNC_S_S3(mtrSF_ShowSaveFileDialog, mtrShowSaveFileDialog)
MTR_SCRIPT_FUNC_S_S3(mtrSF_ShowOpenFileDialog, mtrShowOpenFileDialog)
MTR_SCRIPT_FUNC_S_S2(mtrSF_ShowSelectFolderDialog, mtrShowSelectFolderDialog)
MTR_SCRIPT_FUNC_V_S1U8t2(mtrSF_Notify, mtrNotify)
MTR_SCRIPT_FUNC_U32t_S1(mtrSF_EncodingUtf8Codepoints, mtrEncodingUtf8Codepoints)
MTR_SCRIPT_FUNC_U32t_S1I1(mtrSF_FileOpen, mtrFileOpen)
MTR_SCRIPT_FUNC_B_U32t1(mtrSF_FileClose, mtrFileClose)

MTR_SCRIPT_FUNC(mtrSF_FileRead)
{
    uint32_t   index;
    char      *text;
    #ifdef lua_h
        size_t size;
    #endif /* lua_h */

    MTR_SF_GET_UINT32(index, 1);
    #ifdef lua_h
        size = mtrFileRead(index, &text);
    #else /* lua_h */
        mtrFileRead(index, &text);
    #endif /* lua_h */

    if (text != NULL)
        MTR_SF_PUSH_STRING(text);
    else
        MTR_SF_PUSH_NIL();
    #ifdef lua_h
        MTR_SF_PUSH_SIZE(size);
        return 2;
    #else /* lua_h */
        return 1;
    #endif /* lua_h */
}

MTR_SCRIPT_FUNC_B_U32t1S1(mtrSF_FileWrite, mtrFileWrite)
MTR_SCRIPT_FUNC_B_U32t1S1(mtrSF_FileWriteLine, mtrFileWriteLine)
MTR_SCRIPT_FUNC_V_S2I1(mtrSF_FileWriteFast, mtrFileWriteFast)
MTR_SCRIPT_FUNC_V_S2I1(mtrSF_FileWriteLineFast, mtrFileWriteLineFast)
MTR_SCRIPT_FUNC_B_S1(mtrSF_ClipboardPutText, mtrClipboardPutText)
MTR_SCRIPT_FUNC_S_V(mtrSF_ClipboardGetText, mtrClipboardGetText)
MTR_SCRIPT_FUNC_U32t_S1I1(mtrSF_StringBufferAdd, mtrStringBufferAdd)
MTR_SCRIPT_FUNC_V_U32t1(mtrSF_StringBufferDelete, mtrStringBufferDelete)
MTR_SCRIPT_FUNC_V_U32t1S1(mtrSF_StringBufferSetString, mtrStringBufferSetString)
MTR_SCRIPT_FUNC_S_U32t1(mtrSF_StringBufferGetString, mtrStringBufferGetString)
MTR_SCRIPT_FUNC_I_U32t1(mtrSF_StringBufferGetMaxLen, mtrStringBufferGetMaxLen)
MTR_SCRIPT_FUNC_B_S2(mtrSF_OptionsAlias, mtrOptionsAlias)
MTR_SCRIPT_FUNC_S_S1(mtrSF_OptionsGet, mtrOptionsGet)
MTR_SCRIPT_FUNC_I_S1(mtrSF_OptionsGet_i, mtrOptionsGet_i)
MTR_SCRIPT_FUNC_L_S1(mtrSF_OptionsGet_l, mtrOptionsGet_l)
MTR_SCRIPT_FUNC_F_S1(mtrSF_OptionsGet_f, mtrOptionsGet_f)
MTR_SCRIPT_FUNC_D_S1(mtrSF_OptionsGet_d, mtrOptionsGet_d)

void mtrScriptsRegisterAll(void)
{
    mtrScriptsRegisterVariable_u("IKDM_SMALL", MTR_IKDM_SMALL);
    mtrScriptsRegisterVariable_u("IKDM_MEDIUM", MTR_IKDM_MEDIUM);
    mtrScriptsRegisterVariable_u("IKDM_LARGE", MTR_IKDM_LARGE);
    mtrScriptsRegisterVariable_i("FM_READ", MTR_FM_READ);
    mtrScriptsRegisterVariable_i("FM_WRITE", MTR_FM_WRITE);
    mtrScriptsRegisterVariable_i("FM_APPEND", MTR_FM_APPEND);
    mtrScriptsRegisterVariable_i("LMT_INFO", MTR_LMT_INFO);
    mtrScriptsRegisterVariable_i("LMT_NOTE", MTR_LMT_NOTE);
    mtrScriptsRegisterVariable_i("LMT_WARNING", MTR_LMT_WARNING);
    mtrScriptsRegisterVariable_i("LMT_ERROR", MTR_LMT_ERROR);
    mtrScriptsRegisterVariable_i("LMT_FATAL", MTR_LMT_FATAL);
    mtrScriptsRegisterVariable_i("LMT_DEBUG", MTR_LMT_DEBUG);
    mtrScriptsRegisterVariable_i("DMT_INFO", MTR_DMT_INFO);
    mtrScriptsRegisterVariable_i("DMT_NOTE", MTR_DMT_NOTE);
    mtrScriptsRegisterVariable_i("DMT_WARNING", MTR_DMT_WARNING);
    mtrScriptsRegisterVariable_i("DMT_ERROR", MTR_DMT_ERROR);
    mtrScriptsRegisterVariable_i("DMT_FATAL", MTR_DMT_FATAL);
    mtrScriptsRegisterVariable_i("DMT_DEBUG", MTR_DMT_DEBUG);
    mtrScriptsRegisterVariable_i("FA_NO", MTR_FA_NO);
    mtrScriptsRegisterVariable_i("FA_DUMMY", MTR_FA_DUMMY);
    mtrScriptsRegisterVariable_i("FA_BUGGY", MTR_FA_BUGGY);
    mtrScriptsRegisterVariable_i("FA_PARTIAL", MTR_FA_PARTIAL);
    mtrScriptsRegisterVariable_i("FA_YES", MTR_FA_YES);

    mtrScriptsRegisterFunction(mtrSF_ScriptsFunctionSupported,
     "ScriptsFunctionSupported");
    mtrScriptsRegisterFunction(mtrSF_ScriptsGetAutorunPath,
     "ScriptsGetAutorunPath");
    mtrScriptsRegisterFunction(mtrSF_ScriptsRegisterVariable_b,
     "RegisterVariable_b");
    mtrScriptsRegisterFunction(mtrSF_ScriptsRegisterVariable_i,
     "RegisterVariable_i");
    mtrScriptsRegisterFunction(mtrSF_ScriptsRegisterVariable_u,
     "RegisterVariable_u");
    mtrScriptsRegisterFunction(mtrSF_ScriptsRegisterVariable_f,
     "RegisterVariable_f");
    mtrScriptsRegisterFunction(mtrSF_ScriptsRegisterVariable_d,
     "RegisterVariable_d");
    mtrScriptsRegisterFunction(mtrSF_ScriptsRegisterVariable_s,
     "RegisterVariable_s");

    mtrScriptsRegisterFunction(mtrSF_MarathonerGetVersion,
     "MarathonerGetVersion");
    mtrScriptsRegisterFunction(mtrSF_MarathonerGetModuleVersion,
     "MarathonerGetModuleVersion");
    mtrScriptsRegisterFunction(mtrSF_ConfigfileGetKeyName,
     "ConfigfileGetKeyName");
    mtrScriptsRegisterFunction(mtrSF_ConfigfileGetSectionName,
     "ConfigfileGetSectionName");
    mtrScriptsRegisterFunction(mtrSF_ConfigfileDeleteKey,
     "ConfigfileDeleteKey");
    mtrScriptsRegisterFunction(mtrSF_ConfigfileDeleteSection,
     "ConfigfileDeleteSection");
    mtrScriptsRegisterFunction(mtrSF_ConfigfileReadBool, "ConfigfileReadBool");
    mtrScriptsRegisterFunction(mtrSF_ConfigfileReadInt, "ConfigfileReadInt");
    mtrScriptsRegisterFunction(mtrSF_ConfigfileReadSingle,
     "ConfigfileReadSingle");
    mtrScriptsRegisterFunction(mtrSF_ConfigfileReadString,
     "ConfigfileReadString");
    mtrScriptsRegisterFunction(mtrSF_ConfigfileWriteBool,
     "ConfigfileWriteBool");
    mtrScriptsRegisterFunction(mtrSF_ConfigfileWriteInt, "ConfigfileWriteInt");
    mtrScriptsRegisterFunction(mtrSF_ConfigfileWriteSingle,
     "ConfigfileWriteSingle");
    mtrScriptsRegisterFunction(mtrSF_ConfigfileWriteString,
     "ConfigfileWriteString");
    mtrScriptsRegisterFunction(mtrSF_ConfigfileCreateSection,
     "ConfigfileCreateSection");

    mtrScriptsRegisterFunction(mtrSF_LogWrite, "LogWrite");
    mtrScriptsRegisterFunction(mtrSF_LogWrite_s, "LogWrite_s");
    mtrScriptsRegisterFunction(mtrSF_LogWrite_i, "LogWrite_i");
    mtrScriptsRegisterFunction(mtrSF_LogWrite_d, "LogWrite_d");

    mtrScriptsRegisterFunction(mtrSF_ShowSimpleMessageBox,
     "ShowSimpleMessageBox");
    mtrScriptsRegisterFunction(mtrSF_ShowYesNoMessageBox,
     "ShowYesNoMessageBox");
    mtrScriptsRegisterFunction(mtrSF_ShowOkCancelMessageBox,
     "ShowOkCancelMessageBox");
    mtrScriptsRegisterFunction(mtrSF_ShowInputDialog, "ShowInputDialog");
    mtrScriptsRegisterFunction(mtrSF_ShowPasswordDialog, "ShowPasswordDialog");
    mtrScriptsRegisterFunction(mtrSF_AddFileFilter, "AddFileFilter");
    mtrScriptsRegisterFunction(mtrSF_ClearFileFilters, "ClearFileFilters");
    mtrScriptsRegisterFunction(mtrSF_ShowSaveFileDialog, "ShowSaveFileDialog");
    mtrScriptsRegisterFunction(mtrSF_ShowOpenFileDialog, "ShowOpenFileDialog");
    mtrScriptsRegisterFunction(mtrSF_ShowSelectFolderDialog,
     "ShowSelectFolderDialog");

    mtrScriptsRegisterFunction(mtrSF_Notify, "Notify");

    mtrScriptsRegisterFunction(mtrSF_EncodingUtf8Codepoints,
     "EncodingUtf8Codepoints");

    mtrScriptsRegisterFunction(mtrSF_FileOpen, "FileOpen");
    mtrScriptsRegisterFunction(mtrSF_FileClose, "FileClose");
    mtrScriptsRegisterFunction(mtrSF_FileRead, "FileRead");
    mtrScriptsRegisterFunction(mtrSF_FileWrite, "FileWrite");
    mtrScriptsRegisterFunction(mtrSF_FileWriteLine, "FileWriteLine");
    mtrScriptsRegisterFunction(mtrSF_FileWriteFast, "FileWriteFast");
    mtrScriptsRegisterFunction(mtrSF_FileWriteLineFast, "FileWriteLineFast");

    mtrScriptsRegisterFunction(mtrSF_ClipboardPutText, "ClipboardPutText");
    mtrScriptsRegisterFunction(mtrSF_ClipboardGetText, "ClipboardGetText");

    mtrScriptsRegisterFunction(mtrSF_StringBufferAdd, "StringBufferAdd");
    mtrScriptsRegisterFunction(mtrSF_StringBufferDelete, "StringBufferDelete");
    mtrScriptsRegisterFunction(mtrSF_StringBufferSetString,
     "StringBufferSetString");
    mtrScriptsRegisterFunction(mtrSF_StringBufferGetString,
     "StringBufferGetString");
    mtrScriptsRegisterFunction(mtrSF_StringBufferGetMaxLen,
     "StringBufferGetMaxLen");

    mtrScriptsRegisterFunction(mtrSF_OptionsAlias, "OptionsAlias");
    mtrScriptsRegisterFunction(mtrSF_OptionsGet, "OptionsGet");
    mtrScriptsRegisterFunction(mtrSF_OptionsGet_i, "OptionsGet_i");
    mtrScriptsRegisterFunction(mtrSF_OptionsGet_l, "OptionsGet_l");
    mtrScriptsRegisterFunction(mtrSF_OptionsGet_f, "OptionsGet_f");
    mtrScriptsRegisterFunction(mtrSF_OptionsGet_d, "OptionsGet_d");
}

#endif
