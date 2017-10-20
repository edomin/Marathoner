#ifndef MTR_SCRIPT_COMMON_C
#define MTR_SCRIPT_COMMON_C

#include "marathoner/script_func.h"

MTR_SCRIPT_FUNC_I_S1(MTR_SF_ScriptsFunctionSupported,
 MTR_ScriptsFunctionSupported)
MTR_SCRIPT_FUNC_S_V(MTR_SF_ScriptsGetAutorunPath,
 MTR_ScriptsGetAutorunPath)
MTR_SCRIPT_FUNC_B_S1B1(MTR_SF_ScriptsRegisterVariable_b,
 MTR_ScriptsRegisterVariable_b)
MTR_SCRIPT_FUNC_B_S1I1(MTR_SF_ScriptsRegisterVariable_i,
 MTR_ScriptsRegisterVariable_i)
MTR_SCRIPT_FUNC_B_S1U1(MTR_SF_ScriptsRegisterVariable_u,
 MTR_ScriptsRegisterVariable_u)
MTR_SCRIPT_FUNC_B_S1F1(MTR_SF_ScriptsRegisterVariable_f,
 MTR_ScriptsRegisterVariable_f)
MTR_SCRIPT_FUNC_B_S1D1(MTR_SF_ScriptsRegisterVariable_d,
 MTR_ScriptsRegisterVariable_d)
MTR_SCRIPT_FUNC_B_S2(MTR_SF_ScriptsRegisterVariable_s,
 MTR_ScriptsRegisterVariable_s)
MTR_SCRIPT_FUNC_U32t_V(MTR_SF_MarathonerGetVersion, MTR_MarathonerGetVersion)
MTR_SCRIPT_FUNC_U32t_S1(MTR_SF_MarathonerGetModuleVersion,
 MTR_MarathonerGetModuleVersion)
MTR_SCRIPT_FUNC_S_S2I1(MTR_SF_ConfigfileGetKeyName, MTR_ConfigfileGetKeyName)
MTR_SCRIPT_FUNC_S_S1I1(MTR_SF_ConfigfileGetSectionName,
 MTR_ConfigfileGetSectionName)
MTR_SCRIPT_FUNC_B_S3(MTR_SF_ConfigfileDeleteKey, MTR_ConfigfileDeleteKey)
MTR_SCRIPT_FUNC_B_S2(MTR_SF_ConfigfileDeleteSection,
 MTR_ConfigfileDeleteSection)
MTR_SCRIPT_FUNC_B_S3B1(MTR_SF_ConfigfileReadBool, MTR_ConfigfileReadBool)
MTR_SCRIPT_FUNC_I_S3I1(MTR_SF_ConfigfileReadInt, MTR_ConfigfileReadInt)
MTR_SCRIPT_FUNC_F_S3F1(MTR_SF_ConfigfileReadSingle, MTR_ConfigfileReadSingle)
MTR_SCRIPT_FUNC_S_S4(MTR_SF_ConfigfileReadString, MTR_ConfigfileReadString)
MTR_SCRIPT_FUNC_B_S3B1(MTR_SF_ConfigfileWriteBool, MTR_ConfigfileWriteBool)
MTR_SCRIPT_FUNC_B_S3I1(MTR_SF_ConfigfileWriteInt, MTR_ConfigfileWriteInt)
MTR_SCRIPT_FUNC_B_S3F1(MTR_SF_ConfigfileWriteSingle, MTR_ConfigfileWriteSingle)
MTR_SCRIPT_FUNC_B_S4(MTR_SF_ConfigfileWriteString, MTR_ConfigfileWriteString)
MTR_SCRIPT_FUNC_B_S2(MTR_SF_ConfigfileCreateSection,
 MTR_ConfigfileCreateSection)
