#include "clipboard.h"

bool MTR_CALL mtrClipboardPutText(const char* text)
{
    bool success;
    success = true;
    if (!Clipboard_open())
        return false;
    if (!Clipboard_set_string(text))
        success = false;
    if (Clipboard_close())
        return success;
    else
        return false;
}

char *MTR_CALL mtrClipboardGetText(void)
{
    size_t size;
    char  *text;
    bool   success;

    success = true;
    if (Clipboard_is_format_avail(CF_TEXT))
    {
        size = Clipboard_get_size(CF_TEXT);
        text = malloc(sizeof(char) * (size + 1));
        if (!Clipboard_open())
        {
            free(text);
            return NULL;
        }
        if (!Clipboard_get(CF_TEXT, (uint8_t*)text, size))
            success = false;
        if (!Clipboard_close())
            success = false;

        if (success)
            return text;
        else
        {
            free(text);
            return NULL;
        }
    }
    else
        return NULL;
}
