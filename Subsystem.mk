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
RCDIR = ../../../rc
INCDIRS = -I$(PREFIX)/include -I../../../include $(XINCDIRS)

STATIC_NAME = $(A_PR)mtr_$(MODULE_NAME)$(A_EXT)
PLUGIN_NAME = $(SO_PR)mtr_$(MODULE_NAME)$(SO_EXT)

CONST = $(shell echo $(MODULE_NAME) | tr a-z A-Z)
CONST_VER = MTR_VERSION_$(CONST)

ifeq ($(PLATFORM), win32)
  OBJS = $(OBJSDIR)/$(SUBSYSTEM)/$(MODULE).o \
    $(OBJSDIR)/$(SUBSYSTEM)/$(MODULE).res
endif

ifeq ($(MOD), static)
all: $(LIBDIR)/$(STATIC_NAME)
endif
ifeq ($(MOD), plugin)
all: $(BINDIR)/$(PLUGIN_NAME)
endif

$(LIBDIR)/$(STATIC_NAME): $(OBJSDIR)/$(SUBSYSTEM)/$(MODULE).o
	$(AR) $(ARFLAGS) $(LIBDIR)/$(STATIC_NAME) $(OBJSDIR)/$(SUBSYSTEM)/$(MODULE).o

$(BINDIR)/$(PLUGIN_NAME): $(OBJS)
	$(LD) $(LDFLAGS) -o $(BINDIR)/$(PLUGIN_NAME) $(OBJS) $(LIBS)

$(OBJSDIR)/$(SUBSYSTEM)/$(MODULE).o: $(SUBSYSTEM).c $(SUBSYSTEM).h
	-mkdir $(OBJSDIR)/$(SUBSYSTEM)
	$(CC) $(CFLAGS) $(INCDIRS) -c $(SUBSYSTEM).c -o $(OBJSDIR)/$(SUBSYSTEM)/$(MODULE).o

$(OBJSDIR)/$(SUBSYSTEM)/$(MODULE).res: $(RCDIR)/$(MODULE_NAME).rc
	$(RC) $(RCFLAGS) -i $(RCDIR)/$(MODULE_NAME).rc -o $(OBJSDIR)/$(SUBSYSTEM)/$(MODULE).res

$(RCDIR)/$(MODULE_NAME).rc:
	../../../rcgen ../../../include/marathoner/version.h $(RCDIR)/$(MODULE_NAME).rc $(CONST_VER) $(MODULE_NAME) "$(MODULE_NAME) plugin for Marathoner Engine" mtr_$(MODULE_NAME).dll

$(SUBSYSTEM).c:

$(SUBSYSTEM).h:
