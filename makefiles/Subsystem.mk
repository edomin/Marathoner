include ../../../makefiles/Build.mk
include ../../../makefiles/Module.mk

FADIR = $(ROOTDIR)/$(PLATFORM)/fa
INCDIRS += -I$(ROOTDIR)/$(PLATFORM)

FAGEN = $(ROOTDIR)/$(PLATFORM)/fagen

ifndef MODULE_H
  MODULE_H = $(SUBSYSTEM).h
endif

$(OBJ): $(SUBSYSTEM).c $(MODULE_H) $(PREREQS) \
 $(ROOTDIR)/include/marathoner/version.h $(FADIR)/$(MODULE_NAME).h
	-mkdir $(OBJSDIR)/$(SUBSYSTEM)
	$(CC) $(CFLAGS) $(INCDIRS) -c $(SUBSYSTEM).c -o $(OBJ)

$(SUBSYSTEM).c: $(ROOTDIR)/include/marathoner/plugin_common.c

$(MODULE_H): $(ROOTDIR)/include/marathoner/plugin.h

$(FADIR)/$(MODULE_NAME).h: $(FAGEN)$(EXE_EXT) $(SUBSYSTEM).c
	$(FAGEN) $(FADIR)/$(MODULE_NAME).h $(PLATFORM) $(SUBSYSTEM).c
