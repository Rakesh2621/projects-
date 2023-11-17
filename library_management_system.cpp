#include <iostream>
#include <vector>
#include <string>

class Book {
public:
    std::string title;
    std::string author;
    int year;

    Book(const std::string& title, const std::string& author, int year)
        : title(title), author(author), year(year) {}
};

class Library {
private:
    std::vector<Book> books;

public:
    void addBook(const Book& book) {
        books.push_back(book);
        std::cout << "Book added to the library." << std::endl;
    }

    void searchBook(const std::string& title) {
        bool found = false;
        for (const Book& book : books) {
            if (book.title == title) {
                found = true;
                std::cout << "Title: " << book.title << std::endl;
                std::cout << "Author: " << book.author << std::endl;
                std::cout << "Year: " << book.year << std::endl;
                std::cout << std::endl;
            }
        }
        if (!found) {
            std::cout << "Book not found in the library." << std::endl;
        }
    }

    void displayInventory() {
        std::cout << "Library Inventory:" << std::endl;
        for (const Book& book : books) {
            std::cout << "Title: " << book.title << std::endl;
            std::cout << "Author: " << book.author << std::endl;
            std::cout << "Year: " << book.year << std::endl;
            std::cout << std::endl;
        }
    }
};

int main() {
    Library library;

    while (true) {
        std::cout << "Library Management System" << std::endl;
        std::cout << "1. Add a book" << std::endl;
        std::cout << "2. Search for a book" << std::endl;
        std::cout << "3. Display inventory" << std::endl;
        std::cout << "4. Quit" << std::endl;
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string title, author;
                int year;
                std::cout << "Enter book title: ";
                std::cin.ignore();
                std::getline(std::cin, title);
                std::cout << "Enter book author: ";
                std::getline(std::cin, author);
                std::cout << "Enter publication year: ";
                std::cin >> year;
                Book book(title, author, year);
                library.addBook(book);
                break;
            }
            case 2: {
                std::string title;
                std::cout << "Enter the title to search: ";
                std::cin.ignore();
                std::getline(std::cin, title);
                library.searchBook(title);
                break;
            }
            case 3:
                library.displayInventory();
                break;
            case 4:
                std::cout << "Goodbye!" << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
