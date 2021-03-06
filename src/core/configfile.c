#include "configfile.h"

/*fa MTR_ConfigfileGetKeyName yes */
char *MTR_CALL MTR_ConfigfileGetKeyName(const char* filename,
 const char *section, int index)
{
    uint16_t valueLength;
    char    *result;
    if (filename == NULL)
        return NULL;
    if (index >= 0)
    {
        valueLength = ini_getkey(section, index, mtrConfigfileTempbuf,
         sizearray(mtrConfigfileTempbuf), filename);
        if (valueLength)
        {
            result = malloc(sizeof(char *) * valueLength + 1);
            if (result == NULL)
                return NULL;
            else
                return strcpy(result, (const char *)mtrConfigfileTempbuf);
        }
        else
            return NULL;
    }
    else
        return NULL;
}

/*fa MTR_ConfigfileGetSectionName yes */
char *MTR_CALL MTR_ConfigfileGetSectionName(const char* filename, int index)
{
    uint16_t valueLength;
    char    *result;
    if (filename == NULL)
        return NULL;
    if (index >= 0)
    {
        valueLength = ini_getsection(index, mtrConfigfileTempbuf,
         sizearray(mtrConfigfileTempbuf), filename);
        if (valueLength)
        {
            result = malloc(sizeof(char *) * valueLength + 1);
            if (result == NULL)
                return NULL;
            else
                return strcpy(result, (const char *)mtrConfigfileTempbuf);
        }
        else
            return NULL;
    }
    else
        return NULL;
}

/*fa MTR_ConfigfileKeyExists yes */
bool MTR_CALL MTR_ConfigfileKeyExists(const char *filename, const char *section,
 const char *key)
{
    uint16_t valueLength;
    int      index;
    if (filename == NULL)
        return NULL;

    index = 0;
    do {
        valueLength = ini_getkey(section, index, mtrConfigfileTempbuf,
         sizearray(mtrConfigfileTempbuf), filename);
        if (strcmp(key, mtrConfigfileTempbuf) == 0)
            return true;
        index++;
    } while (valueLength != 0);

    return false;
}

/*fa MTR_ConfigfileSectionExists yes */
bool MTR_CALL MTR_ConfigfileSectionExists(const char *filename,
 const char *section)
{
    uint16_t valueLength;
    int      index;
    if (filename == NULL)
        return NULL;

    index = 0;
    do {
        valueLength = ini_getsection(index, mtrConfigfileTempbuf,
         sizearray(mtrConfigfileTempbuf), filename);
        if (strcmp(section, mtrConfigfileTempbuf) == 0)
            return true;
        index++;
    } while (valueLength != 0);

    return false;
}

/*fa MTR_ConfigfileDeleteKey yes */
bool MTR_CALL MTR_ConfigfileDeleteKey(const char* filename, const char *section,
 const char *key)
{
    if ((key == NULL) || (filename == NULL))
        return false;
    if (ini_puts(section, key, NULL, filename) == 1)
        return true;
    else
        return false;
}

/*fa MTR_ConfigfileDeleteSection yes */
bool MTR_CALL MTR_ConfigfileDeleteSection(const char* filename,
 const char *section)
{
    if ((section == NULL) || (filename == NULL))
        return false;
    if (ini_puts(section, NULL, NULL, filename) == 1)
        return true;
    else
        return false;
}

/*fa MTR_ConfigfileReadBool yes */
bool MTR_CALL MTR_ConfigfileReadBool(const char* filename, const char *section,
 const char *key, bool defaultValue)
{
    if ((key != NULL) && (filename != NULL))
        return ini_getbool(section, key, defaultValue, filename);
    else
        return defaultValue;
}

/*fa MTR_ConfigfileReadInt yes */
int MTR_CALL MTR_ConfigfileReadInt(const char* filename, const char *section,
 const char *key, int defaultValue)
{
    if ((key != NULL) && (filename != NULL))
        return (int)ini_getl(section, key, (long)defaultValue, filename);
    else
        return defaultValue;
}

/*fa MTR_ConfigfileReadSingle yes */
float MTR_CALL MTR_ConfigfileReadSingle(const char* filename,
 const char *section, const char *key, float defaultValue)
{
    if ((key != NULL) && (filename != NULL))
        return ini_getf(section, key, defaultValue, filename);
    else
        return defaultValue;
}

/*fa MTR_ConfigfileReadString yes */
char *MTR_CALL MTR_ConfigfileReadString(const char* filename,
 const char *section, const char *key, const char *defaultValue)
{
    uint16_t valueLength;
    char    *result;
    if ((key != NULL) && (filename != NULL))
    {
        valueLength = ini_gets(section, key, defaultValue, mtrConfigfileTempbuf,
         sizearray(mtrConfigfileTempbuf), filename);
        result = malloc(sizeof(char *) * valueLength + 1);
        if (result == NULL)
            return NULL;
        else
            return strcpy(result, (const char *)mtrConfigfileTempbuf);
    }
    else
    {
        result = malloc(sizeof(char *) * strlen(defaultValue));
        if (result == NULL)
            return NULL;
        else
            return strcpy(result, (const char *)defaultValue);
    }
}

/*fa MTR_ConfigfileWriteBool yes */
bool MTR_CALL MTR_ConfigfileWriteBool(const char* filename, const char *section,
 const char *key, bool value)
{
    if ((key != NULL) && (filename != NULL))
        if (ini_putl(section, key, (long)(value == true), filename) == 1)
            return true;
        else
            return false;
    else
        return false;
}

/*fa MTR_ConfigfileWriteInt yes */
bool MTR_CALL MTR_ConfigfileWriteInt(const char* filename, const char *section,
 const char *key, int value)
{
    if ((key != NULL) && (filename != NULL))
        if (ini_putl(section, key, (long)value, filename) == 1)
            return true;
        else
            return false;
    else
        return false;
}

/*fa MTR_ConfigfileWriteSingle yes */
bool MTR_CALL MTR_ConfigfileWriteSingle(const char* filename,
 const char *section, const char *key, float value)
{
    if ((key != NULL) && (filename != NULL))
        if (ini_putf(section, key, value, filename) == 1)
            return true;
        else
            return false;
    else
        return false;
}

/*fa MTR_ConfigfileWriteString yes */
bool MTR_CALL MTR_ConfigfileWriteString(const char* filename,
 const char *section, const char *key, const char *value)
{
    if ((key != NULL) && (filename != NULL))
        if (ini_puts(section, key, value, filename) == 1)
            return true;
        else
            return false;
    else
        return false;
}

/*fa MTR_ConfigfileCreateSection yes */
bool MTR_CALL MTR_ConfigfileCreateSection(const char* filename,
 const char *section)
{
    if ((section != NULL) && (filename != NULL))
        if (ini_puts(section, NULL, NULL, filename) == 1)
            return true;
        else
            return false;
    else
        return false;
}
