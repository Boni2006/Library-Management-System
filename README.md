# Library Management System (C++)

A beginner-friendly, console-based Library Management System developed in C++.

## Student Details

- **Student UID:** 25BCA10370
- **Project:** Library Management System
- **Language:** C++

## Features

- Add new books with a unique Book ID
- Display all books in the library
- Search for a book using its ID
- Issue available books
- Return issued books
- Save book records in a text file and load them when the program starts

## Concepts Used

- Classes and objects
- Vectors
- Functions
- Conditional statements and loops
- File handling using `ifstream` and `ofstream`
- String input using `getline()`

## Files

- `main.cpp` — Main C++ source code
- `books.txt` — Created automatically when book records are saved; stores library data locally

## How to Compile and Run

Using g++:

```bash
g++ main.cpp -o library
./library
```

On Windows:

```bash
g++ main.cpp -o library.exe
library.exe
```

The program creates or updates `books.txt` in the working directory when books are added, issued, or returned.

## Note

This is a console-based academic project. The data file is generated locally when the program is run; it does not need to be uploaded with the source code.
