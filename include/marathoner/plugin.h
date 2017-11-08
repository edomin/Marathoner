#ifndef MTR_PLUGIN_H
#define MTR_PLUGIN_H

#include "marathoner/marathoner.h"

typedef struct mtrIndexkeeper_t {
    void    *data;
    size_t   dataSize;
    uint32_t reservedData;
    uint32_t dataCount;
    uint32_t dmSize;
    uint32_t *dataMap;
} mtrIndexkeeper_t;

typedef struct mtrPixels_t {
    void *data;
    int   w;
    int   h;
    int   pitch;
    int   pixelformat;
} mtrPixels_t;

/* Texture flipping constants */
#define MTR_FLIP_NONE       0
#define MTR_FLIP_HORIZONTAL 1
#define MTR_FLIP_VERTICAL   2
#define MTR_FLIP_BOTH       (MTR_FLIP_HORIZONTAL | MTR_FLIP_VERTICAL)

/* Pixel format constants */
#define MTR_PF_RGBA         1
#define MTR_PF_ARGB         2

MTR_MarathonerFunctionSupportedFunc_t        MTR_MarathonerFunctionSupported;
MTR_MarathonerGetVersionFunc_t               MTR_MarathonerGetVersion;
MTR_MarathonerGetModuleVersionFunc_t         MTR_MarathonerGetModuleVersion;

MTR_ConfigfileGetKeyNameFunc_t               MTR_ConfigfileGetKeyName;
MTR_ConfigfileGetSectionNameFunc_t           MTR_ConfigfileGetSectionName;
MTR_ConfigfileKeyExistsFunc_t                MTR_ConfigfileKeyExists;
MTR_ConfigfileSectionExistsFunc_t            MTR_ConfigfileSectionExists;
MTR_ConfigfileDeleteKeyFunc_t                MTR_ConfigfileDeleteKey;
MTR_ConfigfileDeleteSectionFunc_t            MTR_ConfigfileDeleteSection;
MTR_ConfigfileReadBoolFunc_t                 MTR_ConfigfileReadBool;
MTR_ConfigfileReadIntFunc_t                  MTR_ConfigfileReadInt;
MTR_ConfigfileReadSingleFunc_t               MTR_ConfigfileReadSingle;
MTR_ConfigfileReadStringFunc_t               MTR_ConfigfileReadString;
MTR_ConfigfileWriteBoolFunc_t                MTR_ConfigfileWriteBool;
MTR_ConfigfileWriteIntFunc_t                 MTR_ConfigfileWriteInt;
MTR_ConfigfileWriteSingleFunc_t              MTR_ConfigfileWriteSingle;
MTR_ConfigfileWriteStringFunc_t              MTR_ConfigfileWriteString;
MTR_ConfigfileCreateSectionFunc_t            MTR_ConfigfileCreateSection;

MTR_LogWriteFunc_t                           MTR_LogWrite;
MTR_LogWrite_sFunc_t                         MTR_LogWrite_s;
MTR_LogWrite_iFunc_t                         MTR_LogWrite_i;
MTR_LogWrite_dFunc_t                         MTR_LogWrite_d;

MTR_ShowSimpleMessageBoxFunc_t               MTR_ShowSimpleMessageBox;
MTR_ShowYesNoMessageBoxFunc_t                MTR_ShowYesNoMessageBox;
MTR_ShowOkCancelMessageBoxFunc_t             MTR_ShowOkCancelMessageBox;
MTR_ShowInputDialogFunc_t                    MTR_ShowInputDialog;
MTR_ShowPasswordDialogFunc_t                 MTR_ShowPasswordDialog;
MTR_AddFileFilterFunc_t                      MTR_AddFileFilter;
MTR_ClearFileFiltersFunc_t                   MTR_ClearFileFilters;
MTR_ShowSaveFileDialogFunc_t                 MTR_ShowSaveFileDialog;
MTR_ShowOpenFileDialogFunc_t                 MTR_ShowOpenFileDialog;
MTR_ShowSelectFolderDialogFunc_t             MTR_ShowSelectFolderDialog;

MTR_NotifyFunc_t                             MTR_Notify;

