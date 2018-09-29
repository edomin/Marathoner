#!/bin/bash
cd ..
./Marathoner --script Script_Lua --screen Screen_SDL2_gpu \
 --texture Texture_SDL2_gpu --primitive Primitive_SDL2_gpu --timer Timer_SDL2 \
 --autorun-plugin Script_Lua --autorun-script test/texture/texture_shear.lua
cd test_launch
