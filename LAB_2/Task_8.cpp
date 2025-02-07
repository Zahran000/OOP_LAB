Task 8: Dynamic Array of Pointers

#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int** arr = new int*[size];
    for (int i = 0; i < size; ++i) {
        arr[i] = new int;
    }

    cout << "Enter " << size << " integers:\n";
    for (int i = 0; i < size; ++i) {
        cin >> *arr[i];
    }

    cout << "\nArray elements:\n";
    for (int i = 0; i < size; ++i) {
        cout << *arr[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < size; ++i) {
        delete arr[i];
    }
    delete[] arr;

    return 0;
}

