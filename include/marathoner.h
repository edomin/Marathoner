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
/* Dialog Message Types */
#define MTR_DMT_INFO    0
#define MTR_DMT_NOTE    1
#define MTR_DMT_WARNING 2
#define MTR_DMT_ERROR   3
#define MTR_DMT_FATAL   4
#define MTR_DMT_DEBUG   5

#endif
