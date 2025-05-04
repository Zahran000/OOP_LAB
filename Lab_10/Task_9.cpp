#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream createFile("large_log.txt");
    createFile << "Line 1: This is some sample log data\n";
    createFile << "Line 2: More log information here\n";
    createFile << "Line 3: Additional logging details\n";
    createFile.close();

    ifstream inFile("large_log.txt");
    if (!inFile) {
        cerr << "Error opening file" << endl;
        return 1;
    }

    char buffer[11];
    inFile.read(buffer, 10);
    buffer[10] = '\0';
    streampos pos1 = inFile.tellg();
    cout << "First 10 chars: " << buffer << endl;
    cout << "Position after first read: " << pos1 << endl;

    inFile.read(buffer, 10);
    buffer[10] = '\0';
    streampos pos2 = inFile.tellg();
    cout << "Next 10 chars: " << buffer << endl;
    cout << "Position after second read: " << pos2 << endl;

    string line;
    getline(inFile, line);
    streampos pos3 = inFile.tellg();
    cout << "Next line: " << line << endl;
    cout << "Position after getline: " << pos3 << endl;

    inFile.close();
    return 0;
}
