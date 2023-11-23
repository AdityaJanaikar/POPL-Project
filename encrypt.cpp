#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

string swapAdjacentCharacters(const string& str) {
    string swapped = str;

    for (int i = 0; i < swapped.length() - 1; i += 2) {
        char temp = swapped[i];
        swapped[i] = swapped[i + 1];
        swapped[i + 1] = temp;
    }

    return swapped;
}

string xorWithKey(const string& str, const string& key) {
    string result = str;

    for (size_t i = 0; i < result.length(); ++i) {
        result[i] ^= key[i % key.length()];
    }

    return result;
}

void displayInHex(const string& str) {
    for (char c : str) {
        cout << hex << setw(2) << setfill('0') << static_cast<int>(c);
    }
    cout << endl;
}

string getKeyFromUser() {
    string key;
    cout << "Enter the encryption key: ";
    getline(cin, key);
    return key;
}

string encrypt(const string& str, const string& key) {
    string swapped = swapAdjacentCharacters(str);
    string encrypted = xorWithKey(swapped, key);
    return encrypted;
}

string decrypt(const string& enc, const string& key) {
    string decrypted = xorWithKey(enc, key);
    string original = swapAdjacentCharacters(decrypted);
    return original;
}

int main() {
    string str;
    cout << "Enter the original string: ";
    getline(cin, str);

    string key = getKeyFromUser();

    string encrypted = encrypt(str, key);
    cout << "Encrypted string (Hex): ";
    displayInHex(encrypted);

    string decrypted = decrypt(encrypted, key);
    cout << "Decrypted string: " << decrypted << endl;

    return 0;
}
