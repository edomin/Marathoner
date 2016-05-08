CC = mingw32-gcc
LD = mingw32-gcc
OBJSDIR = obj
BINDIR = bin

GENERAL_SDL2 = general/sdl2
SCREEN_SDL2 = screen/sdl2

all: prebuild
	make -C src/engine
	make -C src/$(GENERAL_SDL2)
	make -C src/$(SCREEN_SDL2)

prebuild:
	-mkdir $(OBJSDIR)
	-mkdir $(BINDIR)

clean:
	-rm -f -r $(OBJSDIR)
	-rm -f -r $(BINDIR)

.PHONY:
