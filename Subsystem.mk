CC = mingw32-gcc
LD = mingw32-gcc
CFLAGS = -Wall -O2
LDFLAGS = -s -shared -Wl,--kill-at -L../../../lib
OBJSDIR = ../../../obj
BINDIR = ../../../plugin
SRCDIR = ../../../src
INCDIR = ../../../include

all: $(BINDIR)/$(MODULE_NAME).dll

$(BINDIR)/$(MODULE_NAME).dll: $(OBJSDIR)/$(SUBSYSTEM)/$(MODULE).o
	$(LD) $(LDFLAGS) -o $(BINDIR)/mtr_$(MODULE_NAME).dll $(OBJSDIR)/$(SUBSYSTEM)/$(MODULE).o $(LIBS)

$(OBJSDIR)/$(SUBSYSTEM)/$(MODULE).o: $(SUBSYSTEM).c $(SUBSYSTEM).h
	-mkdir $(OBJSDIR)/$(SUBSYSTEM)
	$(CC) $(CFLAGS) -I$(INCDIR) -c $(SUBSYSTEM).c -o $(OBJSDIR)/$(SUBSYSTEM)/$(MODULE).o

$(SUBSYSTEM).c:

$(SUBSYSTEM).h:
