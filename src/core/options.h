#ifndef MTR_CORE_OPTIONS_H
#define MTR_CORE_OPTIONS_H

#include "marathoner/marathoner.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wold-style-declaration"
#include "saneopt.h"
#pragma GCC diagnostic pop

#include "marathoner/engine.h"

saneopt_t* mtrArguments;

void MTR_CALL mtrOptionsProcess(int argc, char **argv);
bool MTR_CALL mtrOptionsAlias(const char *option, const char *alias);
char *MTR_CALL mtrOptionsGet(const char *option);

#endif

