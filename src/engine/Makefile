CC = mingw32-gcc
LD = mingw32-gcc
CFLAGS = -Wall
LDFLAGS =
OBJSDIR = ../../obj
BINDIR = ../..

OBJS = $(OBJSDIR)/main.o \
	$(OBJSDIR)/log.o

all: Marathoner

Marathoner: $(OBJS)
	$(LD) $(LDFLAGS) -o $(BINDIR)/Marathoner.exe $(OBJS)

$(OBJSDIR)/main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o $(OBJSDIR)/main.o

$(OBJSDIR)/log.o: log.c log.h
	$(CC) $(CFLAGS) -c log.c -o $(OBJSDIR)/log.o
