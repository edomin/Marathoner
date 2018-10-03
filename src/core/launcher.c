#include "launcher.h"

NK_API lchrFont *NkLchrFontCreateFromDefault(void) {
    lchrFont *font;
    font = malloc(sizeof(struct lchrFont));
    if (font != NULL) {
        font->font = gfxPrimitivesFontdata;
        font->height = 8;
        font->width = 8;
    }

    return font;
}

NK_INTERN void NkLchrClipboardPaste(nk_handle usr, struct nk_text_edit *edit) {
    char *text;

    text = MTR_ClipboardGetText();

    if (text)
        nk_textedit_paste(edit, text, nk_strlen(text));
    (void)usr;
    free(text);
}

NK_INTERN void NkLchrClipboardCopy(nk_handle usr, const char *text, int len) {
    char *str;

    str = 0;
    (void)usr;
    if (!len)
        return;
    str = (char*)malloc((size_t)len + 1);
    if (!str)
        return;
    memcpy(str, text, (size_t)len);
    str[len] = '\0';

    MTR_ClipboardPutText(str);

    free(str);
}

static float NkLchrFontGetTextWidth(nk_handle handle, float height,
 const char *text, int len) {
    lchrFont *font;

    font = (lchrFont*)handle.ptr;

    if (!font || !text)
        return 0;

    strncpy((char*)&getTextWidthBuffer, text, len);
    getTextWidthBuffer[len] = '\0';

    return len * font->width;
}

NK_API struct nk_context* NkLchrInit(lchrFont *defaultFont, SDL_Window *dsp,
 SDL_Renderer *backdrop, unsigned int width, unsigned int height) {
    struct nk_user_font *font;

    if (defaultFont == NULL || dsp == NULL || backdrop == NULL)
        return NULL;
    font = &defaultFont->nk;
    font->userdata = nk_handle_ptr(defaultFont);
    font->height = 8.0f;
    font->width = NkLchrFontGetTextWidth;

    launcher.dsp = dsp;
    launcher.backdrop = backdrop;
    launcher.width = width;
    launcher.height = height;
    launcher.is_touch_down = 0;
    launcher.touch_down_id = -1;

    nk_init_default(&launcher.ctx, font);
    launcher.ctx.clip.copy = NkLchrClipboardCopy;
    launcher.ctx.clip.paste = NkLchrClipboardPaste;
    launcher.ctx.clip.userdata = nk_handle_ptr(0);
    return &launcher.ctx;
}

int KeyDown(int key) {
    if (currentKeystate[key] && !previousKeystate[key])
        return 1;
    else if (!currentKeystate[key] && previousKeystate[key])
        return 0;
    else
        return -1;
}

void UpdateKey(int key) {
    struct nk_context *ctx;
    int                keydown;
    bool               control;
    SDL_Event          event;
    int                numEvents;

    ctx = &launcher.ctx;

    keydown = KeyDown(key);
    if (key == MTR_KEY_LSHIFT || key == MTR_KEY_RSHIFT) {
        if (keydown >= 0)
            nk_input_key(ctx, NK_KEY_SHIFT, keydown);
        if (keydown >= 0)
            nk_input_key(ctx, NK_KEY_SHIFT, keydown);
    } else if (key == MTR_KEY_DELETE) {
        if (keydown >= 0)
            nk_input_key(ctx, NK_KEY_DEL, keydown);
    } else if (key == MTR_KEY_RETURN) {
        if (keydown >= 0)
            nk_input_key(ctx, NK_KEY_ENTER, keydown);
    } else if (key == MTR_KEY_TAB) {
        if (keydown >= 0)
            nk_input_key(ctx, NK_KEY_TAB, keydown);
    } else if (key == MTR_KEY_LEFT) {
        if (keydown >= 0)
            nk_input_key(ctx, NK_KEY_LEFT, keydown);
    } else if (key == MTR_KEY_RIGHT) {
        if (keydown >= 0)
            nk_input_key(ctx, NK_KEY_RIGHT, keydown);
    } else if (key == MTR_KEY_UP) {
        if (keydown >= 0)
            nk_input_key(ctx, NK_KEY_UP, keydown);
    } else if (key == MTR_KEY_DOWN) {
        if (keydown >= 0)
            nk_input_key(ctx, NK_KEY_DOWN, keydown);
    } else if (key == MTR_KEY_BACKSPACE) {
        if (keydown >= 0)
            nk_input_key(ctx, NK_KEY_BACKSPACE, keydown);
    } else if (key == MTR_KEY_ESCAPE) {
        if (keydown >= 0)
            nk_input_key(ctx, NK_KEY_TEXT_RESET_MODE, keydown);
    } else if (key == MTR_KEY_PAGEUP) {
        if (keydown >= 0)
            nk_input_key(ctx, NK_KEY_SCROLL_UP, keydown);
    } else if (key == MTR_KEY_PAGEDOWN) {
        if (keydown >= 0)
            nk_input_key(ctx, NK_KEY_SCROLL_DOWN, keydown);
    } else if (key == MTR_KEY_HOME) {
        if (keydown >= 0) {
            nk_input_key(ctx, NK_KEY_TEXT_START, keydown);
            nk_input_key(ctx, NK_KEY_SCROLL_START, keydown);
        }
    } else if (key == MTR_KEY_END) {
        if (keydown >= 0) {
            nk_input_key(ctx, NK_KEY_TEXT_END, keydown);
            nk_input_key(ctx, NK_KEY_SCROLL_END, keydown);
        }
    }

    if ((currentKeystate[MTR_KEY_LCTRL])
     || (currentKeystate[MTR_KEY_RCTRL])
     || (currentKeystate[MTR_KEY_LGUI])
     || (currentKeystate[MTR_KEY_RGUI]))
        control = true;
    else
        control = false;

    if (key == 'C' && control) {
        if (keydown == 1)
            nk_input_key(ctx, NK_KEY_COPY, 1);
    }
    if (key == 'V' && control) {
        if (keydown == 1)
            nk_input_key(ctx, NK_KEY_PASTE, 1);
    }
    if (key == 'X' && control) {
        if (keydown == 1)
            nk_input_key(ctx, NK_KEY_CUT, 1);
    }
    if (key == 'Z' && control) {
        if (keydown == 1)
            nk_input_key(ctx, NK_KEY_TEXT_UNDO, 1);
    }
    if (key == 'R' && control) {
        if (keydown == 1)
            nk_input_key(ctx, NK_KEY_TEXT_REDO, 1);
    }
    if (key == 'A' && control) {
        if (keydown == 1)
            nk_input_key(ctx, NK_KEY_TEXT_SELECT_ALL, 1);
    }
    if (key != MTR_KEY_BACKSPACE &&
     key != MTR_KEY_LEFT &&
     key != MTR_KEY_RIGHT &&
     key != MTR_KEY_UP &&
     key != MTR_KEY_DOWN &&
     key != MTR_KEY_HOME &&
     key != MTR_KEY_DELETE &&
     key != MTR_KEY_RETURN &&
     key != MTR_KEY_END &&
     key != MTR_KEY_ESCAPE &&
     key != MTR_KEY_PAGEDOWN &&
     key != MTR_KEY_PAGEUP) {
        if (keydown == 1) {
            numEvents = SDL_PeepEvents(&event, 1, SDL_GETEVENT, SDL_TEXTINPUT,
             SDL_TEXTINPUT);

            if (numEvents > 0) {
                if (event.text.text != NULL)
                    nk_input_glyph(ctx, event.text.text);
            }
        }
    }
}

