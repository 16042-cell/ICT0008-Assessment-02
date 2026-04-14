/**
 * ============================================================
 * ICT0008 Advanced Programming Skills — Assessment 2
 * File     : Book.h
 * Student  : Rena Onuma (16042)
 * Date     : 2025
 *
 * Description:
 *   Header file for the Book class.
 *   Represents an individual book in the library.
 * ============================================================
 */

#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
using namespace std;

// ============================================================
// Book class
// Represents a single book in the library.
// ============================================================
class Book {
private:
    string title;
    string author;
    string isbn;
    bool   availability;   // true = available, false = borrowed
    string dateAdd;

public:
    // Default constructor
    Book() : title(""), author(""), isbn(""), availability(true), dateAdd("") {}

    // ----------------------------------------------------------
    // setBookDetails()
    // Assigns values to all book attributes.
    // ----------------------------------------------------------
    void setBookDetails(const string& t, const string& a,
                        const string& i, bool avail, const string& d) {
        title        = t;
        author       = a;
        isbn         = i;
        availability = avail;
        dateAdd      = d;
    }

    // ----------------------------------------------------------
    // displayBookDetails()
    // Prints the book's title, author, ISBN, date added, and status.
    // ----------------------------------------------------------
    void displayBookDetails() const {
        cout << "------------------------------" << endl;
        cout << "Title       : " << title  << endl;
        cout << "Author      : " << author << endl;
        cout << "ISBN        : " << isbn   << endl;
        cout << "Date Added  : " << dateAdd << endl;
        cout << "Status      : " << (availability ? "Available" : "Borrowed") << endl;
    }

    // ----------------------------------------------------------
    // borrowBook()
    // Marks the book as borrowed ONLY if currently available.
    // ----------------------------------------------------------
    void borrowBook() {
        if (availability) {
            availability = false;
            cout << "[OK] You have successfully borrowed: \"" << title << "\"" << endl;
        } else {
            cout << "[ERROR] Sorry, \"" << title << "\" is currently not available." << endl;
        }
    }

    // ----------------------------------------------------------
    // returnBook()
    // Marks the book as available again.
    // ----------------------------------------------------------
    void returnBook() {
        availability = true;
        cout << "[OK] \"" << title << "\" has been returned. Thank you!" << endl;
    }

    // Accessors
    string getISBN()     const { return isbn; }
    bool   isAvailable() const { return availability; }
};

#endif
