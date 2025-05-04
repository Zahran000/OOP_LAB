#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream outFile("sensor_log.txt");
    
    if (!outFile) {
        cerr << "Error opening file" << endl;
        return 1;
    }

    outFile << "Sensor1: 25.5C" << endl;
    streampos pos1 = outFile.tellp();
    cout << "Posion after first write: " << pos1 << endl;

    outFile << "Sensor2: 72.3F" << endl;
    streampos pos2 = outFile.tellp();
    cout << "Position fter second write: " << pos2 << endl;

    outFile << "Sensor3: 101.2kPa" << endl;
    streampos pos3 = outFile.tellp();
    cout << "Position after third wrte: " << pos3 << endl;

    outFile.close();

    return 0;
}
