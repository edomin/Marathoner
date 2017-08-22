#ifndef MTR_SCRIPT_COMMON_C
#define MTR_SCRIPT_COMMON_C

#include "marathoner/script_func.h"

MTR_SCRIPT_FUNC_B_S2(mtrSF_ScriptsRegisterStringVariable,
 mtrScriptsRegisterStringVariable)
MTR_SCRIPT_FUNC_B_S1D1(mtrSF_ScriptsRegisterNumericVariable,
 mtrScriptsRegisterNumericVariable)
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

    MTR_SF_PUSH_STRING(text);
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

#endif
