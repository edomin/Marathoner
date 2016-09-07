#win32, html5
PLATFORM = html5

ifeq ($(PLATFORM), win32)
	PREFIX = /usr/local/mingw32
	CC = mingw32-gcc
	LD = mingw32-gcc
	CFLAGS = -Wall -O2
	LDFLAGS = -s -mwindows
	SO_PR =
	SO_EXT = .dll
	EXE_EXT = .exe
endif
ifeq ($(PLATFORM), html5)
	PREFIX = /usr/local/emscripten
	CC = emcc
	LD = emcc
	CFLAGS = -Wall -O2
	LDFLAGS = -O2
	SO_PR = lib
	SO_EXT = .js
	EXE_EXT = .html
endif
