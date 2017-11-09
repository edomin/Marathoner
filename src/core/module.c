#include "module.h"

/*fa MTR_MarathonerGetSubsystemModuleId yes */
char *MTR_CALL MTR_MarathonerGetSubsystemModuleId(const char *subsystem)
{
    int i;

    if (subsystem == NULL)
        return NULL;
    if ((strcmp(subsystem, "") == 0) || (strcmp(subsystem, "binding") == 0) ||
     (strcmp(subsystem, "utility") == 0) ||
     (strcmp(subsystem, "abstraction") == 0))
        return NULL;

    for (i = 0; i < mtrPluginsFound; i++) {
        if (strcmp(mtrPluginData[i].report->subsystem, subsystem) == 0)
            return mtrPluginData[i].report->moduleID;
    }

    return NULL;
}
