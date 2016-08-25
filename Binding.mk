CC = mingw32-gcc
LD = mingw32-gcc
CFLAGS = -Wall -O2
LDFLAGS = -s -shared -Wl,--kill-at -L$(PREFIX)/lib
OBJSDIR = ../../../obj
BINDIR = ../../../plugin
SRCDIR = ../../../src
INCDIRS = -I$(PREFIX)/include -I../../../include $(XINCDIRS)

all: $(BINDIR)/$(MODULE_NAME).dll

$(BINDIR)/$(MODULE_NAME).dll: $(OBJSDIR)/$(SUBSYSTEM)/$(MODULE).o
	$(LD) $(LDFLAGS) -o $(BINDIR)/mtr_$(MODULE_NAME).dll $(OBJSDIR)/$(SUBSYSTEM)/$(MODULE).o $(LIBS)

$(OBJSDIR)/$(SUBSYSTEM)/$(MODULE).o: binding.c binding.h
	-mkdir $(OBJSDIR)/$(SUBSYSTEM)
	$(CC) $(CFLAGS) $(INCDIRS) -c binding.c -o $(OBJSDIR)/$(SUBSYSTEM)/$(MODULE).o

binding.c:

binding.h:

