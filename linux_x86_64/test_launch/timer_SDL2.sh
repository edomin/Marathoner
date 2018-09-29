#!/bin/bash
cd ..
./Marathoner --script Script_Lua --timer Timer_SDL2 \
 --autorun-plugin Script_Lua --autorun-script test/timer/timer.lua
cd test_launch