void NkLchrHandleEvents(void) {
    int                i;
    struct nk_context *ctx;
    uint32_t           mouseState;

    ctx = &launcher.ctx;

    for (i = 0; i < SDL_NUM_SCANCODES; i++) {
        previousKeystate[i] = (uint8_t)currentKeystate[i];
    }
    SDL_PumpEvents();

    mouseState = SDL_GetMouseState(&mouse.x, &mouse.y);
    for (i = 0; i < 5; i++)
    {
        mouse.previousMousestate[i] = mouse.currentMousestate[i];
        mouse.currentMousestate[i] = mouseState & SDL_BUTTON(i);
    }

    nk_input_motion(ctx, mouse.x, mouse.y);
    if ((mouse.currentMousestate[1]) && (!mouse.previousMousestate[1]))
        nk_input_button(ctx, NK_BUTTON_LEFT, mouse.x, mouse.y, 1);
    if ((mouse.currentMousestate[2]) && (!mouse.previousMousestate[2]))
        nk_input_button(ctx, NK_BUTTON_MIDDLE, mouse.x, mouse.y, 1);
    if ((mouse.currentMousestate[3]) && (!mouse.previousMousestate[3]))
        nk_input_button(ctx, NK_BUTTON_RIGHT, mouse.x, mouse.y, 1);
    if ((!mouse.currentMousestate[1]) && (mouse.previousMousestate[1]))
        nk_input_button(ctx, NK_BUTTON_LEFT, mouse.x, mouse.y, 0);
    if ((!mouse.currentMousestate[2]) && (mouse.previousMousestate[2]))
        nk_input_button(ctx, NK_BUTTON_MIDDLE, mouse.x, mouse.y, 0);
    if ((!mouse.currentMousestate[3]) && (mouse.previousMousestate[3]))
        nk_input_button(ctx, NK_BUTTON_RIGHT, mouse.x, mouse.y, 0);

    for (i = 'A'; i <= 'Z'; i++)
        UpdateKey(i);
    for (i = '0'; i <= '9'; i++)
        UpdateKey(i);
    UpdateKey(MTR_KEY_KP_0);
    UpdateKey(MTR_KEY_KP_1);
    UpdateKey(MTR_KEY_KP_2);
    UpdateKey(MTR_KEY_KP_3);
    UpdateKey(MTR_KEY_KP_4);
    UpdateKey(MTR_KEY_KP_5);
    UpdateKey(MTR_KEY_KP_6);
    UpdateKey(MTR_KEY_KP_7);
    UpdateKey(MTR_KEY_KP_8);
    UpdateKey(MTR_KEY_KP_9);
    UpdateKey(MTR_KEY_KP_MULTIPLY);
    UpdateKey(MTR_KEY_KP_PLUS);
    UpdateKey(MTR_KEY_KP_ENTER);
    UpdateKey(MTR_KEY_KP_MINUS);
    UpdateKey(MTR_KEY_KP_PERIOD);
    UpdateKey(MTR_KEY_KP_DIVIDE);
    UpdateKey(MTR_KEY_F1);
    UpdateKey(MTR_KEY_F2);
    UpdateKey(MTR_KEY_F3);
    UpdateKey(MTR_KEY_F4);
    UpdateKey(MTR_KEY_F5);
    UpdateKey(MTR_KEY_F6);
    UpdateKey(MTR_KEY_F7);
    UpdateKey(MTR_KEY_F8);
    UpdateKey(MTR_KEY_F9);
    UpdateKey(MTR_KEY_F10);
    UpdateKey(MTR_KEY_F11);
    UpdateKey(MTR_KEY_F12);
    UpdateKey(MTR_KEY_BACKSPACE);
    UpdateKey(MTR_KEY_TAB);
    UpdateKey(MTR_KEY_RETURN);
    UpdateKey(MTR_KEY_PAUSE);
    UpdateKey(MTR_KEY_CAPSLOCK);
    UpdateKey(MTR_KEY_ESCAPE);
    UpdateKey(MTR_KEY_SPACE);
    UpdateKey(MTR_KEY_PAGEUP);
    UpdateKey(MTR_KEY_PAGEDOWN);
    UpdateKey(MTR_KEY_END);
    UpdateKey(MTR_KEY_HOME);
    UpdateKey(MTR_KEY_LEFT);
    UpdateKey(MTR_KEY_UP);
    UpdateKey(MTR_KEY_RIGHT);
    UpdateKey(MTR_KEY_DOWN);
    UpdateKey(MTR_KEY_INSERT);
    UpdateKey(MTR_KEY_DELETE);
    UpdateKey(MTR_KEY_LGUI);
    UpdateKey(MTR_KEY_RGUI);
    UpdateKey(MTR_KEY_NUMLOCKCLEAR);
    UpdateKey(MTR_KEY_SCROLLLOCK);
    UpdateKey(MTR_KEY_LSHIFT);
    UpdateKey(MTR_KEY_RSHIFT);
    UpdateKey(MTR_KEY_LCTRL);
    UpdateKey(MTR_KEY_RCTRL);
    UpdateKey(MTR_KEY_LALT);
    UpdateKey(MTR_KEY_RALT);
    UpdateKey(MTR_KEY_SEMICOLON);
    UpdateKey(MTR_KEY_EQUALS);
    UpdateKey(MTR_KEY_COMMA);
    UpdateKey(MTR_KEY_MINUS);
    UpdateKey(MTR_KEY_PERIOD);
    UpdateKey(MTR_KEY_SLASH);
    UpdateKey(MTR_KEY_GRAVE);
    UpdateKey(MTR_KEY_LEFTBRACKET);
    UpdateKey(MTR_KEY_BACKSLASH);
    UpdateKey(MTR_KEY_RIGHTBRACKET);
    UpdateKey(MTR_KEY_APOSTROPHE);
}

