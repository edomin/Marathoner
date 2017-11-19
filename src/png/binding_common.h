#ifndef MTR_PNG_BINDING_COMMON_H
#define MTR_PNG_BINDING_COMMON_H

MTR_FUNC(int, MTR_PngFunctionSupported, const char *);
MTR_FUNC(void, MTR_PngInit, void);
MTR_FUNC(mtrPixels_t *, MTR_PngLoadSimple, const char *);
MTR_FUNC(bool, MTR_PngSaveSimple, const char *, mtrPixels_t *);

#endif
