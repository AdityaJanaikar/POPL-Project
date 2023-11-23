#include <iostream>
#include <fstream>
#include <sstream>
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

string readFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error: Unable to open input file." << endl;
        return "";
    }

    string content((istreambuf_iterator<char>(inFile)), istreambuf_iterator<char>());
    inFile.close();

    return content;
}

void writeFile(const string& filename, const string& content) {
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Error: Unable to open " << filename << " for writing." << endl;
        return;
    }

    outFile << content;
    outFile.close();
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <filename>" << endl;
        return 1;
    }

    string filename = argv[1];

    // Read the content of the file
    string fileContent = readFile(filename);
    if (fileContent.empty()) {
        return 1;  // Error occurred during file reading
    }

    cout << "Read content from file: " << fileContent << endl;

    string key = getKeyFromUser();

    // Encrypt the content
    string encrypted = encrypt(fileContent, key);

    // Write encrypted content to encrypt.txt
    writeFile("encrypt.txt", encrypted);
    cout << "Content encrypted and written to encrypt.txt." << endl;

    // Decrypt the content
    string decrypted = decrypt(encrypted, key);

    // Write decrypted content to decrypt.txt
    writeFile("decrypt.txt", decrypted);
    cout << "Content decrypted and written to decrypt.txt." << endl;

    return 0;
}
