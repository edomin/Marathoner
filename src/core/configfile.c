#include "configfile.h"

MTR_EXPORT char *MTR_CALL mtrConfigfileGetKeyName(const char* filename,
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

MTR_EXPORT char *MTR_CALL mtrConfigfileGetSectionName(const char* filename,
 int index)
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

MTR_EXPORT bool MTR_CALL mtrConfigfileDeleteKey(const char* filename,
 const char *section, const char *key)
{
    if ((key == NULL) || (filename == NULL))
        return false;
    if (ini_puts(section, key, NULL, filename) == 1)
        return true;
    else
        return false;
}

MTR_EXPORT bool MTR_CALL mtrConfigfileDeleteSection(const char* filename,
 const char *section)
{
    if ((section == NULL) || (filename == NULL))
        return false;
    if (ini_puts(section, NULL, NULL, filename) == 1)
        return true;
    else
        return false;
}

MTR_EXPORT bool MTR_CALL mtrConfigfileReadBool(const char* filename,
 const char *section, const char *key, bool defaultValue)
{
    if ((key != NULL) && (filename != NULL))
        return ini_getbool(section, key, defaultValue, filename);
    else
        return defaultValue;
}

MTR_EXPORT int MTR_CALL mtrConfigfileReadInt(const char* filename,
 const char *section, const char *key, int defaultValue)
{
    if ((key != NULL) && (filename != NULL))
        return (int)ini_getl(section, key, (long)defaultValue, filename);
    else
        return defaultValue;
}

MTR_EXPORT float MTR_CALL mtrConfigfileReadSingle(const char* filename,
 const char *section, const char *key, float defaultValue)
{
    if ((key != NULL) && (filename != NULL))
        return ini_getf(section, key, defaultValue, filename);
    else
        return defaultValue;
}

MTR_EXPORT char *MTR_CALL mtrConfigfileReadString(const char* filename,
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

MTR_EXPORT bool MTR_CALL mtrConfigfileWriteBool(const char* filename,
 const char *section, const char *key, bool value)
{
    if ((key != NULL) && (filename != NULL))
        if (ini_putl(section, key, (long)(value == true), filename) == 1)
            return true;
        else
            return false;
    else
        return false;
}

MTR_EXPORT bool MTR_CALL mtrConfigfileWriteInt(const char* filename,
 const char *section, const char *key, int value)
{
    if ((key != NULL) && (filename != NULL))
        if (ini_putl(section, key, (long)value, filename) == 1)
            return true;
        else
            return false;
    else
        return false;
}

MTR_EXPORT bool MTR_CALL mtrConfigfileWriteSingle(const char* filename,
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

MTR_EXPORT bool MTR_CALL mtrConfigfileWriteString(const char* filename,
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
