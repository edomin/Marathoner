#!/bin/bash
cd ..
./Marathoner --script Script_Lua --screen Screen_SDL2_gpu \
 --texture Texture_SDL2_gpu --autorun-plugin Script_Lua \
 --autorun-script test/function_availability/texture.lua
cd test_launch
