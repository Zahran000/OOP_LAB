Task 10: Dynamic Memory Allocation for 3D Arrays

#include <iostream>
using namespace std;

int main() {
    int x, y, z;
    cout << "Enter the dimensions of the 3D array (x y z): ";
    cin >> x >> y >> z;

    int*** array = new int**[x];
    for (int i = 0; i < x; ++i) {
        array[i] = new int*[y];
        for (int j = 0; j < y; ++j) {
            array[i][j] = new int[z];
        }
    }

    cout << "Enter the elements of the 3D array:\n";
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            for (int k = 0; k < z; ++k) {
                cin >> array[i][j][k];
            }
        }
    }

    cout << "\n3D Array elements:\n";
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            for (int k = 0; k < z; ++k) {
                cout << "array[" << i << "][" << j << "][" << k << "] = " 
                     << array[i][j][k] << endl;
            }
        }
    }

    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            delete[] array[i][j];
        }
        delete[] array[i];
    }
    delete[] array;

    return 0;
}
