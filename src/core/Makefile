include ../../makefiles/Build.mk

ifeq ($(PLATFORM), win32)
  LDEXFLAGS = -L$(PREFIX)/lib
endif
ifeq ($(PLATFORM), win64)
  LDEXFLAGS = -L$(PREFIX)/lib
endif
ifeq ($(PLATFORM), linux_x86_64)
  LDEXFLAGS = -L$(PREFIX)/lib
endif
ifeq ($(PLATFORM), html5)
  LDEXFLAGS = -L$(PREFIX)/lib
#  LDEXFLAGS = -L$(PREFIX)/lib -s MAIN_MODULE=1
endif
ROOTDIR = ../..
OBJSDIR = $(ROOTDIR)/$(PLATFORM)/obj
BINDIR = $(ROOTDIR)/$(PLATFORM)
LIBDIR = $(ROOTDIR)/$(PLATFORM)/lib
FADIR = $(ROOTDIR)/$(PLATFORM)/fa
RCDIR = $(ROOTDIR)/$(PLATFORM)/rc
INCDIRS = -I$(PREFIX)/include -I$(ROOTDIR)/include -I$(ROOTDIR)/$(PLATFORM)
ifeq ($(MOD), static)
  LDEXFLAGS += -L$(LIBDIR)
endif

FAGEN = $(ROOTDIR)/$(HOST)/fagen

MTR_OBJS = $(OBJSDIR)/engine.o \
 $(OBJSDIR)/log.o \
 $(OBJSDIR)/messagebox.o \
 $(OBJSDIR)/notification.o \
 $(OBJSDIR)/configfile.o \
 $(OBJSDIR)/indexkeeper.o \
 $(OBJSDIR)/encoding.o \
 $(OBJSDIR)/file.o \
 $(OBJSDIR)/clipboard.o \
 $(OBJSDIR)/string_buffer.o \
 $(OBJSDIR)/version.o \
 $(OBJSDIR)/console.o \
 $(OBJSDIR)/fa.o

ifneq ($(PLATFORM), html5)
  MTR_OBJS += $(OBJSDIR)/options.o
endif

ifeq ($(MOD), plugin)
  MTR_OBJS += $(OBJSDIR)/directory.o \
   $(OBJSDIR)/so.o \
   $(OBJSDIR)/plugin_loader.o \
   $(OBJSDIR)/module.o
endif

LCHR_OBJS = $(OBJSDIR)/launcher.o \
 $(OBJSDIR)/log.o \
 $(OBJSDIR)/messagebox.o \
 $(OBJSDIR)/notification.o \
 $(OBJSDIR)/configfile.o \
 $(OBJSDIR)/indexkeeper.o \
 $(OBJSDIR)/directory.o \
 $(OBJSDIR)/clipboard.o \
 $(OBJSDIR)/plugin_loader.o \
 $(OBJSDIR)/console.o \
 $(OBJSDIR)/so.o

ifeq ($(PLATFORM), win32)
  MTR_OBJS += $(OBJSDIR)/engine.res
  LCHR_OBJS += $(OBJSDIR)/launcher.res
endif
ifeq ($(PLATFORM), win64)
  MTR_OBJS += $(OBJSDIR)/engine.res
  LCHR_OBJS += $(OBJSDIR)/launcher.res
endif

ifeq ($(MOD), static)
  LIBS_TXT = $(shell ls $(LIBDIR) | grep 'txt$$' | grep '^Script' | sed -e 's%^%$(LIBDIR)/%')
  LIBS_TXT += $(shell ls $(LIBDIR) | grep 'txt$$' | grep -v '^Script' | sed -e 's%^%$(LIBDIR)/%')
  nullstring :=
  space := $(nullstring)
  ifneq ($(PLATFORM), html5)
  LIBS = $(shell cat $(LIBS_TXT) | grep -E -o "(\+|\.|\=|\,|\[|\]|'|\w)*" | sed -e 's%^%-%' | tr '$(space)' '\n' | awk '!x[$$0]++')
  endif
  ifeq ($(PLATFORM), html5)
  LIBS = $(shell cat $(LIBS_TXT))
  endif
  MOD_OBJS = $(shell cat $(OBJSDIR)/objs.txt)