MTR_SCRIPT_FUNC_V_S1U8t2(MTR_SF_LogWrite, MTR_LogWrite)
MTR_SCRIPT_FUNC_V_S1U8t2S1(MTR_SF_LogWrite_s, MTR_LogWrite_s)
MTR_SCRIPT_FUNC_V_S1U8t2I1(MTR_SF_LogWrite_i, MTR_LogWrite_i)
MTR_SCRIPT_FUNC_V_S1U8t2D1(MTR_SF_LogWrite_d, MTR_LogWrite_d)
MTR_SCRIPT_FUNC_V_U8t1S2(MTR_SF_ShowSimpleMessageBox, MTR_ShowSimpleMessageBox)
MTR_SCRIPT_FUNC_B_S2(MTR_SF_ShowYesNoMessageBox, MTR_ShowYesNoMessageBox)
MTR_SCRIPT_FUNC_B_S2(MTR_SF_ShowOkCancelMessageBox, MTR_ShowOkCancelMessageBox)
MTR_SCRIPT_FUNC_S_S3(MTR_SF_ShowInputDialog, MTR_ShowInputDialog)
MTR_SCRIPT_FUNC_S_S2(MTR_SF_ShowPasswordDialog, MTR_ShowPasswordDialog)
MTR_SCRIPT_FUNC_V_S1(MTR_SF_AddFileFilter, MTR_AddFileFilter)
MTR_SCRIPT_FUNC_V_V(MTR_SF_ClearFileFilters, MTR_ClearFileFilters)
MTR_SCRIPT_FUNC_S_S3(MTR_SF_ShowSaveFileDialog, MTR_ShowSaveFileDialog)
MTR_SCRIPT_FUNC_S_S3(MTR_SF_ShowOpenFileDialog, MTR_ShowOpenFileDialog)
MTR_SCRIPT_FUNC_S_S2(MTR_SF_ShowSelectFolderDialog, MTR_ShowSelectFolderDialog)
MTR_SCRIPT_FUNC_V_S1U8t2(MTR_SF_Notify, MTR_Notify)
MTR_SCRIPT_FUNC_U32t_S1(MTR_SF_EncodingUtf8Codepoints,
 MTR_EncodingUtf8Codepoints)
MTR_SCRIPT_FUNC_U32t_S1I1(MTR_SF_FileOpen, MTR_FileOpen)
MTR_SCRIPT_FUNC_B_U32t1(MTR_SF_FileClose, MTR_FileClose)

