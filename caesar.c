#include "include/caesar.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* caesar_encrypt(const char* plaintext, int key) {
    size_t len = strlen(plaintext);
    char* result = (char*)malloc(len + 1);
    if (!result) return NULL;
    for (size_t i = 0; i < len; ++i) {
        if (isalpha((unsigned char)plaintext[i])) {
            char base = isupper((unsigned char)plaintext[i]) ? 'A' : 'a';
            result[i] = (plaintext[i] - base + key) % 26 + base;
        } else {
            result[i] = plaintext[i];
        }
    }
    result[len] = '\0';
    return result;
}

char* caesar_decrypt(const char* ciphertext, int key) {
    return caesar_encrypt(ciphertext, 26 - (key % 26));
}
