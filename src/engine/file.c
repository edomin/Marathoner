#include "file.h"

void MTR_CALL mtrFileWriteLine(const char* filename, const char *text,
 int mode)
{
    FILE *file;
    if (mode == MTR_FM_WRITE)
        file = fopen(filename, "w");
    else
        file = fopen(filename, "a");
    fprintf(file, "%s\n", text);
    fclose(file);
}
