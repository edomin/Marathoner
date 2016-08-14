#ifndef MTR_TTF_SDL2_TTF
#define MTR_TTF_SDL2_TTF

#include "SDL2/SDL_ttf.h"

#include "marathoner/plugin.h"

typedef struct mtrTtf_t {
    TTF_Font *font;
    char     *name;
} mtrTtf_t;

mtrIndexkeeper_t *mtrTtfKeeper;

#define MTR_FS_NORMAL           TTF_STYLE_NORMAL
#define MTR_FS_BOLD             TTF_STYLE_BOLD
#define MTR_FS_ITALIC           TTF_STYLE_ITALIC
#define MTR_FS_UNDERLINE        TTF_STYLE_UNDERLINE
#define MTR_FS_STRIKETHROUGH    TTF_STYLE_STRIKETHROUGH

#endif
