#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // Create and write initial data
    ofstream outFile("config.txt");
    outFile << "AAAAABBBBBCCCCC";
    outFile.close();

    // Reopen in read/write mode
    fstream file("config.txt", ios::in | ios::out);
    if (!file) {
        cerr << "Error opening file" << endl;
        return 1;
    }

    // Move to position 5 (start of second block) and overwrite
    file.seekp(5);
    file << "XXXXX";

    // Close and reopen to verify changes
    file.close();
    ifstream inFile("config.txt");
    string content;
    getline(inFile, content);
    inFile.close();

    cout << "Updated file content: " << content << endl;

    return 0;
}
