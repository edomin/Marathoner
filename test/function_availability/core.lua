-- Function Availability
FileWriteLineFast("test/output.txt", "Function Availability", FM_WRITE);
local fa = dofile("test/common/function_availability.lua");

fa.FunctionSupported(MarathonerGetVersion, "MTR_MarathonerGetVersion",
 MarathonerFunctionSupported);
fa.FunctionSupported(MarathonerGetModuleVersion,
 "MTR_MarathonerGetModuleVersion", MarathonerFunctionSupported);
fa.FunctionSupported(MarathonerGetSubsystemModuleId,
 "MTR_MarathonerGetSubsystemModuleId", MarathonerFunctionSupported);

fa.FunctionSupported(GetCurrentDirectory, "MTR_GetCurrentDirectory",
 MarathonerFunctionSupported);

fa.FunctionSupported(ConfigfileGetKeyName, "MTR_ConfigfileGetKeyName",
 MarathonerFunctionSupported);
fa.FunctionSupported(ConfigfileGetSectionName, "MTR_ConfigfileGetSectionName",
 MarathonerFunctionSupported);
fa.FunctionSupported(ConfigfileKeyExists, "MTR_ConfigfileKeyExists",
 MarathonerFunctionSupported);
fa.FunctionSupported(ConfigfileSectionExists, "MTR_ConfigfileSectionExists",
 MarathonerFunctionSupported);
fa.FunctionSupported(ConfigfileDeleteKey, "MTR_ConfigfileDeleteKey",
 MarathonerFunctionSupported);
fa.FunctionSupported(ConfigfileDeleteSection, "MTR_ConfigfileDeleteSection",
 MarathonerFunctionSupported);
fa.FunctionSupported(ConfigfileReadBool, "MTR_ConfigfileReadBool",
 MarathonerFunctionSupported);
fa.FunctionSupported(ConfigfileReadInt, "MTR_ConfigfileReadInt",
 MarathonerFunctionSupported);
fa.FunctionSupported(ConfigfileReadSingle, "MTR_ConfigfileReadSingle",
 MarathonerFunctionSupported);
fa.FunctionSupported(ConfigfileReadString, "MTR_ConfigfileReadString",
 MarathonerFunctionSupported);
fa.FunctionSupported(ConfigfileWriteBool, "MTR_ConfigfileWriteBool",
 MarathonerFunctionSupported);
fa.FunctionSupported(ConfigfileWriteInt, "MTR_ConfigfileWriteInt",
 MarathonerFunctionSupported);
fa.FunctionSupported(ConfigfileWriteSingle, "MTR_ConfigfileWriteSingle",
 MarathonerFunctionSupported);
fa.FunctionSupported(ConfigfileWriteString, "MTR_ConfigfileWriteString",
 MarathonerFunctionSupported);
fa.FunctionSupported(ConfigfileCreateSection, "MTR_ConfigfileCreateSection",
 MarathonerFunctionSupported);

fa.FunctionSupported(LogWrite, "MTR_LogWrite", MarathonerFunctionSupported);
fa.FunctionSupported(LogWrite_s, "MTR_LogWrite_s", MarathonerFunctionSupported);
fa.FunctionSupported(LogWrite_i, "MTR_LogWrite_i", MarathonerFunctionSupported);
fa.FunctionSupported(LogWrite_d, "MTR_LogWrite_d", MarathonerFunctionSupported);

fa.FunctionSupported(ShowSimpleMessageBox, "MTR_ShowSimpleMessageBox",
 MarathonerFunctionSupported);
fa.FunctionSupported(ShowYesNoMessageBox, "MTR_ShowYesNoMessageBox",
 MarathonerFunctionSupported);
fa.FunctionSupported(ShowOkCancelMessageBox, "MTR_ShowOkCancelMessageBox",
 MarathonerFunctionSupported);
fa.FunctionSupported(ShowInputDialog, "MTR_ShowInputDialog",
 MarathonerFunctionSupported);
fa.FunctionSupported(ShowPasswordDialog, "MTR_ShowPasswordDialog",
 MarathonerFunctionSupported);
fa.FunctionSupported(AddFileFilter, "MTR_AddFileFilter",
 MarathonerFunctionSupported);
fa.FunctionSupported(ClearFileFilters, "MTR_ClearFileFilters",
 MarathonerFunctionSupported);
fa.FunctionSupported(ShowSaveFileDialog, "MTR_ShowSaveFileDialog",
 MarathonerFunctionSupported);
fa.FunctionSupported(ShowOpenFileDialog, "MTR_ShowOpenFileDialog",
 MarathonerFunctionSupported);
fa.FunctionSupported(ShowSelectFolderDialog, "MTR_ShowSelectFolderDialog",
 MarathonerFunctionSupported);

fa.FunctionSupported(Notify, "MTR_Notify", MarathonerFunctionSupported);

fa.FunctionSupported(FileOpen, "MTR_FileOpen", MarathonerFunctionSupported);
fa.FunctionSupported(FileClose, "MTR_FileClose", MarathonerFunctionSupported);
fa.FunctionSupported(FileRead, "MTR_FileRead", MarathonerFunctionSupported);
fa.FunctionSupported(FileWrite, "MTR_FileWrite", MarathonerFunctionSupported);
fa.FunctionSupported(FileWriteLine, "MTR_FileWriteLine",
 MarathonerFunctionSupported);
fa.FunctionSupported(FileWriteFast, "MTR_FileWriteFast",
 MarathonerFunctionSupported);
fa.FunctionSupported(FileWriteLineFast, "MTR_FileWriteLineFast",
 MarathonerFunctionSupported);

fa.FunctionSupported(ClipboardPutText, "MTR_ClipboardPutText",
 MarathonerFunctionSupported);
fa.FunctionSupported(ClipboardGetText, "MTR_ClipboardGetText",
 MarathonerFunctionSupported);

fa.FunctionSupported(StringBufferAdd, "MTR_StringBufferAdd",
 MarathonerFunctionSupported);
fa.FunctionSupported(StringBufferDelete, "MTR_StringBufferDelete",
 MarathonerFunctionSupported);
fa.FunctionSupported(StringBufferSetString, "MTR_StringBufferSetString",
 MarathonerFunctionSupported);
fa.FunctionSupported(StringBufferGetString, "MTR_StringBufferGetString",
 MarathonerFunctionSupported);
fa.FunctionSupported(StringBufferGetMaxLen, "MTR_StringBufferGetMaxLen",
 MarathonerFunctionSupported);

fa.FunctionSupported(OptionsAlias, "MTR_OptionsAlias",
 MarathonerFunctionSupported);
fa.FunctionSupported(OptionsGet, "MTR_OptionsGet", MarathonerFunctionSupported);
fa.FunctionSupported(OptionsGet_b, "MTR_OptionsGet_b",
 MarathonerFunctionSupported);
fa.FunctionSupported(OptionsGet_i, "MTR_OptionsGet_i",
 MarathonerFunctionSupported);
fa.FunctionSupported(OptionsGet_l, "MTR_OptionsGet_l",
 MarathonerFunctionSupported);
fa.FunctionSupported(OptionsGet_f, "MTR_OptionsGet_f",
 MarathonerFunctionSupported);
fa.FunctionSupported(OptionsGet_d, "MTR_OptionsGet_d",
 MarathonerFunctionSupported);

fa.FunctionSupported(ConsoleShow, "MTR_ConsoleShow",
 MarathonerFunctionSupported);
fa.FunctionSupported(ConsoleHide, "MTR_ConsoleHide",
 MarathonerFunctionSupported);
