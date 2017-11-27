#include "binding.h"

#ifdef MTR_MOD_PLUGIN
    #include "marathoner/plugin_common.c"
#endif
#include "../binding_common.c"

MTR_BINDING_COMMON_CODE(TTF_FreeType2_Duktape,
 MTR_VERSION_TTF_FREETYPE2_DUKTAPE, "TTF_FreeType2")
