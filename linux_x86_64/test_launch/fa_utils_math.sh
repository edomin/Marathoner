#!/bin/bash
cd ..
./Marathoner --script Script_Lua --autorun-plugin Script_Lua \
 --autorun-script test/function_availability/math.lua
cd test_launch
