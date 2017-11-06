#ifndef MTR_PNG_BINDING_COMMON_H
#define MTR_PNG_BINDING_COMMON_H

typedef int (MTR_CALL * MTR_PngFunctionSupportedFunc)(const char *);
MTR_PngFunctionSupportedFunc MTR_PngFunctionSupported;

typedef void (MTR_CALL * MTR_PngInitFunc)(void);
MTR_PngInitFunc MTR_PngInit;

typedef mtrPixels_t *(MTR_CALL * MTR_PngLoadSimpleFunc)(const char *);
MTR_PngLoadSimpleFunc MTR_PngLoadSimple;

typedef bool (MTR_CALL * MTR_PngSaveSimpleFunc)(const char *, mtrPixels_t *);
MTR_PngSaveSimpleFunc MTR_PngSaveSimple;

#endif
