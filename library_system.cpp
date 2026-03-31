/**
 * ============================================================
 * ICT0008 Advanced Programming Skills — Assessment 2
 * Subject  : Application Development
 * Student  : Rena Onuma (16042)
 * Date     : 2025
 *
 * Description:
 *   A simple library book management system using a Book class.
 *   Demonstrates OOP concepts: attributes, methods, constructors,
 *   access modifiers, sorting, and borrow/return logic.
 * ============================================================
 */

#include <iostream>
#include <string>
#include <algorithm>   // std::swap

using namespace std;

// ============================================================
// Book class
// ============================================================
class Book {
private:
    // Private attributes — only accessible via public methods
    string title;
    string author;
    string isbn;
    bool   availability;   // true = available, false = borrowed
    string dateAdd;        // Date the library acquired the book

public:
    // ----------------------------------------------------------
    // Default constructor — initialises all attributes to defaults
    // ----------------------------------------------------------
    Book() : title(""), author(""), isbn(""), availability(true), dateAdd("") {}

    // ----------------------------------------------------------
    // setBookDetails()
    // Assigns values to all book attributes.
    // Parameters: title, author, isbn, availability, dateAdd
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
    // Prints the book's title, author, ISBN, and availability.
    // ----------------------------------------------------------
    void displayBookDetails() const {
        cout << "------------------------------" << endl;
        cout << "Title       : " << title        << endl;
        cout << "Author      : " << author       << endl;
        cout << "ISBN        : " << isbn         << endl;
        cout << "Date Added  : " << dateAdd      << endl;
        cout << "Status      : " << (availability ? "Available" : "Borrowed") << endl;
    }

    // ----------------------------------------------------------
    // borrowBook()
    // Marks the book as borrowed ONLY if it is currently available.
    // Displays an error message if the book is already borrowed.
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
    // Marks the book as available again after it is returned.
    // ----------------------------------------------------------
    void returnBook() {
        availability = true;
        cout << "[OK] \"" << title << "\" has been returned. Thank you!" << endl;
    }

    // ----------------------------------------------------------
    // getISBN()
    // Accessor for ISBN — used by sortBookData().
    // ----------------------------------------------------------
    string getISBN() const {
        return isbn;
    }

    // ----------------------------------------------------------
    // isAvailable()
    // Accessor for availability flag.
    // ----------------------------------------------------------
    bool isAvailable() const {
        return availability;
    }
};

// ============================================================
// sortBookData()
// Sorts an array of Book objects by ISBN (ascending).
// Algorithm: Bubble Sort — simple and easy to trace for small sets.
//   Time complexity: O(n²) — acceptable for n=5.
// ============================================================
void sortBookData(Book books[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (books[j].getISBN() > books[j + 1].getISBN()) {
                swap(books[j], books[j + 1]);
            }
        }
    }
}

// ============================================================
// Main application
// ============================================================
int main() {
    const int SIZE = 5;
    Book books[SIZE];

    // ----------------------------------------------------------
    // Initialise the 5 books
    // Format: setBookDetails(title, author, isbn, availability, dateAdded)
    // ----------------------------------------------------------
    books[0].setBookDetails("The Great Gatsby",          "F. Scott Fitzgerald", "978-0743273565", true,  "2020-03-15");
    books[1].setBookDetails("To Kill a Mockingbird",     "Harper Lee",          "978-0061935466", true,  "2019-07-20");
    books[2].setBookDetails("1984",                      "George Orwell",       "978-0451524935", false, "2021-01-10");
    books[3].setBookDetails("Pride and Prejudice",       "Jane Austen",         "978-0141439518", true,  "2018-11-05");
    books[4].setBookDetails("The Catcher in the Rye",    "J.D. Salinger",       "978-0316769174", true,  "2022-06-30");

    // Sort books by ISBN before starting
    sortBookData(books, SIZE);

    cout << "==========================================" << endl;
    cout << "   Welcome to the Community Library!      " << endl;
    cout << "==========================================" << endl;
    cout << "\nCurrent book catalogue (sorted by ISBN):\n" << endl;

    // Display all books on startup
    for (int i = 0; i < SIZE; i++) {
        books[i].displayBookDetails();
    }

    // ----------------------------------------------------------
    // Main loop — prompt user for ISBN until "0" is entered
    // ----------------------------------------------------------
    string inputISBN;

    while (true) {
        cout << "\nEnter the ISBN of the book you wish to borrow (or 0 to quit): ";
        cin >> inputISBN;

        // Termination condition
        if (inputISBN == "0") {
            cout << "\nThank you for using the Community Library. Goodbye!" << endl;
            break;
        }

        // Search for the book by ISBN (linear search)
        bool found = false;
        for (int i = 0; i < SIZE; i++) {
            if (books[i].getISBN() == inputISBN) {
                found = true;
                books[i].borrowBook();
                break;
            }
        }

        // ISBN not found in the library
        if (!found) {
            cout << "[ERROR] No book with ISBN \"" << inputISBN
                 << "\" was found in the library." << endl;
        }
    }

    return 0;
}
