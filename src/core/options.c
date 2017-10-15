#include "options.h"

void MTR_CALL mtrOptionsProcess(int argc, char **argv)
{
    mtrArguments = saneopt_init(argc, argv);
}

/*fa mtrOptionsAlias yes */
bool MTR_CALL mtrOptionsAlias(const char *option, const char *alias)
{
    int result = -1;
    char *charOption;
    char *charAlias;
    int optLen;
    int aliasLen;
    if ((option != NULL) && (alias != NULL))
    {
        optLen = strlen(option);
        aliasLen = strlen(option);
        charOption = malloc(sizeof(char) * (optLen + 1));
        if (charOption == NULL)
            return false;
        charAlias = malloc(sizeof(char) * (aliasLen + 1));
        if (charAlias == NULL)
        {
            free(charOption);
            return false;
        }

        charOption = strcpy(charOption, option);
        charOption[optLen] = '\0';
        charAlias = strcpy(charAlias, alias);
        charAlias[aliasLen] = '\0';
        result = saneopt_alias(mtrArguments, charOption, charAlias);
    }
    if (result == -1)
        return false;
    return true;
}

char *mtrCharOption(const char *option)
{
    char *charOption;
    int optLen;

    optLen = strlen(option);
    charOption = malloc(sizeof(char) * (optLen + 1));
    if (charOption == NULL)
        return NULL;
    charOption = strcpy(charOption, option);
    charOption[optLen] = '\0';

    return charOption;
}

/*fa mtrOptionsGet yes */
char *MTR_CALL mtrOptionsGet(const char *option)
{
    char *charOption;
    char *result = NULL;
    if (option != NULL)
    {
        charOption = mtrCharOption(option);

        result = saneopt_get(mtrArguments, charOption);
        free(charOption);
    }
    return result;
}

/*fa mtrOptionsGet_b yes */
bool MTR_CALL mtrOptionsGet_b(const char *option)
{
    char *charOption;
    char *result = NULL;
    if (option != NULL)
    {
        charOption = mtrCharOption(option);

        result = saneopt_get(mtrArguments, charOption);
        free(charOption);
        if (result == NULL)
            return false;
        if (strcmp(result, "yes") == 0)
            return true;
        if (strcmp(result, "y") == 0)
            return true;
        if (strcmp(result, "1") == 0)
            return true;
        if (strcmp(result, "true") == 0)
            return true;
    }
    return false;
}

/*fa mtrOptionsGet_i yes */
int MTR_CALL mtrOptionsGet_i(const char *option)
{
    char *charOption;
    char *result = NULL;
    long int resultLong = 0L;
    #if (INT_MAX != LONG_MAX)
    int resultNum = 0;
    #endif
    if (option != NULL)
    {
        charOption = mtrCharOption(option);

        result = saneopt_get(mtrArguments, charOption);
        free(charOption);
        resultLong = strtol(result, NULL, 0);
        #if (INT_MAX != LONG_MAX)
        if (resultLong > INT_MAX) {
            resultNum = INT_MAX;
        } else if (resultLong < INT_MIN) {
            resultNum = INT_MIN;
        } else {
            resultNum = resultLong;
        }
        #endif
    }
    #if (INT_MAX != LONG_MAX)
    return resultNum;
    #else
    return resultLong;
    #endif
}

/*fa mtrOptionsGet_l yes */
long int MTR_CALL mtrOptionsGet_l(const char *option)
{
    char *charOption;
    char *result = NULL;
    long int resultNum = 0L;
    if (option != NULL)
    {
        charOption = mtrCharOption(option);

        result = saneopt_get(mtrArguments, charOption);
        free(charOption);
        resultNum = strtol(result, NULL, 0);
    }
    return resultNum;
}

/*fa mtrOptionsGet_f yes */
float MTR_CALL mtrOptionsGet_f(const char *option)
{
    char *charOption;
    char *result = NULL;
    float resultNum = 0.0f;
    if (option != NULL)
    {
        charOption = mtrCharOption(option);

        result = saneopt_get(mtrArguments, charOption);
        free(charOption);
        resultNum = strtof(result, NULL);
    }
    return resultNum;
}

/*fa mtrOptionsGet_d yes */
double MTR_CALL mtrOptionsGet_d(const char *option)
{
    char *charOption;
    char *result = NULL;
    double resultNum = 0.0;
    if (option != NULL)
    {
        charOption = mtrCharOption(option);

        result = saneopt_get(mtrArguments, charOption);
        free(charOption);
        resultNum = strtod(result, NULL);
    }
    return resultNum;
}
