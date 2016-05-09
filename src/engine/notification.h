#ifndef MTR_ENGINE_NOTOFICATION
#define MTR_ENGINE_NOTIFICATION

#include <stdint.h>

#include "marathoner.h"
#include "log.h"
#include "messagebox.h"

void mtrNotify(char *message, uint8_t level, uint8_t messageType);

#endif
