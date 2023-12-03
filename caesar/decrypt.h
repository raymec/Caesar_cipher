#pragma once
#include <string>

class Decrypt {
private:
public:
	std::string cs_decrypt(std::string& cipher, int key);
	std::string ci_decrypt(std::string& cipher, int key);
};