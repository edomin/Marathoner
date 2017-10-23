#ifndef MTR_CORE_PLUGIN_LOADER_H
#define MTR_CORE_PLUGIN_LOADER_H

#include "notification.h"
#include "directory.h"
#include "log.h"
#include "so.h"
#include "marathoner/engine.h"

#ifdef __MINGW32__
    #define MTR_PLUGIN_DIR "win32/plugin/"
#endif

typedef void (* RequireEngineFuncsFunc)(uint8_t);

int             mtrPluginsFound;
mtrDirectory_t *pluginDirectory;
char           *tempFilename;
uint8_t         currentPlugin;

int MTR_LoadAllPlugins(RequireEngineFuncsFunc);

#endif
