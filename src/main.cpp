#include <iostream>
#include <limits>
#include <library.hpp>


int main() {
    Library myLibrary;
    
    while (true) {
        std::cout << "1. Borrow Book\n";
        std::cout << "2. Add/Return Book\n";
        std::cout << "3. List all Books\n";
        std::cout << "4. Quit\n";
        
        std::cout << "\n Please enter your choice: "; 
        int choice;
        std::cin >> choice;

        if (std::cin.fail()) { // Catch invalid inputs
            std::cout << "Invalid input. Please try again!\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (choice < 1 || choice > 4) { // Catch values outside of range
            std::cout << "Please enter a value between 1 and 4.";
            continue;
        }


        if (choice == 1) { // Input 1: Borrowing a book from the LMS
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::string title;
            std::cout << "Please enter the title: ";
            std::getline(std::cin, title);
            myLibrary.borrowBook(title);
        }
    }
}