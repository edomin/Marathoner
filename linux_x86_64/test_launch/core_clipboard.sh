#!/bin/bash
cd ..
./Marathoner --script Script_Lua --autorun-plugin Script_Lua \
 --autorun-script test/core/clipboard.lua
cd test_launch
