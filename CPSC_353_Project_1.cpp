#include "cypher.h"

using namespace std;

int main()
{
    while (true) {
        std::cout << "Choose an option:\n1. Encrypt\n2. Decrypt\n3. Exit\n";
        int choice;
        std::cin >> choice;
        
        if (choice == 3) {
            break;
        }
        if (choice != 1 && choice != 2) {
            std::cout << "Invalid choice\n";
            continue;
        }
        if (choice == 1) {
            std:: string text = get_input("Enter text to encrypt: ");
        }
        else {
            std:: string text = get_input("Enter text to decrypt: ");
        }
        std::cout << "Choose cipher:\n1. Caesar\n2. Vigenere\n3. One-time pad\n";
        int cipher_choice;
        std::cin >> cipher_choice;
        
    }
    return 0;
}

std:: string get_input(const std::string& prompt) {
    std:: string input;
    std::cout << prompt;
    std::getline(std::cin, input);
    return input;
}

void save_to_file(std::string& filename, std::string& content) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << content;
        file.close();
        std::cout << "Ciphertext saved to " << filename << std::endl;
    } else {
        std::cout << "Unable to open file for writing" << std::endl;
    }
}