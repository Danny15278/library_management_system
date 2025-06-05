#pragma once
#include <string>
#include <vector>

struct Book {
    std::string title;
    std::string author;
    int publicationYear;
};

class Library {
private:
    std::vector<Book> bookList;

public:
    Library();

    void addBook(const Book& title);
    bool borrowBook(const Book& title);
    void listBooks();
};