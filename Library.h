/**
 * ============================================================
 * ICT0008 Advanced Programming Skills — Assessment 2
 * File     : Library.h
 * Student  : Rena Onuma (16042)
 * Date     : 2025
 *
 * Description:
 *   Header file for the Library class.
 *   Manages the collection of books and the main application loop.
 * ============================================================
 */

#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include <algorithm>   // std::swap

// ============================================================
// Library class
// Manages an array of 5 Book objects and handles all
// user interactions including searching and borrowing.
// ============================================================
class Library {
private:
    static const int SIZE = 5;
    Book books[SIZE];

    // ----------------------------------------------------------
    // sortBooks()
    // Sorts the books array by ISBN in ascending order.
    // Algorithm: Bubble Sort — O(n²), suitable for n=5.
    // ----------------------------------------------------------
    void sortBooks() {
        for (int i = 0; i < SIZE - 1; i++) {
            for (int j = 0; j < SIZE - i - 1; j++) {
                if (books[j].getISBN() > books[j + 1].getISBN()) {
                    swap(books[j], books[j + 1]);
                }
            }
        }
    }

    // ----------------------------------------------------------
    // initialiseBooks()
    // Sets up the 5 books in the library collection.
    // ----------------------------------------------------------
    void initialiseBooks() {
        books[0].setBookDetails("The Great Gatsby",
            "F. Scott Fitzgerald", "978-0743273565", true,  "2020-03-15");
        books[1].setBookDetails("To Kill a Mockingbird",
            "Harper Lee",          "978-0061935466", true,  "2019-07-20");
        books[2].setBookDetails("1984",
            "George Orwell",       "978-0451524935", false, "2021-01-10");
        books[3].setBookDetails("Pride and Prejudice",
            "Jane Austen",         "978-0141439518", true,  "2018-11-05");
        books[4].setBookDetails("The Catcher in the Rye",
            "J.D. Salinger",       "978-0316769174", true,  "2022-06-30");
    }

    // ----------------------------------------------------------
    // displayAllBooks()
    // Displays all books in the collection.
    // ----------------------------------------------------------
    void displayAllBooks() const {
        for (int i = 0; i < SIZE; i++) {
            books[i].displayBookDetails();
        }
    }

    // ----------------------------------------------------------
    // searchAndBorrow()
    // Searches for a book by ISBN and calls borrowBook() if found.
    // Displays an error message if the ISBN is not found.
    // ----------------------------------------------------------
    void searchAndBorrow(const string& inputISBN) {
        bool found = false;
        for (int i = 0; i < SIZE; i++) {
            if (books[i].getISBN() == inputISBN) {
                found = true;
                books[i].borrowBook();
                break;
            }
        }
        if (!found) {
            cout << "[ERROR] No book with ISBN \"" << inputISBN
                 << "\" was found in the library." << endl;
        }
    }

public:
    // ----------------------------------------------------------
    // run()
    // Main application loop — initialises the library, displays
    // books, and prompts the user to borrow by ISBN until '0'.
    // ----------------------------------------------------------
    void run() {
        initialiseBooks();
        sortBooks();

        cout << "==========================================" << endl;
        cout << "   Welcome to the Community Library!      " << endl;
        cout << "==========================================" << endl;
        cout << "\nCurrent book catalogue (sorted by ISBN):\n" << endl;

        displayAllBooks();

        string inputISBN;
        while (true) {
            cout << "\nEnter the ISBN of the book you wish to borrow (or 0 to quit): ";
            cin >> inputISBN;

            if (inputISBN == "0") {
                cout << "\nThank you for using the Community Library. Goodbye!" << endl;
                break;
            }

            searchAndBorrow(inputISBN);
        }
    }
};

#endif
