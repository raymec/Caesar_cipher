#pragma once
#include <string>

class Encrypt {
private:
public:
	std::string cs_encrpty_caesar(std::string& str, int key);
	std::string ci_encrpty_caesar(std::string& str, int key);
};