#ifndef MTR_COMMON_H
#define MTR_COMMON_H

/* Hack for disabling warning about unused variable */
#define UNUSED(expr) do { (void)(expr); } while (0)

/* Function availability */
#define MTR_FA_NO      0 /* Function availability data not found */
#define MTR_FA_DUMMY   1 /* Function not supported */
#define MTR_FA_BUGGY   2 /* Function are not working correct. Not recommended
                          * for use because bugs can be fatal for application
                          */
#define MTR_FA_PARTIAL 3 /* Function partially supported */
#define MTR_FA_YES     4 /* Function full supported */

#endif
