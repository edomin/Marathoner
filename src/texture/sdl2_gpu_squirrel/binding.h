#ifndef MTR_TEXTURE_SDL2_GPU_SQUIRREL_H
#define MTR_TEXTURE_SDL2_GPU_SQUIRREL_H

#include "squirrel.h"

#include "marathoner/plugin.h"
#include "../binding_common.h"

#define MTR_SOURCE_MODULE "Texture_SDL2_gpu"

#define MTR_BLEND_ZERO                  0
#define MTR_BLEND_ONE                   1
#define MTR_BLEND_SRC_COLOR             2
#define MTR_BLEND_DST_COLOR             3
#define MTR_BLEND_ONE_MINUS_SRC         4
#define MTR_BLEND_ONE_MINUS_DST         5
#define MTR_BLEND_SRC_ALPHA             6
#define MTR_BLEND_DST_ALPHA             7
#define MTR_BLEND_ONE_MINUS_SRC_ALPHA   8
#define MTR_BLEND_ONE_MINUS_DST_ALPHA   9

#include "marathoner/binding_common.h"

MTR_BINDING_COMMON_HEADER()

#endif
