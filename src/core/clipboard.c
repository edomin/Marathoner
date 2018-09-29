#include "clipboard.h"

bool MTR_ClipboardReady(void) {
    if (!clipboardInitialized) {
        clipboard = clipboard_new(NULL);
        if (clipboard == NULL)
            return false;
        clipboardInitialized = true;
    }
    return true;
}

/*fa MTR_ClipboardPutText yes */
bool MTR_CALL MTR_ClipboardPutText(const char* text) {
    if (!MTR_ClipboardReady())
        return false;

    return clipboard_set_text(clipboard, text);
}

/*fa MTR_ClipboardGetText yes */
char *MTR_CALL MTR_ClipboardGetText(void) {
    if (!MTR_ClipboardReady())
        return NULL;

    return clipboard_text(clipboard);
}
