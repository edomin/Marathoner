include ../../../Build.mk

all: rcgen

rcgen: ../../../obj/rcgen.o
	$(LD) $(LDEXFLAGS) -o ../../../rcgen$(EXE_EXT) ../../../obj/rcgen.o

../../../obj/rcgen.o: rcgen.c
	$(CC) $(CFLAGS) $(INCDIRS) -c rcgen.c -o ../../../obj/rcgen.o
