#include <iostream>
#include <string>
#include "encrypt.h"
#include "decrypt.h"

int main()
{
    std::string str;

    // cs = case sensitive: algorithm will leave cases alone
    // ci = case insensitive: algorithm will convert all letters to uppercase
    std::string cs_cipher;
    std::string ci_cipher;
    std::string cs_text;
    std::string ci_text;

    Encrypt encrypt;
    Decrypt decrypt;

    int key;
    
    std::cout << "Enter string to encrypt: ";
    std::getline(std::cin, str);
    std::cout << "Enter private key: ";
    std::cin >> key;
    std::cin.ignore();


    //---encrypt---//
    cs_cipher = encrypt.cs_encrpty_caesar(str, key);
    ci_cipher = encrypt.ci_encrpty_caesar(str, key);
    std::cout << "\n---encrypt---\n" << cs_cipher << " | " << ci_cipher << std::endl;


    //---decrypt---//
    cs_text = decrypt.cs_decrypt(cs_cipher, key);
    ci_text = decrypt.ci_decrypt(ci_cipher, key);
    std::cout << "\n---decrypt---\n" << cs_text << " | " << ci_text << std::endl;


    //---brute force---//
    std::cout << "\n---brute force---\n";
    std::cout << "cipher: " << ci_cipher << std::endl;
    for (int i = 0; i < 26; i++) {
        std::string text;
        text = decrypt.ci_decrypt(ci_cipher, i);
        std::cout << "key " << i << ": " << text << std::endl;
    }
    return 0;
}