endif

TARGETS = $(BINDIR)/Marathoner
ifeq ($(MOD), plugin)
  ifneq ($(PLATFORM), linux_x86_64)
    TARGETS += $(BINDIR)/Launcher
  endif
endif

all: $(TARGETS)

$(BINDIR)/Marathoner: $(MTR_OBJS)
ifeq ($(MOD), static)
  ifeq ($(PLATFORM), win32)
	$(LD) $(LDFLAGS) $(LDEXFLAGS) -o $(BINDIR)/Marathoner$(EXE_EXT) \
	 $(MTR_OBJS) $(MOD_OBJS) -lminini -lutf -ltinyfiledialogs -lole32 \
	 -lshlwapi -llazy_winapi -lsaneopt $(LIBS)
  endif
  ifeq ($(PLATFORM), win64)
	$(LD) $(LDFLAGS) $(LDEXFLAGS) -o $(BINDIR)/Marathoner$(EXE_EXT) \
	 $(MTR_OBJS) $(MOD_OBJS) -lminini -lutf -ltinyfiledialogs -lole32 \
	 -lshlwapi -llazy_winapi -lsaneopt $(LIBS)
  endif
  ifeq ($(PLATFORM), linux_x86_64)
	$(LD) $(LDFLAGS) $(LDEXFLAGS) -o $(BINDIR)/Marathoner$(EXE_EXT) \
	 $(MTR_OBJS) $(MOD_OBJS) -lminini -lutf -ltinyfiledialogs -lsaneopt $(LIBS)
  endif
  ifeq ($(PLATFORM), html5)
	$(LD) $(LDFLAGS) $(LDEXFLAGS) -o $(BINDIR)/Marathoner$(EXE_EXT) \
	 $(MTR_OBJS) $(MOD_OBJS) -lminini -lutf $(LIBS) \
	 --preload-file ../../Marathoner.cfg@/ \
	 --preload-file ../../autorun@/autorun
  endif
endif
ifeq ($(MOD), plugin)
  ifeq ($(PLATFORM), win32)
	$(LD) $(LDFLAGS) $(LDEXFLAGS) -o $(BINDIR)/Marathoner$(EXE_EXT) \
	 $(MTR_OBJS) -lminini -Wl,-Bstatic -lutf -Wl,-Bstatic -ltinyfiledialogs \
	 -lole32 -lshlwapi -llazy_winapi -lsaneopt
  endif
  ifeq ($(PLATFORM), win64)
	$(LD) $(LDFLAGS) $(LDEXFLAGS) -o $(BINDIR)/Marathoner$(EXE_EXT) \
	 $(MTR_OBJS) -lminini -Wl,-Bstatic -lutf -Wl,-Bstatic -ltinyfiledialogs \
	 -lole32 -lshlwapi -llazy_winapi -lsaneopt
  endif
  ifeq ($(PLATFORM), linux_x86_64)
	$(LD) $(LDFLAGS) $(LDEXFLAGS) -o $(BINDIR)/Marathoner$(EXE_EXT) \
	 $(MTR_OBJS) -ldl -lminini -lutf -ltinyfiledialogs -lsaneopt
  endif
#  ifeq ($(PLATFORM), html5)
#	$(LD) $(LDFLAGS) $(LDEXFLAGS) -o $(BINDIR)/Marathoner$(EXE_EXT) \
#	 $(MTR_OBJS) -lminini -lutf8 \
#	 --preload-file ../../Marathoner.cfg@/ \
#	 --preload-file ../../autorun@/autorun
#  endif
endif

