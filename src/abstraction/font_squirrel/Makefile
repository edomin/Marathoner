SUBSYSTEM = abstraction
MODULE = font_squirrel
MODULE_NAME = Abstraction_font_Squirrel
ifeq ($(MOD), plugin)
  LIBS = -lsquirrel
else
  LIBS = -lsquirrel_static
endif
PREREQS = ../font_binding_common.h ../font_binding_common.c

include ../../../makefiles/Binding.mk