void SetClippingRectangle(int x, int y, int w, int h) {
    SDL_Rect cliprect;

    cliprect.x = x;
    cliprect.y = y;
    cliprect.w = w;
    cliprect.h = h;

    SDL_RenderSetClipRect(launcher.backdrop, &cliprect);
}

void DrawLine(int x1, int y1, int x2, int y2, uint8_t r, uint8_t g, uint8_t b,
 uint8_t a) {
    lineRGBA(launcher.backdrop, x1, y1, x2, y2, r, g, b, a);
}

void DrawRect(int x, int y, int w, int h, uint8_t r, uint8_t g, uint8_t b,
 uint8_t a) {
    rectangleRGBA(launcher.backdrop, x, y, x + w, y + h, r, g, b, a);
}

void DrawFilledRect(int x, int y, int w, int h, uint8_t r, uint8_t g, uint8_t b,
 uint8_t a) {
    boxRGBA(launcher.backdrop, x, y, x + w, y + h, r, g, b, a);
}

void DrawCircle(int x, int y, int radius, uint8_t r, uint8_t g, uint8_t b,
 uint8_t a) {
    circleRGBA(launcher.backdrop, x, y, radius, r, g, b, a);
}

void DrawFilledCircle(int x, int y, int radius, uint8_t r, uint8_t g, uint8_t b,
 uint8_t a) {
    filledCircleRGBA(launcher.backdrop, x, y, radius, r, g, b, a);
}

void DrawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, uint8_t r,
 uint8_t g, uint8_t b, uint8_t a) {
    trigonRGBA(launcher.backdrop, x1, y1, x2, y2, x3, y3, r, g, b, a);
}

void DrawFilledTriangle(int x1, int y1, int x2, int y2, int x3, int y3,
 uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
    filledTrigonRGBA(launcher.backdrop, x1, y1, x2, y2, x3, y3, r, g, b, a);
}

void DrawString(lchrFont *font, int x, int y, uint8_t r, uint8_t g, uint8_t b,
 uint8_t a, const char *string) {
    gfxPrimitivesSetFont(font->font, font->width, font->height);
    stringRGBA(launcher.backdrop, x, y, string, r, g, b, a);
}

