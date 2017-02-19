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

#include "lazy_winapi.h"
#define NK_INCLUDE_FIXED_TYPES
#define NK_INCLUDE_STANDARD_IO
#define NK_INCLUDE_STANDARD_VARARGS
#define NK_INCLUDE_DEFAULT_ALLOCATOR
#define NK_IMPLEMENTATION
#include "nuklear.h"
#include "tigr.h"
#include "tinyfiledialogs.h"

#include "log.h"
#include "notification.h"
#include "configfile.h"
#include "messagebox.h"
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

#define UNUSED(expr) do { (void)(expr); } while (0)

#endif
