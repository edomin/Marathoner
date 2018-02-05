#ifndef MTR_PLUGIN_COMMON_H
#define MTR_PLUGIN_COMMON_H

#include <string.h>

#define MTR_REQUIRE_FUNC(func)                    \
    MTR_DCLSPC void MTR_CALL MTR_Require ## func( \
    MTR_ ## func ## Func_t func ## Func)          \
    {                                             \
        MTR_ ## func = func ## Func;              \
    }

#endif
