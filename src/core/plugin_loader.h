#ifndef MTR_CORE_PLUGIN_LOADER_H
#define MTR_CORE_PLUGIN_LOADER_H

#include "notification.h"
#include "directory.h"
#include "log.h"
#include "so.h"
#include "marathoner/engine.h"

#ifdef __GNUC__
    #ifdef __MINGW32__
        #ifdef __MINGW64__
            #define MTR_PLUGIN_DIR "win64/plugin/"
        #else
            #define MTR_PLUGIN_DIR "win32/plugin/"
        #endif
    #else
        #define MTR_PLUGIN_DIR "linux_x86_64/plugin/"
    #endif
#endif

typedef void (* RequireEngineFuncsFunc)(uint8_t);

int             mtrPluginsFound;
mtrDirectory_t *pluginDirectory;
char           *tempFilename;
uint8_t         currentPlugin;

int MTR_LoadAllPlugins(RequireEngineFuncsFunc);

#endif