NK_API void NkLchrRender() {
    const struct nk_command *cmd;
    int                      i;
    float                    points[8];

    UNUSED(points);

    nk_foreach(cmd, &launcher.ctx) {
        switch (cmd->type) {
            case NK_COMMAND_NOP:
                break;
            case NK_COMMAND_SCISSOR:
                {
                    const struct nk_command_scissor *s = (
                     const struct nk_command_scissor*)cmd;
                    SetClippingRectangle((int)s->x, (int)s->y, (int)s->w,
                     (int)s->h);
                }
                break;
            case NK_COMMAND_LINE:
                {
                    const struct nk_command_line *l = (
                     const struct nk_command_line *)cmd;
                    DrawLine(l->begin.x, l->begin.y, l->end.x, l->end.y,
                     l->color.r, l->color.g, l->color.b, l->color.a);
                }
                break;
            case NK_COMMAND_RECT:
                {
                    const struct nk_command_rect *r = (
                     const struct nk_command_rect *)cmd;
                    DrawRect(r->x, r->y, r->w, r->h, r->color.r, r->color.g,
                     r->color.b, r->color.a);
                }
                break;
            case NK_COMMAND_RECT_FILLED:
                {
                    const struct nk_command_rect_filled *r = (
                     const struct nk_command_rect_filled *)cmd;
                    DrawFilledRect(r->x, r->y, r->w, r->h, r->color.r,
                     r->color.g, r->color.b, r->color.a);
                }
                break;
            case NK_COMMAND_CIRCLE:
                {
                    const struct nk_command_circle *c = (
                     const struct nk_command_circle *)cmd;
                    DrawCircle(c->x, c->y, c->w, c->color.r, c->color.g,
                     c->color.b, c->color.a);
                }
                break;
            case NK_COMMAND_CIRCLE_FILLED:
                {
                    const struct nk_command_circle_filled *c = (
                     const struct nk_command_circle_filled *)cmd;
                    DrawFilledCircle(c->x, c->y, c->w, c->color.r,
                     c->color.g, c->color.b, c->color.a);
                }
                break;
            case NK_COMMAND_TRIANGLE:
                {
                    const struct nk_command_triangle*t = (
                     const struct nk_command_triangle*)cmd;

                    DrawTriangle(t->a.x, t->a.y, t->b.x, t->b.y, t->c.x, t->c.y,
                     t->color.r, t->color.g, t->color.b, t->color.a);
                }
                break;
            case NK_COMMAND_TRIANGLE_FILLED:
                {
                    const struct nk_command_triangle_filled *t = (
                     const struct nk_command_triangle_filled *)cmd;
                    DrawFilledTriangle(t->a.x, t->a.y, t->b.x, t->b.y, t->c.x,
                     t->c.y, t->color.r, t->color.g, t->color.b, t->color.a);
                }
                break;
            case NK_COMMAND_POLYGON:
                {
                    const struct nk_command_polygon *p = (
                     const struct nk_command_polygon*)cmd;
                    for (i = 0; i < p->point_count; i++) {
                        if (i == p->point_count - 1)
                            DrawLine(p->points[i].x, p->points[i].y,
                             p->points[0].x, p->points[0].y, p->color.r,
                             p->color.g, p->color.b, p->color.a);
                        else
                            DrawLine(p->points[i].x, p->points[i].y,
                             p->points[i + 1].x, p->points[i + 1].y, p->color.r,
                             p->color.g, p->color.b, p->color.a);
                    }
                }
                break;
            case NK_COMMAND_POLYGON_FILLED:
                {
                    const struct nk_command_polygon_filled *p = (
                     const struct nk_command_polygon_filled *)cmd;
                    for (i = 0; i < p->point_count; i++) {
                        if (i == p->point_count - 1)
                            DrawLine(p->points[i].x, p->points[i].y,
                             p->points[0].x, p->points[0].y, p->color.r,
                             p->color.g, p->color.b, p->color.a);
                        else
                            DrawLine(p->points[i].x, p->points[i].y,
                             p->points[i + 1].x, p->points[i + 1].y, p->color.r,
                             p->color.g, p->color.b, p->color.a);
                    }
                }
                break;
            case NK_COMMAND_POLYLINE:
                {
                    const struct nk_command_polyline *p = (
                     const struct nk_command_polyline *)cmd;
                    for (i = 0; i < p->point_count - 1; i++)
                        DrawLine(p->points[i].x, p->points[i].y,
                         p->points[i + 1].x, p->points[i + 1].y, p->color.r,
                         p->color.g, p->color.b, p->color.a);
                }
                break;
            case NK_COMMAND_TEXT:
                {
                    const struct nk_command_text *t = (
                     const struct nk_command_text *)cmd;
                    lchrFont *font = (lchrFont *)t->font->userdata.ptr;
                    DrawString(font, t->x, t->y, t->foreground.r,
                     t->foreground.g, t->foreground.b, t->foreground.a,
                     t->string);
                }
                break;
            case NK_COMMAND_CURVE:
                {
                    const struct nk_command_curve *q = (
                     const struct nk_command_curve *)cmd;

//                    points[0] = (float)q->begin.x;
//                    points[1] = (float)q->begin.y;
//                    points[2] = (float)q->ctrl[0].x;
//                    points[3] = (float)q->ctrl[0].y;
//                    points[4] = (float)q->ctrl[1].x;
//                    points[5] = (float)q->ctrl[1].y;
//                    points[6] = (float)q->end.x;
//                    points[7] = (float)q->end.y;

                    DrawLine(q->begin.x, q->begin.y, q->ctrl[0].x, q->ctrl[0].y,
                     q->color.r, q->color.g, q->color.b, q->color.a);
                    DrawLine(q->ctrl[0].x, q->ctrl[0].y, q->ctrl[1].x,
                     q->ctrl[1].y, q->color.r, q->color.g, q->color.b,
                     q->color.a);
                    DrawLine(q->ctrl[1].x, q->ctrl[1].y, q->end.x, q->end.y,
                     q->color.r, q->color.g, q->color.b, q->color.a);
                }
                break;
            case NK_COMMAND_ARC:
                //const struct nk_command_arc *a = (const struct nk_command_arc *)cmd;
                //color = nk_color_to_allegro_color(a->color);
                //al_draw_arc((float)a->cx, (float)a->cy, (float)a->r, a->a[0],
                //    a->a[1], color, (float)a->line_thickness);
                break;
            case NK_COMMAND_RECT_MULTI_COLOR:
            case NK_COMMAND_IMAGE:
            case NK_COMMAND_ARC_FILLED:
            default:
                break;
        }
    }
    nk_clear(&launcher.ctx);
}

NK_API void NkLchrShutdown(void) {
    nk_free(&launcher.ctx);
    memset(&launcher, 0, sizeof(launcher));
}

int CountSubsystems(int pluginsFound, mtrPlugin *pluginData) {
    int  i;
    int  j;
    int  subsystemsCount;
    bool newSubsystem;

    subsystemsCount = 0;
    for (i = 0; i < pluginsFound; i++) {
        if (strcmp(pluginData[i].report->subsystem, "binding") != 0
         && strcmp(pluginData[i].report->subsystem, "utils") != 0
         && strcmp(pluginData[i].report->subsystem, "abstraction") != 0) {
            if (i == 0) {
                subsystemsCount++;
                continue;
            }
            newSubsystem = true;
            for (j = 0; j < i; j++) {
                if (strcmp(pluginData[j].report->subsystem, "binding") != 0
                 && strcmp(pluginData[j].report->subsystem, "utils") != 0
                 && strcmp(pluginData[j].report->subsystem, "abstraction") != 0)
                {
                    if (strcmp(pluginData[j].report->subsystem,
                     pluginData[i].report->subsystem) == 0) {
                        newSubsystem = false;
                        break;
                    }
                }
            }
            if (newSubsystem)
                subsystemsCount++;
        }
    }
    return subsystemsCount;
}

