#!/bin/bash
cd ..
./Marathoner --script Script_Lua --ttf TTF_FreeType2 \
 --autorun-plugin Script_Lua --autorun-script test/function_availability/ttf.lua
cd test_launch
