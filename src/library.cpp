#include "library.hpp"
#include "helpers.hpp"
#include <algorithm>
#include <iostream>

Library::Library() = default; // default constructor



void Library::addBook(const Book& book) {
    bookList.push_back(book);
}

bool Library::borrowBook(const std::string& title) {
    auto it = std::find_if(bookList.begin(), bookList.end(), [&] (const Book& book) {
        return toLower(book.title) == toLower(title);
    });

    if (it != bookList.end()) {
        std::cout << "Successfully borrowed \"" << it->title << "\", by " << it->author << " (" << it->publicationYear << ").\n";
        bookList.erase(it);
        return true;
    } else {
        std::cout << "\"" << title << "\" was not found in the library.\n";
        return false;
    }
}

void Library::listBooks() {
    if (bookList.empty())
    {
        std::cout << "There are currently no books in the library.\n";
    }
    else
    {
        std::cout << "Books currently in the library:\n";
        for (const auto& book : bookList) {
            std::cout << "- " << book.title << " by " << book.author << " (" << book.publicationYear << ")\n";
        }
    }
}

bool Library::hasBook(const std::string& title) {
    auto it = std::find_if(bookList.begin(), bookList.end(), [&] (const Book& book) {
        return toLower(book.title) == toLower(title);
    });

    return it != bookList.end(); 
}