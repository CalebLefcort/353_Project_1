#include "cypher.h"

using namespace std;

int main()
{
    Caesar caesar = Caesar('B');
    Vigenere vigenere = Vigenere("AB");
    OneTimePad one_time_pad = OneTimePad("ABC");

    cout << caesar.encrypt("CAT") << endl;
    cout << vigenere.encrypt("CAT") << endl;
    cout << one_time_pad.encrypt("CAT") << endl;

    cout << caesar.decrypt(caesar.encrypt("CAT")) << endl;
    cout << vigenere.decrypt(vigenere.encrypt("CAT")) << endl;
    cout << one_time_pad.decrypt(one_time_pad.encrypt("CAT")) << endl;

    return 0;
}
