#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream outFile("sensor_log.txt");
    
    outFile << "Sensor 1: 25.5 C" << endl;
    streampos pos1 = outFile.tellp();
    cout << pos1 << endl;

    outFile << "Sensor 2: 98.1 %RH" << endl;
    streampos pos2 = outFile.tellp();
    cout << pos2 << endl;

    outFile.close();
    return 0;
}
