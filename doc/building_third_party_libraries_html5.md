### Building on Windows for HTML5
This is my list of commands for building prereqisites. Every block of commands runs from directory of library extracted from archive.  
Before building you need to create directory /usr/local/emscripten (\<path_to_msys2\>/usr/local/emscripten) and add path to compiler to PATH environment variable (and temporary delete paths to other compilers from PATH).  
For building you need Emscripten.  
Also for building of some libraries you need:  

* CMake (I use CMake 3.5.2)
* Python (I use Python 2.7.13)
  * pyyaml package installed
* wget

[bzip2](http://www.bzip.org/)

```
$ emmake make CC=emcc AR=emar
$ emmake make install PREFIX=/usr/local/emscripten
```

[cJSON](https://github.com/DaveGamble/cJSON)

```
$ emcc -Wall -O2 -c cJSON.c -o cJSON.o
$ emar rcs libcjson.a cJSON.o
$ cp libcjson.a /usr/local/emscripten/lib
$ mkdir /usr/local/emscripten/include/cjson
$ cp cJSON.h /usr/local/emscripten/include/cjson
```

[duktape](http://duktape.org/)

```
$ mkdir tmp
$ mkdir tmp/output
$ python tools/configure.py --output-directory ./tmp/output --rom-support \
--platform=Emscripten --compiler=Emscripten --architecture=Emscripten
$ emcc -Wall -O2 -DEMSCRIPTEN -std=c99 --memory-init-file 0 \
-o tmp/output/duktape.o -c tmp/output/duktape.c
$ emar rcs tmp/output/libduktape.a tmp/output/duktape.o
$ emcc -Wall -O2 -DEMSCRIPTEN -std=c99 --memory-init-file 0 \
-o tmp/output/duk_module_node.o -c extras/module-node/duk_module_node.c \
-Itmp/output
$ emar rcs tmp/output/libduk_module_node.a tmp/output/duk_module_node.o
$ cp tmp/output/*.h /usr/local/emscripten/include
$ cp extras/module-node/duk_module_node.h /usr/local/emscripten/include
$ cp tmp/output/*.a /usr/local/emscripten/lib
$ rm -r -f tmp
```

[glew2](http://glew.sourceforge.net/)

```
$ cd build
$ emcmake cmake ./cmake -G "MSYS Makefiles" \
-DCMAKE_INSTALL_PREFIX=/usr/local/emscripten
$ emmake make CC=emcc
$ emmake make install
```

[libflac](https://xiph.org/flac/)(1.3.2)

```
$ emmake make -f Makefile.lite libFLAC CC="emcc \
-Dflac_min\(num1,num2\)=\(\(num1\<num2\)\?num1:num2\) \
-Dflac_max\(num1,num2\)=\(\(num1\>num2\)\?num1:num2\) -s USE_OGG=1" OS=html5 \
LINK="emar rcu"
$ emranlib objs/release/lib/libFLAC.a
$ cp objs/release/lib/libFLAC.a /usr/local/emscripten/lib
$ mkdir /usr/local/emscripten/include/FLAC
$ cp include/FLAC/*.h /usr/local/emscripten/include/FLAC
```

[libmodplug (cmake version by Konstanty)](https://github.com/Konstanty/libmodplug)

```
$ mkdir build
$ cd build
$ emcmake cmake .. -G "MSYS Makefiles" \
-DCMAKE_INSTALL_PREFIX=/usr/local/emscripten -DCMAKE_CXX_FLAGS="-Wall -O2 \
-fno-exceptions -ffast-math -D_REENTRANT -DHAVE_INTTYPES_H -DHAVE_STDINT_H"
$ emmake make
$ emmake make install
$ cd ..
$ rm -r build
```

[lua](http://www.lua.org/)

```
$ emmake make generic CC=emcc AR="emar rcs" RANLIB=emranlib
$ cp src/liblua.a /usr/local/emscripten/lib
$ cp src/lauxlib.h /usr/local/emscripten/include
$ cp src/lua.h /usr/local/emscripten/include
$ cp src/luaconf.h /usr/local/emscripten/include
$ cp src/lualib.h /usr/local/emscripten/include
```

[minIni](https://www.compuphase.com/minini.htm)

```
$ emcc -O2 -Wall -c minIni.c -o minIni.o -Dstrnicmp=strncasecmp
$ emar rcs libminini.a minIni.o
$ mkdir /usr/local/emscripten/include/minINI
$ cp *.h /usr/local/emscripten/include/minINI
$ cp libminini.a /usr/local/emscripten/lib
```

[nuklear](https://github.com/vurtun/nuklear)

```
$ cp nuklear.h /usr/local/emscripten/include
```

[SDL2_gfx](http://www.ferzkopp.net/wordpress/2016/01/02/sdl_gfx-sdl2_gfx/)

```
$ emcc -O1 -Wall -Dmain=SDL_main -s USE_SDL=2 -c SDL2_framerate.c \
-o SDL2_framerate.o
$ emcc -O1 -Wall -Dmain=SDL_main -s USE_SDL=2 -c SDL2_gfxPrimitives.c \
-o SDL2_gfxPrimitives.o
$ emcc -O1 -Wall -Dmain=SDL_main -s USE_SDL=2 -c SDL2_imageFilter.c \
-o SDL2_imageFilter.o
$ emcc -O1 -Wall -Dmain=SDL_main -s USE_SDL=2 -c SDL2_rotozoom.c \
-o SDL2_rotozoom.o
$ emar rcs libSDL2_gfx.a SDL2_framerate.o SDL2_gfxPrimitives.o \
SDL2_imageFilter.o SDL2_rotozoom.o
$ mkdir /usr/local/emscripten/include/SDL2
$ cp *.h /usr/local/emscripten/include/SDL2
$ cp libSDL2_gfx.a /usr/local/emscripten/lib
```

[SDL2_mixer](https://www.libsdl.org/projects/SDL_mixer/)  
I did not able to build this with "./configure". This is why I write custom makefile for building SDL2_mixer with Emscripten.

```
$ rm -rf SDL2_mixer_Emscripten.mk
$ wget -P . \
https://gist.githubusercontent.com/edomin/77de668d6e57bec96610de4409bebf07/raw/4b452494e6e6d787419fa8e21ec8b50a81c2adc8/SDL2_mixer_Emscripten.mk
$ make -f SDL2_mixer_Emscripten.mk
$ make -f SDL2_mixer_Emscripten.mk install PREFIX=/usr/local/emscripten
```

[Squirrel](http://www.squirrel-lang.org/)

```
$ mkdir build
$ cd build
$ emcmake cmake .. -G "MSYS Makefiles" \
-DCMAKE_INSTALL_PREFIX="/usr/local/emscripten"
$ emmake make
$ emmake make install
$ cp ../include/* /usr/local/emscripten/include
$ cd ..
$ rm -r build
```

[stb_image](https://github.com/nothings/stb)

```
$ cp stb_image.h /usr/local/emscripten/include
```

[stb_image_write](https://github.com/nothings/stb)

```
$ cp stb_image_write.h /usr/local/emscripten/include
```

[stb_rect_pack](https://github.com/nothings/stb)

```
$ cp stb_rect_pack.h /usr/local/emscripten/include
```

[utf8](https://github.com/haipome/utf8)

```
$ emcc -O2 -Wall -c utf8.c -o utf8.o
$ emar rcs libutf8.a utf8.o
$ cp utf8.h /usr/local/emscripten/include
$ cp *.a /usr/local/emscripten/lib
```
