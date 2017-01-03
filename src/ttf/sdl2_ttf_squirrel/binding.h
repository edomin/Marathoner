#ifndef MTR_TTF_SDL2_TTF_SQUIRREL
#define MTR_TTF_SDL2_TTF_SQUIRREL

#include "SDL2/SDL_ttf.h"

#include "squirrel.h"

#include "marathoner/plugin.h"
#include "../binding_common.h"

#define MTR_FS_NORMAL           TTF_STYLE_NORMAL
#define MTR_FS_BOLD             TTF_STYLE_BOLD
#define MTR_FS_ITALIC           TTF_STYLE_ITALIC
#define MTR_FS_UNDERLINE        TTF_STYLE_UNDERLINE
#define MTR_FS_STRIKETHROUGH    TTF_STYLE_STRIKETHROUGH

HSQUIRRELVM mtrVm;

typedef HSQUIRRELVM (MTR_CALL * mtrScriptsGetVmFunc)(void);
mtrScriptsGetVmFunc mtrScriptsGetVm;

typedef void (MTR_CALL * mtrScriptsRegisterFunctionFunc)(SQFUNCTION, char *);
mtrScriptsRegisterFunctionFunc mtrScriptsRegisterFunction;

typedef void (MTR_CALL * mtrScriptsRegisterNumericVariableFunc)(char *, double);
mtrScriptsRegisterNumericVariableFunc mtrScriptsRegisterNumericVariable;

#endif
