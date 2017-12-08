include ../../../makefiles/Build.mk

BINDIR = ../../../$(HOST)
OBJSDIR = ../../../$(HOST)/obj
INCDIRS = -I../../../include

all: $(BINDIR)/fagen

$(BINDIR)/fagen: $(OBJSDIR)/fagen.o
	$(LD) $(LDEXFLAGS) -o $(BINDIR)/fagen$(HOST_EXE_EXT) $(OBJSDIR)/fagen.o

$(OBJSDIR)/fagen.o: fagen.c ../../../include/marathoner/common.h
	$(CC) $(CFLAGS) $(INCDIRS) -c fagen.c -o $(OBJSDIR)/fagen.o
