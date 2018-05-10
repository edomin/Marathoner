### Building on Windows for Windows 32bit
This is my list of commands for building prereqisites. Every block of commands runs from directory of library extracted from archive.  
Before building you need to create directory /usr/local/mingw32 (\<path_to_msys2\>/usr/local/mingw32) and add path to compiler to PATH environment variable (and temporary delete paths to other compilers from PATH).  
For building I used toolchain MinGW-W64 i686 based on GCC 7.2.0.
Also for building of some libraries you need:  

* CMake (I use CMake 3.5.2)
* Python (I use Python 2.7.13)

[bzip2](http://www.bzip.org/)

```
$ make
$ make install PREFIX=/usr/local/i686-w64-mingw32
$ i686-w64-mingw32-gcc -shared -o libbz2.dll -Wl,--out-implib,libbz2.dll.a \
blocksort.o huffman.o crctable.o randtable.o compress.o decompress.o bzlib.o
$ cp libbz2.dll /usr/local/i686-w64-mingw32/bin
$ cp libbz2.dll.a /usr/local/i686-w64-mingw32/lib
```

[cJSON](https://github.com/DaveGamble/cJSON)

```
$ mkdir build
$ cd build
$ cmake .. -G "MSYS Makefiles" \
-DCMAKE_INSTALL_PREFIX="/usr/local/i686-w64-mingw32" \
-DENABLE_CJSON_TEST=Off -DBUILD_SHARED_LIBS=Off
$ make
$ make install
$ cd ..
$ rm -r -f build
```

[dr_wav](https://github.com/mackron/dr_libs)

```
$ cp dr_wav.h /usr/local/i686-w64-mingw32/include
```

[duktape](http://duktape.org/)

```
$ mkdir tmp
$ mkdir tmp/output
$ python tools/configure.py --output-directory ./tmp/output --rom-support --dll \
-DDUK_USE_FATAL_HANDLER
$ i686-w64-mingw32-gcc -Wall -mmmx -mfpmath=387 -O2 -o tmp/output/duktape.o \
-c tmp/output/duktape.c
$ i686-w64-mingw32-gcc -o tmp/output/duktape.dll -s -shared tmp/output/duktape.o \
-Wl,--out-implib,tmp/output/libduktape.dll.a
$ ar rcs tmp/output/libduktape.a tmp/output/duktape.o
$ i686-w64-mingw32-gcc -Wall -mmmx -mfpmath=387 -O2 \
-o tmp/output/duk_module_node.o \
-c extras/module-node/duk_module_node.c -Itmp/output
$ ar rcs tmp/output/libduk_module_node.a tmp/output/duk_module_node.o
$ cp tmp/output/*.h /usr/local/i686-w64-mingw32/include
$ cp extras/module-node/duk_module_node.h /usr/local/i686-w64-mingw32/include
$ cp tmp/output/*.a /usr/local/i686-w64-mingw32/lib
$ cp tmp/output/duktape.dll /usr/local/i686-w64-mingw32/bin
$ rm -r -f tmp
```

[Freetype](http://www.freetype.org)  
Dependencies: bzip2, libpng, zlib

```
$ ./configure --prefix=/usr/local/i686-w64-mingw32 --host=i686-w64-mingw32 \
BZIP2_CFLAGS="-I/usr/local/i686-w64-mingw32/include" \
BZIP2_LIBS="-L/usr/local/i686-w64-mingw32/lib -lbz2"
$ make
$ make install
```  
Dependencies: bzip2, harfbuzz, libpng, zlib

```
$ ./configure --prefix=/usr/local/i686-w64-mingw32 --host=i686-w64-mingw32 \
BZIP2_CFLAGS="-I/usr/local/i686-w64-mingw32/include" \
BZIP2_LIBS="-L/usr/local/i686-w64-mingw32/lib -lbz2"
$ make
$ make install
```

[GIFLIB](http://giflib.sourceforge.net/)

```
$ ./configure --prefix=/usr/local/i686-w64-mingw32 --host=i686-w64-mingw32
$ make
$ make install
```

[GLib](https://ftp.gnome.org/pub/gnome/sources/glib/)  
Dependencies: libffi, libiconv, libintl, zlib

```
$ export PKG_CONFIG_PATH=$PKG_CONFIG_PATH:/usr/local/i686-w64-mingw32/lib/pkgconfig
$ ./configure --prefix=/usr/local/i686-w64-mingw32 --host=i686-w64-mingw32 \
--disable-gtk-doc-html --with-threads=posix --with-pcre=internal \
CPPFLAGS="-I/usr/local/i686-w64-mingw32/include" \
LDFLAGS="-L/usr/local/i686-w64-mingw32/lib"
$ make
$ make install
```

[HarfBuzz](https://www.freedesktop.org/wiki/Software/HarfBuzz/)  
Dependencies: Freetype, GLib, ICU

```
$ export PKG_CONFIG_PATH=$PKG_CONFIG_PATH:/usr/local/i686-w64-mingw32/lib/pkgconfig
$ ./configure --prefix=/usr/local/i686-w64-mingw32 --host=i686-w64-mingw32 \
--enable-static --disable-gtk-doc-html --with-glib --with-gobject --with-icu \
--with-freetype
$ make
$ make install
```

[ICU](http://site.icu-project.org/download)

```
$ cd source
$ ./configure --prefix=/usr/local/i686-w64-mingw32 --enable-static=yes \
--with-library-bits=32 --build=i686-w64-mingw32 --host=i686-w64-mingw32
$ make
$ make install
```

[inih](https://github.com/benhoyt/inih)

```
$ i686-w64-mingw32-gcc -c ini.c -o ini.o -O2 -Wall -DINI_ALLOW_MULTILINE=0 \
-DINI_STOP_ON_FIRST_ERROR=1 -DINI_HANDLER_LINENO=1 -DINI_ALLOW_REALLOC=1 \
-DINI_USE_STACK=0
$ ar rcs libinih.a ini.o
$ cp ini.h /usr/local/i686-w64-mingw32/include
$ cp libinih.a /usr/local/i686-w64-mingw32/lib
```

[JPEG](http://www.ijg.org/files/)

```
$ ./configure --prefix=/usr/local/i686-w64-mingw32
$ make
$ make install
```

[lazy-winapi.c](https://github.com/DoumanAsh/lazy-winapi.c)

```
$ mkdir build
$ cd build
$ cmake .. -G "MSYS Makefiles" -DCMAKE_INSTALL_PREFIX=/usr/local/i686-w64-mingw32
$ make
$ cp ../src/lazy_winapi.h /usr/local/i686-w64-mingw32/include
$ mkdir /usr/local/i686-w64-mingw32/include/lazy_winapi
$ cp ../src/lazy_winapi/*.h /usr/local/i686-w64-mingw32/include/lazy_winapi
$ cp liblazy_winapi.a /usr/local/i686-w64-mingw32/lib
$ cd ..
$ rm -r -f build
```

[libffi](https://sourceware.org/libffi/)

```
$ ./configure --prefix=/usr/local/i686-w64-mingw32 --build=i686-w64-mingw32 \
--host=i686-w64-mingw32 --with-gcc-arch=i686
$ make
$ make install
```

[libFLAC](https://xiph.org/flac/)  
Dependencies: libogg

```
$ ./configure --prefix=/usr/local/i686-w64-mingw32 --host=i686-w64-mingw32 \
--enable-static --disable-xmms-plugin --disable-oggtest \
--with-ogg-includes=/usr/local/i686-w64-mingw32/include \
--with-ogg-libraries=/usr/local/i686-w64-mingw32/lib --disable-doxygen-docs \
--disable-cpplibs
$ make
$ make install
```

[libiconv](https://www.gnu.org/software/libiconv/)

```
$ ./configure --prefix=/usr/local/i686-w64-mingw32 --host=i686-w64-mingw32 \
--enable-extra-encodings CC=i686-w64-mingw32-gcc \
CPPFLAGS="-I/usr/local/i686-w64-mingw32/include -Wall" \
LDFLAGS="-L/usr/local/i686-w64-mingw32/lib"
$ make
$ make install
```

[libintl](https://www.gnu.org/software/gettext/)  
Dependencies: libiconv

```
$ cd gettext-runtime
$ ./configure --prefix=/usr/local/i686-w64-mingw32 --host=i686-w64-mingw32 \
--disable-java --disable-native-java --disable-csharp --enable-threads=posix \
--enable-shared --disable-static --disable-libasprintf
$ make
$ make install
```

[libintl-lite](https://github.com/j-jorge/libintl-lite)

```
$ mkdir build
$ cd build
$ cmake .. -G "MSYS Makefiles" -DCMAKE_INSTALL_PREFIX=/usr/local/i686-w64-mingw32
$ make
$ make install
$ cd ..
$ rm -r -f build
```

[liblzma](https://tukaani.org/xz/)

```
$ ./configure --prefix=/usr/local/i686-w64-mingw32 --host=i686-w64-mingw32 \
--disable-xz --disable-xzdec
$ make
$ make install
```

[libmodplug](https://sourceforge.net/projects/modplug-xmms/)

```
$ ./configure --prefix=/usr/local/i686-w64-mingw32 --host=i686-w64-mingw32 \
--enable-shared
$ make
$ make install
```

[libmpg123](http://www.mpg123.org/)

```
$ ./configure --prefix=/usr/local/i686-w64-mingw32 --host=i686-w64-mingw32
$ make
$ make install
```

[libogg](https://www.xiph.org/ogg/)

```
$ ./configure --prefix=/usr/local/i686-w64-mingw32 --host=i686-w64-mingw32
$ make
$ make install
```

[libpng](http://www.libpng.org/pub/png/libpng.html)  
Dependencies: zlib

```
$ ./configure --prefix=/usr/local/i686-w64-mingw32 --host=i686-w64-mingw32 \
CPPFLAGS="-I/usr/local/i686-w64-mingw32/include" \
LDFLAGS="-L/usr/local/i686-w64-mingw32/lib"
$ make
$ make install
```

[libtiff](http://simplesystems.org/libtiff/)  
Dependencies: JPEG, liblzma, zlib

```
$ mkdir tmp
$ cd tmp
$ cmake .. -G "MSYS Makefiles" -DCMAKE_INSTALL_PREFIX=/usr/local/i686-w64-mingw32
$ make
$ make install
$ cd ..
$ rm -r -f tmp
```

[libvorbis](https://www.xiph.org/vorbis/)  
Dependencies: libogg

```
$ ./configure --prefix=/usr/local/i686-w64-mingw32 --host=i686-w64-mingw32 \
--with-ogg-includes=/usr/local/i686-w64-mingw32/include \
--with-ogg-libraries=/usr/local/i686-w64-mingw32/lib
$ make
$ make install
```

[libwebp](https://developers.google.com/speed/webp/download)  
Dependencies: GIFLIB, JPEG, libpng, libTIFF, zlib

```
$ mkdir build
$ cd build
$ cmake .. -G "MSYS Makefiles" \
-DCMAKE_INSTALL_PREFIX=/usr/local/i686-w64-mingw32
$ make
$ mkdir /usr/local/i686-w64-mingw32/include/webp
$ cp ../src/webp/* /usr/local/i686-w64-mingw32/include/webp
$ cp src/webp/* /usr/local/i686-w64-mingw32/include/webp
$ cp *.a /usr/local/i686-w64-mingw32/lib
$ rm -r -f ./*
$ cmake .. -G "MSYS Makefiles" \
-DCMAKE_INSTALL_PREFIX=/usr/local/i686-w64-mingw32 \
-DBUILD_SHARED_LIBS=ON
$ cp *.a /usr/local/i686-w64-mingw32/lib
$ cp *.dll /usr/local/i686-w64-mingw32/bin
$ cd ..
$ rm -r -f build
```

[Lua](http://www.lua.org/)

```
$ make mingw
$ make mingw install INSTALL_TOP=/usr/local/i686-w64-mingw32
$ make mingw install INSTALL_TOP=/usr/local/i686-w64-mingw32 TO_BIN=lua53.dll
```

[minIni](https://www.compuphase.com/minini.htm)

```
$ i686-w64-mingw32-gcc -O2 -Wall -c minIni.c -o minIni.o
$ ar rcs libminini.a minIni.o
$ mkdir /usr/local/i686-w64-mingw32/include/minINI
$ cp *.h /usr/local/i686-w64-mingw32/include/minINI
$ cp libminini.a /usr/local/i686-w64-mingw32/lib
```

[nuklear](https://github.com/vurtun/nuklear)

```
$ cp nuklear.h /usr/local/i686-w64-mingw32/include
```

[PhysicsFS](https://icculus.org/physfs/)

```
$ mkdir build
$ cd build
$ cmake .. -G "MSYS Makefiles" -DCMAKE_INSTALL_PREFIX=/usr/local/i686-w64-mingw32
$ make
$ make install
$ cd ..
$ rm -r -f build
```

[PortAudio](http://www.portaudio.com/)

```
$ ./configure --prefix=/usr/local/i686-w64-mingw32 --build=i686-w64-mingw32
$ make
$ make install
```

[saneopt](https://github.com/mmalecki/saneopt)

```
$ make CC=i686-w64-mingw32-gcc
$ cp include/saneopt.h /usr/local/i686-w64-mingw32/include
$ cp libsaneopt.a /usr/local/i686-w64-mingw32/lib
```

[SDL2_gpu](https://github.com/grimfang4/sdl-gpu)  
Dependencies: SDL2

```
$ mkdir build
$ cd build
$ cmake .. -G "MSYS Makefiles" -DCMAKE_INSTALL_PREFIX=/usr/local/i686-w64-mingw32
$ make
$ mkdir /usr/local/i686-w64-mingw32/include/SDL
$ mkdir /usr/local/i686-w64-mingw32/include/SDL2
$ cp lib/include/*.h /usr/local/i686-w64-mingw32/include/SDL
$ cp lib/include/*.h /usr/local/i686-w64-mingw32/include/SDL2
$ cp lib/*.a /usr/local/i686-w64-mingw32/lib
$ cp bin/libSDL2_gpu.dll /usr/local/i686-w64-mingw32/bin
$ cd ..
$ rm -r -f build
```

[SDL2](https://www.libsdl.org/) (версия 2.0.4)

```
$ ./configure --prefix=/usr/local/i686-w64-mingw32 --host=i686-w64-mingw32
$ make
$ make install
```

[SDL2_gfx](http://www.ferzkopp.net/wordpress/2016/01/02/sdl_gfx-sdl2_gfx/)  
Dependencies: SDL2

```
$ ./configure --prefix=/usr/local/i686-w64-mingw32 --build=i686-w64-mingw32 \
--host=i686-w64-mingw32 --disable-sdltest \
--with-sdl-prefix=/usr/local/i686-w64-mingw32
$ make
$ make install
$ i686-w64-mingw32-gcc -shared -o .libs/SDL2_gfx.dll \
-Wl,--out-implib,.libs/libSDL2_gfx.dll.a .libs/SDL2_framerate.o \
.libs/SDL2_gfxPrimitives.o .libs/SDL2_imageFilter.o .libs/SDL2_rotozoom.o \
-L/usr/local/i686-w64-mingw32/lib -lSDL2.dll
$ cp .libs/SDL2_gfx.dll /usr/local/i686-w64-mingw32/bin
$ cp .libs/libSDL2_gfx.dll.a /usr/local/i686-w64-mingw32/lib
```

[SDL2_image](https://www.libsdl.org/projects/SDL_image/)  
Dependencies: libjpeg, libpng, libtiff, libwebp, SDL2

```
$ ./configure --prefix=/usr/local/i686-w64-mingw32 --build=i686-w64-mingw32 \
CC=i686-w64-mingw32-gcc \
CFLAGS="-Wall -O2 -I/usr/local/i686-w64-mingw32/include -I/usr/local/i686-w64-mingw32/include/SDL2" \
CPPFLAGS="-Wall -O2 -I/usr/local/i686-w64-mingw32/include" \
LDFLAGS="-s -L/usr/local/i686-w64-mingw32/lib" \
SDL_CFLAGS="-I/usr/local/i686-w64-mingw32/include" \
SDL_LIBS="-L/usr/local/i686-w64-mingw32/lib -lSDL2.dll"
$ make
$ cp SDL_image.h /usr/local/i686-w64-mingw32/include/SDL2
$ cp .libs/*.a /usr/local/i686-w64-mingw32/lib
$ cp .libs/SDL2_image.dll /usr/local/i686-w64-mingw32/bin
```

[SDL2_mixer](https://www.libsdl.org/projects/SDL_mixer/)  
Dependencies: libFLAC, libmodplug, libmpg123, libogg, libvorbis, SDL2

```
$ ./configure --prefix=/usr/local/i686-w64-mingw32 --build=i686-w64-mingw32 \
--disable-sdltest --disable-smpegtest \
--with-smpeg-prefix=/usr/local/i686-w64-mingw32 \
CFLAGS="-O2 -Wall -I/usr/local/i686-w64-mingw32/include" \
CPPFLAGS="-I/usr/local/i686-w64-mingw32/include" \
LDFLAGS="-s -L/usr/local/i686-w64-mingw32/lib" \
MODPLUG_CFLAGS="-O2 -Wall -I/usr/local/i686-w64-mingw32/include" \
MODPLUG_LIBS="-L/usr/local/i686-w64-mingw32/lib -lmodplug"
$ make
$ make install
```

[SDL2_ttf](https://www.libsdl.org/projects/SDL_ttf/)  
Dependencies: Freetype, SDL2

```
$ ./configure --prefix=/usr/local/i686-w64-mingw32 --build=i686-w64-mingw32 \
--host=i686-w64-mingw32 --disable-sdltest \
--with-freetype-prefix=/usr/local/i686-w64-mingw32 \
CPPFLAGS="-I/usr/local/i686-w64-mingw32/include/freetype2" \
LDFLAGS="-L/usr/local/i686-w64-mingw32/lib" LIBS="-lfreetype"
$ make
$ make install
```

[Squirrel](http://www.squirrel-lang.org/)

```
$ mkdir build
$ cd build
$ cmake .. -G "MSYS Makefiles" \
-DCMAKE_INSTALL_PREFIX="/usr/local/i686-w64-mingw32"
$ make
$ make install
$ cp ../include/* /usr/local/i686-w64-mingw32/include
$ cd ..
$ rm -r -f build
```

[stb_rect_pack](https://github.com/nothings/stb)

```
$ cp stb_rect_pack.h /usr/local/i686-w64-mingw32/include
```

[tigr](https://bitbucket.org/rmitton/tigr/overview)

```
$ i686-w64-mingw32-gcc -o tigr.o -c tigr.c -Wall -O2 -D_WIN32_WINNT=0x0500
$ ar rcs libtigr.a tigr.o
$ cp tigr.h /usr/local/i686-w64-mingw32/include
$ cp libtigr.a /usr/local/i686-w64-mingw32/lib
```

[tinyfiledialogs](https://sourceforge.net/projects/tinyfiledialogs/)

```
$ i686-w64-mingw32-gcc -c tinyfiledialogs.c -o tinyfiledialogs.o -O2 -Wall
$ i686-w64-mingw32-gcc -o tinyfiledialogs.dll tinyfiledialogs.o -shared -s \
-Wl,--out-implib,libtinyfiledialogs.dll.a -lcomdlg32 -lole32
$ ar rcs libtinyfiledialogs.a tinyfiledialogs.o
$ cp tinyfiledialogs.h /usr/local/i686-w64-mingw32/include
$ cp *.a /usr/local/i686-w64-mingw32/lib
$ cp tinyfiledialogs.dll /usr/local/i686-w64-mingw32/bin
```

[utf](https://github.com/andlabs/utf)

```
$ i686-w64-mingw32-gcc -Wall -O2 -c utf.c -o utf.o
$ ar rcs libutf.a utf.o
$ cp utf.h /usr/local/i686-w64-mingw32/include
$ cp libutf.a /usr/local/i686-w64-mingw32/lib
```

[utf8](https://github.com/haipome/utf8)

```
$ i686-w64-mingw32-gcc -c utf8.c -o utf8.o -O2 -Wall
$ i686-w64-mingw32-gcc -shared -o utf8.dll utf8.o -s \
-Wl,--out-implib,libutf8.dll.a
$ ar rcs libutf8.a utf8.o
$ cp utf8.h /usr/local/i686-w64-mingw32/include
$ cp *.a /usr/local/i686-w64-mingw32/lib
$ cp utf8.dll /usr/local/i686-w64-mingw32/bin
```

[zlib](http://zlib.net/)

```
$ make -f win32/Makefile.gcc
$ make -f win32/Makefile.gcc install \
INCLUDE_PATH=/usr/local/i686-w64-mingw32/include \
LIBRARY_PATH=/usr/local/i686-w64-mingw32/lib \
BINARY_PATH=/usr/local/i686-w64-mingw32/bin \
SHARED_MODE=1
$ sed -i 's:prefix=/usr/local:prefix=/usr/local/i686-w64-mingw32:g' \
/usr/local/i686-w64-mingw32/lib/pkgconfig/zlib.pc
```
