CC = mingw32-gcc
LD = mingw32-gcc
CFLAGS = -Wall
LDFLAGS =
OBJSDIR = ../../obj
BINDIR = ../..
INCDIR = ../../include

OBJS = $(OBJSDIR)/main.o \
	$(OBJSDIR)/log.o \
	$(OBJSDIR)/messagebox.o \
	$(OBJSDIR)/notification.o

all: Marathoner

Marathoner: $(OBJS)
	$(LD) $(LDFLAGS) -o $(BINDIR)/Marathoner.exe $(OBJS)

$(OBJSDIR)/main.o: main.c
	$(CC) $(CFLAGS) -I$(INCDIR) -c main.c -o $(OBJSDIR)/main.o

$(OBJSDIR)/log.o: log.c log.h
	$(CC) $(CFLAGS) -I$(INCDIR) -c log.c -o $(OBJSDIR)/log.o

$(OBJSDIR)/messagebox.o: messagebox.c messagebox.h
	$(CC) $(CFLAGS) -I$(INCDIR) -c messagebox.c -o $(OBJSDIR)/messagebox.o

$(OBJSDIR)/notification.o: notification.c notification.h
	$(CC) $(CFLAGS) -I$(INCDIR) -c notification.c -o $(OBJSDIR)/notification.o
