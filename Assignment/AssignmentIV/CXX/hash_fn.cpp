/*
   ========================================
   hash_fn.cpp — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2026/01/10 gpt help me

   Developer: Yu-Feng Huang <yfhuang@saturn.yzu.edu.tw>
 */
#include "hash_fn.hpp"

int myHashInt(int key, int m) {
    unsigned int x = static_cast<unsigned int>(key);
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = (x >> 16) ^ x;
    return static_cast<int>(x % m);
}

int myHashString(const std::string& str, int m) {
    unsigned long hash = 5381;
    for (unsigned char c : str) {
        hash = ((hash << 5) + hash) + c;
    }
    return static_cast<int>(hash % m);
}
