include ../../../Build.mk
include ../../../Module.mk

FADIR = $(ROOTDIR)/fa
INCDIRS += -I$(ROOTDIR)

FAGEN = $(ROOTDIR)/fagen

$(OBJ): $(SUBSYSTEM).c $(SUBSYSTEM).h $(PREREQS) \
 $(ROOTDIR)/include/marathoner/version.h $(FADIR)/$(MODULE_NAME).h
	-mkdir $(OBJSDIR)/$(SUBSYSTEM)
	$(CC) $(CFLAGS) $(INCDIRS) -c $(SUBSYSTEM).c -o $(OBJ)

$(SUBSYSTEM).c: $(ROOTDIR)/include/marathoner/plugin_common.c

$(SUBSYSTEM).h: $(ROOTDIR)/include/marathoner/plugin.h

$(FADIR)/$(MODULE_NAME).h: $(FAGEN)$(EXE_EXT) $(SUBSYSTEM).c
	$(FAGEN) $(SUBSYSTEM).c $(FADIR)/$(MODULE_NAME).h $(PLATFORM)
