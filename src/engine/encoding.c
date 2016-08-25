#include "encoding.h"

size_t mtrEncodingUtf8ToUcs4(char * utf8Text, uint32_t *ucs4Text)
{
    size_t len;
    size_t max;
    size_t n;
    len = strlen(utf8Text);
    max = len + 1;
    ucs4Text = malloc(sizeof(uint32_t) * max);
    n = u8decode(utf8Text, (ucs4_t *)ucs4Text, max, NULL);
    ucs4Text = realloc(ucs4Text, n);
    return n;
}
