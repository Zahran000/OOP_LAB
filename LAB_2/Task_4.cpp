## Task 4: Dynamic String Array

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int numStrings;
    cout << "Enter the number of strings: ";
    cin >> numStrings;

    string* strings = new string[numStrings];

    cout << "Enter the strings:\n";
    for (int i = 0; i < numStrings; ++i) {
        cin.ignore();
        getline(cin, strings[i]);
    }

    sort(strings, strings + numStrings);

    cout << "\nSorted Strings:\n";
    for (int i = 0; i < numStrings; ++i) {
        cout << strings[i] << endl;
    }

    delete[] strings;
    return 0;
}
