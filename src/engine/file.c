#include "file.h"

void MRT_CALL mtrFileWriteLine(const char* filename, const char *text,
 uint8_t mode)
{
    FILE *file;
    if (mode == MTR_FM_WRITE)
        file = fopen(filename, "w");
    else
        file = fopen(filename, "a");
    fprintf(file, text);
    fprintf(file, "\n");
    fclose(file);
}
