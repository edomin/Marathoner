include ../../../makefiles/Build.mk

SUBSYSTEM = json
MODULE = cjson
MODULE_NAME = JSON_cJSON
ifeq ($(PLATFORM), win32)
  LIBS = -lcjson -lssp
endif
ifeq ($(PLATFORM), win64)
  LIBS = -lcjson -lssp
endif
ifeq ($(PLATFORM), html5)
  LIBS = -lcjson
endif

include ../../../makefiles/Subsystem.mk
