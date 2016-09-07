include ../../../Build.mk

ifeq ($(PLATFORM), win32)
  LDFLAGS = -s -shared -Wl,--kill-at -L$(PREFIX)/lib
endif
ifeq ($(PLATFORM), html5)
  LDFLAGS = -shared -Wl,--kill-at -L$(PREFIX)/lib -s SIDE_MODULE=1 -O2
endif
OBJSDIR = ../../../obj
BINDIR = ../../../plugin
SRCDIR = ../../../src
INCDIRS = -I$(PREFIX)/include -I../../../include $(XINCDIRS)

PLUGIN_NAME = $(SO_PR)mtr_$(MODULE_NAME)$(SO_EXT)

all: $(BINDIR)/$(PLUGIN_NAME)

$(BINDIR)/$(PLUGIN_NAME): $(OBJSDIR)/$(SUBSYSTEM)/$(MODULE).o
	$(LD) $(LDFLAGS) -o $(BINDIR)/$(PLUGIN_NAME) $(OBJSDIR)/$(SUBSYSTEM)/$(MODULE).o $(LIBS)

$(OBJSDIR)/$(SUBSYSTEM)/$(MODULE).o: $(SUBSYSTEM).c $(SUBSYSTEM).h
	-mkdir $(OBJSDIR)/$(SUBSYSTEM)
	$(CC) $(CFLAGS) $(INCDIRS) -c $(SUBSYSTEM).c -o $(OBJSDIR)/$(SUBSYSTEM)/$(MODULE).o

$(SUBSYSTEM).c:

$(SUBSYSTEM).h:
