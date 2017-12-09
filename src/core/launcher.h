#ifndef MTR_LAUNCHER_H
#define MTR_LAUNCHER_H

#include <windows.h>
#include <shlwapi.h>
#include <stdint.h>
#include <limits.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define NK_INCLUDE_FIXED_TYPES
#define NK_INCLUDE_STANDARD_IO
#define NK_INCLUDE_STANDARD_VARARGS
#define NK_INCLUDE_DEFAULT_ALLOCATOR
#define NK_IMPLEMENTATION
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wcast-qual"
#pragma GCC diagnostic ignored "-Wfloat-equal"
#ifdef __MINGW64__
    #pragma GCC diagnostic ignored "-Wnull-dereference"
#endif
#include "nuklear.h"
#pragma GCC diagnostic pop
#include "tigr.h"

#include "log.h"
#include "notification.h"
#include "configfile.h"
#include "messagebox.h"
#include "clipboard.h"
#include "so.h"
#include "plugin_loader.h"
#include "marathoner/marathoner.h"

#define WINDOW_WIDTH  640
#define WINDOW_HEIGHT 600

typedef struct mtrSubsystem {
    const char **plugin;
    int          pluginsCount;
    int          currentPlugin;
} mtrSubsystem;

typedef struct nkTigrFont {
    struct nk_user_font nk;
    int                 height;
    TigrFont           *font;
} nkTigrFont;

static struct nk_tigr {
    Tigr             *dsp;
    Tigr             *backdrop;
    unsigned int      width;
    unsigned int      height;
    int               is_touch_down;
    int               touch_down_id;
    struct nk_context ctx;
    struct nk_buffer  cmds;
    int               clipX;
    int               clipY;
    int               clipW;
    int               clipH;
} tigr;

static struct mouse {
    int x;
    int y;
    int buttonsCurrent;
    int buttonsPrevious;
} mouse;

bool keysCurrent[256];
bool keysPrevious[256];

bool *lchrPluginEnabled;

char getTextWidthBuffer[0x10000];

#endif
