#ifndef MTR_BUILD_UTILS_FAGEN_H
#define MTR_BUILD_UTILS_FAGEN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "marathoner/common.h"

typedef struct functionAvailability_t {
    char *name;
    const char *availability;
} functionAvailability_t;

char *availabilityConst[] = {"MTR_FA_NO", "MTR_FA_DUMMY", "MTR_FA_BUGGY",
 "MTR_FA_PARTIAL", "MTR_FA_YES"};

char defaultIncludeGuard[] = "FA_GENERATED_H";

#endif
