include ../../../Build.mk

BINDIR = ../../../$(PLATFORM)
OBJSDIR = ../../../$(PLATFORM)/obj

all: $(BINDIR)/fagen

$(BINDIR)/fagen: $(OBJSDIR)/fagen.o
	$(LD) $(LDEXFLAGS) -o $(BINDIR)/fagen$(EXE_EXT) $(OBJSDIR)/fagen.o

$(OBJSDIR)/fagen.o: fagen.c ../../../include/marathoner/common.h
	$(CC) $(CFLAGS) -I../../../include $(INCDIRS) -c fagen.c -o $(OBJSDIR)/fagen.o
