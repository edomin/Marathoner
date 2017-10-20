#include "encoding.h"

size_t MTR_CALL MTR_EncodingUtf8ToUcs4(const char *utf8Text, uint32_t **ucs4Text)
{
    size_t len;
    size_t max;
    size_t n;
    int    illegal;

    if (utf8Text == NULL)
        return 0;
    len = strlen(utf8Text);
    max = len + 1;
    *ucs4Text = malloc(sizeof(ucs4_t) * max);
    if (*ucs4Text == NULL)
        return 0;
    illegal = 0;
    n = u8decode(utf8Text, (ucs4_t *)*ucs4Text, max, &illegal);
    return n;
}

size_t MTR_CALL MTR_EncodingUtf8Codepoints(const char *utf8Text)
{
    size_t    result;
    uint32_t *ucs4Text;
    ucs4Text = NULL;
    result = MTR_EncodingUtf8ToUcs4(utf8Text, &ucs4Text);
    free(ucs4Text);
    return result;
}
