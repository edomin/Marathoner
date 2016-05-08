CC = mingw32-gcc
LD = mingw32-gcc
CFLAGS = -Wall
LDFLAGS =
OBJSDIR = ../../obj
BINDIR = ../../bin

all: Marathoner

Marathoner: $(OBJSDIR)/engine.o
	$(LD) $(LDFLAGS) -o $(BINDIR)/Marathoner.exe $(OBJSDIR)/engine.o

$(OBJSDIR)/engine.o: main.c
	$(CC) $(CFLAGS) -c main.c -o $(OBJSDIR)/engine.o
