#ifndef MTR_TTF_BINDING_COMMON_H
#define MTR_TTF_BINDING_COMMON_H

MTR_FUNC(int, MTR_TtfFunctionSupported, const char *);
MTR_FUNC(bool, MTR_TtfInit, uint32_t, uint32_t);
MTR_FUNC(void, MTR_TtfQuit, void);
MTR_FUNC(uint32_t, MTR_TtfLoad, const char *, int);
MTR_FUNC(void, MTR_TtfFree, uint32_t);
MTR_FUNC(int, MTR_TtfGetFontHeight, uint32_t);
MTR_FUNC(bool, MTR_TtfGetStringSizes, uint32_t, const char *, int *, int *);
MTR_FUNC(int, MTR_TtfGetStringWidth, uint32_t, const char *);
MTR_FUNC(void, MTR_TtfSetFontStyle, uint32_t, int);
MTR_FUNC(void, MTR_TtfSetFontOutline, uint32_t, int);
MTR_FUNC(mtrPixels_t *, MTR_TtfRenderString, uint32_t, uint8_t, uint8_t,
 uint8_t, const char *);

#endif
