-- Positive
FileWriteLineFast("test/output.txt", "Positive test", FM_WRITE);
if OptionsAlias("stringOpt", "s") then
    FileWriteLineFast("test/output.txt",
     "Created alias 's' for 'autorun-script'", FM_APPEND);
end;
FileWriteLineFast("test/output.txt",
 "OptionsGet('autorun-script'): " .. OptionsGet("autorun-script"), FM_APPEND);
FileWriteLineFast("test/output.txt",
 "OptionsGet('stringOpt'): " .. OptionsGet("stringOpt"), FM_APPEND);
if OptionsGet_b("boolOpt") then
    FileWriteLineFast("test/output.txt",
     "OptionsGet_b('boolOpt'): true", FM_APPEND);
else
    FileWriteLineFast("test/output.txt",
     "OptionsGet_b('boolOpt'): false", FM_APPEND);
end;
FileWriteLineFast("test/output.txt",
 "OptionsGet_i('intOpt'): " .. OptionsGet_i("intOpt"), FM_APPEND);
FileWriteLineFast("test/output.txt",
 "OptionsGet_l('longOpt'): " .. OptionsGet_l("longOpt"), FM_APPEND);
FileWriteLineFast("test/output.txt",
 "OptionsGet_f('floatOpt'): " .. OptionsGet_f("floatOpt"), FM_APPEND);
FileWriteLineFast("test/output.txt",
 "OptionsGet_d('doubleOpt'): " .. OptionsGet_d("doubleOpt"), FM_APPEND);
