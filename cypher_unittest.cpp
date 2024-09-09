/*
CPSC 353
Group 3(Caleb Lefcort, Madison Spink, Maya Stelzer, Maura Sweeney)
9/8/2024
Project 1

File Purpose: This file is used to test the encryption and decryption of each
    cypher.
*/

#include <iostream>
#include <string>
#include <cassert>
#include "cypher.h"

using namespace std;

void test_encrypt_caeser();
void test_decrypt_caeser();
void test_encrypt_vigenere();
void test_decrypt_vigenere();
void test_encrypt_one_time_pad();
void test_decrypt_one_time_pad();

void test_encrypt_caeser()
{
    string message = "Hello";
    char key = 'K';
    Caesar caesar_cipher(key);
    string expected_output = "ROVVY";

    string encrypted_message = caesar_cipher.encrypt(message);
    assert(encrypted_message == expected_output);

    cout << "The message matches the expected output." << std::endl;
}

void test_decrypt_caeser()
{
    string message = "ROVVY";
    char key = 'K';
    Caesar caesar_cipher(key);
    string expected_output = "HELLO";

    string decrypted_message = caesar_cipher.decrypt(message);
    assert(decrypted_message == expected_output);

    std::cout << "The message matches the expected output." << std::endl;
}

void test_encrypt_vigenere()
{
    string message = "Hello";
    string key = "SL";
    Vigenere vigenere_cypher(key);
    string expected_output = "ZPCWF";

    string encrypted_message = vigenere_cypher.encrypt(message);
    assert(encrypted_message == expected_output);

    std::cout << "The message matches the expected output." << std::endl;
}

void test_decrypt_vigenere()
{
    string message = "ZPCWF";
    string key = "SL";
    Vigenere vigenere_cypher(key);
    string expected_output = "HELLO";

    string decrypted_message = vigenere_cypher.decrypt(message);
    assert(decrypted_message == expected_output);

    std::cout << "The message matches the expected output." << std::endl;
}

void test_encrypt_one_time_pad()
{
    string message = "Hello";
    string key = "MAURA";
    OneTimePad OneTimePad_cypher(key);
    string expected_output = "TEEBO";

    string encrypted_message = OneTimePad_cypher.encrypt(message);
    assert(encrypted_message == expected_output);

    std::cout << "The message matches the expected output." << std::endl;
}

void test_decrypt_one_time_pad()
{
    string message = "TEEBO";
    string key = "MAURA";
    OneTimePad OneTimePad_cypher(key);
    string expected_output = "HELLO";

    string encrypted_message = OneTimePad_cypher.decrypt(message);
    assert(encrypted_message == expected_output);

    std::cout << "The message matches the expected output." << std::endl;
}
