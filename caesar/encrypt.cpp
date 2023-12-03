#include "encrypt.h"

std::string Encrypt::cs_encrpty_caesar(std::string& str, int key)
{
    std::string cipher;
    for (int i = 0; i < str.length(); i++) {
        // the added 26 is to make all letters + key additions positive
        if (isupper(str[i])) {
            cipher += ((((str[i] - 'A') + key) + 26) % 26 + 'A');
        }
        else if (islower(str[i])) {
            cipher += ((((str[i] - 'a') + key) + 26) % 26 + 'a');
        }
        // for spaces or other characters
        else {
            cipher += str[i];
        }

    }
    return cipher;
}

std::string Encrypt::ci_encrpty_caesar(std::string& str, int key)
{
    std::string cipher;
    for (int i = 0; i < str.length(); i++) {
        if (isalpha(str[i])) {
            cipher += (((toupper(str[i]) - 65) + key) % 26 + 65);
        }
        else {
            cipher += str[i];
        }
    }
    return cipher;
}
