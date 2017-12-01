### Building on Windows for Windows 32bit
This is my list of commands for building prereqisites. Every block of commands runs from directory of library extracted from archive.  
Before building you need to create directory /usr/local/mingw32 (\<path_to_msys2\>/usr/local/mingw32) and add path to compiler to PATH environment variable (and temporary delete paths to other compilers from PATH).  
For building I used toolchain TDM GCC 5.1.0.
Also for building of some libraries you need:  

* CMake (I use CMake 3.5.2)
* Python (I use Python 2.7.13)

[bzip2](http://www.bzip.org/)

```
$ make
$ make install PREFIX=/usr/local/mingw32
$ cp bzlib.h /usr/local/mingw32/include
$ cp *.a /usr/local/mingw32/lib
```

[cJSON](https://github.com/DaveGamble/cJSON)

```
$ cmake -G "MSYS Makefiles" -DCMAKE_INSTALL_PREFIX="/usr/local/mingw32" \
-DENABLE_CJSON_TEST=Off -DBUILD_SHARED_LIBS=Off
$ make
$ make install
```

[duktape](http://duktape.org/)

```
$ mkdir tmp
$ mkdir tmp/output
$ python tools/configure.py --output-directory ./tmp/output --rom-support --dll
$ gcc -Wall -mmmx -mfpmath=387 -O2 -o tmp/output/duktape.o -c tmp/output/duktape.c
$ gcc -o tmp/output/duktape.dll -s -shared tmp/output/duktape.o \
-Wl,--out-implib,tmp/output/libduktape.dll.a
$ ar rcs tmp/output/libduktape.a tmp/output/duktape.o
$ gcc -Wall -mmmx -mfpmath=387 -O2 -o tmp/output/duk_module_node.o \
-c extras/module-node/duk_module_node.c -Itmp/output
$ ar rcs tmp/output/libduk_module_node.a tmp/output/duk_module_node.o
$ cp tmp/output/*.h /usr/local/mingw32/include
$ cp extras/module-node/duk_module_node.h /usr/local/mingw32/include
$ cp tmp/output/*.a /usr/local/mingw32/lib
$ cp tmp/output/duktape.dll /usr/local/mingw32/bin
$ rm -r -f tmp
```

[Freetype](http://www.freetype.org)

```
$ ./configure --prefix=/usr/local/mingw32
$ make
$ make install
```

[giflib](http://giflib.sourceforge.net/)

```
$ ./configure --prefix=/usr/local/mingw32
$ make
$ make install
```

[glew](http://glew.sourceforge.net/)

```
$ make
$ make install GLEW_PREFIX=/usr/local/mingw32 GLEW_DEST=/usr/local/mingw32
```

[glfw](http://www.glfw.org/)

```
$ cmake -G "MSYS Makefiles" -DCMAKE_INSTALL_PREFIX=/usr/local/mingw32
$ make
$ make install
$ cmake -G "MSYS Makefiles" -DCMAKE_INSTALL_PREFIX=/usr/local/mingw32 \
-DBUILD_SHARED_LIBS=ON
$ make
$ make install
```

[lazy-winapi](https://github.com/DoumanAsh/lazy-winapi.c)

```
$ cmake -G "MSYS Makefiles" -DCMAKE_INSTALL_PREFIX=/usr/local/mingw32
$ make
$ cp src/lazy_winapi.h /usr/local/mingw32/include
$ mkdir /usr/local/mingw32/include/lazy_winapi
$ cp src/lazy_winapi/*.h /usr/local/mingw32/include/lazy_winapi
$ cp liblazy_winapi.a /usr/local/mingw32/lib
```

[libflac](https://xiph.org/flac/)

```
$ ./configure --prefix=/usr/local/mingw32 --enable-static \
--disable-xmms-plugin --disable-oggtest \
--with-ogg-includes=/usr/local/mingw32/include \
--with-ogg-libraries=/usr/local/mingw32/lib --disable-doxygen-docs \
--disable-cpplibs
$ make
$ make install
```

[libjpeg](http://www.ijg.org/files/)

```
$ ./configure --prefix=/usr/local/mingw32
$ make
$ make install
```

[libmodplug](https://sourceforge.net/projects/modplug-xmms/)

```
$ ./configure --prefix=/usr/local/mingw32 --enable-static
$ make
$ make install
```

[libogg](https://www.xiph.org/ogg/)

```
$ ./configure --prefix=/usr/local/mingw32
$ make
$ make install
```

[libpng](http://www.libpng.org/pub/png/libpng.html)

```
$ ./configure --prefix=/usr/local/mingw32 \
CFLAGS="-W -Wall -O2 -I/usr/local/mingw32/include" \
CPPFLAGS="-I/usr/local/mingw32/include" \
LDFLAGS="-L/usr/local/mingw32/lib"
$ make
$ make install
```

[libtiff](http://simplesystems.org/libtiff/)

```
$ ./configure --prefix=/usr/local/mingw32 --build=mingw32 \
--with-zlib-include-dir=/usr/local/mingw32/include \
--with-zlib-lib-dir=/usr/local/mingw32/lib \
--with-jpeg-include-dir=/usr/local/mingw32/include \
--with-jpeg-lib-dir=/usr/local/mingw32/lib --disable-jbig
$ make
$ make install
```

[libvorbis](https://www.xiph.org/vorbis/)

```
$ ./configure --prefix=/usr/local/mingw32 \
--with-ogg-includes=/usr/local/mingw32/include \
--with-ogg-libraries=/usr/local/mingw32/lib
$ make
$ make install
```

[libwebp](https://developers.google.com/speed/webp/download)

```
$ cmake -G "MSYS Makefiles"
$ mkdir /usr/local/mingw32/include/webp
$ cp include/webp/* /usr/local/mingw32/include/webp
$ cp src/webp/* /usr/local/mingw32/include/webp
$ cp *.a /usr/local/mingw32/lib
```

[lua](http://www.lua.org/)

```
$ make mingw
$ make mingw install INSTALL_TOP=/usr/local/mingw32 TO_BIN=lua53.dll
```

[minIni](https://www.compuphase.com/minini.htm)

```
$ mingw32-gcc -O2 -Wall -c minIni.c -o minIni.o
$ ar rcs libminini.a minIni.o
$ mkdir /usr/local/mingw32/include/minINI
$ cp *.h /usr/local/mingw32/include/minINI
$ cp libminini.a /usr/local/mingw32/lib
```

[nuklear](https://github.com/vurtun/nuklear)

```
$ cp nuklear.h /usr/local/mingw32/include
```

[saneopt](https://github.com/mmalecki/saneopt)

```
$ make CC=mingw32-gcc
$ cp include/saneopt.h /usr/local/mingw32/include
$ cp libsaneopt.a /usr/local/mingw32/lib
```

[SDL_gpu](https://github.com/grimfang4/sdl-gpu)

```
$ cmake -G "MSYS Makefiles" -DCMAKE_INSTALL_PREFIX=--prefix=/usr/local/mingw32
$ make
$ mkdir /usr/local/mingw32/include/SDL
$ mkdir /usr/local/mingw32/include/SDL2
$ cp include/*.h /usr/local/mingw32/include/SDL
$ cp include/*.h /usr/local/mingw32/include/SDL2
$ cp src/*.a /usr/local/mingw32/lib
$ cp src/*.dll /usr/local/mingw32/bin
```

[SDL2](https://www.libsdl.org/) (версия 2.0.4)

```
$ ./configure --prefix=/usr/local/mingw32
$ make
$ make install
```

[SDL2_gfx](http://www.ferzkopp.net/wordpress/2016/01/02/sdl_gfx-sdl2_gfx/)

```
$ ./configure --prefix=/usr/local/mingw32 --disable-sdltest \
--with-sdl-prefix=/usr/local/mingw32 --host=mingw32 --build=mingw32
$ make
$ cp *.h /usr/local/mingw32/include/sdl2
$ cp .libs/libSDL2_gfx.a /usr/local/mingw32/lib
```

[SDL2_image](https://www.libsdl.org/projects/SDL_image/)

```
$ ./configure --prefix=/usr/local/mingw32 --build=mingw32 CC=mingw32-gcc \
CFLAGS="-Wall -O2 -I/usr/local/mingw32/include" \
CPPFLAGS="-Wall -O2 -I/usr/local/mingw32/include" \
LDFLAGS="-s -L/usr/local/mingw32/lib"
$ make
$ make install
```

[SDL2_mixer](https://www.libsdl.org/projects/SDL_mixer/)

```
$ ./configure --prefix=/usr/local/mingw32 --build=mingw32 --disable-static \
--disable-sdltest --disable-smpegtest \
CFLAGS="-O2 -Wall -I/usr/local/mingw32/include" \
CPPFLAGS="-I/usr/local/mingw32/include" \
LDFLAGS="-s -L/usr/local/mingw32/lib" --with-smpeg-prefix=/usr/local/mingw32 \
MODPLUG_CFLAGS="-O2 -Wall -I/usr/local/mingw32/include" \
MODPLUG_LIBS="-L/usr/local/mingw32/lib -lmodplug"
$ make
$ make install
$ make clean
$ ./configure --prefix=/usr/local/mingw32 --build=mingw32 \
--disable-shared --disable-music-mod-modplug-shared --disable-music-ogg-shared \
--disable-music-flac-shared --enable-music-mp3-smpeg-shared --disable-sdltest \
--disable-smpegtest CFLAGS="-O2 -Wall -I/usr/local/mingw32/include" \
CPPFLAGS="-I/usr/local/mingw32/include" \
LDFLAGS="-s -L/usr/local/mingw32/lib" \
--with-smpeg-prefix=/usr/local/mingw32 \
MODPLUG_CFLAGS="-O2 -Wall -I/usr/local/mingw32/include" \
MODPLUG_LIBS="-L/usr/local/mingw32/lib"
$ make
$ cp build/.libs/libSDL2_mixer.a /usr/local/mingw32/lib
```

[SDL2_ttf](https://www.libsdl.org/projects/SDL_ttf/)

```
$ ./configure --prefix=/usr/local/mingw32 --disable-sdltest \
--with-freetype-prefix=/usr/local/mingw32
$ make
$ make install
```

[smpeg2](https://www.libsdl.org/projects/smpeg/release/)

```
$ ./configure --prefix=/usr/local/mingw32 --disable-sdltest --disable-static
$ make
$ make install
```

[Squirrel](http://www.squirrel-lang.org/)

```
$ cmake -G "MSYS Makefiles" -DCMAKE_INSTALL_PREFIX="/usr/local/mingw32"
$ make
$ make install
$ cp include/* /usr/local/mingw32/include
```

[stb_image](https://github.com/nothings/stb)

```
$ cp stb_image.h /usr/local/mingw32/include
```

[stb_image_write](https://github.com/nothings/stb)

```
$ cp stb_image_write.h /usr/local/mingw32/include
```

[stb_rect_pack](https://github.com/nothings/stb)

```
$ cp stb_rect_pack.h /usr/local/mingw32/include
```

[tigr](https://bitbucket.org/rmitton/tigr/overview)

```
$ mingw32-gcc -o tigr.o -c tigr.c -Wall -O2 -D_WIN32_WINNT=0x0500
$ mingw32-gcc -o tigr.dll tigr.o -shared -s -Wl,--out-implib,libtigr.dll.a -ld3d9
$ ar rcs libtigr.a tigr.o
$ cp tigr.h /usr/local/mingw32/include
$ cp *.a /usr/local/mingw32/lib
$ cp tigr.dll /usr/local/mingw32/bin
```

[tinyfiledialogs](https://sourceforge.net/projects/tinyfiledialogs/) (похоже, что мой TDM GCC 5.1.0 использует стандартную библиотеку из GCC 4, поэтому без хака "-D__GNUC__=4" не собирается)

```
$ mingw32-gcc -c tinyfiledialogs.c -o tinyfiledialogs.o -O2 -Wall -D__GNUC__=4
$ mingw32-gcc -o tinyfiledialogs.dll tinyfiledialogs.o -shared -s \
-Wl,--out-implib,libtinyfiledialogs.dll.a -lcomdlg32 -lole32
$ ar rcs libtinyfiledialogs.a tinyfiledialogs.o
$ cp tinyfiledialogs.h /usr/local/mingw32/include
$ cp *.a /usr/local/mingw32/lib
$ cp tinyfiledialogs.dll /usr/local/mingw32/bin
```

[utf8](https://github.com/haipome/utf8)

```
$ mingw32-gcc -c utf8.c -o utf8.o -O2 -Wall
$ mingw32-gcc -shared -o utf8.dll utf8.o -s -Wl,--out-implib,libutf8.dll.a
$ ar rcs libutf8.a utf8.o
$ cp utf8.h /usr/local/mingw32/include
$ cp *.a /usr/local/mingw32/lib
$ cp utf8.dll /usr/local/mingw32/bin
```

[xz](https://tukaani.org/xz/) (liblzma)

```
$ ./configure --prefix=/usr/local/mingw32 --disable-xz --disable-xzdec
$ make
$ make install
```

[zlib](http://zlib.net/)

```
$ make -f win32/Makefile.gcc
$ make -f win32/Makefile.gcc install INCLUDE_PATH=/usr/local/mingw32/include \
LIBRARY_PATH=/usr/local/mingw32/lib BINARY_PATH=/usr/local/mingw32/bin \
SHARED_MODE=1
```
