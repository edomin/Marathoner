#ifndef MTR_CORE_VERSION_H
#define MTR_CORE_VERSION_H

#include "marathoner/marathoner.h"

#include "plugin_loader.h"

#include "marathoner/engine.h"

uint32_t MTR_CALL MTR_MarathonerGetVersion(void);
uint32_t MTR_CALL MTR_MarathonerGetModuleVersion(const char *moduleID);

#endif
