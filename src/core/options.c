#include "options.h"

void MTR_CALL mtrOptionsProcess(int argc, char **argv)
{
    mtrArguments = saneopt_init(argc, argv);
}

bool MTR_CALL mtrOptionsAlias(const char *option, const char *alias)
{
    int result = -1;
    if ((option != NULL) && (alias != NULL))
        result = saneopt_alias(mtrArguments, option, alias);
    if (result == -1)
        return false;
    return true;
}

char *mtrOptionsGet(char *option)
{
    if (option != NULL)
        return saneopt_get(mtrArguments, option);
    return NULL;
}
