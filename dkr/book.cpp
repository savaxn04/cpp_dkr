#include <iostream>
#include <vector>
#include <fstream>
#include <string>

// Клас для книги
class Book {
    int id;
    std::string title;
    std::string author;
    std::string publisher;
    int year;
    int pages;
    double price;
    std::string coverType;

public:
    Book(int id, std::string title, std::string author, std::string publisher, int year, int pages, double price, std::string coverType)
        : id(id), title(title), author(author), publisher(publisher), year(year), pages(pages), price(price), coverType(coverType) {}

    // Перевантаження оператора '<<'
    friend std::ostream& operator<<(std::ostream& os, const Book& book) {
        os << "ID: " << book.getID() << ", Title: " << book.getTitle() << ", Author: " << book.getAuthor()
            << ", Publisher: " << book.getPublisher() << ", Year: " << book.getYear()
            << ", Pages: " << book.getPages() << ", Price: " << book.getPrice()
            << ", Cover Type: " << book.getCoverType();
        return os;
    }

    // Методи get...
    int getID() const { return id; }
    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }
    std::string getPublisher() const { return publisher; }
    int getYear() const { return year; }
    int getPages() const { return pages; }
    double getPrice() const { return price; }
    std::string getCoverType() const { return coverType; }

    std::string toString() const {
        return "ID: " + std::to_string(id) + ", Title: " + title + ", Author: " + author
            + ", Publisher: " + publisher + ", Year: " + std::to_string(year)
            + ", Pages: " + std::to_string(pages) + ", Price: " + std::to_string(price)
            + ", Cover Type: " + coverType;
    }
};

// Ваш код для взаємодії з користувачем, створення об'єктів Book, збереження їх в масиві та виведення відповідних списків книг тут...