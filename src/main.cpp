#include "library.hpp"
#include <iostream>


int main() {
    Library myLibrary;

    myLibrary.addBook("Crime and Punishment");
    myLibrary.addBook("Metamorphosis");
    myLibrary.addBook("Blood Meridian");

    std::cout << "Listing books after adding:\n";
    myLibrary.listBooks();

    std::cout << "\nAttempting to borrow 'Metamorphosis':\n";
    if (myLibrary.borrowBook("Metamorphosis"))
        std::cout << "Successfully borrowed Metamorphosis.\n";
    else
        std::cout << "Metamorphosis was unavailable.\n";

    std::cout << "Listing books after borrowing:\n";
    myLibrary.listBooks();

    return 0;
}