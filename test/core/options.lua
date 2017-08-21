-- Positive
FileWriteLineFast("test/output.txt", "Positive test", FM_WRITE);
OptionsAlias("autorun-script", "s");
FileWriteLineFast("test/output.txt", "OptionsGet('s'): " .. OptionsGet("s"),
 FM_APPEND);
