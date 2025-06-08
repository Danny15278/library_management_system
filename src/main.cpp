#include <iostream>
#include <limits>
#include "library.hpp"

void printMenu() {
    std::cout << "=============================\n";
    std::cout << "   Welcome to the Library!   \n\n";
    std::cout << "1. Borrow Book\n";
    std::cout << "2. Add Book\n";
    std::cout << "3. Check for Book\n";
    std::cout << "4. List all Books\n";
    std::cout << "5. Quit\n";
    std::cout << "=============================\n";
    
}

int main() {
    Library myLibrary;

    printMenu();

    while (true) {
        std::cout << "Please enter your choice: "; 
        int choice;
        std::cin >> choice;

        if (std::cin.fail()) { // Catch invalid inputs
            std::cout << "Invalid input. Please try again!\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (choice < 1 || choice > 5) { // Catch values outside of range
            std::cout << "Please enter a value between 1 and 5.";
            continue;
        }


        if (choice == 1) { // Input 1: Borrowing a book from the LMS
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::string title;
            std::cout << "Please enter the title: ";
            std::getline(std::cin, title);
            myLibrary.borrowBook(title);

            std::cout << "Press ENTER to continue.";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.get();

            std::cout << "\033[2J\033[H";
            printMenu(); 
        }

        else if (choice == 2) { // Input 2: Add/Returning a book to the LMS 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::string title;
            std::cout << "Please enter the title: ";
            std::getline(std::cin, title);

            std::string author;
            std::cout << "Please enter the author's name: ";
            std::getline(std::cin, author);
            
            int publicationYear;
            std::cout << "Please enter the publication year: ";
            std::cin >> publicationYear;

            Book book{ title, author, publicationYear };
            myLibrary.addBook(book);
            
            std::cout << "Press ENTER to continue.";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.get();
            std::cout << "\033[2J\033[H"; 
            printMenu();
        }
        
        else if (choice == 3) { // Input 3: Check if LMS has book
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::string title;
            std::cout << "Please enter the title: ";
            std::getline(std::cin, title);
            if (myLibrary.hasBook(title)) {
                std::cout << title << " is in the library!\n";
            } else {
                std::cout << title << " is unfortunately not in the library.\n";
            }

            std::cout << "Press ENTER to continue.";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.get();
            std::cout << "\033[2J\033[H";
            printMenu(); 
        }

        else if (choice == 4) { // Input 4: List all books in LMS
            myLibrary.listBooks();

            std::cout << "Press ENTER to continue.";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.get();
            std::cout << "\033[2J\033[H"; 
            printMenu(); 
            
        }

        else { // Input 5: Exit programme.
            std::cout << "Exiting the programme.\n" << std::flush;
            break;
        }
    }
}