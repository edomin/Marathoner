#include "encoding.h"

size_t MTR_CALL MTR_EncodingUtf8ToUcs4(const char *utf8Text,
 uint32_t **ucs4Text)
{
    size_t      len;
    size_t      i;
    const char *utf8Rune = utf8Text;

    if (utf8Text == NULL)
        return 0UL;
    len = utf8RuneCount(utf8Text, 0UL);
    *ucs4Text = malloc(sizeof(uint32_t) * len);
    if (*ucs4Text == NULL)
        return 0UL;

    for (i = 0UL; i < len; i++)
        utf8Rune = utf8DecodeRune(utf8Rune, 0UL, &(*ucs4Text[i]));

    return len;
}
    if (*ucs4Text == NULL)
        return 0;
    illegal = 0;
    n = u8decode(utf8Text, (ucs4_t *)*ucs4Text, max, &illegal);
    return n;
}

size_t MTR_CALL MTR_EncodingUtf8Codepoints(const char *utf8Text)
{
    return utf8RuneCount(utf8Text, strlen(utf8Text));
}
