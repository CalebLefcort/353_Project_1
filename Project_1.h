#ifndef PROJECT_1_H
#define PROJECT_1_H

#include <string>

using namespace std;

int find_index(char);
string caesar(string, char);
string vigenere(string, string);
string one_time_pad(string, string);

void test_encrypt_caeser();
void test_decrypt_caeser();
void test_encrypt_vigenere();
void test_decrypt_vigenere();
void test_encrypt_one_time_pad();
void test_decrypt_one_time_pad();

const char ALPHA[27] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ' '};

#endif
