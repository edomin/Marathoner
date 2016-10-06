#win32, html5
PLATFORM = win32
#static, plugin
MOD = plugin

ifeq ($(PLATFORM), win32)
	PREFIX = /usr/local/mingw32
	CC = mingw32-gcc
	LD = mingw32-gcc
	AR = mingw32-ar
	CFLAGS = -Wall -O2
	LDFLAGS = -s -mwindows
	ARFLAGS = rcs
	SO_PR =
	SO_EXT = .dll
	A_PR = lib
	A_EXT = .a
	EXE_EXT = .exe
endif
ifeq ($(PLATFORM), html5)
	PREFIX = /usr/local/emscripten
	CC = emcc
	LD = emcc
	AR = emar
	CFLAGS = -Wall -O2
	LDFLAGS = -O2
	ARFLAGS = rcs
	SO_PR = lib
	SO_EXT = .js
	A_PR = lib
	A_EXT = .a
	EXE_EXT = .html
endif

ifeq ($(MOD), static)
	CFLAGS += -DMTR_MOD_STATIC
endif
ifeq ($(MOD), plugin)
	CFLAGS += -DMTR_MOD_PLUGIN
endif
