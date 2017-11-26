#win32, win64, html5
PLATFORM = win32
#static, plugin
MOD = plugin
# yes, no
DEBUG = yes
# yes, no
MORE_WARNINGS = yes
# Emscripten only. How many bytes are available for application
MEMORY = 134217728

ifeq ($(MOD), plugin)
  ifeq ($(PLATFORM), html5)
    $(error Plugin-based build currently not supported for html5 platform)
  endif
endif

ifeq ($(OS), Windows_NT)
  ifeq ($(PROCESSOR_ARCHITECTURE), x86)
    HOST = win32
  endif
  ifeq ($(PROCESSOR_ARCHITECTURE), AMD64)
    HOST = win64
  endif
endif

ifeq ($(HOST_BUILD), yes)
  PLATFORM = $(HOST)
  ifeq ($(HOST), win32)
    HOST_EXE_EXT = .exe
  endif
  ifeq ($(HOST), win64)
    HOST_EXE_EXT = .exe
  endif
endif

ifneq ($(NUMBER_OF_PROCESSORS),)
  CORES = $(NUMBER_OF_PROCESSORS)
else
  CORES = 1
endif

ifeq ($(PLATFORM), win32)
  PREFIX = /usr/local/mingw32
  CC = mingw32-gcc
  LD = mingw32-gcc
  AR = ar
  RC = mingw32-windres
  CFLAGS = -Wall -Wextra -Wno-unused-parameter -Wshadow -Werror -mmmx \
   -mfpmath=387
  ifeq ($(MORE_WARNINGS), yes)
    CFLAGS += -Wbad-function-cast -Wcast-qual \
     -Wdeclaration-after-statement -Wdouble-promotion -Wfloat-equal \
     -Wformat-nonliteral -Wformat-security -Wformat-signedness -Winit-self \
     -Wlogical-op -Wredundant-decls -Wswitch-default -Wuninitialized \
     -Wundef -Wvla
  endif
  LDFLAGS = -mwindows
  ifeq ($(DEBUG), no)
    CFLAGS += -O2 -Wdisabled-optimization
    LDFLAGS += -s
  endif
  ifeq ($(DEBUG), yes)
    CFLAGS += -O0 -ggdb3 -fvar-tracking
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
  RC = x86_64-w64-mingw32-windres
  CFLAGS = -Wall -Wextra -Wno-unused-parameter -Wshadow -Werror -mmmx -msse \
   -msse2 -mfpmath=sse
  ifeq ($(MORE_WARNINGS), yes)
    CFLAGS += -Wbad-function-cast -Wcast-qual \
     -Wdeclaration-after-statement -Wdouble-promotion \
     -Wduplicated-cond -Wfloat-equal \
     -Wformat-nonliteral -Wformat-security -Wformat-signedness -Winit-self \
     -Wlogical-op -Wmisleading-indentation -Wnull-dereference \
     -Wredundant-decls -Wshift-overflow=2 -Wswitch-default -Wuninitialized \
     -Wundef -Wvla
  endif
  LDFLAGS = -mwindows
  ifeq ($(DEBUG), no)
    CFLAGS += -O2 -Wdisabled-optimization
    LDFLAGS += -s
  endif
  ifeq ($(DEBUG), yes)
    CFLAGS += -O0 -ggdb3 -fvar-tracking
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
  CFLAGS = -Wall -Wextra -Wno-unused-parameter -Wshadow -Werror -s EMTERPRETIFY=1 -s EMTERPRETIFY_ASYNC=1
  ifeq ($(MORE_WARNINGS), yes)
    CFLAGS += -Wbad-function-cast -Wcast-qual -Wdeclaration-after-statement \
     -Wdouble-promotion -Wfloat-equal -Wformat-nonliteral -Wformat-security \
     -Winit-self -Wnull-dereference -Wredundant-decls -Wshift-overflow \
     -Wswitch-default -Wuninitialized -Wundef -Wvla
  endif
  LDFLAGS = --output_eol linux -s TOTAL_MEMORY=$(MEMORY) -s ABORTING_MALLOC=0 \
   -s ERROR_ON_UNDEFINED_SYMBOLS=1 -s ERROR_ON_MISSING_LIBRARIES=1 \
   -s EMTERPRETIFY=1 -s EMTERPRETIFY_ASYNC=1 -s SAFE_HEAP=1
  ifeq ($(DEBUG), no)
    CFLAGS += -O2 -Wdisabled-optimization
    LDFLAGS += -O2 -s ASSERTIONS=1
  endif
  ifeq ($(DEBUG), yes)
    CFLAGS += -O0 -g
    LDFLAGS += -O0 -g3 -s ASSERTIONS=2 \
     -s STACK_OVERFLOW_CHECK=2 -s ALIASING_FUNCTION_POINTERS=0
	#Not creating source maps for modules with -g4 flag
  endif
  ARFLAGS = rcs
  SO_PR = lib
  SO_EXT = .js
  A_PR = lib
  A_EXT = .a
  EXE_EXT = .html
endif

ifeq ($(MOD), static)
  CFLAGS += -DMTR_MOD_STATIC
  LDFLAGS += -Wl,-Bstatic
endif
ifeq ($(MOD), plugin)
  CFLAGS += -DMTR_MOD_PLUGIN
endif