char **GetSubsystemList(int pluginsFound, mtrPlugin *pluginData, int ssCount) {
    char **ssList;
    int    i;
    int    j;
    bool   newSubsystem;
    int    currentSubsystem;

    ssList = malloc(sizeof(char *) * ssCount);
    if (ssList == NULL)
        return NULL;

    currentSubsystem = 0;

    for (i = 0; i < pluginsFound; i++) {
        if (strcmp(pluginData[i].report->subsystem, "binding") != 0
         && strcmp(pluginData[i].report->subsystem, "utils") != 0
         && strcmp(pluginData[i].report->subsystem, "abstraction") != 0) {
            if (i == 0) {
                ssList[currentSubsystem] = malloc(
                 sizeof(char) * (strlen(pluginData[i].report->subsystem) + 1));
                if (ssList[currentSubsystem] == NULL)
                    return NULL;
                strcpy(ssList[currentSubsystem],
                 pluginData[i].report->subsystem);
                currentSubsystem++;
                continue;
            }
            newSubsystem = true;
            for (j = 0; j < i; j++) {
                if (strcmp(pluginData[j].report->subsystem, "binding") != 0
                 && strcmp(pluginData[j].report->subsystem, "utils") != 0
                 && strcmp(pluginData[j].report->subsystem, "abstraction") != 0)
                {
                    if (strcmp(pluginData[j].report->subsystem,
                     pluginData[i].report->subsystem) == 0) {
                        newSubsystem = false;
                        break;
                    }
                }
            }
            if (newSubsystem) {
                ssList[currentSubsystem] = malloc(
                 sizeof(char) * (strlen(pluginData[i].report->subsystem) + 1));
                if (ssList[currentSubsystem] == NULL)
                    return NULL;
                strcpy(ssList[currentSubsystem],
                 pluginData[i].report->subsystem);
                currentSubsystem++;
            }
        }
    }
    return ssList;
}

bool ConfigSave(mtrSubsystem *ssScript, char scriptName[64], int pluginsCount,
 mtrPlugin *pluginData, int subsystemsCount, char **ssList,
 mtrSubsystem **subsystem)
{
    bool success;
    int i;

    success = MTR_ConfigfileWriteString(CONFIGFILE_PATH, "Autorun", "plugin",
     ssScript->plugin[ssScript->currentPlugin]);
    if (!success)
        return false;
    success = MTR_ConfigfileWriteString(CONFIGFILE_PATH, "Autorun", "script",
     scriptName);
    if (!success)
        return false;

    for (i = 0; i < pluginsCount; i++) {
        success = MTR_ConfigfileWriteBool(CONFIGFILE_PATH, "Module",
         pluginData[i].report->moduleID, lchrPluginEnabled[i]);
        if (!success)
            return false;
    }

    for (i = 0; i < subsystemsCount; i++) {
        success = MTR_ConfigfileWriteString(CONFIGFILE_PATH, "Subsystem",
         ssList[i], subsystem[i]->plugin[subsystem[i]->currentPlugin]);
        if (!success)
            return false;
    }

    return true;
}

bool RunEngine() {
#if 0
    #ifdef UNICODE
    const wchar_t *appName;
    int appNameLen;
    int convResultLen;
    #else
    const char appName[] = "Marathoner.exe";
    #endif
    STARTUPINFO sti;
    PROCESS_INFORMATION pi;
    bool success;
    uint32_t error;
    char *errorText;

    #ifdef UNICODE
    appNameLen = strlen("Marathoner.exe");
    appName = malloc(sizeof(wchar_t) * (appNameLen + 1));
    if (appName == NULL) {
        MTR_Notify("Unable to allocate memory for Application name", 0,
         MTR_LMT_ERROR);
        return false;
    }
    convResultLen = MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED,
     "Marathoner.exe", -1, appName, appNameLen);
    if (convResultLen == 0) {
        error = GetLastError();
        free(appName);
        MTR_Notify("Unable to convert Application name to wide char", 0,
         MTR_LMT_ERROR);
        errorText = MTR_WindowsErrorCodeToText(error);
        MTR_Notify(errorText, 0, MTR_LMT_ERROR);
        return false;
    }
    appName[appNameLen] = '/0';
    #endif

    ZeroMemory(&sti, sizeof(STARTUPINFO));
    sti.cb=sizeof(STARTUPINFO);
    success = CreateProcess(appName, NULL, NULL, NULL, false,
     CREATE_DEFAULT_ERROR_MODE | CREATE_NEW_PROCESS_GROUP |
     DETACHED_PROCESS | NORMAL_PRIORITY_CLASS, NULL, NULL, &sti, &pi);
    if (success == false) { /* Error occured */
        error = GetLastError();
        errorText = MTR_WindowsErrorCodeToText(error);
        MTR_Notify(errorText, 0, MTR_LMT_ERROR);
    } else {
        CloseHandle(pi.hThread);
        CloseHandle(pi.hProcess);
    }
    #ifdef UNICODE
    free(appName);
    #endif
    return success;
#endif /* 0 */
return false;
}

