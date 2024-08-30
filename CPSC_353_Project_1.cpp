#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int find_index(char);
string caesar(string, char);
string vigenere(string, string);
string one_time_pad(string, string);

const char ALPHA[27] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',' '};
int main(){
    cout << caesar("CAT", 'B') << endl;
    cout << vigenere("CAT", "AB") << endl;
    cout << one_time_pad("CAT", "ABC") << endl;

    return 0;
}

int find_index(char ch){
    for(int i = 0; i < sizeof(ALPHA)-1; i++){
        if (ch == ALPHA[i]){
            return i;
        }
    }
    throw invalid_argument("Recived an invalid character");
    return -1;
}

string caesar(string str, char key){
    int keyVal = find_index(key);
    for (int i = 0; i < str.length(); i++){
        str[i] = ALPHA[(find_index(toupper(str[i])) + keyVal) % 27];
    }
    return str;
}

string vigenere(string str, string key){
    if (key.length() >= str.length()){
        throw invalid_argument("Key length too long");
    }
    for (int i = 0; i < str.length(); i++){
        str[i] = ALPHA[(find_index(toupper(str[i])) + find_index(key[i % key.length()])) % 27];
    }
    return str;
}

string one_time_pad(string str, string key){
    if (key.length() != str.length()){
        throw invalid_argument("Key and string must be the same length");
    }
    for (int i = 0; i < str.length(); i++){
        str[i] = ALPHA[(find_index(toupper(str[i])) + find_index(key[i])) % 27];
    }
    return str;
}