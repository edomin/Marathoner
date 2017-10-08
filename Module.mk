ifeq ($(PLATFORM), win32)
  ifeq ($(DEBUG), no)
    LDFLAGS = -s -shared -Wl,--kill-at -L$(PREFIX)/lib
  endif
  ifeq ($(DEBUG), yes)
    LDFLAGS = -shared -Wl,--kill-at -L$(PREFIX)/lib
  endif
endif
ifeq ($(PLATFORM), html5)
  LDFLAGS += -shared -Wl,--kill-at -L$(PREFIX)/lib -s SIDE_MODULE=1 -O2
endif
ROOTDIR = ../../..
OBJSDIR = $(ROOTDIR)/obj
LIBDIR = $(ROOTDIR)/lib
BINDIR = $(ROOTDIR)/plugin
SRCDIR = $(ROOTDIR)/src
RCDIR = $(ROOTDIR)/rc
INCDIRS = -I$(PREFIX)/include -I$(ROOTDIR)/include $(XINCDIRS)

STATIC_NAME = $(A_PR)mtr_$(MODULE_NAME)$(A_EXT)
PLUGIN_NAME = $(SO_PR)mtr_$(MODULE_NAME)$(SO_EXT)

OBJ = $(OBJSDIR)/$(SUBSYSTEM)/$(MODULE).o
RES =

ifeq ($(PLATFORM), win32)
  RCGEN = $(ROOTDIR)/rcgen
  VERSION_H = $(ROOTDIR)/include/marathoner/version.h
  RCFILE = $(RCDIR)/$(MODULE_NAME).rc
  RES = $(OBJSDIR)/$(SUBSYSTEM)/$(MODULE).res
  OBJS = $(OBJ) $(RES)
  PLUGIN_DESCRIPTION = "$(MODULE_NAME) plugin for Marathoner Engine"
endif

CONST = $(shell echo $(MODULE_NAME) | tr a-z A-Z)
CONST_VER = MTR_VERSION_$(CONST)

ifeq ($(MOD), static)
all: $(LIBDIR)/$(STATIC_NAME)
endif
ifeq ($(MOD), plugin)
all: $(BINDIR)/$(PLUGIN_NAME)
endif

$(LIBDIR)/$(STATIC_NAME): $(OBJ)
	$(AR) $(ARFLAGS) $(LIBDIR)/$(STATIC_NAME) $(OBJ)

$(BINDIR)/$(PLUGIN_NAME): $(OBJS)
	$(LD) $(LDFLAGS) -o $(BINDIR)/$(PLUGIN_NAME) $(OBJS) $(LIBS)

$(RES): $(RCFILE)
	$(RC) $(RCFLAGS) -i $(RCFILE) -o $(RES)

$(RCFILE): $(ROOTDIR)/include/marathoner/version.h
	$(RCGEN) $(VERSION_H) $(RCFILE) $(CONST_VER) $(MODULE_NAME) \
	 $(PLUGIN_DESCRIPTION) $(PLUGIN_NAME)

$(ROOTDIR)/include/marathoner/plugin.h: \
 $(ROOTDIR)/include/marathoner/marathoner.h

$(ROOTDIR)/include/marathoner/marathoner.h: \
 $(ROOTDIR)/include/marathoner/version.h $(ROOTDIR)/include/marathoner/types.h \
 $(ROOTDIR)/include/marathoner/common.h
