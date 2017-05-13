#win32, win64, html5
PLATFORM = win32
#static, plugin
MOD = plugin
# yes, no
DEBUG = yes
# yes, no
MORE_WARNINGS = yes

ifeq ($(PLATFORM), win32)
	PREFIX = /usr/local/mingw32
	CC = mingw32-gcc
	LD = mingw32-gcc
	AR = mingw32-gcc-ar
	RC = windres
	CFLAGS = -Wall -Wextra -Wno-unused-parameter -Wshadow -Werror -mmmx \
	 -mfpmath=387
	ifeq ($(MORE_WARNINGS), yes)
        CFLAGS += -Wdouble-promotion -Wformat-security -Wformat-signedness \
         -Wswitch-default -Wuninitialized -Wsuggest-attribute=const \
         -Wfloat-equal -Wdeclaration-after-statement -Wundef \
         -Wbad-function-cast -Wcast-qual -Wlogical-op -Wredundant-decls -Wvla
	endif
	LDFLAGS = -mwindows
	ifeq ($(DEBUG), no)
        CFLAGS += -O2 -Wdisabled-optimization
        LDFLAGS += -s
	endif
	ifeq ($(DEBUG), yes)
        CFLAGS += -ggdb3 -fvar-tracking
	endif
	ARFLAGS = rcs
	RCFLAGS = -O coff
	SO_PR =
	SO_EXT = .dll
	A_PR = lib
	A_EXT = .a
	EXE_EXT = .exe
endif
ifeq ($(PLATFORM), win64)
	PREFIX = /usr/local/x86_64-w64-mingw32
	CC = x86_64-w64-mingw32-gcc
	LD = x86_64-w64-mingw32-gcc
	AR = x86_64-w64-mingw32-gcc-ar
	RC = windres
	CFLAGS = -Wall -Wextra -Wno-unused-parameter -Wshadow -Werror -mmmx -msse \
	 -msse2 -mfpmath=sse
	ifeq ($(MORE_WARNINGS), yes)
        CFLAGS += -Wdouble-promotion -Wformat-security -Wformat-signedness \
         -Wswitch-default -Wuninitialized -Wsuggest-attribute=const \
         -Wfloat-equal -Wdeclaration-after-statement -Wundef \
         -Wbad-function-cast -Wcast-qual -Wlogical-op -Wredundant-decls -Wvla
	endif
	LDFLAGS = -mwindows
	ifeq ($(DEBUG), no)
        CFLAGS += -O2 -Wdisabled-optimization
        LDFLAGS += -s
	endif
	ifeq ($(DEBUG), yes)
        CFLAGS += -ggdb3 -fvar-tracking
	endif
	ARFLAGS = rcs
	RCFLAGS = -O coff
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
