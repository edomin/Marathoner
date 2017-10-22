#ifndef MTR_CORE_OPTIONS_H
#define MTR_CORE_OPTIONS_H

#include "marathoner/marathoner.h"

#include <limits.h>
#include <string.h>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wold-style-declaration"
#include "saneopt.h"
#pragma GCC diagnostic pop

#include "marathoner/engine.h"

saneopt_t* mtrArguments;

void MTR_CALL MTR_OptionsProcess(int argc, char **argv);
bool MTR_CALL MTR_OptionsAlias(const char *option, const char *alias);
char *MTR_CALL MTR_OptionsGet(const char *option);
bool MTR_CALL MTR_OptionsGet_b(const char *option);
int MTR_CALL MTR_OptionsGet_i(const char *option);
long int MTR_CALL MTR_OptionsGet_l(const char *option);
float MTR_CALL MTR_OptionsGet_f(const char *option);
double MTR_CALL MTR_OptionsGet_d(const char *option);

#endif

