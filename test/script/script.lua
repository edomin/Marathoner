-- Positive
FileWriteLineFast("test/output.txt", "Positive test", FM_WRITE);
RegisterStringVariable("STRING_VARIABLE", "Hello");
RegisterNumericVariable("NUMERIC_VARIABLE", 9000);
FileWriteLineFast("test/output.txt", "STRING_VARIABLE: " .. STRING_VARIABLE, FM_APPEND);
FileWriteLineFast("test/output.txt", "NUMERIC_VARIABLE: " .. NUMERIC_VARIABLE, FM_APPEND);

-- Negative
FileWriteLineFast("test/output.txt", "Negative test", FM_APPEND);

FileWriteLineFast("test/output.txt", "string var - empty name", FM_APPEND);
RegisterStringVariable("", "Hello");

FileWriteLineFast("test/output.txt", "string var - nil name", FM_APPEND);
RegisterStringVariable(nil, "Hello");

FileWriteLineFast("test/output.txt", "string var - empty table as name", FM_APPEND);
RegisterStringVariable({}, "Hello");

FileWriteLineFast("test/output.txt", "string var - number as name", FM_APPEND);
RegisterStringVariable(9000, "Hello");

FileWriteLineFast("test/output.txt", "string var - number as value", FM_APPEND);
RegisterStringVariable("STRING_VARIABLE_2", 9000);

FileWriteLineFast("test/output.txt", "string var - nil as value", FM_APPEND);
RegisterStringVariable("STRING_VARIABLE_3", nil);

FileWriteLineFast("test/output.txt", "string var - empty table as value", FM_APPEND);
RegisterStringVariable("STRING_VARIABLE_4", {});

FileWriteLineFast("test/output.txt", "string var - empty name", FM_APPEND);
RegisterNumericVariable("", 9000);

FileWriteLineFast("test/output.txt", "string var - nil name", FM_APPEND);
RegisterNumericVariable(nil, 9000);

FileWriteLineFast("test/output.txt", "string var - empty table as name", FM_APPEND);
RegisterNumericVariable({}, 9000);

FileWriteLineFast("test/output.txt", "string var - number as name", FM_APPEND);
RegisterNumericVariable(9000, 9000);

FileWriteLineFast("test/output.txt", "string var - string as value", FM_APPEND);
RegisterNumericVariable("NUMERIC_VARIABLE_2", "Hello");

FileWriteLineFast("test/output.txt", "string var - nil as value", FM_APPEND);
RegisterNumericVariable("NUMERIC_VARIABLE_3", nil);

FileWriteLineFast("test/output.txt", "string var - empty table as value", FM_APPEND);
RegisterNumericVariable("NUMERIC_VARIABLE_4", {});

FileWriteLineFast("test/output.txt", "STRING_VARIABLE_2: " .. STRING_VARIABLE_2, FM_APPEND);
FileWriteLineFast("test/output.txt", "STRING_VARIABLE_3: " .. STRING_VARIABLE_3, FM_APPEND);
FileWriteLineFast("test/output.txt", "STRING_VARIABLE_4: " .. STRING_VARIABLE_4, FM_APPEND);
FileWriteLineFast("test/output.txt", "NUMERIC_VARIABLE_2: " .. NUMERIC_VARIABLE_2, FM_APPEND);
FileWriteLineFast("test/output.txt", "NUMERIC_VARIABLE_3: " .. NUMERIC_VARIABLE_3, FM_APPEND);
FileWriteLineFast("test/output.txt", "NUMERIC_VARIABLE_4: " .. NUMERIC_VARIABLE_4, FM_APPEND);

-- Registering variable with same name
FileWriteLineFast("test/output.txt", "Test of registering variable with same name", FM_APPEND);
RegisterStringVariable("STRING_VARIABLE", "Hello");
RegisterNumericVariable("NUMERIC_VARIABLE", 9000);
FileWriteLineFast("test/output.txt", "STRING_VARIABLE: " .. STRING_VARIABLE, FM_APPEND);
FileWriteLineFast("test/output.txt", "NUMERIC_VARIABLE: " .. NUMERIC_VARIABLE, FM_APPEND);
