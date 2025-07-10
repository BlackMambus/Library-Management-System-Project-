#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include <string>
#include <vector>

struct Book {
    int id;
    std::string title;
    std::string author;
    int year;
    bool isAvailable;
};

class Library {
private:
    std::vector<Book> books;
    int nextId;

public:
    Library();

    void addBook(const std::string& title, const std::string& author, int year);
    bool updateBook(int id, const std::string& title, const std::string& author, int year, bool isAvailable);
    bool deleteBook(int id);
    Book* searchBook(int id);
    void displayBooks() const;
};

#endif
#include "Library.hpp"
#include <iostream>
#include <iomanip>

Library::Library() : nextId(1) {}

void Library::addBook(const std::string& title, const std::string& author, int year) {
    books.push_back({nextId++, title, author, year, true});
}

bool Library::updateBook(int id, const std::string& title, const std::string& author, int year, bool isAvailable) {
    for (auto& book : books) {
        if (book.id == id) {
            book.title = title;
            book.author = author;
            book.year = year;
            book.isAvailable = isAvailable;
            return true;
        }
    }
    return false;
}

bool Library::deleteBook(int id) {
    for (auto it = books.begin(); it != books.end(); ++it) {
        if (it->id == id) {
            books.erase(it);
            return true;
        }
    }
    return false;
}

Book* Library::searchBook(int id) {
    for (auto& book : books) {
        if (book.id == id) {
            return &book;
        }
    }
    return nullptr;
}

void Library::displayBooks() const {
    std::cout << std::left << std::setw(5) << "ID"
              << std::setw(25) << "Title"
              << std::setw(20) << "Author"
              << std::setw(6) << "Year"
              << std::setw(10) << "Available" << "\n";

    for (const auto& book : books) {
        std::cout << std::left << std::setw(5) << book.id
                  << std::setw(25) << book.title
                  << std::setw(20) << book.author
                  << std::setw(6) << book.year
                  << std::setw(10) << (book.isAvailable ? "Yes" : "No") << "\n";
    }
}
#include "Library.hpp"
#include <iostream>

int main() {
    Library library;
    int choice;

    while (true) {
        std::cout << "\nLibrary Management System\n";
        std::cout << "1. Add Book\n2. Update Book\n3. Delete Book\n4. Search Book\n5. Display All Books\n6. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        if (choice == 1) {
            std::string title, author;
            int year;
            std::cout << "Enter title, author, year: ";
            std::cin.ignore();
            std::getline(std::cin, title);
            std::getline(std::cin, author);
            std::cin >> year;
            library.addBook(title, author, year);
        } else if (choice == 2) {
            int id, year;
            std::string title, author;
            bool isAvailable;
            std::cout << "Enter ID to update: ";
            std::cin >> id;
            std::cin.ignore();
            std::cout << "Enter new title, author, year, availability (1 for yes, 0 for no): ";
            std::getline(std::cin, title);
            std::getline(std::cin, author);
            std::cin >> year >> isAvailable;
            if (!library.updateBook(id, title, author, year, isAvailable))
                std::cout << "Book not found.\n";
        } else if (choice == 3) {
            int id;
            std::cout << "Enter ID to delete: ";
            std::cin >> id;
            if (!library.deleteBook(id))
                std::cout << "Book not found.\n";
        } else if (choice == 4) {
            int id;
            std::cout << "Enter ID to search: ";
            std::cin >> id;
            Book* book = library.searchBook(id);
            if (book) {
                std::cout << "Found: " << book->title << " by " << book->author
                          << " (" << book->year << ") - "
                          << (book->isAvailable ? "Available" : "Checked Out") << "\n";
            } else {
                std::cout << "Book not found.\n";
            }
        } else if (choice == 5) {
            library.displayBooks();
        } else if (choice == 6) {
            break;
        } else {
            std::cout << "Invalid choice.\n";
        }
    }

    return 0;
}



