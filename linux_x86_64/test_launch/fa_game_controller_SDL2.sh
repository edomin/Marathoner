#!/bin/bash
cd ..
./Marathoner --script Script_Lua --game_controller Game_Controller_SDL2 \
 --autorun-plugin Script_Lua \
 --autorun-script test/function_availability/game_controller.lua
cd test_launch
