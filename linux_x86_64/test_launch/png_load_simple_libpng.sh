#!/bin/bash
cd ..
./Marathoner --script Script_Lua --screen Screen_SDL2_gpu \
 --png PNG_libpng --autorun-plugin Script_Lua \
 --autorun-script test/png/png_load_simple.lua
cd test_launch
