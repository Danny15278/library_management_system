#pragma once;
#include <string>
#include <vector>


class Library {
private:
    std::vector<std::string> bookList;

public:
    Library();

    void addBook(const std::string& title);
    bool borrowBook(const std::string& title);
    void listBooks();
};