### General info
[Marathoner](https://github.com/edomin/Marathoner) - game engine for Game Jams.  
Work in progress.  
Supported platforms:

* Windows 32x or 64x

More detailed description will be in v1.0.0.  
There is [plan](https://trello.com/b/HfeG5Dbo/marathoner-todo) what we need complete till version 1.0.0 on Trello. Completed tasks will be moved to archive. Estimated date of completing plan is August-December 2018.

### Philosophy of the Project
Some general features of this project. This project is only my hobby. This is why some of features can be a bit unreasonably. I just do what I like and no more.

* Using available solutions for everything. I do not want to write so many low-level routines. This is why project using so many third-party libraries as possible.
* Writing alternative modules if unable to build some modules on target platform. For example if needed third-party libraries does not support target platforms.
* Writing alternative modules if we need some more possibilities of other third-party libraries not exists in libraries used by current modules.
* Main Programming Language of this project is C without specific standard. It is possible to use C++ or Pascal in cases if I will need to use other language library or if I will want to do API for C++ or other language.
* Making so many abstraction levels as possible. I think it makes minimum limitations for game programmer.
* Not needed to support every file format. This file formats must be supported. Other formats are optional (for example extra file formats support in addition to mandatory can be provided by some third-party libraries).
  * Images - png
  * Sounds - wav
  * Music - ogg
  * Fonts - ttf and png-fonts
  * Text - uft-8
  * Config - ini

I can consider some ideas conflicting with current phylosophy if that ideas will not something as "Use pure OpenGL", "Use modern C++ as main programming language" or something similar.

### Building
##### Building third-party libraries
Instructions for building third-party libraries can be found in:

* [doc/building_third_party_libraries_win32.md](https://github.com/edomin/Marathoner/blob/master/doc/building_third_party_libraries_win32.md)
* [doc/building_third_party_libraries_win64.md](https://github.com/edomin/Marathoner/blob/master/doc/building_third_party_libraries_win64.md)

##### Building Engine
Path to all needed toolchains' binaries must be in PATH varisble.  
Used compilers:  

* Windows 32bit - TDM GCC 5.1.0
* Windows 64bit - MinGW-W64 x86_64 based on GCC 6.3.0

Before building you need to resolve conflicting names for windres utility in windows toolchains. My solution for every toolchain:  

* Copy file windres.exe
* Rename copyed file to mingw32-windres.exe or x86_64-w64-mingw32-windres.exe

Directories "bin", "include" and "lib" of all prerequired libraries must be placed in "usr/local/toolchain_name" else you need build engine with parameter "PREFIX=\<path_to_libraries\>". In this case "bin" folder of third party libraries will be in directory "\<path_to_libraries\>/bin", "include" folder will be in "\<path_to_libraries\>/include" etc. On MSYS2 root "/" directory placed in MSYS2 folder, "/usr" directory in "\<path_to_msys2\>/usr" etc.  

Build for default platform (currently Windows 32bit) with default options: 
 
```
$ make
```  

Build with custom options:

```
$ make [PLATFORM=<platform>] [<option1>=<value>] [<option2>=<value>] ...
```  

Additional options:  

* PLATFORM=\<platform\> - Choose target platform: win32 or win64. Default - PLATFORM=win32
* MOD=static, MOD=plugin - Build monolythic or plugin-based application. Currently implemented only plugin-based. Default - MOD=plugin
* DEBUG=no, DEBUG=yes - Add or not add debug information in executables and plugins. Default - DEBUG=yes
* MORE_WARNINGS=no, MORE_WARNINGS=yes - Enable or disable some more warnings in compiletime. Default - MORE_WARNINGS=yes

Default options can be changed in file "Build.mk"  
Builded executables can be found in directories "win32", "win64" etc.  

##### Running tests
Scripts (Bat-files on Windows) for running tests plased in directory "\<platform_name\>/test_launch". Valid platform names - win32 and win64.  
Text output of each test will be writed in file "test/output.txt".  
Scripts with prefix "fa_" are launching Lua-scripts generating list of supported functions of that module.  
Lua-scripts of tests placed in "test/\<subsystem\>" folder.

### General usage
See function syntax without description in file "FunctionListAndSyntax.txt"  
More detailed will be in v1.0.0

### Commandline API (See first Configfile usage and Launcher usage)
You can setup launch options with commandline arguments.  
"Marathoner [\<option\> \<value\>] [...]"  
Engine options:

* "show-console" - show console with log on startup. Default - no. Valid values for showing console - "yes", "y", "1", "true".

Autorun options. This options have priority higher than configfile options:

* "--autorun-action \<action\>" - running way. Valid values: "runScript"
* "--autorun-plugin \<pluginname\>" - ID of plugin that will be run VM
* "--autorun-script \<filename\>" - autorun script filename

Choose module of subsystem:  
"--\<subsystem\> \<module\>" - Example "--script Script_Lua"  
Force disable modules via commandline not implemented now.  
More examples in tests' bat-files. See "\<platform\>/test_launch" directory.

### Configfile usage (Not recommended for use. Read Launcher usage)
##### "Engine" section
* "show_console" key - show console with log on startup. Default - no

##### "Autorun" section
Game starting settings

* "action" key - running way. Valid values: "runScript"
* "plugin" key (if "action = runScript") - ID of plugin that will be run VM
* "script" key (if "action = runScript") - autorun script filename

##### "Module" section
Mark modules for forced disable.  
key-value format: "<plugin_ID> = 0|1"  
0 - disabled  
1 - enabled (default)
##### "Subsystem" section
Specify plugin ID of each subsystem for solve conflicts
of several plugins responsible for one subsystem or completely disable
subsystem:  
key-value format: "\<subsystem_name\> = \<plugin_ID\> | none"  

* \<plugin_ID\> for assign plugin  
* "none" for disable subsystem  

### Launcher usage
Launcher - program for edit configuration of the engine and launching needed
autorun script file.

* Upper panel's buttons:
  * Save - save configuration
  * Save and Exit - save configuration and close Launcher
  * Discard and Exit - discard changes and close Launcher
  * Save and Run - save configuration and execute autorun script
  * Discard and Run - discard changes and execute autorun script
* "Autorun" section:
  * Plugin - choose Script plugin
  * Script - choose Autorun script
* "Subsystem":  
Choose module for every subsystem. You need to know about compatibility of
the various standard modules (I need to do documentation for it).
* "Enabled Modules":  
check and uncheck modules for force disable (default - all enabled).

### Contributing
Em... somewho, theach me how to maintain project (and teach me English language and good manners too). I do not familiar with OpenSource culture.  
I think I will able to do tasks of the plan till version 1.0.0 alone and then I will make complete "Contributing" instructions. If you will have ideas how to help, open issue or write me on e-mail: Vasiliy.Edomin{antispam}gmail{antispam}com.

### Copying:
* Source code are under zlib license (for this moment. Read LICENSE).
* Images made by me and generated sounds/music are under CC0 license (Public
Domain):
  * "test/media/helicopter.png"
  * "test/media/helicopter_anim.png"
  * "test/media/mbf_big_00.png"
  * "test/media/mbf_big_04.png"
  * "test/media/bu-a-ninja-and-shields.ogg"
  * "test/media/pickup.wav"
  * "test/media/punch.wav"
  * "test/media/explosion.wav"
* License text for font "test/media/Vera.ttf" can be found in file
"test/media/COPYRIGHT-Vera.TXT". Author - Bitstream, Inc.
* Images made by [Shepardskin](https://twitter.com/Shepardskin) are under CC0 license (Public Domain):
  * "test/media/dog.png"

And I am sorry for my bad english.
