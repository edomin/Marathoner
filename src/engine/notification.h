#ifndef MTR_ENGINE_NOTOFICATION
#define MTR_ENGINE_NOTIFICATION

#include <stdint.h>

#include "marathoner.h"
#include "log.h"
#include "messagebox.h"

/* Notification texts */
#define MTR_NTT_INFO    "Info"
#define MTR_NTT_NOTE    "Note"
#define MTR_NTT_WARNING "Warning"
#define MTR_NTT_ERROR   "Error"
#define MTR_NTT_FATAL   "Fatal Error"
#define MTR_NTT_DEBUG   "Debug"

void __stdcall mtrNotify(char *message, uint8_t level, uint8_t messageType);

#endif
