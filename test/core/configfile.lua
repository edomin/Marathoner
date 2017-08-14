-- Positive
FileWriteLineFast("test/output.txt", "Positive test", FM_WRITE);

local keyname = ConfigfileGetKeyName("test/core/test_cfg.ini", "section_1", 0);
FileWriteLineFast("test/output.txt", "keyname: " .. keyname, FM_APPEND);
keyname = ConfigfileGetKeyName("test/core/test_cfg.ini", "section_1", 1);
FileWriteLineFast("test/output.txt", "keyname: " .. keyname, FM_APPEND);

local section_name = ConfigfileGetSectionName("test/core/test_cfg.ini", 0);
FileWriteLineFast("test/output.txt", "section_name: " .. section_name,
 FM_APPEND);

ConfigfileWriteBool("test/core/test_cfg.ini", "section_1", "someBool", true);
ConfigfileWriteInt("test/core/test_cfg.ini", "section_1", "someInt", 42);
ConfigfileWriteSingle("test/core/test_cfg.ini", "section_1", "someSingle",
 3.14);
ConfigfileWriteString("test/core/test_cfg.ini", "section_1", "someString",
 "test string");

local someBool = ConfigfileReadBool("test/core/test_cfg.ini", "section_1",
 "someBool", false);
local someInt = ConfigfileReadInt("test/core/test_cfg.ini", "section_1",
 "someInt", 24);
local someSingle = ConfigfileReadSingle("test/core/test_cfg.ini", "section_1",
 "someSingle", 0.01);
local someString = ConfigfileReadString("test/core/test_cfg.ini", "section_1",
 "someString", "default_string");
FileWriteLineFast("test/output.txt", "someBool: " .. someBool, FM_APPEND);
FileWriteLineFast("test/output.txt", "someInt: " .. someInt, FM_APPEND);
FileWriteLineFast("test/output.txt", "someSingle: " .. someSingle, FM_APPEND);
FileWriteLineFast("test/output.txt", "someString: " .. someString, FM_APPEND);

ConfigfileDeleteKey("test/core/test_cfg.ini", "section_1", "someBool");
ConfigfileDeleteKey("test/core/test_cfg.ini", "section_1", "someInt");
ConfigfileDeleteKey("test/core/test_cfg.ini", "section_1", "someSingle");
ConfigfileDeleteKey("test/core/test_cfg.ini", "section_1", "someString");

someBool = ConfigfileReadBool("test/core/test_cfg.ini", "section_1", "someBool",
 false);
someInt = ConfigfileReadInt("test/core/test_cfg.ini", "section_1", "someInt",
 24);
someSingle = ConfigfileReadSingle("test/core/test_cfg.ini", "section_1",
 "someSingle", 0.01);
someString = ConfigfileReadString("test/core/test_cfg.ini", "section_1",
 "someString", "default_string");
FileWriteLineFast("test/output.txt",
 "someBool after deleting key: " .. someBool, FM_APPEND);
FileWriteLineFast("test/output.txt",
 "someInt after deleting key: " .. someInt, FM_APPEND);
FileWriteLineFast("test/output.txt",
 "someSingle after deleting key: " .. someSingle, FM_APPEND);
FileWriteLineFast("test/output.txt",
 "someString after deleting key: " .. someString, FM_APPEND);

ConfigfileCreateSection("test/core/test_cfg.ini", "new_section");
ConfigfileWriteString("test/core/test_cfg.ini", "new_section", "newString",
 "Hello");
local newString = ConfigfileReadString("test/core/test_cfg.ini", "new_section",
 "newString", "default_string");
FileWriteLineFast("test/output.txt", "newString: " .. newString, FM_APPEND);
ConfigfileDeleteSection("test/core/test_cfg.ini", "new_section");
newString = ConfigfileReadString("test/core/test_cfg.ini", "new_section",
 "newString", "default_string");
FileWriteLineFast("test/output.txt", "newString: " .. newString, FM_APPEND);

-- Negative
-- TODO
