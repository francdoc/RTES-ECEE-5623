#include <stdint.h>
#include <stddef.h>

typedef int64_t int64;
typedef int32_t int32;
typedef int16_t int16;
typedef int8_t int8;

#define byte uint8

#define bool uint8

typedef uint64_t uint64;
typedef uint32_t uint32;
typedef uint16_t uint16;
typedef uint8_t uint8;

typedef float float32;
typedef double float64;

typedef long double float128;

typedef int error;

typedef struct
{
    error (*sequencer)(void *threadp);
} OSAL_Sequencer;