int main(int argc, char** argv) {
    int                error;
    int                i;
    int                j;
    char              *temp;
    const char        *ctemp;
    //char               mtemp[MAX_PATH];
    bool               ok;
    SDL_Window        *screen;
    SDL_Renderer      *renderer;
    lchrFont          *font;
    struct nk_context *ctx;
    struct nk_color    headerColor;
    const float        autorunRatio[] = {128, 256, 64};
    char               scriptName[64];
    int                scriptNameLen;
    mtrSubsystem      *ssScript;
    const char        *pluginInvalid = " ";
    mtrSubsystem     **subsystem;
    int                subsystemsCount;
    char             **ssList;
    const float        subsystemRatio[] = {128, 256};
    bool quit;

    chdir("..");

    quit = false;
    ssScript = NULL;
    subsystem = NULL;

    headerColor = nk_rgb(0x99, 0x99, 0x00);

    MTR_LogInit("Launcher.log");

    MTR_LogWrite("Reporting Launcher version:", 0, MTR_LMT_INFO);
    MTR_LogWrite_i("Majon:", 1, MTR_LMT_INFO,
     (MTR_VERSION_LAUNCHER & 0xFF0000) >> 16);
    MTR_LogWrite_i("Minor:", 1, MTR_LMT_INFO,
     (MTR_VERSION_LAUNCHER & 0x00FF00) >> 8);
    MTR_LogWrite_i("Patch:", 1, MTR_LMT_INFO,
     MTR_VERSION_LAUNCHER & 0x0000FF);
    MTR_LogWrite("Searching available plugins", 0, MTR_LMT_INFO);

    MTR_ClearFileFilters();

    MTR_SoInit(MTR_IKDM_MEDIUM, 256);

    error = MTR_LoadAllPlugins(NULL);
    if (error != 0)
        return error;

    subsystemsCount = CountSubsystems(mtrPluginsFound, mtrPluginData);
    ssList = GetSubsystemList(mtrPluginsFound, mtrPluginData, subsystemsCount);

    if (subsystemsCount > 0) {
        subsystem = malloc(sizeof(mtrSubsystem *) * subsystemsCount);
        if (subsystem == NULL) {
            MTR_Notify("Unable to allocate memory for subsystem's data "
             "structures", 0, MTR_LMT_FATAL);
            return 5;
        }
    } else {
        MTR_Notify("Unable to find modules of subsystems",  0, MTR_LMT_FATAL);
        return 6;
    }

    if (ssList == NULL) {
        MTR_Notify("Unable to allocate memory for subsystem's list",
         0, MTR_LMT_FATAL);
        return 7;
    }

    for (i = 0; i < subsystemsCount; i++) {
        subsystem[i] = malloc(sizeof(mtrSubsystem));
        if (subsystem[i] == NULL) {
            MTR_Notify("Unable to allocate memory for data of subsystem",
             0, MTR_LMT_FATAL);
            return 8;
        }
        subsystem[i]->pluginsCount = 0;
    }

    lchrPluginEnabled = malloc(sizeof(bool) * mtrPluginsFound);

    for (i = 0; i < mtrPluginsFound; i++) {
        lchrPluginEnabled[i] = false;

        for (j = 0; j < subsystemsCount; j++) {
            if (strcmp(mtrPluginData[i].report->subsystem, ssList[j]) == 0) {
                subsystem[j]->pluginsCount++;
                break;
            }
        }
    }

    for (i = 0; i < subsystemsCount; i++) {
        subsystem[i]->plugin = malloc(
         sizeof(char *) * (subsystem[i]->pluginsCount + 1));
        if (subsystem[i]->plugin == NULL) {
            MTR_Notify("Unable to allocate memory for names subsystem's "
             "plugins", 0, MTR_LMT_FATAL);
            return 9;
        }
        subsystem[i]->plugin[0] = pluginInvalid;

        if (strcmp(ssList[i], "script") == 0)
            ssScript = subsystem[i];
    }

    for (i = 0; i < subsystemsCount; i++)
        subsystem[i]->pluginsCount = 1;

    for (i = 0; i < mtrPluginsFound; i++) {
        for (j = 0; j < subsystemsCount; j++) {
            if (strcmp(mtrPluginData[i].report->subsystem, ssList[j]) == 0) {
                int pluginsCount = subsystem[j]->pluginsCount;
                char *moduleID = mtrPluginData[i].report->moduleID;
                subsystem[j]->plugin[pluginsCount] = moduleID;
                subsystem[j]->pluginsCount++;
                break;
            }
        }
    }

    for (i = 0; i < subsystemsCount; i++) {
        temp = MTR_ConfigfileReadString(CONFIGFILE_PATH, "Subsystem", ssList[i],
         " ");
        for (j = 0; j < subsystem[i]->pluginsCount; j++) {
            if (strcmp(subsystem[i]->plugin[j], temp) == 0) {
                subsystem[i]->currentPlugin = j;
                free(temp);
                break;
            }
        }
    }

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) == 0)
        MTR_LogWrite(
         "SDL library with video and events subsystems initialized", 1,
         MTR_LMT_INFO);
    else {
        MTR_Notify(
         "Unable to initialize SDL library with video and events "
         "subsystems", 1, MTR_LMT_ERROR);
        return 10;
    }

    screen = SDL_CreateWindow("Launcher", SDL_WINDOWPOS_UNDEFINED,
     SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_OPENGL);
    if (screen != NULL)
        MTR_LogWrite("Window created", 1, MTR_LMT_INFO);
    else {
        MTR_Notify("Unable to create window", 1, MTR_LMT_ERROR);
        return 11;
    }

    renderer = SDL_CreateRenderer(screen, 1,
     SDL_RENDERER_SOFTWARE);
    if (renderer != NULL)
        MTR_LogWrite("Renderer initialized:", 1, MTR_LMT_INFO);
    else {
        MTR_Notify("Unable to initialize renderer", 1, MTR_LMT_ERROR);
        SDL_DestroyWindow(screen);
        return 11;
    }

    font = NkLchrFontCreateFromDefault();
    if (font == NULL) {
        MTR_Notify("Unable to create default font's structure", 0,
         MTR_LMT_FATAL);
        return 12;
    }
    MTR_LogWrite("Font structure from default font created", 0, MTR_LMT_INFO);

    ctx = NkLchrInit(font, screen, renderer, WINDOW_WIDTH, WINDOW_HEIGHT);
    if (ctx == NULL) {
        MTR_Notify("Unable to create Nuklear context", 0,
         MTR_LMT_FATAL);
        return 13;
    }
    MTR_LogWrite("Nuklear context created", 0, MTR_LMT_INFO);

    mouse.x = 0;
    mouse.y = 0;
    for (i = 0; i < 5; i++) {
        mouse.currentMousestate[i] = 0;
        mouse.previousMousestate[i] = 0;
    }

    currentKeystate = SDL_GetKeyboardState(NULL);

    for (i = 0; i < 255; i++) {
        previousKeystate[i] = false;
    }

    MTR_LogWrite("Reading '" CONFIGFILE_PATH "' for autorun options", 0,
     MTR_LMT_INFO);

    if (!MTR_ConfigfileKeyExists(CONFIGFILE_PATH, "Autorun", "action"))
        MTR_ConfigfileWriteString(CONFIGFILE_PATH, "Autorun", "action",
         "runScript");

    temp = MTR_ConfigfileReadString(CONFIGFILE_PATH, "Autorun", "action",
     "none");
    if (strcmp(temp, "runScript") != 0) {
        MTR_Notify("Invalid autorun action command", 1, MTR_LMT_WARNING);
        if (MTR_ConfigfileWriteString(CONFIGFILE_PATH, "Autorun", "action",
         "runScript"))
            MTR_Notify("Autorun action command changed to 'runScript'", 1,
             MTR_LMT_NOTE);
        else
            MTR_Notify("Unable to change action command to 'runScript'", 1,
             MTR_LMT_WARNING);
    }
    free(temp);

    if (!MTR_ConfigfileKeyExists(CONFIGFILE_PATH, "Autorun", "plugin"))
        MTR_ConfigfileWriteString(CONFIGFILE_PATH, "Autorun", "plugin",
         "none");

    temp = MTR_ConfigfileReadString(CONFIGFILE_PATH, "Autorun", "plugin",
     "none");
    ok = false;
    for (i = 0; i < mtrPluginsFound; i++) {
        if (strcmp(mtrPluginData[i].report->moduleID, temp) == 0) {
            ok = true;
            break;
        }
    }
    if (ssScript != NULL) {
        ssScript->currentPlugin = 0;
        for (i = 0; i <= ssScript->pluginsCount - 1; i++) {
            if (strcmp(ssScript->plugin[i], temp) == 0) {
                ssScript->currentPlugin = i;
                break;
            }
        }
    }
    if (!ok || ssScript == NULL)
        MTR_Notify("Ivalid autorun plugin", 1, MTR_LMT_ERROR);
    free(temp);

    temp = MTR_ConfigfileReadString(CONFIGFILE_PATH, "Autorun",
     "script", "none");
    if (strcmp(temp, "none") != 0) {
        strcpy(scriptName, temp);
        scriptNameLen = strlen(scriptName);
    }
    free(temp);

    for (i = 0; i < mtrPluginsFound; i++) {
        if (!MTR_ConfigfileKeyExists(CONFIGFILE_PATH, "Module",
         mtrPluginData[i].report->moduleID)) {
            MTR_ConfigfileWriteBool(CONFIGFILE_PATH, "Module",
             mtrPluginData[i].report->moduleID, true);
        }
        lchrPluginEnabled[i] = MTR_ConfigfileReadBool(CONFIGFILE_PATH,
         "Module", mtrPluginData[i].report->moduleID, true);
    }


    while (!quit) {
    //while (!tigrClosed(screen) && !tigrKeyDown(screen, TK_ESCAPE) && !quit) {
        SDL_Delay(0.06f);
        nk_input_begin(ctx);
        NkLchrHandleEvents();
        nk_input_end(ctx);

        /* GUI */
        if (nk_begin(ctx, "Menu", nk_rect(0, 0, WINDOW_WIDTH, 24),
         NK_WINDOW_BORDER | NK_WINDOW_NO_SCROLLBAR)) {
            nk_layout_row_dynamic(ctx, 16, 5);
            if (nk_button_label(ctx, "Save")) {
                scriptName[scriptNameLen] = '\0';
                ok = ConfigSave(ssScript, scriptName, mtrPluginsFound,
                 mtrPluginData, subsystemsCount, ssList, subsystem);
                if (!ok)
                    MTR_Notify("Unable to save preferences to configfile", 0,
                     MTR_LMT_ERROR);
            }
            if (nk_button_label(ctx, "Save and Exit")) {
                scriptName[scriptNameLen] = '\0';
                ok = ConfigSave(ssScript, scriptName, mtrPluginsFound,
                 mtrPluginData, subsystemsCount, ssList, subsystem);
                if (!ok)
                    MTR_Notify("Unable to save preferences to configfile", 0,
                     MTR_LMT_ERROR);
                else
                    quit = true;
            }
            if (nk_button_label(ctx, "Discard and Exit"))
                quit = true;
            if (nk_button_label(ctx, "Save and Run")) {
                scriptName[scriptNameLen] = '\0';
                ok = ConfigSave(ssScript, scriptName, mtrPluginsFound,
                 mtrPluginData, subsystemsCount, ssList, subsystem);
                if (!ok)
                    MTR_Notify("Unable to save preferences to configfile", 0,
                     MTR_LMT_ERROR);
                else {
                    if (!RunEngine())
                        MTR_Notify("Unable to run Engine", 0, MTR_LMT_ERROR);
                    else
                        quit = true;
                }
            }
            if (nk_button_label(ctx, "Discard and Run")) {
                if (!RunEngine())
                    MTR_Notify("Unable to run Engine", 0, MTR_LMT_ERROR);
                else
                    quit = true;
            }

            nk_layout_row_dynamic(ctx, 16, 5);
            if (nk_button_label(ctx, "Import Configuration"))
                {}
            if (nk_button_label(ctx, "Export Configuration"))
                {}
        }
        nk_end(ctx);

        if (nk_begin(ctx, "Main", nk_rect(0, 25, WINDOW_WIDTH, WINDOW_HEIGHT - 25),
         NK_WINDOW_BORDER)) {
            nk_layout_row_dynamic(ctx, 16, 1);
            nk_label_colored(ctx, "Autorun:", NK_TEXT_LEFT, headerColor);

            nk_layout_row(ctx, NK_STATIC, 16, 3, autorunRatio);
            nk_label(ctx, "Action:", NK_TEXT_LEFT);
            nk_label(ctx, "runScript", NK_TEXT_LEFT);
            nk_spacing(ctx, 1);
            if (ssScript != NULL) {
                nk_label(ctx, "Plugin:", NK_TEXT_LEFT);
                ssScript->currentPlugin = nk_combo(ctx, ssScript->plugin,
                 ssScript->pluginsCount, ssScript->currentPlugin, 16,
                 nk_vec2(200, 200));
                nk_spacing(ctx, 1);
            }
            nk_label(ctx, "Script:", NK_TEXT_LEFT);
            nk_edit_string(ctx, NK_EDIT_SIMPLE, scriptName, &scriptNameLen, 64,
             nk_filter_default);
            if (nk_button_label(ctx, "Browse")) {
                temp = MTR_GetCurrentDirectory();
                if (temp == NULL) {
                    temp = malloc(sizeof(char) * (scriptNameLen + 3));
                    strcpy(temp, "./");
                    strcat(temp, scriptName);
                } else {
                    temp = realloc(temp,
                     sizeof(char) * (strlen(temp) + strlen(scriptName) + 2));
                    strcat(temp, "\\");
                    strcat(temp, scriptName);
                }
                ctemp = MTR_ShowOpenFileDialog("Choose autorun script...", temp,
                 NULL);
                if (ctemp != NULL) {
                    free(temp);
                    temp = MTR_GetCurrentDirectory();
                    if (temp == NULL) {
                        temp = realloc(temp,
                         sizeof(char) * (
                         strlen(temp) + strlen("Launcher.exe") + 2));
                        strcat(temp, "./");
                        strcat(temp, "Launcher.exe");
                    } else {
                        temp = realloc(temp,
                         sizeof(char) * (
                         strlen(temp) + strlen("Launcher.exe") + 2));
                        strcat(temp, "\\");
                        strcat(temp, "Launcher.exe");
                    }

                    /*if (PathRelativePathTo(mtemp, temp, FILE_ATTRIBUTE_NORMAL,
                     ctemp, FILE_ATTRIBUTE_NORMAL)) {
                        if (mtemp[0] == '.' && mtemp[1] == '\\') {
                            strcpy(scriptName, mtemp + sizeof(char) * 2);
                            scriptNameLen = strlen(scriptName);
                        } else {
                            strcpy(scriptName, ctemp);
                            scriptNameLen = strlen(scriptName);
                        }
                    } else*/ {
                        strcpy(scriptName, ctemp);
                        scriptNameLen = strlen(scriptName);
                    }
                }
                free(temp);
            }

            nk_layout_row_dynamic(ctx, 16, 1);
            nk_label_colored(ctx, "Subsystem:", NK_TEXT_LEFT, headerColor);

            nk_layout_row(ctx, NK_STATIC, 16, 2, subsystemRatio);
            for (i = 0; i < subsystemsCount; i++) {
                nk_label(ctx, ssList[i], NK_TEXT_LEFT);
                subsystem[i]->currentPlugin = nk_combo(ctx,
                 subsystem[i]->plugin, subsystem[i]->pluginsCount,
                 subsystem[i]->currentPlugin, 16, nk_vec2(200, 200));
            }

            nk_layout_row_dynamic(ctx, 16, 1);
            nk_label_colored(ctx, "Enabled modules:", NK_TEXT_LEFT,
             headerColor);

            nk_layout_row_static(ctx, 16, 128, 2);
            if (nk_button_label(ctx, "Enable all")) {
                for (i = 0; i < mtrPluginsFound; i++)
                    lchrPluginEnabled[i] = true;
            }
            if (nk_button_label(ctx, "Disable all")) {
                for (i = 0; i < mtrPluginsFound; i++)
                    lchrPluginEnabled[i] = false;
            }

            nk_layout_row_dynamic(ctx, mtrPluginsFound * 16, 2);

            if (nk_group_begin(ctx, "left", NK_WINDOW_NO_SCROLLBAR)) {
                nk_layout_row_dynamic(ctx, 25, 1);
                for (i = 0; i < mtrPluginsFound / 2; i++)
                    lchrPluginEnabled[i] = nk_check_label(ctx,
                     mtrPluginData[i].report->moduleID, lchrPluginEnabled[i]);
                nk_group_end(ctx);
            }
            if (nk_group_begin(ctx, "right", NK_WINDOW_NO_SCROLLBAR)) {
                nk_layout_row_dynamic(ctx, 25, 1);
                for (i = mtrPluginsFound / 2 + 1; i < mtrPluginsFound; i++)
                    lchrPluginEnabled[i] = nk_check_label(ctx,
                     mtrPluginData[i].report->moduleID, lchrPluginEnabled[i]);
                nk_group_end(ctx);
            }
        }
        nk_end(ctx);

        /* Draw */
        boxRGBA(launcher.backdrop, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, 19, 43,
         81, 0xFF);

        NkLchrRender();
        SDL_RenderPresent(launcher.backdrop);
    }

    MTR_LogWrite("Quiting Launcher", 0, MTR_LMT_INFO);

    NkLchrShutdown();
    MTR_LogWrite("Nuklear context destroyed", 0, MTR_LMT_INFO);
    SDL_DestroyRenderer(launcher.backdrop);
    MTR_LogWrite("SDL2 Renderer destroyed", 0, MTR_LMT_INFO);
    SDL_DestroyWindow(launcher.dsp);
    MTR_LogWrite("Screen destroyed", 0, MTR_LMT_INFO);

    /* Freing allocated structures and unloading libraries */
    for (i = 0; i < mtrPluginsFound; i++) {
        MTR_LogWrite_s("Unloading plugin", 0, MTR_LMT_INFO,
         mtrPluginData[i].report->moduleID);
        MTR_SoClose(mtrPluginData[i].so);
    }

    free(mtrPluginData);
    free(lchrPluginEnabled);
    for (i = 0; i < subsystemsCount; i++) {
        free(ssList[i]);
        free(subsystem[i]->plugin);
        free(subsystem[i]);
    }
    free(ssList);
    free(subsystem);

    MTR_LogWrite("Launcher stopped", 0, MTR_LMT_INFO);

    return 0;
}
