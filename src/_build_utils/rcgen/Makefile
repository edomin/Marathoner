include ../../../makefiles/Build.mk

BINDIR = ../../../$(PLATFORM)
OBJSDIR = ../../../$(PLATFORM)/obj

all: $(BINDIR)/rcgen

$(BINDIR)/rcgen: $(OBJSDIR)/rcgen.o
	$(LD) $(LDEXFLAGS) -o $(BINDIR)/rcgen$(EXE_EXT) $(OBJSDIR)/rcgen.o

$(OBJSDIR)/rcgen.o: rcgen.c
	$(CC) $(CFLAGS) $(INCDIRS) -c rcgen.c -o $(OBJSDIR)/rcgen.o
