ifeq ($(MOD), plugin)
  ifeq ($(PLATFORM), linux_x86_64)
    ifeq ($(CROSSPLATFORM), yes)
      LIBS = -lsquirrel
    else
      LIBS = -lsquirrel3
      LDFLAGS += -L/usr/lib/x86_64-linux-gnu
    endif
  else
    LIBS = -lsquirrel.dll
  endif
else
  LIBS = -lsquirrel_static
endif