MTR_IndexkeeperCreateFunc_t                  MTR_IndexkeeperCreate;
MTR_IndexkeeperGetFreeIndexFunc_t            MTR_IndexkeeperGetFreeIndex;
MTR_IndexkeeperFreeIndexFunc_t               MTR_IndexkeeperFreeIndex;
MTR_IndexkeeperIndexIsEmptyFunc_t            MTR_IndexkeeperIndexIsEmpty;
MTR_IndexkeeperGetReservedDataCountFunc_t    MTR_IndexkeeperGetReservedDataCount;
MTR_IndexkeeperDestroyFunc_t                 MTR_IndexkeeperDestroy;

MTR_EncodingUtf8ToUcs4Func_t                 MTR_EncodingUtf8ToUcs4;
MTR_EncodingUtf8CodepointsFunc_t             MTR_EncodingUtf8Codepoints;

MTR_FileOpenFunc_t                           MTR_FileOpen;
MTR_FileCloseFunc_t                          MTR_FileClose;
MTR_FileReadFunc_t                           MTR_FileRead;
MTR_FileWriteFunc_t                          MTR_FileWrite;
MTR_FileWriteLineFunc_t                      MTR_FileWriteLine;
MTR_FileWriteFastFunc_t                      MTR_FileWriteFast;
MTR_FileWriteLineFastFunc_t                  MTR_FileWriteLineFast;

MTR_ClipboardPutTextFunc_t                   MTR_ClipboardPutText;
MTR_ClipboardGetTextFunc_t                   MTR_ClipboardGetText;

MTR_StringBufferAddFunc_t                    MTR_StringBufferAdd;
MTR_StringBufferDeleteFunc_t                 MTR_StringBufferDelete;
MTR_StringBufferSetStringFunc_t              MTR_StringBufferSetString;
MTR_StringBufferGetStringFunc_t              MTR_StringBufferGetString;
MTR_StringBufferGetMaxLenFunc_t              MTR_StringBufferGetMaxLen;

MTR_OptionsAliasFunc_t                       MTR_OptionsAlias;
MTR_OptionsGetFunc_t                         MTR_OptionsGet;
MTR_OptionsGet_bFunc_t                       MTR_OptionsGet_b;
MTR_OptionsGet_iFunc_t                       MTR_OptionsGet_i;
MTR_OptionsGet_lFunc_t                       MTR_OptionsGet_l;
MTR_OptionsGet_fFunc_t                       MTR_OptionsGet_f;
MTR_OptionsGet_dFunc_t                       MTR_OptionsGet_d;

MTR_ConsoleShowFunc_t                        MTR_ConsoleShow;
MTR_ConsoleHideFunc_t                        MTR_ConsoleHide;

MTR_SoLoadSymbolFunc_t                       MTR_SoLoadSymbol;

uint8_t mtrPluginsCount;


#define MTR_FIND_FUNCTION(function, module)                         \
    function = (function ## Func)MTR_FindFunction(module,           \
    #function);                                                     \
    if (function == NULL)                                           \
    {                                                               \
        MTR_LogWrite_s("Unable to load function", 3, MTR_LMT_ERROR, \
         #function);                                                \
        ok = false;                                                 \
    }

#define MTR_FIND_FUNCTION_IN_SUBSYSTEM(function, subsystem)             \
    function = (function ## Func)MTR_FindFunctionInSubsystem(subsystem, \
    #function);                                                         \
    if (function == NULL)                                               \
    {                                                                   \
        MTR_LogWrite_s("Unable to load function", 1, MTR_LMT_ERROR,     \
         #function);                                                    \
        return false;                                                   \
    }

#define MTR_SUBSYSTEM_FUNCTION_SUPPORTED_FUNC(subsystemPrefix, functionsCount) \
    MTR_DCLSPC int MTR_CALL MTR_ ## subsystemPrefix ## FunctionSupported(      \
     const char *functionName)                                                 \
    {                                                                          \
        int i;                                                                 \
        for (i = 0; i < functionsCount; i++)                                   \
        {                                                                      \
            if (strcmp(functionName, fa[i].name) == 0)                         \
                return fa[i].availability;                                     \
        }                                                                      \
        return MTR_FA_NO;                                                      \
    }

#endif
