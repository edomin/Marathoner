// Positive
FileWriteLineFast("test/output.txt", "Positive test", FM_WRITE);
FileWriteLineFast("test/output.txt",
 "Autorun path: " + ScriptsGetAutorunPath(), FM_APPEND);
RegisterVariable_b("BOOL_VARIABLE", false);
RegisterVariable_i("INT_VARIABLE", 42);
RegisterVariable_u("UNSIGNED_VARIABLE", 0xDEADBEEF);
RegisterVariable_f("SINGLE_VARIABLE", 3.14);
RegisterVariable_d("DOUBLE_VARIABLE", 0.0001);
RegisterVariable_s("STRING_VARIABLE", "Hello");
if (BOOL_VARIABLE) {
    FileWriteLineFast("test/output.txt", "BOOL_VARIABLE: true", FM_APPEND);
} else {
    FileWriteLineFast("test/output.txt", "BOOL_VARIABLE: false", FM_APPEND);
}
FileWriteLineFast("test/output.txt", "INT_VARIABLE: " + INT_VARIABLE,
 FM_APPEND);
FileWriteLineFast("test/output.txt", "UNSIGNED_VARIABLE: " + UNSIGNED_VARIABLE,
 FM_APPEND);
FileWriteLineFast("test/output.txt", "SINGLE_VARIABLE: " + SINGLE_VARIABLE,
 FM_APPEND);
FileWriteLineFast("test/output.txt", "DOUBLE_VARIABLE: " + DOUBLE_VARIABLE,
 FM_APPEND);
FileWriteLineFast("test/output.txt", "STRING_VARIABLE: " + STRING_VARIABLE,
 FM_APPEND);
