#include "configfile.h"

void ConfigfileInit(void)
{

}

bool mtrConfigfileReadBool(char* filename, char *section, char *key,
 bool defaultValue)
{
    return ini_getbool(section, key, defaultValue, filename);
}

int mtrConfigfileReadInt(char* filename, char *section, char *key,
 int defaultValue)
{
    return (int)ini_getl(section, key, (long)defaultValue, filename);
}

char *mtrConfigfileReadString(char* filename, char *section, char *key,
 char *defaultValue)
{
    uint16_t valueLength;
    char    *result;
    valueLength = ini_gets(section, key, defaultValue, mtrConfigfileTempbuf,
     sizearray(mtrConfigfileTempbuf), filename);
    result = malloc(sizeof(char *) * valueLength + 1);
    return strcpy(result, (const char *)mtrConfigfileTempbuf);
}
