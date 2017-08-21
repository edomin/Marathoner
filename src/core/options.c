#include "options.h"

void MTR_CALL mtrOptionsProcess(int argc, char **argv)
{
    mtrArguments = saneopt_init(argc, argv);
}

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

char *MTR_CALL mtrOptionsGet(const char *option)
{
    char *charOption;
    int optLen;
    char *result = NULL;
    if (option != NULL)
    {
        optLen = strlen(option);
        charOption = malloc(sizeof(char) * (optLen + 1));
        if (charOption == NULL)
            return NULL;
        charOption = strcpy(charOption, option);
        charOption[optLen] = '\0';

        result = saneopt_get(mtrArguments, charOption);
        free(charOption);
    }
    return result;
}
