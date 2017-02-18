#include "encoding.h"

size_t mtrEncodingUtf8ToUcs4(const char * utf8Text, uint32_t *ucs4Text)
{
    size_t len;
    size_t max;
    size_t n;
    if (utf8Text == NULL)
        return 0;
    len = strlen(utf8Text);
    max = len + 1;
    ucs4Text = malloc(sizeof(uint32_t) * max);
    if (ucs4Text == NULL)
        return 0;
    n = u8decode(utf8Text, (ucs4_t *)ucs4Text, max, NULL);
    ucs4Text = realloc(ucs4Text, n);
    return n;
}
