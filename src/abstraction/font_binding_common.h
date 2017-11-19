#ifndef MTR_ABSTRACTION_FONT_BINDING_COMMON_H
#define MTR_ABSTRACTION_FONT_BINDING_COMMON_H

MTR_FUNC(int, MTR_FontFunctionSupported, const char *);
MTR_FUNC(bool, MTR_FontInit, uint32_t, uint32_t);
MTR_FUNC(uint32_t, MTR_FontLoadTtf, const char *, int);
MTR_FUNC(void, MTR_FontFree, uint32_t);
MTR_FUNC(void, MTR_FontSetTtfStyle, uint32_t, int);
MTR_FUNC(void, MTR_FontSetTtfOutline, uint32_t, int);
MTR_FUNC(bool, MTR_FontRenderTtfString, uint32_t, uint32_t, uint8_t, uint8_t,
 uint8_t, const char *);
MTR_FUNC(uint32_t, MTR_FontCreateMbf, const char *, int, int, int);
MTR_FUNC(bool, MTR_FontAddMbfTextureTable, uint32_t, uint32_t, int);
MTR_FUNC(bool, MTR_FontDrawMbfString_f, uint32_t, float, float, const char *);
MTR_FUNC(int, MTR_FontGetHeight, uint32_t);
MTR_FUNC(int, MTR_FontGetStringWidth, uint32_t, const char *);
MTR_FUNC(char *, MTR_FontGetName, uint32_t);

#endif
