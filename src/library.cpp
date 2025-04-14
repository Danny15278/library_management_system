#include "library.hpp"
#include <iostream>


Library::Library() = default; // default constructor



void Library::addBook(const std::string& title) {
    bookList.push_back(title);
}

bool Library::borrowBook(const std::string& title) {
    auto book = std::find(bookList.begin(), bookList.end(), title);
    if (book != bookList.end())
    {
        bookList.erase(book);
        std::cout << "Successfully borrowed " << title << ".\n";
        return true;
    }
    std::cout << title << " was not found.\n";
    return false;
}

void Library::listBooks() {
    if (bookList.empty())
    {
        std::cout << "There are currently no books in the library.\n";
    }
    else
    {
        std::cout << "Books currently in the library:\n";
        for (const auto& title : bookList)
            std::cout << "- " << title << "\n";
    }
}