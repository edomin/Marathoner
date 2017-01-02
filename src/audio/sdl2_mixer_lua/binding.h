#ifndef MTR_AUDIO_SDL2_MIXER_LUA
#define MTR_AUDIO_SDL2_MIXER_LUA

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

#include "marathoner/plugin.h"
#include "../binding_common.h"

#define MTR_AU_FREQ_DEFAULT         0
#define MTR_AU_CHANNELS_DEFAULT     0
#define MTR_AU_CHUNK_SIZE_DEFAULT   0
#define MTR_AU_DEFAULT              0

lua_State *mtrVm;

typedef lua_State* (MTR_CALL * mtrScriptsGetVmFunc)(void);
mtrScriptsGetVmFunc mtrScriptsGetVm;

typedef void (MTR_CALL * mtrScriptsRegisterFunctionFunc)(lua_CFunction,
 char *);
mtrScriptsRegisterFunctionFunc mtrScriptsRegisterFunction;

typedef void (MTR_CALL * mtrScriptsRegisterNumericVariableFunc)(char *,
 double);
mtrScriptsRegisterNumericVariableFunc mtrScriptsRegisterNumericVariable;

#endif
