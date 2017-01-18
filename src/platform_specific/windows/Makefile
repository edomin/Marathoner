include ../../../Build.mk

all: rcgen

rcgen: rcgen.o
	$(LD) $(LDEXFLAGS) -o ../../../rcgen$(EXE_EXT) ../../../obj/rcgen.o

rcgen.o: rcgen.c
	$(CC) $(CFLAGS) $(INCDIRS) -c rcgen.c -o ../../../obj/rcgen.o
