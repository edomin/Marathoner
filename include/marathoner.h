#ifndef MTR_MARATHONER
#define MTR_MARATHONER

#include <stdint.h> /* for uintXX_t types */
#include <stdlib.h> /* for malloc */

typedef struct mtrReport{
    char    *moduleID;
    uint8_t prereqsCount;
    char   **prereqs;
} mtrReport;
#define MTR_DECLSPEC __declspec(dllexport)

#endif
