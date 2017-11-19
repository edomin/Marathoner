include ../../../makefiles/Build.mk
BINDING = yes
include ../../../makefiles/Module.mk

$(OBJ): binding.c binding.h $(PREREQS) \
 $(ROOTDIR)/include/marathoner/script_func.h \
 $(ROOTDIR)/include/marathoner/version.h
	-mkdir $(OBJSDIR)/$(SUBSYSTEM)
	$(CC) $(CFLAGS) $(INCDIRS) -c binding.c -o $(OBJ)

binding.c: $(ROOTDIR)/include/marathoner/plugin_common.c

binding.h: $(ROOTDIR)/include/marathoner/plugin.h \
 $(ROOTDIR)/include/marathoner/binding_common.h
