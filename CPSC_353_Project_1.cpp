#include <iostream>
#include <string>
#include <unordered_map>
#include "Project_1.h"

using namespace std;

int main()
{
    test_encrypt_caeser();
    test_encrypt_vigenere();
    test_encrypt_one_time_pad();
    // cout << caesar("CAT", 'B') << endl;
    // cout << vigenere("CAT", "AB") << endl;
    // cout << one_time_pad("CAT", "ABC") << endl;

    return 0;
}

int find_index(char ch)
{
    for (int i = 0; i < sizeof(ALPHA) - 1; i++)
    {
        if (ch == ALPHA[i])
        {
            return i;
        }
    }
    throw invalid_argument("Recived an invalid character");
    return -1;
}

string caesar(string str, char key)
{
    int keyVal = find_index(key);
    for (int i = 0; i < str.length(); i++)
    {
        str[i] = ALPHA[(find_index(toupper(str[i])) + keyVal) % 27];
    }
    return str;
}

string vigenere(string str, string key)
{
    if (key.length() >= str.length())
    {
        throw invalid_argument("Key length too long");
    }
    for (int i = 0; i < str.length(); i++)
    {
        str[i] = ALPHA[(find_index(toupper(str[i])) + find_index(key[i % key.length()])) % 27];
    }
    return str;
}

string one_time_pad(string str, string key)
{
    if (key.length() != str.length())
    {
        throw invalid_argument("Key and string must be the same length");
    }
    for (int i = 0; i < str.length(); i++)
    {
        str[i] = ALPHA[(find_index(toupper(str[i])) + find_index(key[i])) % 27];
    }
    return str;
}