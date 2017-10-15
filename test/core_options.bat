cd ..
Marathoner --script Script_Lua --autorun-plugin Script_Lua ^
 --autorun-script test/core/options.lua --boolOpt 1 --intOpt 42 --longOpt 0xFF ^
 --floatOpt 3.14 --doubleOpt 1e-5 -s Hello
cd test
