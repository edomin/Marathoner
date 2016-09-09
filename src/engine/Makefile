include ../../Build.mk

ifeq ($(PLATFORM), win32)
  LDEXFLAGS = -L$(PREFIX)/lib
endif
ifeq ($(PLATFORM), html5)
  LDEXFLAGS = -L$(PREFIX)/lib -s MAIN_MODULE=1
endif
OBJSDIR = ../../obj
BINDIR = ../..
INCDIRS = -I$(PREFIX)/include -I../../include

OBJS = $(OBJSDIR)/main.o \
	$(OBJSDIR)/log.o \
	$(OBJSDIR)/messagebox.o \
	$(OBJSDIR)/notification.o \
	$(OBJSDIR)/configfile.o \
	$(OBJSDIR)/indexkeeper.o \
	$(OBJSDIR)/encoding.o \
	$(OBJSDIR)/file.o

all: Marathoner

Marathoner: $(OBJS)
ifeq ($(PLATFORM), win32)
	$(LD) $(LDFLAGS) $(LDEXFLAGS) -o $(BINDIR)/Marathoner$(EXE_EXT) $(OBJS) -lminini -lutf8
endif
ifeq ($(PLATFORM), html5)
	$(LD) $(LDFLAGS) $(LDEXFLAGS) -o $(BINDIR)/Marathoner$(EXE_EXT) $(OBJS) -lminini -lutf8 --preload-file ../../plugin@/plugin --preload-file ../../Marathoner.cfg@/ --preload-file ../../autorun@/autorun -s TOTAL_MEMORY=134217728
endif

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

$(OBJSDIR)/file.o: file.c file.h
	$(CC) $(CFLAGS) $(INCDIRS) -c file.c -o $(OBJSDIR)/file.o
