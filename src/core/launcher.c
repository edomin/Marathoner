#include "launcher.h"

NK_API nkTigrFont *nk_tigr_font_create_from_default(void)
{
    nkTigrFont *font;
    font = malloc(sizeof(struct nkTigrFont));
    if (font != NULL)
    {
        font->font = tfont;
        font->height = 12;
    }

    return font;
}

NK_INTERN void nk_tigr_clipboard_paste(nk_handle usr, struct nk_text_edit *edit)
{
    char *text;

    text = MTR_ClipboardGetText();

    if (text)
        nk_textedit_paste(edit, text, nk_strlen(text));
    (void)usr;
    free(text);
}

NK_INTERN void nk_tigr_clipboard_copy(nk_handle usr, const char *text, int len)
{
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

static float nk_tigr_font_get_text_width(nk_handle handle, float height,
 const char *text, int len)
{
    nkTigrFont *font;

    font = (nkTigrFont*)handle.ptr;

    if (!font || !text)
        return 0;

    strncpy((char*)&getTextWidthBuffer, text, len);
    getTextWidthBuffer[len] = '\0';

    return tigrTextWidth(font->font, getTextWidthBuffer);
}

NK_API struct nk_context* nk_tigr_init(nkTigrFont *tigrfont, Tigr *dsp,
 Tigr *backdrop, unsigned int width, unsigned int height)
{
    struct nk_user_font *font;

    if (tigrfont == NULL || dsp == NULL || backdrop == NULL)
        return NULL;
    font = &tigrfont->nk;
    font->userdata = nk_handle_ptr(tigrfont);
    font->height = 12.0f;
    font->width = nk_tigr_font_get_text_width;

    tigr.dsp = dsp;
    tigr.backdrop = backdrop;
    tigr.width = width;
    tigr.height = height;
    tigr.is_touch_down = 0;
    tigr.touch_down_id = -1;

    nk_init_default(&tigr.ctx, font);
    tigr.ctx.clip.copy = nk_tigr_clipboard_copy;
    tigr.ctx.clip.paste = nk_tigr_clipboard_paste;
    tigr.ctx.clip.userdata = nk_handle_ptr(0);
    return &tigr.ctx;
}

int KeyDown(int key)
{
    if (keysCurrent[key] && !keysPrevious[key])
        return 1;
    else if (!keysCurrent[key] && keysPrevious[key])
        return 0;
    else
        return -1;
}

void UpdateKey(int key)
{
    struct nk_context *ctx;
    int                keydown;
    bool               control;
    uint32_t           uchar;

    ctx = &tigr.ctx;

    keysPrevious[key] = keysCurrent[key];
    if (tigrKeyHeld(tigr.dsp, key) != 0)
        keysCurrent[key] = true;
    else
        keysCurrent[key] = false;
    keydown = KeyDown(key);
    if (key == TK_LSHIFT || key == TK_RSHIFT)
    {
        if (keydown >= 0)
            nk_input_key(ctx, NK_KEY_SHIFT, keydown);
        if (keydown >= 0)
            nk_input_key(ctx, NK_KEY_SHIFT, keydown);
    }
    else if (key == TK_DELETE)
    {
        if (keydown >= 0)
            nk_input_key(ctx, NK_KEY_DEL, keydown);
    }
    else if (key == TK_RETURN)
    {
        if (keydown >= 0)
            nk_input_key(ctx, NK_KEY_ENTER, keydown);
    }
    else if (key == TK_TAB)
    {
        if (keydown >= 0)
            nk_input_key(ctx, NK_KEY_TAB, keydown);
    }
    else if (key == TK_LEFT)
    {
        if (keydown >= 0)
            nk_input_key(ctx, NK_KEY_LEFT, keydown);
    }
    else if (key == TK_RIGHT)
    {
        if (keydown >= 0)
            nk_input_key(ctx, NK_KEY_RIGHT, keydown);
    }
    else if (key == TK_UP)
    {
        if (keydown >= 0)
            nk_input_key(ctx, NK_KEY_UP, keydown);
    }
    else if (key == TK_DOWN)
    {
        if (keydown >= 0)
            nk_input_key(ctx, NK_KEY_DOWN, keydown);
    }
    else if (key == TK_BACKSPACE)
    {
        if (keydown >= 0)
            nk_input_key(ctx, NK_KEY_BACKSPACE, keydown);
    }
    else if (key == TK_ESCAPE)
    {
        if (keydown >= 0)
            nk_input_key(ctx, NK_KEY_TEXT_RESET_MODE, keydown);
    }
    else if (key == TK_PAGEUP)
    {
        if (keydown >= 0)
            nk_input_key(ctx, NK_KEY_SCROLL_UP, keydown);
    }
    else if (key == TK_PAGEDN)
    {
        if (keydown >= 0)
            nk_input_key(ctx, NK_KEY_SCROLL_DOWN, keydown);
    }
    else if (key == TK_HOME)
    {
        if (keydown >= 0)
        {
            nk_input_key(ctx, NK_KEY_TEXT_START, keydown);
            nk_input_key(ctx, NK_KEY_SCROLL_START, keydown);
        }
    }
    else if (key == TK_END)
    {
        if (keydown >= 0)
        {
            nk_input_key(ctx, NK_KEY_TEXT_END, keydown);
            nk_input_key(ctx, NK_KEY_SCROLL_END, keydown);
        }
    }

    if ((tigrKeyHeld(tigr.dsp, TK_LCONTROL) != 0)
     || (tigrKeyHeld(tigr.dsp, TK_RCONTROL) != 0)
     || (tigrKeyHeld(tigr.dsp, TK_LWIN) != 0)
     || (tigrKeyHeld(tigr.dsp, TK_RWIN) != 0))
        control = true;
    else
        control = false;

    if (key == 'C' && control)
    {
        if (keydown == 1)
            nk_input_key(ctx, NK_KEY_COPY, 1);
    }
    if (key == 'V' && control)
    {
        if (keydown == 1)
            nk_input_key(ctx, NK_KEY_PASTE, 1);
    }
    if (key == 'X' && control)
    {
        if (keydown == 1)
            nk_input_key(ctx, NK_KEY_CUT, 1);
    }
    if (key == 'Z' && control)
    {
        if (keydown == 1)
            nk_input_key(ctx, NK_KEY_TEXT_UNDO, 1);
    }
    if (key == 'R' && control)
    {
        if (keydown == 1)
            nk_input_key(ctx, NK_KEY_TEXT_REDO, 1);
    }
    if (key == 'A' && control)
    {
        if (keydown == 1)
            nk_input_key(ctx, NK_KEY_TEXT_SELECT_ALL, 1);
    }
    if (key != TK_BACKSPACE &&
     key != TK_LEFT &&
     key != TK_RIGHT &&
     key != TK_UP &&
     key != TK_DOWN &&
     key != TK_HOME &&
     key != TK_DELETE &&
     key != TK_RETURN &&
     key != TK_END &&
     key != TK_ESCAPE &&
     key != TK_PAGEDN &&
     key != TK_PAGEUP)
    {
        if (keydown == 1)
        {
            uchar = tigrReadChar(tigr.dsp);

            if (uchar != 0)
                nk_input_unicode(ctx, uchar);
        }
    }
}

void nk_tigr_handle_events(void)
{
    int                i;
    struct nk_context *ctx;

    ctx = &tigr.ctx;

    mouse.buttonsPrevious = mouse.buttonsCurrent;
    tigrMouse(tigr.dsp, &mouse.x, &mouse.y, &mouse.buttonsCurrent);

    nk_input_motion(ctx, mouse.x, mouse.y);
    if (((mouse.buttonsCurrent & 1) == 1) && ((mouse.buttonsPrevious & 1) == 0))
        nk_input_button(ctx, NK_BUTTON_LEFT, mouse.x, mouse.y, 1);
    if (((mouse.buttonsCurrent & 2) == 1) && ((mouse.buttonsPrevious & 2) == 0))
        nk_input_button(ctx, NK_BUTTON_MIDDLE, mouse.x, mouse.y, 1);
    if (((mouse.buttonsCurrent & 4) == 1) && ((mouse.buttonsPrevious & 4) == 0))
        nk_input_button(ctx, NK_BUTTON_RIGHT, mouse.x, mouse.y, 1);
    if (((mouse.buttonsCurrent & 1) == 0) && ((mouse.buttonsPrevious & 1) == 1))
        nk_input_button(ctx, NK_BUTTON_LEFT, mouse.x, mouse.y, 0);
    if (((mouse.buttonsCurrent & 2) == 0) && ((mouse.buttonsPrevious & 2) == 1))
        nk_input_button(ctx, NK_BUTTON_MIDDLE, mouse.x, mouse.y, 0);
    if (((mouse.buttonsCurrent & 4) == 0) && ((mouse.buttonsPrevious & 4) == 1))
        nk_input_button(ctx, NK_BUTTON_RIGHT, mouse.x, mouse.y, 0);

    for (i = 'A'; i <= 'Z'; i++)
    {
        UpdateKey(i);
    }
    for (i = '0'; i <= '9'; i++)
    {
        UpdateKey(i);
    }
    UpdateKey(TK_PAD0);
    UpdateKey(TK_PAD1);
    UpdateKey(TK_PAD2);
    UpdateKey(TK_PAD3);
    UpdateKey(TK_PAD4);
    UpdateKey(TK_PAD5);
    UpdateKey(TK_PAD6);
    UpdateKey(TK_PAD7);
    UpdateKey(TK_PAD8);
    UpdateKey(TK_PAD9);
	UpdateKey(TK_PADMUL);
	UpdateKey(TK_PADADD);
	UpdateKey(TK_PADENTER);
	UpdateKey(TK_PADSUB);
	UpdateKey(TK_PADDOT);
	UpdateKey(TK_PADDIV);
	UpdateKey(TK_F1);
	UpdateKey(TK_F2);
	UpdateKey(TK_F3);
	UpdateKey(TK_F4);
	UpdateKey(TK_F5);
	UpdateKey(TK_F6);
	UpdateKey(TK_F7);
	UpdateKey(TK_F8);
	UpdateKey(TK_F9);
	UpdateKey(TK_F10);
	UpdateKey(TK_F11);
	UpdateKey(TK_F12);
	UpdateKey(TK_BACKSPACE);
	UpdateKey(TK_TAB);
	UpdateKey(TK_RETURN);
	UpdateKey(TK_SHIFT);
	UpdateKey(TK_CONTROL);
	UpdateKey(TK_ALT);
	UpdateKey(TK_PAUSE);
	UpdateKey(TK_CAPSLOCK);
	UpdateKey(TK_ESCAPE);
	UpdateKey(TK_SPACE);
	UpdateKey(TK_PAGEUP);
	UpdateKey(TK_PAGEDN);
	UpdateKey(TK_END);
	UpdateKey(TK_HOME);
	UpdateKey(TK_LEFT);
	UpdateKey(TK_UP);
	UpdateKey(TK_RIGHT);
	UpdateKey(TK_DOWN);
	UpdateKey(TK_INSERT);
	UpdateKey(TK_DELETE);
	UpdateKey(TK_LWIN);
	UpdateKey(TK_RWIN);
	UpdateKey(TK_NUMLOCK);
	UpdateKey(TK_SCROLL);
	UpdateKey(TK_LSHIFT);
	UpdateKey(TK_RSHIFT);
	UpdateKey(TK_LCONTROL);
	UpdateKey(TK_RCONTROL);
	UpdateKey(TK_LALT);
	UpdateKey(TK_RALT);
	UpdateKey(TK_SEMICOLON);
	UpdateKey(TK_EQUALS);
	UpdateKey(TK_COMMA);
	UpdateKey(TK_MINUS);
	UpdateKey(TK_DOT);
	UpdateKey(TK_SLASH);
	UpdateKey(TK_BACKTICK);
	UpdateKey(TK_LSQUARE);
	UpdateKey(TK_BACKSLASH);
	UpdateKey(TK_RSQUARE);
	UpdateKey(TK_TICK);
}

void SetClippingRectangle(int x, int y, int w, int h)
{
    tigr.clipX = x;
    tigr.clipY = y;
    tigr.clipW = w;
    tigr.clipH = h;
}

void DrawLine(int x1, int y1, int x2, int y2, uint8_t r, uint8_t g, uint8_t b,
 uint8_t a)
{
    TPixel color;
    int    actualX1 = x1;
    int    actualY1 = y1;
    int    actualX2 = x2;
    int    actualY2 = y2;

    if (actualX1 < tigr.clipX)
    {
        actualX2 = actualX2 - (tigr.clipX - actualX1);
        actualX1 = tigr.clipX;
    }
    if (actualY1 < tigr.clipY)
    {
        actualY2 = actualY2 - (tigr.clipY - actualY1);
        actualY1 = tigr.clipY;
    }
    if (actualX2 > tigr.clipX + tigr.clipW)
        actualX2 = tigr.clipX + tigr.clipW;
    if (actualY2 > tigr.clipY + tigr.clipH)
        actualY2 = tigr.clipY + tigr.clipH;

    color = tigrRGBA(r, g, b, a);
    tigrLine(tigr.backdrop, actualX1, actualY1, actualX2, actualY2, color);
}

void DrawRect(int x, int y, int w, int h, uint8_t r, uint8_t g, uint8_t b,
 uint8_t a)
{
    TPixel color;
    int    actualX = x;
    int    actualY = y;
    int    actualW = w;
    int    actualH = h;

    if (actualX < tigr.clipX)
    {
        actualW = actualW - (tigr.clipX - actualX);
        actualX = tigr.clipX;
    }
    if (actualY < tigr.clipY)
    {
        actualH = actualH - (tigr.clipY - actualY);
        actualY = tigr.clipY;
    }
    if (actualX + actualW > tigr.clipX + tigr.clipW)
        actualW = (tigr.clipX + tigr.clipW) - actualX;
    if (actualY + actualH > tigr.clipY + tigr.clipH)
        actualH = (tigr.clipY + tigr.clipH) - actualY;

    color = tigrRGBA(r, g, b, a);
    tigrRect(tigr.backdrop, actualX, actualY, actualW, actualH, color);
}

void DrawFilledRect(int x, int y, int w, int h, uint8_t r, uint8_t g, uint8_t b,
 uint8_t a)
{
    TPixel color;
    int    actualX = x;
    int    actualY = y;
    int    actualW = w;
    int    actualH = h;

    if (actualX < tigr.clipX)
    {
        actualW = actualW - (tigr.clipX - actualX);
        actualX = tigr.clipX;
    }
    if (actualY < tigr.clipY)
    {
        actualH = actualH - (tigr.clipY - actualY);
        actualY = tigr.clipY;
    }
    if (actualX + actualW > tigr.clipX + tigr.clipW)
        actualW = (tigr.clipX + tigr.clipW) - actualX;
    if (actualY + actualH > tigr.clipY + tigr.clipH)
        actualH = (tigr.clipY + tigr.clipH) - actualY;

    color = tigrRGBA(r, g, b, a);
    tigrFill(tigr.backdrop, actualX, actualY, actualW, actualH, color);
}

void DrawString(nkTigrFont *font, int x, int y, uint8_t r, uint8_t g, uint8_t b,
 uint8_t a, const char *string)
{
    TPixel color;
    int    textWidth = tigrTextWidth(font->font, string);

    if ((x < tigr.clipX) || (x + textWidth > tigr.clipX + tigr.clipW) ||
     (y < tigr.clipY) || (y + 12 > tigr.clipY + tigr.clipH))
        return;

    color = tigrRGBA(r, g, b, a);
    tigrPrint(tigr.backdrop, font->font, x, y, color, string);
}

NK_API void nk_tigr_render()
{
    const struct nk_command *cmd;
    int                      i;
    float                    points[8];

    UNUSED(points);

    nk_foreach(cmd, &tigr.ctx)
    {
        switch (cmd->type)
        {
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
                    DrawRect(c->x, c->y, c->w, c->h, c->color.r, c->color.g,
                     c->color.b, c->color.a);
                }
                break;
            case NK_COMMAND_CIRCLE_FILLED:
                {
                    const struct nk_command_circle_filled *c = (
                     const struct nk_command_circle_filled *)cmd;
                    DrawFilledRect(c->x, c->y, c->w, c->h, c->color.r,
                     c->color.g, c->color.b, c->color.a);
                }
                break;
            case NK_COMMAND_TRIANGLE:
                {
                    const struct nk_command_triangle*t = (
                     const struct nk_command_triangle*)cmd;
                    DrawLine(t->a.x, t->a.y, t->b.x, t->b.y, t->color.r,
                     t->color.g, t->color.b, t->color.a);
                    DrawLine(t->b.x, t->b.y, t->c.x, t->c.y, t->color.r,
                     t->color.g, t->color.b, t->color.a);
                    DrawLine(t->c.x, t->c.y, t->a.x, t->a.y, t->color.r,
                     t->color.g, t->color.b, t->color.a);
                }
                break;
            case NK_COMMAND_TRIANGLE_FILLED:
                {
                    const struct nk_command_triangle_filled *t = (
                     const struct nk_command_triangle_filled *)cmd;
                    DrawLine(t->a.x, t->a.y, t->b.x, t->b.y, t->color.r,
                     t->color.g, t->color.b, t->color.a);
                    DrawLine(t->b.x, t->b.y, t->c.x, t->c.y, t->color.r,
                     t->color.g, t->color.b, t->color.a);
                    DrawLine(t->c.x, t->c.y, t->a.x, t->a.y, t->color.r,
                     t->color.g, t->color.b, t->color.a);
                }
                break;
            case NK_COMMAND_POLYGON:
                {
                    const struct nk_command_polygon *p = (
                     const struct nk_command_polygon*)cmd;
                    for (i = 0; i < p->point_count; i++)
                    {
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
                    for (i = 0; i < p->point_count; i++)
                    {
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
                     const struct nk_command_text*)cmd;
                    nkTigrFont *font = (nkTigrFont*)t->font->userdata.ptr;
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
    nk_clear(&tigr.ctx);
}

NK_API void nk_tigr_shutdown(void)
{
    nk_free(&tigr.ctx);
    memset(&tigr, 0, sizeof(tigr));
}

int CountSubsystems(int pluginsFound, mtrPlugin *pluginData)
{
    int  i;
    int  j;
    int  subsystemsCount;
    bool newSubsystem;

    subsystemsCount = 0;
    for (i = 0; i < pluginsFound; i++)
    {
        if (strcmp(pluginData[i].report->subsystem, "binding") != 0
         && strcmp(pluginData[i].report->subsystem, "utils") != 0
         && strcmp(pluginData[i].report->subsystem, "abstraction") != 0)
        {
            if (i == 0)
            {
                subsystemsCount++;
                continue;
            }
            newSubsystem = true;
            for (j = 0; j < i; j++)
            {
                if (strcmp(pluginData[j].report->subsystem, "binding") != 0
                 && strcmp(pluginData[j].report->subsystem, "utils") != 0
                 && strcmp(pluginData[j].report->subsystem, "abstraction") != 0)
                {
                    if (strcmp(pluginData[j].report->subsystem,
                     pluginData[i].report->subsystem) == 0)
                    {
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

char **GetSubsystemList(int pluginsFound, mtrPlugin *pluginData, int ssCount)
{
    char **ssList;
    int    i;
    int    j;
    bool   newSubsystem;
    int    currentSubsystem;

    ssList = malloc(sizeof(char *) * ssCount);
    if (ssList == NULL)
        return NULL;

    currentSubsystem = 0;

    for (i = 0; i < pluginsFound; i++)
    {
        if (strcmp(pluginData[i].report->subsystem, "binding") != 0
         && strcmp(pluginData[i].report->subsystem, "utils") != 0
         && strcmp(pluginData[i].report->subsystem, "abstraction") != 0)
        {
            if (i == 0)
            {
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
            for (j = 0; j < i; j++)
            {
                if (strcmp(pluginData[j].report->subsystem, "binding") != 0
                 && strcmp(pluginData[j].report->subsystem, "utils") != 0
                 && strcmp(pluginData[j].report->subsystem, "abstraction") != 0)
                {
                    if (strcmp(pluginData[j].report->subsystem,
                     pluginData[i].report->subsystem) == 0)
                    {
                        newSubsystem = false;
                        break;
                    }
                }
            }
            if (newSubsystem)
            {
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

    for (i = 0; i < pluginsCount; i++)
    {
        success = MTR_ConfigfileWriteBool(CONFIGFILE_PATH, "Module",
         pluginData[i].report->moduleID, lchrPluginEnabled[i]);
        if (!success)
            return false;
    }

    for (i = 0; i < subsystemsCount; i++)
    {
        success = MTR_ConfigfileWriteString(CONFIGFILE_PATH, "Subsystem",
         ssList[i], subsystem[i]->plugin[subsystem[i]->currentPlugin]);
        if (!success)
            return false;
    }

    return true;
}

bool RunEngine()
{
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
    if (appName == NULL)
    {
        MTR_Notify("Unable to allocate memory for Application name.", 0,
         MTR_LMT_ERROR);
        return false;
    }
    convResultLen = MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED,
     "Marathoner.exe", -1, appName, appNameLen);
    if (convResultLen == 0)
    {
        error = GetLastError();
        free(appName);
        MTR_Notify("Unable to convert Application name to wide char.", 0,
         MTR_LMT_ERROR);
        errorText = WinErrorCodeToText(error);
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
    if (success == false) /* Error occured */
    {
        error = GetLastError();
        errorText = WinErrorCodeToText(error);
        MTR_Notify(errorText, 0, MTR_LMT_ERROR);
    }
    else
    {
        CloseHandle(pi.hThread);
        CloseHandle(pi.hProcess);
    }
    #ifdef UNICODE
    free(appName);
    #endif
    return success;
}

int main(int argc, char** argv)
{
    int                error;
    int                i;
    int                j;
    char              *temp;
    const char        *ctemp;
    char               mtemp[MAX_PATH];
    bool               ok;
    Tigr              *screen;
    Tigr              *backdrop;
    nkTigrFont        *font;
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

    MTR_SoInit(MTR_IKDM_SMALL, 256);

    error = MTR_LoadAllPlugins(NULL);
    if (error != 0)
        return error;

    subsystemsCount = CountSubsystems(mtrPluginsFound, mtrPluginData);
    ssList = GetSubsystemList(mtrPluginsFound, mtrPluginData, subsystemsCount);

    if (subsystemsCount > 0)
    {
        subsystem = malloc(sizeof(mtrSubsystem *) * subsystemsCount);
        if (subsystem == NULL)
        {
            MTR_Notify("Unable to allocate memory for subsystem's data "
             "structures", 0, MTR_LMT_FATAL);
            return 5;
        }
    }
    else
    {
        MTR_Notify("Unable to find modules of subsystems",  0, MTR_LMT_FATAL);
        return 6;
    }

    if (ssList == NULL)
    {
        MTR_Notify("Unable to allocate memory for subsystem's list",
         0, MTR_LMT_FATAL);
        return 7;
    }

    for (i = 0; i < subsystemsCount; i++)
    {
        subsystem[i] = malloc(sizeof(mtrSubsystem));
        if (subsystem[i] == NULL)
        {
            MTR_Notify("Unable to allocate memory for data of subsystem",
             0, MTR_LMT_FATAL);
            return 8;
        }
        subsystem[i]->pluginsCount = 0;
    }

    lchrPluginEnabled = malloc(sizeof(bool) * mtrPluginsFound);

    for (i = 0; i < mtrPluginsFound; i++)
    {
        lchrPluginEnabled[i] = false;

        for (j = 0; j < subsystemsCount; j++)
        {
            if (strcmp(mtrPluginData[i].report->subsystem, ssList[j]) == 0)
            {
                subsystem[j]->pluginsCount++;
                break;
            }
        }
    }

    for (i = 0; i < subsystemsCount; i++)
    {
        subsystem[i]->plugin = malloc(
         sizeof(char *) * (subsystem[i]->pluginsCount + 1));
        if (subsystem[i]->plugin == NULL)
        {
            MTR_Notify("Unable to allocate memory for names subsystem's plugins",
             0, MTR_LMT_FATAL);
            return 9;
        }
        subsystem[i]->plugin[0] = pluginInvalid;

        if (strcmp(ssList[i], "script") == 0)
            ssScript = subsystem[i];
    }

    for (i = 0; i < subsystemsCount; i++)
    {
        subsystem[i]->pluginsCount = 1;
    }

    for (i = 0; i < mtrPluginsFound; i++)
    {
        for (j = 0; j < subsystemsCount; j++)
        {
            if (strcmp(mtrPluginData[i].report->subsystem, ssList[j]) == 0)
            {
                int pluginsCount = subsystem[j]->pluginsCount;
                char *moduleID = mtrPluginData[i].report->moduleID;
                subsystem[j]->plugin[pluginsCount] = moduleID;
                subsystem[j]->pluginsCount++;
                break;
            }
        }
    }

    for (i = 0; i < subsystemsCount; i++)
    {
        temp = MTR_ConfigfileReadString(CONFIGFILE_PATH, "Subsystem", ssList[i],
         " ");
        for (j = 0; j < subsystem[i]->pluginsCount; j++)
        {
            if (strcmp(subsystem[i]->plugin[j], temp) == 0)
            {
                subsystem[i]->currentPlugin = j;
                free(temp);
                break;
            }
        }
    }

    screen = tigrWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Launcher", TIGR_FIXED);
    if (screen == NULL)
    {
        MTR_Notify("Unable to create window", 0, MTR_LMT_FATAL);
        return 10;
    }
    MTR_LogWrite("Window created", 0, MTR_LMT_INFO);

    backdrop = tigrBitmap(screen->w, screen->h);
    if (backdrop == NULL)
    {
        MTR_Notify("Unable to create backbuffer", 0, MTR_LMT_FATAL);
        return 11;
    }
    MTR_LogWrite("Backbuffer created", 0, MTR_LMT_INFO);

    font = nk_tigr_font_create_from_default();
    if (font == NULL)
    {
        MTR_Notify("Unable to create default font's structure", 0,
         MTR_LMT_FATAL);
        return 12;
    }
    MTR_LogWrite("Font structure from default font created", 0, MTR_LMT_INFO);

    ctx = nk_tigr_init(font, screen, backdrop, screen->w, screen->h);
    if (ctx == NULL)
    {
        MTR_Notify("Unable to create Nuklear context", 0,
         MTR_LMT_FATAL);
        return 13;
    }
    MTR_LogWrite("Nuklear context created", 0, MTR_LMT_INFO);

    mouse.x = 0;
    mouse.y = 0;
    mouse.buttonsCurrent = 0;
    mouse.buttonsPrevious = 0;

    for (i = 0; i < 255; i++)
    {
        keysCurrent[i] = false;
        keysPrevious[i] = false;
    }

    MTR_LogWrite("Reading 'Marathoner.cfg' for autorun options", 0,
      MTR_LMT_INFO);

    temp = MTR_ConfigfileReadString(CONFIGFILE_PATH, "Autorun", "action",
      "none");
    if (strcmp(temp, "runScript") != 0)
    {
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

    temp = MTR_ConfigfileReadString(CONFIGFILE_PATH, "Autorun", "plugin",
     "none");
    ok = false;
    for (i = 0; i < mtrPluginsFound; i++)
    {
        if (strcmp(mtrPluginData[i].report->moduleID, temp) == 0)
        {
            ok = true;
            break;
        }
    }
    if (ssScript != NULL)
    {
        ssScript->currentPlugin = 0;
        for (i = 0; i <= ssScript->pluginsCount; i++)
            if (strcmp(ssScript->plugin[i], temp) == 0)
            {
                ssScript->currentPlugin = i;
                break;
            }
    }
    if (!ok || ssScript == NULL)
        MTR_Notify("Ivalid autorun plugin", 1, MTR_LMT_ERROR);
    free(temp);

    temp = MTR_ConfigfileReadString(CONFIGFILE_PATH, "Autorun",
     "script", "none");
    if (strcmp(temp, "none") != 0)
    {
        strcpy(scriptName, temp);
        scriptNameLen = strlen(scriptName);
    }
    free(temp);

    for (i = 0; i < mtrPluginsFound; i++)
    {
        lchrPluginEnabled[i] = MTR_ConfigfileReadBool(CONFIGFILE_PATH,
         "Module", mtrPluginData[i].report->moduleID, true);
    }


    while (!tigrClosed(screen) && !tigrKeyDown(screen, TK_ESCAPE) && !quit)
    {
        Sleep(0.06);
        nk_input_begin(ctx);
        nk_tigr_handle_events();
        nk_input_end(ctx);

        /* GUI */
        if (nk_begin(ctx, "Menu", nk_rect(0, 0, screen->w, 24),
         NK_WINDOW_BORDER | NK_WINDOW_NO_SCROLLBAR))
        {
            nk_layout_row_dynamic(ctx, 16, 5);
            if (nk_button_label(ctx, "Save"))
            {
                scriptName[scriptNameLen] = '\0';
                ok = ConfigSave(ssScript, scriptName, mtrPluginsFound,
                 mtrPluginData, subsystemsCount, ssList, subsystem);
                if (!ok)
                    MTR_Notify("Unable to save preferences to configfile", 0,
                     MTR_LMT_ERROR);
            }
            if (nk_button_label(ctx, "Save and Exit"))
            {
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
            {
                quit = true;
            }
            if (nk_button_label(ctx, "Save and Run"))
            {
                scriptName[scriptNameLen] = '\0';
                ok = ConfigSave(ssScript, scriptName, mtrPluginsFound,
                 mtrPluginData, subsystemsCount, ssList, subsystem);
                if (!ok)
                    MTR_Notify("Unable to save preferences to configfile", 0,
                     MTR_LMT_ERROR);
                else
                {
                    if (!RunEngine())
                        MTR_Notify("Unable to run Engine", 0, MTR_LMT_ERROR);
                    else
                        quit = true;
                }
            }
            if (nk_button_label(ctx, "Discard and Run"))
            {
                if (!RunEngine())
                    MTR_Notify("Unable to run Engine", 0, MTR_LMT_ERROR);
                else
                    quit = true;
            }

            nk_layout_row_dynamic(ctx, 16, 5);
            if (nk_button_label(ctx, "Import Configuration"))
            {

            }
            if (nk_button_label(ctx, "Export Configuration"))
            {

            }
        }
        nk_end(ctx);

        if (nk_begin(ctx, "Main", nk_rect(0, 25, screen->w, screen->h - 25),
         NK_WINDOW_BORDER))
        {
            nk_layout_row_dynamic(ctx, 16, 1);
            nk_label_colored(ctx, "Autorun:", NK_TEXT_LEFT, headerColor);

            nk_layout_row(ctx, NK_STATIC, 16, 3, autorunRatio);
            nk_label(ctx, "Action:", NK_TEXT_LEFT);
            nk_label(ctx, "runScript", NK_TEXT_LEFT);
            nk_spacing(ctx, 1);
            if (ssScript != NULL)
            {
                nk_label(ctx, "Plugin:", NK_TEXT_LEFT);
                ssScript->currentPlugin = nk_combo(ctx, ssScript->plugin,
                 ssScript->pluginsCount, ssScript->currentPlugin, 16,
                 nk_vec2(200, 200));
                nk_spacing(ctx, 1);
            }
            nk_label(ctx, "Script:", NK_TEXT_LEFT);
            nk_edit_string(ctx, NK_EDIT_SIMPLE, scriptName, &scriptNameLen, 64,
             nk_filter_default);
            if (nk_button_label(ctx, "Browse"))
            {
                temp = MTR_GetCurrentDirectory();
                if (temp == NULL)
                {
                    temp = malloc(sizeof(char) * (scriptNameLen + 3));
                    strcpy(temp, "./");
                    strcat(temp, scriptName);
                }
                else
                {
                    temp = realloc(temp,
                     sizeof(char) * (strlen(temp) + strlen(scriptName) + 2));
                    strcat(temp, "\\");
                    strcat(temp, scriptName);
                }
                ctemp = MTR_ShowOpenFileDialog("Choose autorun script...", temp,
                 NULL);
                if (ctemp != NULL)
                {
                    free(temp);
                    temp = MTR_GetCurrentDirectory();
                    if (temp == NULL)
                    {
                        temp = realloc(temp,
                         sizeof(char) * (
                         strlen(temp) + strlen("Launcher.exe") + 2));
                        strcat(temp, "./");
                        strcat(temp, "Launcher.exe");
                    }
                    else
                    {
                        temp = realloc(temp,
                         sizeof(char) * (
                         strlen(temp) + strlen("Launcher.exe") + 2));
                        strcat(temp, "\\");
                        strcat(temp, "Launcher.exe");
                    }

                    if (PathRelativePathTo(mtemp, temp, FILE_ATTRIBUTE_NORMAL,
                     ctemp, FILE_ATTRIBUTE_NORMAL))
                    {
                        if (mtemp[0] == '.' && mtemp[1] == '\\')
                        {
                            strcpy(scriptName, mtemp + sizeof(char) * 2);
                            scriptNameLen = strlen(scriptName);
                        }
                        else
                        {
                            strcpy(scriptName, ctemp);
                            scriptNameLen = strlen(scriptName);
                        }
                    }
                    else
                    {
                        strcpy(scriptName, ctemp);
                        scriptNameLen = strlen(scriptName);
                    }
                }
                free(temp);
            }

            nk_layout_row_dynamic(ctx, 16, 1);
            nk_label_colored(ctx, "Subsystem:", NK_TEXT_LEFT, headerColor);

            nk_layout_row(ctx, NK_STATIC, 16, 2, subsystemRatio);
            for (i = 0; i < subsystemsCount; i++)
            {
                nk_label(ctx, ssList[i], NK_TEXT_LEFT);
                subsystem[i]->currentPlugin = nk_combo(ctx,
                 subsystem[i]->plugin, subsystem[i]->pluginsCount,
                 subsystem[i]->currentPlugin, 16, nk_vec2(200, 200));
            }

            nk_layout_row_dynamic(ctx, 16, 1);
            nk_label_colored(ctx, "Enabled modules:", NK_TEXT_LEFT,
             headerColor);

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
        tigrClear(backdrop, tigrRGB(19,43,81));

        nk_tigr_render();
        tigrBlit(screen, backdrop, 0,0,0,0, backdrop->w, backdrop->h);
        tigrUpdate(screen);
    }

    MTR_LogWrite("Quiting Launcher", 0, MTR_LMT_INFO);

    nk_tigr_shutdown();
    MTR_LogWrite("Nuklear context destroyed", 0, MTR_LMT_INFO);
    tigrFree(backdrop);
    MTR_LogWrite("Backbuffer destroyed", 0, MTR_LMT_INFO);
	tigrFree(screen);
	MTR_LogWrite("Screen destroyed", 0, MTR_LMT_INFO);

    /* Freing allocated structures and unloading libraries */
    for (i = 0; i < mtrPluginsFound; i++)
    {
        MTR_LogWrite_s("Unloading plugin", 0, MTR_LMT_INFO,
         mtrPluginData[i].report->moduleID);
        MTR_SoClose(mtrPluginData[i].so);
    }

    free(mtrPluginData);
    free(lchrPluginEnabled);
    for (i = 0; i < subsystemsCount; i++)
    {
        free(ssList[i]);
        free(subsystem[i]->plugin);
        free(subsystem[i]);
    }
    free(ssList);
    free(subsystem);

    MTR_LogWrite("Launcher stopped", 0, MTR_LMT_INFO);

    return 0;
}
