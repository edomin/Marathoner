-- Positive
LogWrite("Test info", 0, LMT_INFO);
LogWrite("Test note", 0, LMT_NOTE);
LogWrite("Test warning", 0, LMT_WARNING);
LogWrite("Test error", 0, LMT_ERROR);
LogWrite("Test fatal", 0, LMT_FATAL);
LogWrite("Test debug", 0, LMT_DEBUG);

LogWrite_s("Fruit", 0, MTR_LMT_INFO, "apple");
LogWrite_i("Integer", 0, MTR_LMT_INFO, 42);
LogWrite_d("Double", 0, MTR_LMT_INFO, 3.14);
