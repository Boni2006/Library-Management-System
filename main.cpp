#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Book {
public:
    int id;
    string title;
    string author;
    bool available;

    Book(int i, string t, string a) {
        id = i;
        title = t;
        author = a;
        available = true;
    }
};

vector<Book> books;

void saveBooks() {
    ofstream file("books.txt");

    for (int i = 0; i < (int)books.size(); i++) {
        file << books[i].id << '\n';
        file << books[i].title << '\n';
        file << books[i].author << '\n';
        file << books[i].available << '\n';
    }

    file.close();
}

void loadBooks() {
    ifstream file("books.txt");

    int id, available;
    string title, author;

    while (file >> id) {
        file.ignore(1000, '\n');
        getline(file, title);
        getline(file, author);
        file >> available;
        file.ignore(1000, '\n');

        Book b(id, title, author);
        b.available = (available == 1);
        books.push_back(b);
    }

    file.close();
}

void addBook() {
    int id;
    string title, author;

    cout << "Enter Book ID: ";
    cin >> id;
    cin.ignore(1000, '\n');

    for (int i = 0; i < (int)books.size(); i++) {
        if (books[i].id == id) {
            cout << "Book ID already exists!\n";
            return;
        }
    }

    cout << "Enter Book Title: ";
    getline(cin, title);

    cout << "Enter Author Name: ";
    getline(cin, author);

    books.push_back(Book(id, title, author));
    saveBooks();

    cout << "Book added successfully!\n";
}

void displayBooks() {
    if (books.empty()) {
        cout << "No books available.\n";
        return;
    }

    cout << "\n--- Library Books ---\n";

    for (int i = 0; i < (int)books.size(); i++) {
        cout << "\nBook ID: " << books[i].id;
        cout << "\nTitle: " << books[i].title;
        cout << "\nAuthor: " << books[i].author;
        cout << "\nStatus: "
             << (books[i].available ? "Available" : "Issued");
        cout << "\n---------------------\n";
    }
}

void searchBook() {
    int id;
    cout << "Enter Book ID to search: ";
    cin >> id;

    for (int i = 0; i < (int)books.size(); i++) {
        if (books[i].id == id) {
            cout << "\nBook Found!\n";
            cout << "Title: " << books[i].title << '\n';
            cout << "Author: " << books[i].author << '\n';
            cout << "Status: "
                 << (books[i].available ? "Available" : "Issued")
                 << '\n';
            return;
        }
    }

    cout << "Book not found!\n";
}

void issueBook() {
    int id;
    cout << "Enter Book ID to issue: ";
    cin >> id;

    for (int i = 0; i < (int)books.size(); i++) {
        if (books[i].id == id) {
            if (books[i].available) {
                books[i].available = false;
                saveBooks();
                cout << "Book issued successfully!\n";
            } else {
                cout << "Book is already issued!\n";
            }
            return;
        }
    }

    cout << "Book not found!\n";
}

void returnBook() {
    int id;
    cout << "Enter Book ID to return: ";
    cin >> id;

    for (int i = 0; i < (int)books.size(); i++) {
        if (books[i].id == id) {
            if (!books[i].available) {
                books[i].available = true;
                saveBooks();
                cout << "Book returned successfully!\n";
            } else {
                cout << "This book was not issued!\n";
            }
            return;
        }
    }

    cout << "Book not found!\n";
}

int main() {
    loadBooks();

    int choice;

    do {
        cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Search Book\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number.\n";
            break;
        }

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                issueBook();
                break;
            case 5:
                returnBook();
                break;
            case 6:
                cout << "Thank you for using the Library System!\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 6);

    return 0;
}