#include "version.h"

uint32_t MTR_CALL mtrMarathonerGetVersion(void)
{
    return MTR_VERSION_MARATHONER;
}

uint32_t MTR_CALL mtrMarathonerGetModuleVersion(const char *moduleID)
{
    int i;

    if (moduleID == NULL)
        return 0U;

    for (i = 0; i < mtrPluginsFound; i++)
    {
        if (strcmp(mtrPluginData[i].report->moduleID, moduleID) == 0)
        {
            return mtrPluginData[i].report->version;
        }
    }

    return 0U;
}