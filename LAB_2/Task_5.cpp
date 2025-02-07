## Task 5: Pointers and Arrays

#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int* arr = new int[size];
    cout << "Enter " << size << " integers:\n";
    for (int i = 0; i < size; ++i) {
        cin >> *(arr + i);
    }

    cout << "\nArray elements using pointer arithmetic:\n";
    for (int i = 0; i < size; ++i) {
        cout << *(arr + i) << " ";
    }

    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += *(arr + i);
    }
    cout << "\nSum of array elements: " << sum << endl;

    delete[] arr;
    return 0;
}

