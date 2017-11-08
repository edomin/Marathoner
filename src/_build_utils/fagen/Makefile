include ../../../Build.mk

BINDIR = ../../../$(PLATFORM)
OBJSDIR = ../../../$(PLATFORM)/obj
INCDIRS = -I../../../include

all: $(BINDIR)/fagen

$(BINDIR)/fagen: $(OBJSDIR)/fagen.o
	$(LD) $(LDEXFLAGS) -o $(BINDIR)/fagen$(EXE_EXT) $(OBJSDIR)/fagen.o

$(OBJSDIR)/fagen.o: fagen.c ../../../include/marathoner/common.h
	$(CC) $(CFLAGS) $(INCDIRS) -c fagen.c -o $(OBJSDIR)/fagen.o
