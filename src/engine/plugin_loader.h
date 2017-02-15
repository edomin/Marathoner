#ifndef MTR_ENGINE_PLUGIN_LOADER_H
#define MTR_ENGINE_PLUGIN_LOADER_H

#include "notification.h"
#include "directory.h"
#include "log.h"
#include "marathoner/engine.h"

typedef void (* RequireEngineFuncsFunc)(uint8_t);

int             mtrPluginsFound;
mtrDirectory_t *pluginDirectory;
char           *tempFilename;
uint8_t         currentPlugin;

int mtrLoadAllPlugins(RequireEngineFuncsFunc);

#endif
