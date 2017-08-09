-- Positive
local MTR_LMT_INFO = 0;
local MTR_LMT_NOTE = 1;
local MTR_LMT_WARNING = 2;
local MTR_LMT_ERROR = 3;
local MTR_LMT_FATAL = 4;
local MTR_LMT_DEBUG = 5;

LogWrite("Test info", 0, MTR_LMT_INFO);
LogWrite("Test note", 0, MTR_LMT_NOTE);
LogWrite("Test warning", 0, MTR_LMT_WARNING);
LogWrite("Test error", 0, MTR_LMT_ERROR);
LogWrite("Test fatal", 0, MTR_LMT_FATAL);
LogWrite("Test debug", 0, MTR_LMT_DEBUG);

LogWrite_s("Fruit", 0, MTR_LMT_INFO, "apple");
LogWrite_i("Integer", 0, MTR_LMT_INFO, 42);
LogWrite_d("Double", 0, MTR_LMT_INFO, 3.14);
