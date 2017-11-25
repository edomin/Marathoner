include ../../../makefiles/Build.mk
include ../../../makefiles/Module.mk

FADIR = $(ROOTDIR)/$(PLATFORM)/fa
INCDIRS += -I$(ROOTDIR)/$(PLATFORM)

FAGEN = $(ROOTDIR)/$(HOST)/fagen

$(OBJ): $(MODULE).c $(MODULE).h $(PREREQS) \
 $(ROOTDIR)/include/marathoner/version.h $(FADIR)/$(MODULE_NAME).h
	-mkdir $(OBJSDIR)/$(SUBSYSTEM)
	$(CC) $(CFLAGS) $(CEXFLAGS) $(INCDIRS) -c $(MODULE).c -o $(OBJ)

$(MODULE).c: $(ROOTDIR)/include/marathoner/plugin_common.c

$(MODULE).h: $(ROOTDIR)/include/marathoner/plugin.h

$(FADIR)/$(MODULE_NAME).h: $(FAGEN)$(HOST_EXE_EXT) $(MODULE).c
	$(FAGEN) $(FADIR)/$(MODULE_NAME).h $(PLATFORM) $(MODULE).c
