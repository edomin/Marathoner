#ifndef MTR_LAUNCHER_H
#define MTR_LAUNCHER_H

#include <stdint.h>
#include <limits.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>

#define NK_INCLUDE_FIXED_TYPES
#define NK_INCLUDE_STANDARD_IO
#define NK_INCLUDE_STANDARD_VARARGS
#define NK_INCLUDE_DEFAULT_ALLOCATOR
#define NK_IMPLEMENTATION
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wcast-qual"
#pragma GCC diagnostic ignored "-Wfloat-equal"
#pragma GCC diagnostic ignored "-Wnull-dereference"
#include "nuklear.h"
#pragma GCC diagnostic pop

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wswitch-default"
#include "SDL2/SDL.h"
#pragma GCC diagnostic pop

#include "SDL2/SDL2_gfxPrimitives.h"
#include "SDL2/SDL2_gfxPrimitives_font.h"

#include "log.h"
#include "notification.h"
#include "configfile.h"
#include "messagebox.h"
#include "clipboard.h"
#include "so.h"
#include "plugin_loader.h"
#include "marathoner/marathoner.h"

#define WINDOW_WIDTH  800
#define WINDOW_HEIGHT 600

#if defined(__GNUC__) && !defined(__MINGW32__)
    #define MAX_PATH 8192
#endif

typedef struct mtrSubsystem {
    const char **plugin;
    int          pluginsCount;
    int          currentPlugin;
} mtrSubsystem;

typedef struct lchrFont {
    struct nk_user_font nk;
    int                 height;
    int                 width;
    unsigned char      *font;
} lchrFont;

static struct nkLauncher {
    SDL_Window       *dsp;
    SDL_Renderer     *backdrop;
    unsigned int      width;
    unsigned int      height;
    int               is_touch_down;
    int               touch_down_id;
    struct nk_context ctx;
    struct nk_buffer  cmds;
} launcher;

static struct mouse {
    int x;
    int y;
    int currentMousestate[5];
    int previousMousestate[5];
    int relativeWheel;
} mouse;

const uint8_t *currentKeystate;
uint8_t        previousKeystate[SDL_NUM_SCANCODES];
char           utf8char[SDL_TEXTINPUTEVENT_TEXT_SIZE];

bool *lchrPluginEnabled;

char getTextWidthBuffer[0x10000];

#endif
