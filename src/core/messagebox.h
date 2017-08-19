#ifndef MTR_CORE_MESSAGEBOX_H
#define MTR_CORE_MESSAGEBOX_H

#include "marathoner/marathoner.h"

#ifdef __EMSCRIPTEN__
    #include <emscripten.h>
#else
    #include "tinyfiledialogs.h"
#endif

#include "marathoner/engine.h"

char *mtrFileFilter[256];
static int mtrFileFiltersCount __attribute__((used)) = 0;

void MTR_CALL mtrShowSimpleMessageBox(uint8_t type, const char *title,
 const char *message);
bool MTR_CALL mtrShowYesNoMessageBox(const char *title, const char *message);
bool MTR_CALL mtrShowOkCancelMessageBox(const char *title, const char *message);
const char *MTR_CALL mtrShowInputDialog(const char *title, const char *message,
 const char *defaultInput);
const char *MTR_CALL mtrShowPasswordDialog(const char *title,
 const char *message);
void MTR_CALL mtrAddFileFilter(char *filter);
void MTR_CALL mtrClearFileFilters(void);
const char *MTR_CALL mtrShowSaveFileDialog(const char *title,
 const char *defaultPathAndFile, const char *singleFilterDescription);
const char *MTR_CALL mtrShowOpenFileDialog(const char *title,
 const char *defaultPathAndFile, const char *singleFilterDescription);
const char *MTR_CALL mtrShowSelectFolderDialog(const char *title,
 const char *defaultPath);
#endif
