include ../../../Build.mk
include ../../../Module.mk

FADIR = $(ROOTDIR)/fa
INCDIRS += -I$(ROOTDIR)

FAGEN = $(ROOTDIR)/fagen

$(OBJ): $(MODULE).c $(MODULE).h $(PREREQS) \
 $(ROOTDIR)/include/marathoner/version.h $(FADIR)/$(MODULE_NAME).h
	-mkdir $(OBJSDIR)/$(SUBSYSTEM)
	$(CC) $(CFLAGS) $(INCDIRS) -c $(MODULE).c -o $(OBJ)

$(MODULE).c: $(ROOTDIR)/include/marathoner/plugin_common.c

$(MODULE).h: $(ROOTDIR)/include/marathoner/plugin.h

$(FADIR)/$(MODULE_NAME).h: $(FAGEN)$(EXE_EXT) $(MODULE).c
	$(FAGEN) $(MODULE).c $(FADIR)/$(MODULE_NAME).h $(PLATFORM)
