-- Positive
FileWriteLineFast("test/output.txt", "Positive test", FM_WRITE);
FileWriteLineFast("test/output.txt",
 "Screen Subsystem module: " .. MarathonerGetSubsystemModuleId("screen"),
 FM_APPEND);
FileWriteLineFast("test/output.txt",
 "JSON support module: " .. MarathonerGetSubsystemModuleId("json"), FM_APPEND);
FileWriteLineFast("test/output.txt",
 "Script module: " .. MarathonerGetSubsystemModuleId("script"), FM_APPEND);
