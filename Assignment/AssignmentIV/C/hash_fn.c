/*
   ========================================
   hash_fn.c — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/01/10: Refactored to use hash_fn.h

   Developer: Ray
 */

#include "hash_fn.h"

int myHashInt(int key, int m) {
    // TODO: replace with your own design
    return key % m;  // division method example
}

int myHashString(const char* str, int m) {
    unsigned long hash = 0;
    // TODO: replace with your own design
    return (int)(hash % m); // basic division method
}
