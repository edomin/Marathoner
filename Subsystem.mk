CC = mingw32-gcc
LD = mingw32-gcc
CFLAGS = -Wall
LDFLAGS = -shared
OBJSDIR = ../../../obj
BINDIR = ../../../bin
SRCDIR = ../../../src
INCDIR = ../../../include

all: $(BINDIR)/$(MODULE_NAME).dll

$(BINDIR)/$(MODULE_NAME).dll: $(OBJSDIR)/$(SUBSYSTEM)/$(MODULE).o
	$(LD) $(LDFLAGS) -o $(BINDIR)/$(MODULE_NAME).dll $(OBJSDIR)/$(SUBSYSTEM)/$(MODULE).o

$(OBJSDIR)/$(SUBSYSTEM)/$(MODULE).o: $(SUBSYSTEM).c $(SUBSYSTEM).h
	-mkdir $(OBJSDIR)/$(SUBSYSTEM)
	$(CC) $(CFLAGS) -I$(INCDIR) -c $(SUBSYSTEM).c -o $(OBJSDIR)/$(SUBSYSTEM)/$(MODULE).o

.PHONY:  $(SUBSYSTEM).c $(SUBSYSTEM).h
