#ifndef MTR_CORE_ENCODING_H
#define MTR_CORE_ENCODING_H

#include <string.h>

#include "utf8.h"

#include "marathoner/engine.h"

size_t MTR_CALL mtrEncodingUtf8ToUcs4(const char *utf8Text,
 uint32_t **ucs4Text);
size_t MTR_CALL mtrEncodingUtf8Codepoints(const char *utf8Text);

#endif
