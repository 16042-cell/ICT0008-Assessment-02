

#include "Book.h"
#include <iostream>
#include <algorithm>
using namespace std;

// ============================================================
// sortBooks()
// Sorts an array of Book objects by ISBN (Bubble Sort)
// ============================================================
void sortBooks(Book books[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (books[j].getISBN() > books[j + 1].getISBN()) {
                swap(books[j], books[j + 1]);
            }
        }
    }
}

// ============================================================
// printArray()
// Displays all books in an array with a label
// ============================================================
void printArray(const string& label, Book books[], int size) {
    cout << "\n=== " << label << " ===" << endl;
    for (int i = 0; i < size; i++) {
        books[i].displayBookDetails();
    }
}

// ============================================================
// MAIN
// ============================================================
int main() {

    cout << "==========================================" << endl;
    cout << "   Library Book System - Test Application " << endl;
    cout << "==========================================" << endl;

    // ----------------------------------------------------------
    // TEST 1: Correct Book Instantiation
    // ----------------------------------------------------------
    cout << "\n--- TEST 1: Correct Book Instantiation ---" << endl;

    Book correct1, correct2, correct3;

    correct1.setBookDetails("The Great Gatsby",
        "F. Scott", "Fitzgerald", "978-0743273565", true, "2020-03-15");
    correct2.setBookDetails("1984",
        "George", "Orwell", "978-0451524935", false, "2021-01-10");
    correct3.setBookDetails("Pride and Prejudice",
        "Jane", "Austen", "978-0141439518", true, "2018-11-05");

    cout << "\n[Correct Book 1]" << endl;
    correct1.displayBookDetails();
    cout << "\n[Correct Book 2]" << endl;
    correct2.displayBookDetails();
    cout << "\n[Correct Book 3]" << endl;
    correct3.displayBookDetails();

    // ----------------------------------------------------------
    // TEST 2: Incorrect Book Instantiation
    // ----------------------------------------------------------
    cout << "\n--- TEST 2: Incorrect Book Instantiation ---" << endl;

    Book incorrect1, incorrect2, incorrect3;

    // Book 1: numeric title, empty author, invalid ISBN, invalid date
    incorrect1.setBookDetails("12345",
        "", "", "INVALID", true, "9999-99-99");

    // Book 2: empty title, valid author, invalid ISBN, empty date
    incorrect2.setBookDetails("",
        "George", "Orwell", "000-0000000000", false, "");

    // Book 3: author same as title, valid ISBN, empty availability handled as false, invalid date
    incorrect3.setBookDetails("The Great Gatsby",
        "The Great", "Gatsby", "978-0743273565", false, "abcde");

    cout << "\n[Incorrect Book 1] - numeric title, empty author, invalid ISBN" << endl;
    incorrect1.displayBookDetails();
    cout << "\n[Incorrect Book 2] - empty title, invalid ISBN format, empty date" << endl;
    incorrect2.displayBookDetails();
    cout << "\n[Incorrect Book 3] - author same as title, invalid date format" << endl;
    incorrect3.displayBookDetails();

    // ----------------------------------------------------------
    // TEST 3: Arrays in different orders + Sort
    // ----------------------------------------------------------
    cout << "\n--- TEST 3: Sorting Arrays ---" << endl;

    // Array A: Ascending order (by ISBN)
    Book arrayA[3];
    arrayA[0].setBookDetails("Pride and Prejudice",
        "Jane", "Austen", "978-0141439518", true, "2018-11-05");
    arrayA[1].setBookDetails("1984",
        "George", "Orwell", "978-0451524935", false, "2021-01-10");
    arrayA[2].setBookDetails("The Great Gatsby",
        "F. Scott", "Fitzgerald", "978-0743273565", true, "2020-03-15");

    // Array B: Descending order (by ISBN)
    Book arrayB[3];
    arrayB[0].setBookDetails("The Great Gatsby",
        "F. Scott", "Fitzgerald", "978-0743273565", true, "2020-03-15");
    arrayB[1].setBookDetails("1984",
        "George", "Orwell", "978-0451524935", false, "2021-01-10");
    arrayB[2].setBookDetails("Pride and Prejudice",
        "Jane", "Austen", "978-0141439518", true, "2018-11-05");

    // Array C: Mixed order
    Book arrayC[3];
    arrayC[0].setBookDetails("1984",
        "George", "Orwell", "978-0451524935", false, "2021-01-10");
    arrayC[1].setBookDetails("The Great Gatsby",
        "F. Scott", "Fitzgerald", "978-0743273565", true, "2020-03-15");
    arrayC[2].setBookDetails("Pride and Prejudice",
        "Jane", "Austen", "978-0141439518", true, "2018-11-05");

    // Print before sorting
    printArray("Array A - Before Sort (Ascending order added)", arrayA, 3);
    printArray("Array B - Before Sort (Descending order added)", arrayB, 3);
    printArray("Array C - Before Sort (Mixed order added)", arrayC, 3);

    // Sort all arrays
    sortBooks(arrayA, 3);
    sortBooks(arrayB, 3);
    sortBooks(arrayC, 3);

    // Print after sorting
    cout << "\n\n========== AFTER SORTING ==========" << endl;
    printArray("Array A - After Sort", arrayA, 3);
    printArray("Array B - After Sort", arrayB, 3);
    printArray("Array C - After Sort", arrayC, 3);

    cout << "\n==========================================" << endl;
    cout << "   Test Complete                           " << endl;
    cout << "==========================================" << endl;

    return 0;
}