#include <iostream>
#include <string>
using namespace std;

struct Book {
    string title;
    string author;
    int year;
};

int main() {
    int numBooks;
    cout << "Enter the number of books: ";
    cin >> numBooks;

    Book* books = new Book[numBooks];

    for (int i = 0; i < numBooks; ++i) {
        cout << "\nEnter details for book " << i + 1 << ":\n";
        cout << "Title: ";
        cin.ignore(); 
        getline(cin, books[i].title);
        cout << "Author: ";
        getline(cin, books[i].author);
        cout << "Year: ";
        cin >> books[i].year;
    }

    int specificYear;
    cout << "\nEnter a year to display books published after it: ";
    cin >> specificYear;

    cout << "\nBooks published after " << specificYear << ":\n";
    for (int i = 0; i < numBooks; ++i) {
        if (books[i].year > specificYear) {
            cout << "Title: " << books[i].title
                 << ", Author: " << books[i].author
                 << ", Year: " << books[i].year << endl;
        }
    }

    // Deallocate memory
    delete[] books;

    return 0;
}

