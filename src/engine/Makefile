CC = mingw32-gcc
LD = mingw32-gcc
CFLAGS = -Wall -O2
LDFLAGS = -s -L$(PREFIX)/lib -mwindows
OBJSDIR = ../../obj
BINDIR = ../..
INCDIRS = -I$(PREFIX)/include -I../../include

OBJS = $(OBJSDIR)/main.o \
	$(OBJSDIR)/log.o \
	$(OBJSDIR)/messagebox.o \
	$(OBJSDIR)/notification.o \
	$(OBJSDIR)/configfile.o \
	$(OBJSDIR)/indexkeeper.o \
	$(OBJSDIR)/encoding.o

all: Marathoner

Marathoner: $(OBJS)
	$(LD) $(LDFLAGS) -o $(BINDIR)/Marathoner.exe $(OBJS) -lminini -lutf8

$(OBJSDIR)/main.o: main.c
	$(CC) $(CFLAGS) $(INCDIRS) -c main.c -o $(OBJSDIR)/main.o

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
