/**
 * @file vigenere.h
 * @brief Vigenère cipher functions
 * @author (your name)
 */
#ifndef VIGENERE_H
#define VIGENERE_H

/**
 * @brief Encrypts a string using Vigenère cipher.
 * @param plaintext The input string to encrypt.
 * @param key The keyword (string).
 * @return Pointer to the encrypted string (dynamically allocated, must be freed).
 */
char* vigenere_encrypt(const char* plaintext, const char* key);

/**
 * @brief Decrypts a string using Vigenère cipher.
 * @param ciphertext The input string to decrypt.
 * @param key The keyword (string).
 * @return Pointer to the decrypted string (dynamically allocated, must be freed).
 */
char* vigenere_decrypt(const char* ciphertext, const char* key);

#endif // VIGENERE_H
