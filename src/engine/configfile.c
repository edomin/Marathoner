#include "configfile.h"

void ConfigfileInit(void)
{

}

char *mtrConfigfileReadString(char* filename, char *section, char *key, char *defaultValue)
{
    uint16_t valueLength;
    char *result;
    valueLength = ini_gets(section, key, defaultValue, mtrConfigfileTempbuf, sizearray(mtrConfigfileTempbuf), filename);
    result = malloc(sizeof(char *) * valueLength + 1);
    return strcpy(result, (const char *)mtrConfigfileTempbuf);
}
