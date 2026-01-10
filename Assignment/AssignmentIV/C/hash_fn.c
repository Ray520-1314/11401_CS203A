/*
   ========================================
   hash_fn.c — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2026/01/10: Refactored to use hash_fn.h

   Developer: Ray
 */

#include "hash_fn.h"

int myHashInt(int key, int m) {
    unsigned int x = (unsigned int)key;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = (x >> 16) ^ x;
    return (int)(x % m);
}

int myHashString(const char* str, int m) {
    unsigned long hash = 5381;
    const unsigned char* p = (const unsigned char*)str;
    while (*p) {
        hash = ((hash << 5) + hash) + *p;
        p++;
    }
    return (int)(hash % m);
}






