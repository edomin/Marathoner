ifeq ($(PLATFORM), linux_x86_64)
  ifeq ($(CROSSPLATFORM), yes)
    LIBS = -llua
  else
    LIBS = -llua5.3
    LDFLAGS += -L/usr/lib/x86_64-linux-gnu
  endif
else
  ifeq ($(MOD), plugin)
    LUA_UTILITY_PRESENT = $(shell \
     if [ -a $(PREFIX)/bin/lua$(EXE_EXT) ]; then \
       echo yes; \
     else \
       echo no; \
     fi;)
    ifeq (LUA_UTILITY_PRESENT, yes)
      LUA_VERSION_INFO = $(shell $(PREFIX)/bin/lua$(EXE_EXT) -v)
      LUA_VERSION_STRING = $(word 2,$(LUA_VERSION_INFO))
      LUA_VERSION_SPACES = $(subst ., ,$(LUA_VERSION_STRING))
      LUA_VERSION_MAJOR = $(word 1,$(LUA_VERSION_SPACES))
      LUA_VERSION_MINOR = $(word 2,$(LUA_VERSION_SPACES))
      LIBS = -Wl,-Bdynamic
      LIBS += $(shell \
       if [ -a $(PREFIX)/bin/lua$(LUA_VERSION_MAJOR)$(LUA_VERSION_MINOR).dll ]; \
       then \
         echo -llua$(LUA_VERSION_MAJOR)$(LUA_VERSION_MINOR); \
       else \
         echo -llua; \
       fi;)
    else
      LUA_SO_NAME = $(shell ls $(PREFIX)/bin | grep '^lua' | grep 'dll$$')
      LUA_SO_NAME_SPACES = $(subst ., ,$(LUA_SO_NAME))
      LIBS = -Wl,-Bdynamic
      LIBS += -l$(word 1,$(LUA_SO_NAME_SPACES))
    endif
  else
    LIBS = -llua
  endif
endif
