#include "decrypt.h"

std::string Decrypt::cs_decrypt(std::string& cipher, int key)
{
    std::string plain;

    // calculation if cipher - key is negative
    // encryption: y + 5 mod 26 -> d
    // decryption: d - 5 mod 26 is negative -2
    // add 26 (num_letters) to key first to make it positive
    // 26-2 mod 26 = 24 + 97 = 121 -> y

    for (int i = 0; i < cipher.length(); i++) {
        if (isupper(cipher[i])) {
            plain += ((((cipher[i] - 65) - key) + 26) % 26 + 65);
        }
        else if (islower(cipher[i])) {
            plain += ((((cipher[i] - 97) - key) + 26) % 26 + 97);
        }
        //for spaces
        else {
            plain += cipher[i];
        }
    }
    return plain;
}

std::string Decrypt::ci_decrypt(std::string& cipher, int key)
{
    std::string plain;
    // Cipher is already all uppercase due to case insensitive encryption
    for (int i = 0; i < cipher.length(); i++) {
        if (isalpha(cipher[i])) {
            plain += ((((cipher[i] - 65) - key) + 26) % 26 + 65);
        }
        //for spaces
        else {
            plain += cipher[i];
        }
    }
    return plain;
}
