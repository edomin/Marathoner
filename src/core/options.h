#ifndef MTR_CORE_OPTIONS_H
#define MTR_CORE_OPTIONS_H

#include "marathoner/marathoner.h"

#include <limits.h>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wold-style-declaration"
#include "saneopt.h"
#pragma GCC diagnostic pop

#include "marathoner/engine.h"

saneopt_t* mtrArguments;

void MTR_CALL mtrOptionsProcess(int argc, char **argv);
bool MTR_CALL mtrOptionsAlias(const char *option, const char *alias);
char *MTR_CALL mtrOptionsGet(const char *option);
bool MTR_CALL mtrOptionsGet_b(const char *option);
int MTR_CALL mtrOptionsGet_i(const char *option);
long int MTR_CALL mtrOptionsGet_l(const char *option);
float MTR_CALL mtrOptionsGet_f(const char *option);
double MTR_CALL mtrOptionsGet_d(const char *option);

#endif

