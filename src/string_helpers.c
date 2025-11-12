/*
    Implementation of "utility.h"
*/

#include "string_helpers.h"
#include <stdlib.h>

#if SIZE_MAX == UINT64_MAX
    #define FNV_OFFSET 1469598103934665603ULL
    #define FNV_PRIME  1099511628211ULL
#elif SIZE_MAX == UINT32_MAX
    #define FNV_OFFSET 2166136261U
    #define FNV_PRIME  16777619U
#endif

size_t str_hash(const char *str, const int mod) {
    size_t hash = FNV_OFFSET;
    for (char c; (c = *str); str++) {
        hash ^= c;
        hash *= FNV_PRIME;
    }
    return hash % mod;
}