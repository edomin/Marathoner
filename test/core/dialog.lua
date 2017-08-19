-- Positive
FileWriteLineFast("test/output.txt", "Positive test", FM_WRITE);
local MTR_DMT_INFO = 0;
local MTR_DMT_NOTE = 1;
local MTR_DMT_WARNING = 2;
local MTR_DMT_ERROR = 3;
local MTR_DMT_FATAL = 4;
local MTR_DMT_DEBUG = 5;

ShowSimpleMessageBox(MTR_DMT_INFO, "Info", "Info dialog");
ShowSimpleMessageBox(MTR_DMT_NOTE, "Note", "Note dialog");
ShowSimpleMessageBox(MTR_DMT_WARNING, "Warning", "Warning dialog");
ShowSimpleMessageBox(MTR_DMT_ERROR, "Error", "Error dialog");
ShowSimpleMessageBox(MTR_DMT_FATAL, "Fatal", "Fatal dialog");
ShowSimpleMessageBox(MTR_DMT_DEBUG, "Debug", "Debug dialog");

local yesNo = ShowYesNoMessageBox("Yes_No", "Yes or No?");
local okCancel = ShowOkCancelMessageBox("Ok_Cancel", "Ok or Cancel?");
local input = ShowInputDialog("input", "Input something:", "something");
local password = ShowPasswordDialog("password", "Enter password:");

ClearFileFilters();
AddFileFilter("*.txt");
AddFileFilter("*.ini");
AddFileFilter("*.json");
local savedFile = ShowSaveFileDialog("Save...", nil, "text files");
local loadedFile = ShowOpenFileDialog("Open...", nil, "text files");

FileWriteLineFast("test/output.txt", "yesNo: " .. yesNo, FM_APPEND);
FileWriteLineFast("test/output.txt", "okCancel: " .. okCancel, FM_APPEND);
FileWriteLineFast("test/output.txt", "input: " .. input, FM_APPEND);
FileWriteLineFast("test/output.txt", "password: " .. password, FM_APPEND);
FileWriteLineFast("test/output.txt", "savedFile: " .. savedFile, FM_APPEND);
FileWriteLineFast("test/output.txt", "loadedFile: " .. loadedFile, FM_APPEND);
