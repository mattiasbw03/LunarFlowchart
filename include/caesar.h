/**
 * @file caesar.h
 * @brief Caesar cipher functions
 * @author (your name)
 */
#ifndef CAESAR_H
#define CAESAR_H

/**
 * @brief Encrypts a string using Caesar cipher.
 * @param plaintext The input string to encrypt.
 * @param key The shift key (integer).
 * @return Pointer to the encrypted string (dynamically allocated, must be freed).
 */
char* caesar_encrypt(const char* plaintext, int key);

/**
 * @brief Decrypts a string using Caesar cipher.
 * @param ciphertext The input string to decrypt.
 * @param key The shift key (integer).
 * @return Pointer to the decrypted string (dynamically allocated, must be freed).
 */
char* caesar_decrypt(const char* ciphertext, int key);

#endif // CAESAR_H
