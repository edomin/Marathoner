### Building on Linux for Linux x86-64
This is my list of commands for building prereqisites. Every block of commands runs from directory of library extracted from archive.
Before building you need to create directory "/usr/local/x86_64-linux-gnu".
For building I used GCC 7.3.0.
Also for building of some libraries you need:

* CMake (I use CMake 3.10.2)
* Python (I use Python 2.7.15rc1)
* pip (I use pip 9.0.1)
* yaml

[cJSON](https://github.com/DaveGamble/cJSON)

```
$ mkdir build
$ cd build
$ cmake .. -DCMAKE_C_FLAGS="-fPIC" -DENABLE_CJSON_TEST=Off \
 -DBUILD_SHARED_LIBS=Off
$ make
$ sudo make install
```

[dr_wav](https://github.com/mackron/dr_libs)

```
$ sudo cp dr_wav.h /usr/local/include
```

[duktape](http://duktape.org/)

```
$ mkdir tmp
$ mkdir tmp/output
$ python tools/configure.py --output-directory ./tmp/output --rom-support \
--dll -DDUK_USE_FATAL_HANDLER
$ x86_64-linux-gnu-gcc -Wall -mmmx -msse -msse2 -mfpmath=sse -O2 -fPIC \
-o tmp/output/duktape.o -c tmp/output/duktape.c
$ x86_64-linux-gnu-gcc -o tmp/output/libduktape.so -s \
-shared tmp/output/duktape.o
$ x86_64-linux-gnu-ar rcs tmp/output/libduktape.a tmp/output/duktape.o
$ x86_64-linux-gnu-gcc -Wall -mmmx -msse -msse2 -mfpmath=sse -O2 \
-o tmp/output/duk_module_node.o \
-c extras/module-node/duk_module_node.c -Itmp/output
$ x86_64-linux-gnu-ar rcs tmp/output/libduk_module_node.a \
tmp/output/duk_module_node.o
$ sudo cp tmp/output/*.h /usr/local/include
$ sudo cp extras/module-node/duk_module_node.h \
/usr/local/include
$ sudo cp tmp/output/*.a /usr/local/lib
$ sudo cp tmp/output/libduktape.so /usr/local/lib
$ rm -r -f tmp
```

[Freetype](http://www.freetype.org)

```
$ sudo apt install libfreetype6-dev
```

[inih](https://github.com/benhoyt/inih)

```
$ sudo apt install libinih-dev
```

[libclipboard](https://jtanx.github.io/libclipboard/)

```
$ mkdir build
$ cd build
$ cmake .. \
 -DCMAKE_C_FLAGS="-std=c99 -Wall -pedantic -g -I./include -I../include"
$ make
$ sudo make install
$ sudo cp include/libclipboard-config.h /usr/local/include
```

[libpng](http://www.libpng.org/pub/png/libpng.html)

```
$ sudo apt-get install libpng-dev
```

[libvorbis](https://www.xiph.org/vorbis/)

```
$ sudo apt install libvorbis-dev
```

[Lua](http://www.lua.org/)

```
$ sudo apt-get install liblua5.3-dev
```

[minIni](https://www.compuphase.com/minini.htm)

```
$ x86_64-linux-gnu-gcc -O2 -Wall -fPIC -c minIni.c -o minIni.o
$ x86_64-linux-gnu-ar rcs libminini.a minIni.o
$ sudo mkdir /usr/local/include/minINI
$ sudo cp *.h /usr/local/include/minINI
$ sudo cp libminini.a /usr/local/lib
```

[nuklear](https://github.com/vurtun/nuklear)

```
$ sudo cp nuklear.h /usr/local/include
```

[PhysicsFS](https://icculus.org/physfs/)

```
$ sudo apt install libphysfs-dev
```

[PortAudio](http://www.portaudio.com/)

```
$ ./configure
$ make
$ sudo make install
```

[saneopt](https://github.com/mmalecki/saneopt)

```
$ make
$ sudo cp include/saneopt.h /usr/local/include
$ sudo cp libsaneopt.a /usr/local/lib
```

[SDL2](https://www.libsdl.org/)

```
$ sudo apt install libsdl2-dev
```

[SDL2_gfx](http://www.ferzkopp.net/wordpress/2016/01/02/sdl_gfx-sdl2_gfx/)

```
$ ./configure --disable-sdltest
$ make
$ sudo make install
$ sudo cp SDL2_gfxPrimitives_font.h /usr/local/include/SDL2
```

[SDL2_gpu](https://github.com/grimfang4/sdl-gpu)
Dependencies: SDL2

```
$ mkdir build
$ cd build
$ cmake ..
$ make
$ sudo make install
```

[SDL2_image](https://www.libsdl.org/projects/SDL_image/)

```
$ .sudo apt install libsdl2-image-dev
```

[SDL2_mixer](https://www.libsdl.org/projects/SDL_mixer/)

```
$ sudo apt install libsdl2-mixer-dev
```

[SDL2_ttf](https://www.libsdl.org/projects/SDL_ttf/)

```
$ sudo apt install libsdl2-ttf-dev
```

[Squirrel](http://www.squirrel-lang.org/)

```
$ sudo apt install libsquirrel-dev
```

[stb_rect_pack](https://github.com/nothings/stb)

```
$ sudo cp stb_rect_pack.h /usr/local/include
```

[tinyfiledialogs](https://sourceforge.net/projects/tinyfiledialogs/)

```
$ x86_64-linux-gnu-gcc -c tinyfiledialogs.c -o tinyfiledialogs.o -O2 -Wall -fPIC
$ x86_64-linux-gnu-gcc -shared -s -o libtinyfiledialogs.so tinyfiledialogs.o
$ x86_64-linux-gnu-ar rcs libtinyfiledialogs.a tinyfiledialogs.o
$ sudo cp tinyfiledialogs.h /usr/local/include
$ sudo cp libtinyfiledialogs.a /usr/local/lib
$ sudo cp libtinyfiledialogs.so /usr/local/lib
```

[utf](https://github.com/andlabs/utf)

```
$ x86_64-linux-gnu-gcc -Wall -O2 -c utf.c -o utf.o
$ x86_64-linux-gnu-ar rcs libutf.a utf.o
$ sudo cp utf.h /usr/local/include
$ sudo cp libutf.a /usr/local/lib
```
