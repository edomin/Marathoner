#ifndef MTR_ABSTRACTION_FONT_BINDING_COMMON_H
#define MTR_ABSTRACTION_FONT_BINDING_COMMON_H

MTR_FUNC(int, MTR_FontFunctionSupported, const char *);
MTR_FUNC(bool, MTR_FontInit, uint32_t, uint32_t);
MTR_FUNC(uint32_t, MTR_FontCreate, const char *, int);
MTR_FUNC(bool, MTR_FontAddAtlas, uint32_t, uint32_t, unsigned int);
MTR_FUNC(uint32_t, MTR_FontCacheTtf, const char *, uint32_t, unsigned int);
MTR_FUNC(void, MTR_FontFree, uint32_t);
MTR_FUNC(void, MTR_FontSetStyle, uint32_t, int);
MTR_FUNC(void, MTR_FontSetOutline, uint32_t, int);
MTR_FUNC(bool, MTR_FontDrawString_f, uint32_t, float, float, const char *);
MTR_FUNC(int, MTR_FontGetHeight, uint32_t);
MTR_FUNC(int, MTR_FontGetStringWidth, uint32_t, const char *);
MTR_FUNC(char *, MTR_FontGetName, uint32_t);

#endif
