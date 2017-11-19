LDFLAGS = -shared -Wl,--kill-at -L$(PREFIX)/lib -L$(PREFIX)/bin
ifeq ($(PLATFORM), win32)
  ifeq ($(DEBUG), no)
    LDFLAGS += -s
  endif
endif
ifeq ($(PLATFORM), win64)
  ifeq ($(DEBUG), no)
    LDFLAGS += -s
  endif
endif
ifeq ($(PLATFORM), html5)
  LDFLAGS += -s SIDE_MODULE=1 -O2
endif
ROOTDIR = ../../..
OBJSDIR = $(ROOTDIR)/$(PLATFORM)/obj
LIBDIR = $(ROOTDIR)/$(PLATFORM)/lib
BINDIR = $(ROOTDIR)/$(PLATFORM)/plugin
SRCDIR = $(ROOTDIR)/src
RCDIR = $(ROOTDIR)/$(PLATFORM)/rc
INCDIRS = -I$(PREFIX)/include -I$(ROOTDIR)/include $(XINCDIRS)
ifeq ($(MOD), static)
  ifdef BINDING
    LIBS_TXT = $(LIBDIR)/_$(MODULE_NAME).txt
  endif
  ifndef BINDING
    LIBS_TXT = $(LIBDIR)/$(MODULE_NAME).txt
  endif
  OBJS_TXT = $(OBJSDIR)/objs.txt
  BIFDIR = $(ROOTDIR)/$(PLATFORM)/binding_init_func
  BIFDIR_ESCAPED = ..\/..\/..\/$(PLATFORM)\/binding_init_func\/
  BIFCALLDIR = $(ROOTDIR)/$(PLATFORM)/binding_init_func_call
  BIFCALLDIR_ESCAPED = ..\/..\/..\/$(PLATFORM)\/binding_init_func_call\/
endif

STATIC_NAME = $(A_PR)mtr_$(MODULE_NAME)$(A_EXT)
PLUGIN_NAME = $(SO_PR)mtr_$(MODULE_NAME)$(SO_EXT)

OBJ = $(OBJSDIR)/$(SUBSYSTEM)/$(MODULE).o
RES =

ifeq ($(PLATFORM), win32)
  RCGEN = $(ROOTDIR)/$(PLATFORM)/rcgen
  VERSION_H = $(ROOTDIR)/include/marathoner/version.h
  RCFILE = $(RCDIR)/$(MODULE_NAME).rc
  RES = $(OBJSDIR)/$(SUBSYSTEM)/$(MODULE).res
  OBJS = $(OBJ) $(RES)
  PLUGIN_DESCRIPTION = "$(MODULE_NAME) plugin for Marathoner Engine"
endif
ifeq ($(PLATFORM), win64)
  RCGEN = $(ROOTDIR)/$(PLATFORM)/rcgen
  VERSION_H = $(ROOTDIR)/include/marathoner/version.h
  RCFILE = $(RCDIR)/$(MODULE_NAME).rc
  RES = $(OBJSDIR)/$(SUBSYSTEM)/$(MODULE).res
  OBJS = $(OBJ) $(RES)
  PLUGIN_DESCRIPTION = "$(MODULE_NAME) plugin for Marathoner Engine"
endif

CONST = $(shell echo $(MODULE_NAME) | tr a-z A-Z)
CONST_VER = MTR_VERSION_$(CONST)

ifeq ($(MOD), static)
  ifeq ($(BINDING), yes)
    BIF = $(BIFDIR)/$(MODULE_NAME).txt
    BIFCALL = $(BIFCALLDIR)/$(MODULE_NAME).txt
  endif
  ifeq ($(SCRIPT), yes)
    BIF_HEADER = $(BIFDIR)/bindings_init.h
  endif
all: $(LIBS_TXT) $(BIF) $(BIFCALL) $(OBJS_TXT) $(BIF_HEADER)
endif
ifeq ($(MOD), plugin)
all: $(BINDIR)/$(PLUGIN_NAME)
endif

$(BINDIR)/$(PLUGIN_NAME): $(OBJS)
	$(LD) $(LDFLAGS) -o $(BINDIR)/$(PLUGIN_NAME) $(OBJS) $(LIBS)

$(RES): $(RCFILE)
	-mkdir $(OBJSDIR)/$(SUBSYSTEM)
	$(RC) $(RCFLAGS) -i $(RCFILE) -o $(RES)

$(RCFILE): $(ROOTDIR)/include/marathoner/version.h
	$(RCGEN) $(VERSION_H) $(RCFILE) $(CONST_VER) $(MODULE_NAME) \
	 $(PLUGIN_DESCRIPTION) $(PLUGIN_NAME)

$(OBJS_TXT): $(OBJ)
	echo ../../$(PLATFORM)/obj/$(SUBSYSTEM)/$(MODULE).o >> $(OBJS_TXT)

$(LIBS_TXT):
	-rm -f $(LIBS_TXT)
	echo $(LIBS) >> $(LIBS_TXT)

#binding init function
$(BIF):
	-rm -f $(BIF)
	echo MTR_DCLSPC void MTR_CALL MTR_$(MODULE_NAME)PluginInit\(void\)\; >> $(BIF)

$(BIFCALL):
	-rm -f $(BIFCALL)
	echo MTR_$(MODULE_NAME)PluginInit\(\)\; >> $(BIFCALL)

$(BIF_HEADER):
	-rm -f $(BIF_HEADER)
#	ls $(BIFDIR) | sed -e 's/^/$(BIFDIR_ESCAPED)/' | cat > $(BIF_HEADER)
	cat $(shell ls $(BIFDIR) | sed -e 's/^/$(BIFDIR_ESCAPED)/') > $(BIF_HEADER)
	echo void MTR_BifInitAll\(void\) >> $(BIF_HEADER)
	echo { >> $(BIF_HEADER)
#	cat $(shell ls $(BIFCALLDIR)) >> $(BIF_HEADER)
	cat $(shell ls $(BIFCALLDIR) | sed -e 's/^/$(BIFCALLDIR_ESCAPED)/') >> $(BIF_HEADER)
	echo } >> $(BIF_HEADER)

$(ROOTDIR)/include/marathoner/plugin.h: \
 $(ROOTDIR)/include/marathoner/marathoner.h

$(ROOTDIR)/include/marathoner/marathoner.h: \
 $(ROOTDIR)/include/marathoner/version.h $(ROOTDIR)/include/marathoner/types.h \
 $(ROOTDIR)/include/marathoner/common.h
