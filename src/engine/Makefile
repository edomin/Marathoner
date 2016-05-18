CC = mingw32-gcc
LD = mingw32-gcc
CFLAGS = -Wall
LDFLAGS = -s -L../../lib -mwindows
OBJSDIR = ../../obj
BINDIR = ../..
INCDIR = ../../include

OBJS = $(OBJSDIR)/main.o \
	$(OBJSDIR)/log.o \
	$(OBJSDIR)/messagebox.o \
	$(OBJSDIR)/notification.o \
	$(OBJSDIR)/configfile.o

all: Marathoner

Marathoner: $(OBJS)
	$(LD) $(LDFLAGS) -o $(BINDIR)/Marathoner.exe $(OBJS) -lminini

$(OBJSDIR)/main.o: main.c
	$(CC) $(CFLAGS) -I$(INCDIR) -c main.c -o $(OBJSDIR)/main.o

$(OBJSDIR)/log.o: log.c log.h
	$(CC) $(CFLAGS) -I$(INCDIR) -c log.c -o $(OBJSDIR)/log.o

$(OBJSDIR)/messagebox.o: messagebox.c messagebox.h
	$(CC) $(CFLAGS) -I$(INCDIR) -c messagebox.c -o $(OBJSDIR)/messagebox.o

$(OBJSDIR)/notification.o: notification.c notification.h
	$(CC) $(CFLAGS) -I$(INCDIR) -c notification.c -o $(OBJSDIR)/notification.o

$(OBJSDIR)/configfile.o: configfile.c configfile.h
	$(CC) $(CFLAGS) -I$(INCDIR) -c configfile.c -o $(OBJSDIR)/configfile.o