$(BINDIR)/Launcher: $(LCHR_OBJS)
ifeq ($(MOD), plugin)
  ifeq ($(PLATFORM), win32)
	$(LD) $(LDFLAGS) $(LDEXFLAGS) -o $(BINDIR)/Launcher$(EXE_EXT) \
	 $(LCHR_OBJS) -lminini -Wl,-Bstatic -ltigr -ld3d9 -llazy_winapi \
	 -Wl,-Bstatic -ltinyfiledialogs -lole32 -lshlwapi
  endif
  ifeq ($(PLATFORM), win64)
	$(LD) $(LDFLAGS) $(LDEXFLAGS) -o $(BINDIR)/Launcher$(EXE_EXT) \
	 $(LCHR_OBJS) -lminini -Wl,-Bstatic -ltigr -ld3d9 -llazy_winapi \
	 -Wl,-Bstatic -ltinyfiledialogs -lole32 -lshlwapi
  endif
endif

$(OBJSDIR)/launcher.o: launcher.c launcher.h
	$(CC) $(CFLAGS) -Wno-unused-function $(INCDIRS) -c launcher.c \
	 -o $(OBJSDIR)/launcher.o

$(OBJSDIR)/engine.o: engine.c log.h notification.h configfile.h messagebox.h \
 indexkeeper.h file.h directory.h encoding.h clipboard.h string_buffer.h so.h \
 fa.h plugin_loader.h options.h version.h console.h module.h \
 $(ROOTDIR)/include/marathoner/engine.h
	$(CC) $(CFLAGS) $(INCDIRS) -c engine.c -o $(OBJSDIR)/engine.o

$(OBJSDIR)/log.o: log.c log.h
	$(CC) $(CFLAGS) $(INCDIRS) -c log.c -o $(OBJSDIR)/log.o

$(OBJSDIR)/messagebox.o: messagebox.c messagebox.h
	$(CC) $(CFLAGS) $(INCDIRS) -c messagebox.c -o $(OBJSDIR)/messagebox.o

$(OBJSDIR)/notification.o: notification.c notification.h
	$(CC) $(CFLAGS) $(INCDIRS) -c notification.c -o $(OBJSDIR)/notification.o

$(OBJSDIR)/configfile.o: configfile.c configfile.h
	$(CC) $(CFLAGS) $(INCDIRS) -c configfile.c -o $(OBJSDIR)/configfile.o

$(OBJSDIR)/indexkeeper.o: indexkeeper.c indexkeeper.h
	$(CC) $(CFLAGS) $(INCDIRS) -c indexkeeper.c -o $(OBJSDIR)/indexkeeper.o

$(OBJSDIR)/encoding.o: encoding.c encoding.h
	$(CC) $(CFLAGS) $(INCDIRS) -c encoding.c -o $(OBJSDIR)/encoding.o

$(OBJSDIR)/file.o: file.c file.h
	$(CC) $(CFLAGS) $(INCDIRS) -c file.c -o $(OBJSDIR)/file.o

$(OBJSDIR)/directory.o: directory.c directory.h
	$(CC) $(CFLAGS) $(INCDIRS) -c directory.c -o $(OBJSDIR)/directory.o

$(OBJSDIR)/clipboard.o: clipboard.c clipboard.h
	$(CC) $(CFLAGS) $(INCDIRS) -c clipboard.c -o $(OBJSDIR)/clipboard.o

$(OBJSDIR)/string_buffer.o: string_buffer.c string_buffer.h
	$(CC) $(CFLAGS) $(INCDIRS) -c string_buffer.c -o $(OBJSDIR)/string_buffer.o

$(OBJSDIR)/plugin_loader.o: plugin_loader.c plugin_loader.h
	$(CC) $(CFLAGS) $(INCDIRS) -c plugin_loader.c -o $(OBJSDIR)/plugin_loader.o

$(OBJSDIR)/options.o: options.c options.h
	$(CC) $(CFLAGS) $(INCDIRS) -c options.c -o $(OBJSDIR)/options.o

$(OBJSDIR)/version.o: version.c version.h
	$(CC) $(CFLAGS) $(INCDIRS) -c version.c -o $(OBJSDIR)/version.o

$(OBJSDIR)/console.o: console.c console.h
	$(CC) $(CFLAGS) $(INCDIRS) -c console.c -o $(OBJSDIR)/console.o

