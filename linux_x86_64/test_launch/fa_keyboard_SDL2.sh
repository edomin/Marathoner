#!/bin/bash
cd ..
./Marathoner --script Script_Lua --keyboard Keyboard_SDL2 \
 --autorun-plugin Script_Lua \
 --autorun-script test/function_availability/keyboard.lua
cd test_launch
