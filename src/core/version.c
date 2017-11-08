#include "version.h"

/*fa MTR_MarathonerGetVersion yes */
uint32_t MTR_CALL MTR_MarathonerGetVersion(void)
{
    return MTR_VERSION_MARATHONER;
}

/*fa MTR_MarathonerGetModuleVersion yes */
uint32_t MTR_CALL MTR_MarathonerGetModuleVersion(const char *moduleID)
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
