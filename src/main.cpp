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
        if (std::cin.fail()) {
            std::cout << "Invalid input. Please try again!\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (choice < 1 || choice > 4) {
            std::cout << "Please enter a value between 1 and 4.";
            continue;
        }
    }
}