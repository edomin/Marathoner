#ifndef MTR_TYPES
#define MTR_TYPES

#include <stdint.h>
#include <stdbool.h>

/*

typedef char                    mtr_char;
typedef signed char             mtr_schar;
typedef unsigned char           mtr_uchar;
typedef int                     mtr_int;
typedef signed int              mtr_sint;
typedef unsigned int            mtr_uint;
typedef short int               mtr_short;
typedef signed short int        mtr_sshort;
typedef unsigned short int      mtr_ushort;
typedef long int                mtr_long;
typedef signed long int         mtr_slong;
typedef unsigned long int       mtr_ulong;
typedef long long int           mtr_llong;
typedef signed long long int    mtr_sllong;
typedef unsigned long long int  mtr_ullong;

typedef int8_t                  mtr_int8;
typedef int8_t                  mtr_sint8;
typedef uint8_t                 mtr_uint8;
typedef int16_t                 mtr_int16;
typedef int16_t                 mtr_sint16;
typedef uint16_t                mtr_uint16;
typedef int32_t                 mtr_int32;
typedef int32_t                 mtr_sint32;
typedef uint32_t                mtr_uint32;
typedef int64_t                 mtr_int64;
typedef int64_t                 mtr_sint64;
typedef uint64_t                mtr_uint64;
typedef intmax_t                mtr_intmax;
typedef intmax_t                mtr_sintmax;
typedef uintmax_t               mtr_uintmax;

typedef int_least8_t            mtr_int8_least;
typedef int_least8_t            mtr_sint8_least;
typedef uint_least8_t           mtr_uint8_least;
typedef int_least16_t           mtr_int16_least;
typedef int_least16_t           mtr_sint16_least;
typedef uint_least16_t          mtr_uint16_least;
typedef int_least32_t           mtr_int32_least;
typedef int_least32_t           mtr_sint32_least;
typedef uint_least32_t          mtr_uint32_least;
typedef int_least64_t           mtr_int64_least;
typedef int_least64_t           mtr_sint64_least;
typedef uint_least64_t          mtr_uint64_least;

typedef int_fast8_t             mtr_int8_fast;
typedef int_fast8_t             mtr_sint8_fast;
typedef uint_fast8_t            mtr_uint8_fast;
typedef int_fast16_t            mtr_int16_fast;
typedef int_fast16_t            mtr_sint16_fast;
typedef uint_fast16_t           mtr_uint16_fast;
typedef int_fast32_t            mtr_int32_fast;
typedef int_fast32_t            mtr_sint32_fast;
typedef uint_fast32_t           mtr_uint32_fast;
typedef int_fast64_t            mtr_int64_fast;
typedef int_fast64_t            mtr_sint64_fast;
typedef uint_fast64_t           mtr_uint64_fast;

typedef float                   mtr_float;
typedef float                   mtr_single;
typedef double                  mtr_double;
typedef long double             mtr_ldouble;
typedef long double             mtr_extended;
typedef float                   mtr_float32;
typedef double                  mtr_float64;

typedef bool                    mtr_bool;

#define MTR_INT8_MIN            INT8_MIN
#define MTR_SINT8_MIN           INT8_MIN
#define MTR_INT8_MAX            INT8_MAX
#define MTR_SINT8_MAX           INT8_MAX
#define MTR_UINT8_MAX           UINT8_MAX

#define MTR_INT16_MIN           INT16_MIN
#define MTR_SINT16_MIN          INT16_MIN
#define MTR_INT16_MAX           INT16_MAX
#define MTR_SINT16_MAX          INT16_MAX
#define MTR_UINT16_MAX          UINT16_MAX

#define MTR_INT32_MIN           INT32_MIN
#define MTR_SINT32_MIN          INT32_MIN
#define MTR_INT32_MAX           INT32_MAX
#define MTR_SINT32_MAX          INT32_MAX
#define MTR_UINT32_MAX          UINT32_MAX

#define MTR_INT64_MIN           INT64_MIN
#define MTR_SINT64_MIN          INT64_MIN
#define MTR_INT64_MAX           INT64_MAX
#define MTR_SINT64_MAX          INT64_MAX
#define MTR_UINT64_MAX          UINT64_MAX

#define MTR_INTMAX_MIN          INTMAX_MIN
#define MTR_SINTMAX_MIN         INTMAX_MIN
#define MTR_INTMAX_MAX          INTMAX_MAX
#define MTR_SINTMAX_MAX         INTMAX_MAX
#define MTR_UINTMAX_MAX         UINTMAX_MAX

#define MTR_INT8_LEAST_MIN      INT_LEAST8_MIN
#define MTR_SINT8_LEAST_MIN     INT_LEAST8_MIN
#define MTR_INT8_LEAST_MAX      INT_LEAST8_MAX
#define MTR_SINT8_LEAST_MAX     INT_LEAST8_MAX
#define MTR_UINT8_LEAST_MAX     UINT_LEAST8_MAX

#define MTR_INT16_LEAST_MIN     INT_LEAST16_MIN
#define MTR_SINT16_LEAST_MIN    INT_LEAST16_MIN
#define MTR_INT16_LEAST_MAX     INT_LEAST16_MAX
#define MTR_SINT16_LEAST_MAX    INT_LEAST16_MAX
#define MTR_UINT16_LEAST_MAX    UINT_LEAST16_MAX

#define MTR_INT32_LEAST_MIN     INT_LEAST32_MIN
#define MTR_SINT32_LEAST_MIN    INT_LEAST32_MIN
#define MTR_INT32_LEAST_MAX     INT_LEAST32_MAX
#define MTR_SINT32_LEAST_MAX    INT_LEAST32_MAX
#define MTR_UINT32_LEAST_MAX    UINT_LEAST32_MAX

#define MTR_INT64_LEAST_MIN     INT_LEAST64_MIN
#define MTR_SINT64_LEAST_MIN    INT_LEAST64_MIN
#define MTR_INT64_LEAST_MAX     INT_LEAST64_MAX
#define MTR_SINT64_LEAST_MAX    INT_LEAST64_MAX
#define MTR_UINT64_LEAST_MAX    UINT_LEAST64_MAX

#define MTR_INT8_FAST_MIN       INT_FAST8_MIN
#define MTR_SINT8_FAST_MIN      INT_FAST8_MIN
#define MTR_INT8_FAST_MAX       INT_FAST8_MAX
#define MTR_SINT8_FAST_MAX      INT_FAST8_MAX
#define MTR_UINT8_FAST_MAX      UINT_FAST8_MAX

#define MTR_INT16_FAST_MIN      INT_FAST16_MIN
#define MTR_SINT16_FAST_MIN     INT_FAST16_MIN
#define MTR_INT16_FAST_MAX      INT_FAST16_MAX
#define MTR_SINT16_FAST_MAX     INT_FAST16_MAX
#define MTR_UINT16_FAST_MAX     UINT_FAST16_MAX

#define MTR_INT32_FAST_MIN      INT_FAST32_MIN
#define MTR_SINT32_FAST_MIN     INT_FAST32_MIN
#define MTR_INT32_FAST_MAX      INT_FAST32_MAX
#define MTR_SINT32_FAST_MAX     INT_FAST32_MAX
#define MTR_UINT32_FAST_MAX     UINT_FAST32_MAX

#define MTR_INT64_FAST_MIN      INT_FAST64_MIN
#define MTR_SINT64_FAST_MIN     INT_FAST64_MIN
#define MTR_INT64_FAST_MAX      INT_FAST64_MAX
#define MTR_SINT64_FAST_MAX     INT_FAST64_MAX
#define MTR_UINT64_FAST_MAX     UINT_FAST64_MAX

*/

#endif
