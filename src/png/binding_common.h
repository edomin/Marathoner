#ifndef MTR_PNG_BINDING_COMMON_H
#define MTR_PNG_BINDING_COMMON_H

typedef int (MTR_CALL * MTR_PngFunctionSupportedFunc)(const char *);
MTR_PngFunctionSupportedFunc MTR_PngFunctionSupported;

typedef void (MTR_CALL * MTR_PngInitFunc)(void);
MTR_PngInitFunc MTR_PngInit;

typedef mtrPixels_t *(MTR_CALL * MTR_PngLoadFastFunc)(const char *);
MTR_PngLoadFastFunc MTR_PngLoadFast;

typedef bool (MTR_CALL * MTR_PngSaveFastFunc)(const char *, mtrPixels_t *);
MTR_PngSaveFastFunc MTR_PngSaveFast;

#endif
