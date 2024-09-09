/*
CPSC 353
Group 3(Caleb Lefcort, Madison Spink, Maya Stelzer, Maura Sweeney)
9/8/2024
Project 1

File Purpose: This file is the central loop and file for the program allowing
    the user to encrypt and decrypt a string with three different cyphers.
*/

#include "cypher.h"
#include <fstream>
#include <regex>
#include <limits>

using namespace std;

void encrypt(std::ofstream &outFile);
void decrypt(std::ofstream &outFile);

int main()
{

    std::ofstream outFile("output.txt");
    while (true)
    {
        std::cout << "Choose an option:\n1. Encrypt\n2. Decrypt\n3. Exit\n";
        int choice;
        std::cin >> choice;
        
        if (choice == 3) {
            return 0;
        }
        if (choice != 1 && choice != 2)
        {
            std::cout << "Invalid choice\n";
            continue;
        }
        else if (choice == 1) {
            encrypt(outFile);
        }
        else
        {
            decrypt(outFile);
        }
    }
    outFile.close();
    return 0;
}

void encrypt(std::ofstream &outFile)
{
    string message;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while (true)
    {
        std::cout << "Enter text to encrypt: ";
        std::getline(std::cin, message);

        if (!std::regex_match(message, std::regex("^[a-zA-Z ]+$")))
        {
            std::cout << "Error: Input must contain only letters and spaces\n";
            continue;
        }
        else
        {
            break;
        }
    }

    std::cout << "Choose cipher: \n1. Caesar\n2. Vigenere\n3. One-time pad\n";
    int cipher_choice;
    std::cin >> cipher_choice;

    string key;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while (true)
    {
        std::cout << "Enter key: ";
        std::getline(std::cin, key);

        if (!std::regex_match(message, std::regex("^[a-zA-Z ]+$")))
        {
            std::cout << "Error: Input must contain only letters and spaces\n";
            continue;
        }
        else if (cipher_choice == 1 && key.length() != 1)
        {
            std::cout << "Error: Key must be a single letter\n";
            continue;
        }
        else if (cipher_choice == 3 && key.length() != message.length())
        {
            std::cout << "Error: Key and message must be the same length\n";
            continue;
        }
        else
        {
            break;
        }
    }

    for (int i = 0; i < key.length(); i++)
    {
        key[i] = toupper(key[i]);
    }

    for (int i = 0; i < message.length(); i++) {
        message[i] = toupper(message[i]);
    }

    string result;

    if (cipher_choice == 1)
    {
        Caesar caesar(key[0]);
        result = caesar.encrypt(message);
        cout << endl;
        cout << "Message: " << message << endl;
        cout << "Key: " << key << endl;
        cout << "Result: " << result << endl;
        cout << endl;

        if (outFile.is_open())
        {
            outFile << "Message: " << message << endl;
            outFile << "Key: " << key << endl;
            outFile << "Result: " << result << endl;
            outFile << endl;
        }
        else
        {
            std::cout << "Unable to open file for writing" << std::endl;
        }
    }
    if (cipher_choice == 2)
    {
        Vigenere vigenere(key);
        result = vigenere.encrypt(message);
        cout << endl;
        cout << "Message: " << message << endl;
        cout << "Key: " << key << endl;
        cout << "Result: " << result << endl;
        cout << endl;

        if (outFile.is_open())
        {
            outFile << "Message: " << message << endl;
            outFile << "Key: " << key << endl;
            outFile << "Result: " << result << endl;
            outFile << endl;
        }
        else
        {
            std::cout << "Unable to open file for writing" << std::endl;
        }
    }
    if (cipher_choice == 3)
    {
        OneTimePad one_time_pad(key);
        result = one_time_pad.encrypt(message);
        cout << endl;
        cout << "Message: " << message << endl;
        cout << "Key: " << key << endl;
        cout << "Result: " << result << endl;
        cout << endl;

        if (outFile.is_open())
        {
            outFile << "Message: " << message << endl;
            outFile << "Key: " << key << endl;
            outFile << "Result: " << result << endl;
            outFile << endl;
        }
        else
        {
            std::cout << "Unable to open file for writing" << std::endl;
        }
    }
}

void decrypt(std::ofstream &outFile)
{
    string message;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while (true)
    {
        std::cout << "Enter text to decrypt: ";
        std::getline(std::cin, message);

        if (!std::regex_match(message, std::regex("^[a-zA-Z ]+$")))
        {
            std::cout << "Error: Input must contain only letters and spaces\n";
            continue;
        }
        else
        {
            break;
        }
    }
    std::cout << "Choose cipher: \n1. Caesar\n2. Vigenere\n3. One-time pad\n";
    int cipher_choice;
    std::cin >> cipher_choice;

    string key;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while (true)
    {
        std::cout << "Enter key: ";
        std::getline(std::cin, key);

        if (!std::regex_match(message, std::regex("^[a-zA-Z ]+$")))
        {
            std::cout << "Error: Input must contain only letters and spaces\n";
            continue;
        }
        else if (cipher_choice == 1 && key.length() != 1)
        {
            std::cout << "Error: Key must be a single letter\n";
            continue;
        }
        else if (cipher_choice == 3 && key.length() != message.length())
        {
            std::cout << "Error: Key and message must be the same length\n";
            continue;
        }
        else
        {
            break;
        }
    }
    for (int i = 0; i < key.length(); i++)
    {
        key[i] = toupper(key[i]);
    }
    string result;

    if (cipher_choice == 1)
    {
        Caesar caesar(key[0]);
        result = caesar.decrypt(message);
        cout << endl;
        cout << "Message: " << message << endl;
        cout << "Key: " << key << endl;
        cout << "Result: " << result << endl;
        cout << endl;

        if (outFile.is_open())
        {
            outFile << "Message: " << message << endl;
            outFile << "Key: " << key << endl;
            outFile << "Result: " << result << endl;
            outFile << endl;
        }
        else
        {
            std::cout << "Unable to open file for writing" << std::endl;
        }
    }
    if (cipher_choice == 2)
    {
        Vigenere vigenere(key);
        result = vigenere.decrypt(message);
        cout << endl;
        cout << "Message: " << message << endl;
        cout << "Key: " << key << endl;
        cout << "Result: " << result << endl;
        cout << endl;

        if (outFile.is_open())
        {
            outFile << "Message: " << message << endl;
            outFile << "Key: " << key << endl;
            outFile << "Result: " << result << endl;
            outFile << endl;
        }
        else
        {
            std::cout << "Unable to open file for writing" << std::endl;
        }
    }
    if (cipher_choice == 3)
    {
        OneTimePad one_time_pad(key);
        result = one_time_pad.decrypt(message);
        cout << endl;
        cout << "Message: " << message << endl;
        cout << "Key: " << key << endl;
        cout << "Result: " << result << endl;
        cout << endl;

        if (outFile.is_open())
        {
            outFile << "Message: " << message << endl;
            outFile << "Key: " << key << endl;
            outFile << "Result: " << result << endl;
            outFile << endl;
        }
        else
        {
            std::cout << "Unable to open file for writing" << std::endl;
        }
    }
}