$(OBJSDIR)/so.o: so.c so.h
	$(CC) $(CFLAGS) $(INCDIRS) -c so.c -o $(OBJSDIR)/so.o

$(OBJSDIR)/fa.o: fa.c fa.h $(FADIR)/core.h
	$(CC) $(CFLAGS) $(INCDIRS) -c fa.c -o $(OBJSDIR)/fa.o

$(OBJSDIR)/module.o: module.c module.h
	$(CC) $(CFLAGS) $(INCDIRS) -c module.c -o $(OBJSDIR)/module.o

$(OBJSDIR)/engine.res: $(RCDIR)/engine.rc
	$(RC) $(RCFLAGS) -i $(RCDIR)/engine.rc -o $(OBJSDIR)/engine.res

$(OBJSDIR)/launcher.res: $(RCDIR)/launcher.rc
	$(RC) $(RCFLAGS) -i $(RCDIR)/launcher.rc -o $(OBJSDIR)/launcher.res

$(RCDIR)/engine.rc: $(ROOTDIR)/include/marathoner/version.h
	$(BINDIR)/rcgen $(ROOTDIR)/include/marathoner/version.h $(RCDIR)/engine.rc \
	 MTR_VERSION_MARATHONER Marathoner \
	 "Marathoner Game Engine core application" Marathoner.exe

$(RCDIR)/launcher.rc: ../../include/marathoner/version.h
	$(BINDIR)/rcgen ../../include/marathoner/version.h $(RCDIR)/launcher.rc \
	MTR_VERSION_LAUNCHER Launcher "Marathoner launcher" Launcher.exe

launcher.h: log.h notification.h configfile.h messagebox.h clipboard.h \
 plugin_loader.h $(ROOTDIR)/include/marathoner/marathoner.h

log.h: $(ROOTDIR)/include/marathoner/engine.h

messagebox.h: $(ROOTDIR)/include/marathoner/marathoner.h \
 $(ROOTDIR)/include/marathoner/engine.h

notification.h: log.h messagebox.h $(ROOTDIR)/include/marathoner/marathoner.h \
 $(ROOTDIR)/include/marathoner/engine.h

configfile.h: $(ROOTDIR)/include/marathoner/engine.h

indexkeeper.h: log.h notification.h $(ROOTDIR)/include/marathoner/marathoner.h \
 $(ROOTDIR)/include/marathoner/engine.h

encoding.h: $(ROOTDIR)/include/marathoner/engine.h

file.h: indexkeeper.h $(ROOTDIR)/include/marathoner/marathoner.h \
 $(ROOTDIR)/include/marathoner/engine.h

directory.h: $(ROOTDIR)/include/marathoner/engine.h

clipboard.h: $(ROOTDIR)/include/marathoner/engine.h

string_buffer.h: indexkeeper.h $(ROOTDIR)/include/marathoner/engine.h

plugin_loader.h: notification.h directory.h log.h \
 $(ROOTDIR)/include/marathoner/engine.h

options.h: $(ROOTDIR)/include/marathoner/engine.h

version.h: plugin_loader.h $(ROOTDIR)/include/marathoner/engine.h

console.h: $(ROOTDIR)/include/marathoner/engine.h

so.h: notification.h log.h $(ROOTDIR)/include/marathoner/engine.h

module.h: plugin_loader.h $(ROOTDIR)/include/marathoner/engine.h

fa.h: $(FADIR)/core.h

$(FADIR)/core.h: $(FAGEN)$(HOST_EXE_EXT) log.c notification.c configfile.c \
 messagebox.c file.c clipboard.c string_buffer.c options.c console.c version.c \
 module.c directory.c
	$(FAGEN) $(FADIR)/core.h $(PLATFORM) log.c notification.c configfile.c \
     messagebox.c file.c clipboard.c string_buffer.c options.c console.c \
     version.c module.c directory.c

../../include/marathoner/engine.h: ../../include/marathoner/marathoner.h

../../include/marathoner/marathoner.h: ../../include/marathoner/version.h \
 ../../include/marathoner/types.h
