#ifndef MTR_ENGINE_MESSAGEBOX
#define MTR_ENGINE_MESSAGEBOX

#include <windows.h>
#include "marathoner/marathoner.h"


#include "marathoner/engine.h"

void MRT_CALL mtrShowSimpleMessageBox(uint8_t type, const char *title,
 const char *message);
bool MRT_CALL mtrShowYesNoMessageBox(const char *title, const char *message);

#endif
