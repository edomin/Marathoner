#define MTR_FA_DECLARATION
#include "fa.h"

int MTR_CALL MTR_MarathonerFunctionSupported(const char *functionName)
{
    int i;
    for (i = 0; i < FA_FUNCTIONS_COUNT; i++)
    {
        if (strcmp(functionName, fa[i].name) == 0)
            return fa[i].availability;
    }
    return MTR_FA_NO;
}
