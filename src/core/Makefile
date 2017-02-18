include ../../Build.mk

ifeq ($(PLATFORM), win32)
  LDEXFLAGS = -L$(PREFIX)/lib
endif
ifeq ($(PLATFORM), html5)
  LDEXFLAGS = -L$(PREFIX)/lib -s MAIN_MODULE=1
endif
OBJSDIR = ../../obj
BINDIR = ../..
RCDIR = ../../rc
INCDIRS = -I$(PREFIX)/include -I../../include

MTR_OBJS = $(OBJSDIR)/engine.o \
	$(OBJSDIR)/log.o \
	$(OBJSDIR)/messagebox.o \
	$(OBJSDIR)/notification.o \
	$(OBJSDIR)/configfile.o \
	$(OBJSDIR)/indexkeeper.o \
	$(OBJSDIR)/encoding.o \
	$(OBJSDIR)/file.o \
	$(OBJSDIR)/directory.o \
	$(OBJSDIR)/plugin_loader.o

LCHR_OBJS = $(OBJSDIR)/launcher.o \
	$(OBJSDIR)/log.o \
	$(OBJSDIR)/messagebox.o \
	$(OBJSDIR)/notification.o \
	$(OBJSDIR)/configfile.o \
	$(OBJSDIR)/directory.o \
	$(OBJSDIR)/plugin_loader.o

ifeq ($(PLATFORM), win32)
  MTR_OBJS += $(OBJSDIR)/engine.res
  LCHR_OBJS += $(OBJSDIR)/launcher.res
endif

all: Marathoner Launcher

Marathoner: $(MTR_OBJS)
ifeq ($(MOD), static)
  ifeq ($(PLATFORM), win32)
	$(LD) $(LDFLAGS) $(LDEXFLAGS) -o $(BINDIR)/Marathoner$(EXE_EXT) $(MTR_OBJS) -lminini -lutf8 -L../../lib -lmtr_Audio_SDL2_mixer \
      -lmtr_Audio_SDL2_mixer_Lua52 \
      -lmtr_Game_Controller_SDL2 \
      -lmtr_Game_Controller_SDL2_Lua52 \
      -lmtr_Keyboard_SDL2 \
      -lmtr_Keyboard_SDL2_Lua52 \
      -lmtr_Mouse_SDL2 \
      -lmtr_Mouse_SDL2_Lua52 \
      -lmtr_Primitive_SDL2 \
      -lmtr_Primitive_SDL2_Lua52 \
      -lmtr_Screen_SDL2 \
      -lmtr_Screen_SDL2_Lua52 \
      -lmtr_Script_Lua52 \
      -lmtr_Texture_SDL2_image \
      -lmtr_Texture_SDL2_image_Lua52 \
      -lmtr_Timer_SDL2 \
      -lmtr_Timer_SDL2_Lua52 \
      -lmtr_TTF_SDL2_ttf \
      -lmtr_TTF_SDL2_ttf_Lua52 \
      -lmtr_Utils_color \
      -lmtr_Utils_color_Lua52
  endif
  ifeq ($(PLATFORM), html5)
	$(LD) $(LDFLAGS) $(LDEXFLAGS) -o $(BINDIR)/Marathoner$(EXE_EXT) $(MTR_OBJS) -lminini -lutf8 --preload-file ../../plugin@/plugin --preload-file ../../Marathoner.cfg@/ --preload-file ../../autorun@/autorun -s TOTAL_MEMORY=134217728
  endif
endif
ifeq ($(MOD), plugin)
  ifeq ($(PLATFORM), win32)
	$(LD) $(LDFLAGS) $(LDEXFLAGS) -o $(BINDIR)/Marathoner$(EXE_EXT) $(MTR_OBJS) -lminini -Wl,-Bstatic -lutf8
  endif
  ifeq ($(PLATFORM), html5)
	$(LD) $(LDFLAGS) $(LDEXFLAGS) -o $(BINDIR)/Marathoner$(EXE_EXT) $(MTR_OBJS) -lminini -lutf8 --preload-file ../../plugin@/plugin --preload-file ../../Marathoner.cfg@/ --preload-file ../../autorun@/autorun -s TOTAL_MEMORY=134217728
  endif
endif

Launcher: $(LCHR_OBJS)
ifeq ($(MOD), plugin)
  ifeq ($(PLATFORM), win32)
	$(LD) $(LDFLAGS) $(LDEXFLAGS) -o $(BINDIR)/Launcher$(EXE_EXT) $(LCHR_OBJS) -lminini -Wl,-Bstatic -ltigr -ld3d9 -llazy_winapi -Wl,-Bstatic -ltinyfiledialogs -lole32 -lshlwapi
  endif
endif

# Nuklear have too much warnings about unused functions. This is why I can not
# to use -Werror flag from CFLAGS for compile launcher.o
$(OBJSDIR)/launcher.o: launcher.c
	$(CC) $(CFLAGS) -Wno-unused-function $(INCDIRS) -c launcher.c -o $(OBJSDIR)/launcher.o

$(OBJSDIR)/engine.o: engine.c
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

$(OBJSDIR)/plugin_loader.o: plugin_loader.c plugin_loader.h
	$(CC) $(CFLAGS) $(INCDIRS) -c plugin_loader.c -o $(OBJSDIR)/plugin_loader.o

$(OBJSDIR)/engine.res: engine.rc
	$(RC) $(RCFLAGS) -i $(RCDIR)/engine.rc -o $(OBJSDIR)/engine.res

$(OBJSDIR)/launcher.res: launcher.rc
	$(RC) $(RCFLAGS) -i $(RCDIR)/launcher.rc -o $(OBJSDIR)/launcher.res

engine.rc:
	../../rcgen ../../include/marathoner/version.h $(RCDIR)/engine.rc MTR_VERSION_MARATHONER Marathoner "Marathoner Game Engine core application" Marathoner.exe

launcher.rc:
	../../rcgen ../../include/marathoner/version.h $(RCDIR)/launcher.rc MTR_VERSION_LAUNCHER Launcher "Marathoner launcher" Launcher.exe