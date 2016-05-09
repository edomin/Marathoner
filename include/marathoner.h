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

/* Log Message Types */
#define MTR_LMT_INFO    0
#define MTR_LMT_NOTE    1
#define MTR_LMT_WARNING 2
#define MTR_LMT_ERROR   3
#define MTR_LMT_FATAL   4
#define MTR_LMT_DEBUG   5

/* Dialog Message Types */
#define MTR_DMT_INFO    0
#define MTR_DMT_NOTE    1
#define MTR_DMT_WARNING 2
#define MTR_DMT_ERROR   3
#define MTR_DMT_FATAL   4
#define MTR_DMT_DEBUG   5

/* Notification texts */
#define MTR_NTT_INFO    "Info"
#define MTR_NTT_NOTE    "Note"
#define MTR_NTT_WARNING "Warning"
#define MTR_NTT_ERROR   "Error"
#define MTR_NTT_FATAL   "Fatal Error"
#define MTR_NTT_DEBUG   "Debug"

#endif
