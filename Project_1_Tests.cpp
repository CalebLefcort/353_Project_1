#include <iostream>
#include <string>
#include <cassert>
#include "Project_1.h"

using namespace std;

void test_encrypt_caeser()
{
    string message = "Hello";
    char key = 'K';
    string expected_output = "ROVVY";
    string encrypted_message = caesar(message, key);
    assert(encrypted_message == expected_output);

    cout << "The message matches the expected output." << std::endl;
}

void test_decrypt_caeser()
{
    string message = "ROVVY";
    char key = 'K';
    string expected_output = "HELLO";
    string decrypted_message = caesar(message, key);
    assert(decrypted_message == expected_output);

    std::cout << "The message matches the expected output." << std::endl;
}

void test_encrypt_vigenere()
{
    string message = "Hello";
    string key = "SL";
    string expected_output = "ZPCWF";
    string encrypted_message = vigenere(message, key);
    assert(encrypted_message == expected_output);

    std::cout << "The message matches the expected output." << std::endl;
}

void test_decrypt_vigenere()
{
    string message = "";
    string key = "";
    string expected_output = "";
    string decrypted_message = vigenere(message, key);
    assert(decrypted_message == expected_output);

    std::cout << "The message matches the expected output." << std::endl;
}

void test_encrypt_one_time_pad()
{
    string message = "Hello";
    string key = "MAURA";
    string expected_output = "TEEBO";
    string encrypted_message = one_time_pad(message, key);
    assert(encrypted_message == expected_output);

    std::cout << "The message matches the expected output." << std::endl;
}

void test_decrypt_one_time_pad()
{
    string message = "";
    string key = "";
    string expected_output = "";
    string decrypted_message = one_time_pad(message, key);
    assert(decrypted_message == expected_output);

    std::cout << "The message matches the expected output." << std::endl;
}