MTR_SCRIPT_FUNC(MTR_SF_FileRead)
{
    uint32_t   index;
    char      *text;
    #ifdef lua_h
        size_t size;
    #endif /* lua_h */

    MTR_SF_GET_UINT32(index, 1);
    #ifdef lua_h
        size = MTR_FileRead(index, &text);
    #else /* lua_h */
        MTR_FileRead(index, &text);
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

MTR_SCRIPT_FUNC_B_U32t1S1(MTR_SF_FileWrite, MTR_FileWrite)
MTR_SCRIPT_FUNC_B_U32t1S1(MTR_SF_FileWriteLine, MTR_FileWriteLine)
MTR_SCRIPT_FUNC_V_S2I1(MTR_SF_FileWriteFast, MTR_FileWriteFast)
MTR_SCRIPT_FUNC_V_S2I1(MTR_SF_FileWriteLineFast, MTR_FileWriteLineFast)
MTR_SCRIPT_FUNC_B_S1(MTR_SF_ClipboardPutText, MTR_ClipboardPutText)
MTR_SCRIPT_FUNC_S_V(MTR_SF_ClipboardGetText, MTR_ClipboardGetText)
MTR_SCRIPT_FUNC_U32t_S1I1(MTR_SF_StringBufferAdd, MTR_StringBufferAdd)
MTR_SCRIPT_FUNC_V_U32t1(MTR_SF_StringBufferDelete, MTR_StringBufferDelete)
MTR_SCRIPT_FUNC_V_U32t1S1(MTR_SF_StringBufferSetString,
 MTR_StringBufferSetString)
MTR_SCRIPT_FUNC_S_U32t1(MTR_SF_StringBufferGetString, MTR_StringBufferGetString)
MTR_SCRIPT_FUNC_I_U32t1(MTR_SF_StringBufferGetMaxLen, MTR_StringBufferGetMaxLen)
MTR_SCRIPT_FUNC_B_S2(MTR_SF_OptionsAlias, MTR_OptionsAlias)
MTR_SCRIPT_FUNC_S_S1(MTR_SF_OptionsGet, MTR_OptionsGet)
MTR_SCRIPT_FUNC_B_S1(MTR_SF_OptionsGet_b, MTR_OptionsGet_b)
MTR_SCRIPT_FUNC_I_S1(MTR_SF_OptionsGet_i, MTR_OptionsGet_i)
MTR_SCRIPT_FUNC_L_S1(MTR_SF_OptionsGet_l, MTR_OptionsGet_l)
MTR_SCRIPT_FUNC_F_S1(MTR_SF_OptionsGet_f, MTR_OptionsGet_f)
MTR_SCRIPT_FUNC_D_S1(MTR_SF_OptionsGet_d, MTR_OptionsGet_d)
MTR_SCRIPT_FUNC_V_V(MTR_SF_ConsoleShow, MTR_ConsoleShow)
MTR_SCRIPT_FUNC_V_V(MTR_SF_ConsoleHide, MTR_ConsoleHide)

void MTR_ScriptsRegisterAll(void)
{
    MTR_ScriptsRegisterVariable_u("IKDM_SMALL", MTR_IKDM_SMALL);
    MTR_ScriptsRegisterVariable_u("IKDM_MEDIUM", MTR_IKDM_MEDIUM);
    MTR_ScriptsRegisterVariable_u("IKDM_LARGE", MTR_IKDM_LARGE);
    MTR_ScriptsRegisterVariable_i("FM_READ", MTR_FM_READ);
    MTR_ScriptsRegisterVariable_i("FM_WRITE", MTR_FM_WRITE);
    MTR_ScriptsRegisterVariable_i("FM_APPEND", MTR_FM_APPEND);
    MTR_ScriptsRegisterVariable_i("LMT_INFO", MTR_LMT_INFO);
    MTR_ScriptsRegisterVariable_i("LMT_NOTE", MTR_LMT_NOTE);
    MTR_ScriptsRegisterVariable_i("LMT_WARNING", MTR_LMT_WARNING);
    MTR_ScriptsRegisterVariable_i("LMT_ERROR", MTR_LMT_ERROR);
    MTR_ScriptsRegisterVariable_i("LMT_FATAL", MTR_LMT_FATAL);
    MTR_ScriptsRegisterVariable_i("LMT_DEBUG", MTR_LMT_DEBUG);
    MTR_ScriptsRegisterVariable_i("DMT_INFO", MTR_DMT_INFO);
    MTR_ScriptsRegisterVariable_i("DMT_NOTE", MTR_DMT_NOTE);
    MTR_ScriptsRegisterVariable_i("DMT_WARNING", MTR_DMT_WARNING);
    MTR_ScriptsRegisterVariable_i("DMT_ERROR", MTR_DMT_ERROR);
    MTR_ScriptsRegisterVariable_i("DMT_FATAL", MTR_DMT_FATAL);
    MTR_ScriptsRegisterVariable_i("DMT_DEBUG", MTR_DMT_DEBUG);
    MTR_ScriptsRegisterVariable_i("FA_NO", MTR_FA_NO);
    MTR_ScriptsRegisterVariable_i("FA_DUMMY", MTR_FA_DUMMY);
    MTR_ScriptsRegisterVariable_i("FA_BUGGY", MTR_FA_BUGGY);
    MTR_ScriptsRegisterVariable_i("FA_PARTIAL", MTR_FA_PARTIAL);
    MTR_ScriptsRegisterVariable_i("FA_YES", MTR_FA_YES);

    MTR_ScriptsRegisterFunction(MTR_SF_ScriptsFunctionSupported,
     "ScriptsFunctionSupported");
    MTR_ScriptsRegisterFunction(MTR_SF_ScriptsGetAutorunPath,
     "ScriptsGetAutorunPath");
    MTR_ScriptsRegisterFunction(MTR_SF_ScriptsRegisterVariable_b,
     "RegisterVariable_b");
    MTR_ScriptsRegisterFunction(MTR_SF_ScriptsRegisterVariable_i,
     "RegisterVariable_i");
    MTR_ScriptsRegisterFunction(MTR_SF_ScriptsRegisterVariable_u,
     "RegisterVariable_u");
    MTR_ScriptsRegisterFunction(MTR_SF_ScriptsRegisterVariable_f,
     "RegisterVariable_f");
    MTR_ScriptsRegisterFunction(MTR_SF_ScriptsRegisterVariable_d,
     "RegisterVariable_d");
    MTR_ScriptsRegisterFunction(MTR_SF_ScriptsRegisterVariable_s,
     "RegisterVariable_s");

    MTR_ScriptsRegisterFunction(MTR_SF_MarathonerGetVersion,
     "MarathonerGetVersion");
    MTR_ScriptsRegisterFunction(MTR_SF_MarathonerGetModuleVersion,
     "MarathonerGetModuleVersion");
    MTR_ScriptsRegisterFunction(MTR_SF_ConfigfileGetKeyName,
     "ConfigfileGetKeyName");
    MTR_ScriptsRegisterFunction(MTR_SF_ConfigfileGetSectionName,
     "ConfigfileGetSectionName");
    MTR_ScriptsRegisterFunction(MTR_SF_ConfigfileDeleteKey,
     "ConfigfileDeleteKey");
    MTR_ScriptsRegisterFunction(MTR_SF_ConfigfileDeleteSection,
     "ConfigfileDeleteSection");
    MTR_ScriptsRegisterFunction(MTR_SF_ConfigfileReadBool,
     "ConfigfileReadBool");
    MTR_ScriptsRegisterFunction(MTR_SF_ConfigfileReadInt, "ConfigfileReadInt");
    MTR_ScriptsRegisterFunction(MTR_SF_ConfigfileReadSingle,
     "ConfigfileReadSingle");
    MTR_ScriptsRegisterFunction(MTR_SF_ConfigfileReadString,
     "ConfigfileReadString");
    MTR_ScriptsRegisterFunction(MTR_SF_ConfigfileWriteBool,
     "ConfigfileWriteBool");
    MTR_ScriptsRegisterFunction(MTR_SF_ConfigfileWriteInt,
     "ConfigfileWriteInt");
    MTR_ScriptsRegisterFunction(MTR_SF_ConfigfileWriteSingle,
     "ConfigfileWriteSingle");
    MTR_ScriptsRegisterFunction(MTR_SF_ConfigfileWriteString,
     "ConfigfileWriteString");
    MTR_ScriptsRegisterFunction(MTR_SF_ConfigfileCreateSection,
     "ConfigfileCreateSection");

    MTR_ScriptsRegisterFunction(MTR_SF_LogWrite, "LogWrite");
    MTR_ScriptsRegisterFunction(MTR_SF_LogWrite_s, "LogWrite_s");
    MTR_ScriptsRegisterFunction(MTR_SF_LogWrite_i, "LogWrite_i");
    MTR_ScriptsRegisterFunction(MTR_SF_LogWrite_d, "LogWrite_d");

    MTR_ScriptsRegisterFunction(MTR_SF_ShowSimpleMessageBox,
     "ShowSimpleMessageBox");
    MTR_ScriptsRegisterFunction(MTR_SF_ShowYesNoMessageBox,
     "ShowYesNoMessageBox");
    MTR_ScriptsRegisterFunction(MTR_SF_ShowOkCancelMessageBox,
     "ShowOkCancelMessageBox");
    MTR_ScriptsRegisterFunction(MTR_SF_ShowInputDialog, "ShowInputDialog");
    MTR_ScriptsRegisterFunction(MTR_SF_ShowPasswordDialog,
     "ShowPasswordDialog");
    MTR_ScriptsRegisterFunction(MTR_SF_AddFileFilter, "AddFileFilter");
    MTR_ScriptsRegisterFunction(MTR_SF_ClearFileFilters, "ClearFileFilters");
    MTR_ScriptsRegisterFunction(MTR_SF_ShowSaveFileDialog,
     "ShowSaveFileDialog");
    MTR_ScriptsRegisterFunction(MTR_SF_ShowOpenFileDialog,
     "ShowOpenFileDialog");
    MTR_ScriptsRegisterFunction(MTR_SF_ShowSelectFolderDialog,
     "ShowSelectFolderDialog");

    MTR_ScriptsRegisterFunction(MTR_SF_Notify, "Notify");

    MTR_ScriptsRegisterFunction(MTR_SF_EncodingUtf8Codepoints,
     "EncodingUtf8Codepoints");

    MTR_ScriptsRegisterFunction(MTR_SF_FileOpen, "FileOpen");
    MTR_ScriptsRegisterFunction(MTR_SF_FileClose, "FileClose");
    MTR_ScriptsRegisterFunction(MTR_SF_FileRead, "FileRead");
    MTR_ScriptsRegisterFunction(MTR_SF_FileWrite, "FileWrite");
    MTR_ScriptsRegisterFunction(MTR_SF_FileWriteLine, "FileWriteLine");
    MTR_ScriptsRegisterFunction(MTR_SF_FileWriteFast, "FileWriteFast");
    MTR_ScriptsRegisterFunction(MTR_SF_FileWriteLineFast, "FileWriteLineFast");

    MTR_ScriptsRegisterFunction(MTR_SF_ClipboardPutText, "ClipboardPutText");
    MTR_ScriptsRegisterFunction(MTR_SF_ClipboardGetText, "ClipboardGetText");

    MTR_ScriptsRegisterFunction(MTR_SF_StringBufferAdd, "StringBufferAdd");
    MTR_ScriptsRegisterFunction(MTR_SF_StringBufferDelete,
     "StringBufferDelete");
    MTR_ScriptsRegisterFunction(MTR_SF_StringBufferSetString,
     "StringBufferSetString");
    MTR_ScriptsRegisterFunction(MTR_SF_StringBufferGetString,
     "StringBufferGetString");
    MTR_ScriptsRegisterFunction(MTR_SF_StringBufferGetMaxLen,
     "StringBufferGetMaxLen");

    MTR_ScriptsRegisterFunction(MTR_SF_OptionsAlias, "OptionsAlias");
    MTR_ScriptsRegisterFunction(MTR_SF_OptionsGet, "OptionsGet");
    MTR_ScriptsRegisterFunction(MTR_SF_OptionsGet_b, "OptionsGet_b");
    MTR_ScriptsRegisterFunction(MTR_SF_OptionsGet_i, "OptionsGet_i");
    MTR_ScriptsRegisterFunction(MTR_SF_OptionsGet_l, "OptionsGet_l");
    MTR_ScriptsRegisterFunction(MTR_SF_OptionsGet_f, "OptionsGet_f");
    MTR_ScriptsRegisterFunction(MTR_SF_OptionsGet_d, "OptionsGet_d");

    MTR_ScriptsRegisterFunction(MTR_SF_ConsoleShow, "ConsoleShow");
    MTR_ScriptsRegisterFunction(MTR_SF_ConsoleHide, "ConsoleHide");
}

#endif
