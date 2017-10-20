#ifndef MTR_CORE_MESSAGEBOX_H
#define MTR_CORE_MESSAGEBOX_H

#include "marathoner/marathoner.h"

#ifdef __EMSCRIPTEN__
    #include <emscripten.h>
#else
    #include "tinyfiledialogs.h"
#endif

#include "marathoner/engine.h"

const char *mtrFileFilter[256];
static int mtrFileFiltersCount __attribute__((used)) = 0;

void MTR_CALL MTR_ShowSimpleMessageBox(uint8_t type, const char *title,
 const char *message);
bool MTR_CALL MTR_ShowYesNoMessageBox(const char *title, const char *message);
bool MTR_CALL MTR_ShowOkCancelMessageBox(const char *title,
 const char *message);
const char *MTR_CALL MTR_ShowInputDialog(const char *title, const char *message,
 const char *defaultInput);
const char *MTR_CALL MTR_ShowPasswordDialog(const char *title,
 const char *message);
void MTR_CALL MTR_AddFileFilter(const char *filter);
void MTR_CALL MTR_ClearFileFilters(void);
const char *MTR_CALL MTR_ShowSaveFileDialog(const char *title,
 const char *defaultPathAndFile, const char *singleFilterDescription);
const char *MTR_CALL MTR_ShowOpenFileDialog(const char *title,
 const char *defaultPathAndFile, const char *singleFilterDescription);
const char *MTR_CALL MTR_ShowSelectFolderDialog(const char *title,
 const char *defaultPath);
#endif
