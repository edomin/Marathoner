include ../../../Build.mk

ifeq ($(PLATFORM), win32)
  LDFLAGS = -s -shared -Wl,--kill-at -L$(PREFIX)/lib
endif
ifeq ($(PLATFORM), html5)
  LDFLAGS = -shared -Wl,--kill-at -L$(PREFIX)/lib -s SIDE_MODULE=1 -O2
endif
OBJSDIR = ../../../obj
LIBDIR = ../../../lib
BINDIR = ../../../plugin
SRCDIR = ../../../src
INCDIRS = -I$(PREFIX)/include -I../../../include $(XINCDIRS)

STATIC_NAME = $(A_PR)mtr_$(MODULE_NAME)$(A_EXT)
PLUGIN_NAME = $(SO_PR)mtr_$(MODULE_NAME)$(SO_EXT)

ifeq ($(MOD), static)
all: $(LIBDIR)/$(STATIC_NAME)
endif
ifeq ($(MOD), plugin)
all: $(BINDIR)/$(PLUGIN_NAME)
endif

$(LIBDIR)/$(STATIC_NAME): $(OBJSDIR)/$(SUBSYSTEM)/$(MODULE).o
	$(AR) $(ARFLAGS) $(LIBDIR)/$(STATIC_NAME) $(OBJSDIR)/$(SUBSYSTEM)/$(MODULE).o

$(BINDIR)/$(PLUGIN_NAME): $(OBJSDIR)/$(SUBSYSTEM)/$(MODULE).o
	$(LD) $(LDFLAGS) -o $(BINDIR)/$(PLUGIN_NAME) $(OBJSDIR)/$(SUBSYSTEM)/$(MODULE).o $(LIBS)

$(OBJSDIR)/$(SUBSYSTEM)/$(MODULE).o: $(MODULE).c $(MODULE).h
	-mkdir $(OBJSDIR)/$(SUBSYSTEM)
	$(CC) $(CFLAGS) $(INCDIRS) -c $(MODULE).c -o $(OBJSDIR)/$(SUBSYSTEM)/$(MODULE).o

$(MODULE).c:

$(MODULE).h:

