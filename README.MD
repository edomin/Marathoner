### General info
Marathoner - game engine for Game Jams.  
Work in progress.  
Supported platforms:

* Windows 32x or 64x

More detailed description will be in v1.0.0.  
There is [plan](https://trello.com/b/HfeG5Dbo/marathoner-todo) what we need complete till version 1.0.0 on Trello. Completed tasks will be moved to archive. Estimated date of completing plan is August-December 2018.

### Building
Will be in v1.0.0

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
More examples in tests' bat-files. See "test" directory.

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
