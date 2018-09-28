ifeq ($(MOD), plugin)
  ifeq ($(PLATFORM), linux_x86_64)
    LIBS = -lduktape
  else
    LIBS = -lduktape.dll
  endif
else
  LIBS = -lduktape
endif
