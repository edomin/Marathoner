#!/bin/bash
cd ..
./Marathoner --script Script_Lua --screen Screen_SDL2 \
 --texture Texture_SDL2_image --primitive Primitive_SDL2 --timer Timer_SDL2 \
 --autorun-plugin Script_Lua --autorun-script test/texture/texture.lua
cd test_launch
