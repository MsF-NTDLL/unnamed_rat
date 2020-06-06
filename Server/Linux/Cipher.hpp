#ifndef __CIPHER
#define __CIPHER
#include "headers.hpp"

class LCipher{
   protected:
	std::size_t b64_encoded_size(std::size_t);
	std::size_t b64_decoded_size(const char*);
	int b64_valid_char(char);
	char *b64_encode(const char*, std::size_t);
	int b64_decode(const char*, char*&, std::size_t);
	u_int calc(char, u_int);
	u_int r_calc(char, u_int);
	char *b64_e(const char*);
	char *b64_d(const char*);
   public:
    std::string strPassword;
	LCipher(): strPassword("W3@kYc1PhEr"){} //default password
    LCipher(std::string p): strPassword(p){}
	std::string strCipher(const std::string&);
	std::string strUnCipher(const std::string&);
	int BinaryCipher(const char*, char*&);
	char *BinaryUnCipher(const char*);
	std::string ShellXor(const std::string, const std::string);
};

#endif
