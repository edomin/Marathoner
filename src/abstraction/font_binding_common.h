#ifndef MTR_ABSTRACTION_FONT_BINDING_COMMON_H
#define MTR_ABSTRACTION_FONT_BINDING_COMMON_H

typedef int (MTR_CALL * MTR_FontFunctionSupportedFunc)(const char *);
MTR_FontFunctionSupportedFunc MTR_FontFunctionSupported;

typedef bool (MTR_CALL * MTR_FontInitFunc)(uint32_t, uint32_t);
MTR_FontInitFunc MTR_FontInit;

typedef uint32_t (MTR_CALL * MTR_FontLoadTtfFunc)(const char *, int);
MTR_FontLoadTtfFunc MTR_FontLoadTtf;

typedef void (MTR_CALL * MTR_FontFreeFunc)(uint32_t);
MTR_FontFreeFunc MTR_FontFree;

typedef void (MTR_CALL * MTR_FontSetTtfStyleFunc)(uint32_t, int);
MTR_FontSetTtfStyleFunc MTR_FontSetTtfStyle;

typedef void (MTR_CALL * MTR_FontSetTtfOutlineFunc)(uint32_t, int);
MTR_FontSetTtfOutlineFunc MTR_FontSetTtfOutline;

typedef bool (MTR_CALL * MTR_FontRenderTtfStringFunc)(uint32_t, uint32_t,
 uint8_t, uint8_t, uint8_t, const char *);
MTR_FontRenderTtfStringFunc MTR_FontRenderTtfString;

typedef uint32_t (MTR_CALL * MTR_FontCreateMbfFunc)(const char *, int, int, int);
MTR_FontCreateMbfFunc MTR_FontCreateMbf;

typedef bool (MTR_CALL * MTR_FontAddMbfTextureTableFunc)(uint32_t, uint32_t,
 int);
MTR_FontAddMbfTextureTableFunc MTR_FontAddMbfTextureTable;

typedef bool (MTR_CALL * MTR_FontDrawMbfString_fFunc)(uint32_t, float, float,
 const char *);
MTR_FontDrawMbfString_fFunc MTR_FontDrawMbfString_f;

typedef int (MTR_CALL * MTR_FontGetHeightFunc)(uint32_t);
MTR_FontGetHeightFunc MTR_FontGetHeight;

typedef int (MTR_CALL * MTR_FontGetStringWidthFunc)(uint32_t, const char *);
MTR_FontGetStringWidthFunc MTR_FontGetStringWidth;

typedef char *(MTR_CALL * MTR_FontGetNameFunc)(uint32_t);
MTR_FontGetNameFunc MTR_FontGetName;

#endif
