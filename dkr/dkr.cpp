// dkr.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "logger.cpp"
#include "book.cpp"

int main() {
    Logger logger("log.txt");
    std::vector<Book> books;

    // Додаємо книги
    books.emplace_back(1, "Title1", "Author1", "Publisher1", 2000, 100, 10.0, "Hardcover");
    books.emplace_back(2, "Title2", "Author2", "Publisher2", 2005, 200, 20.0, "Softcover");
    // ... додайте більше книг за потреби
    std::string author, publisher;
    int year;

    // Вивести список книг заданого автора
    std::cout << "Enter author name: ";
    std::getline(std::cin, author);
    logger.log("User entered author: " + author);
    for (const Book& book : books) {
        if (book.getAuthor() == author) {
            std::cout << book << std::endl;
        }
    }

    // Вивести список книг, випущених заданим видавництвом
    std::cout << "Enter publisher name: ";
    std::getline(std::cin, publisher);
    logger.log("User entered publisher: " + publisher);
    for (const Book& book : books) {
        if (book.getPublisher() == publisher) {
            std::cout << book << std::endl;
        }
    }

    // Вивести список книг, випущених після заданого року
    std::cout << "Enter year: ";
    std::cin >> year;
    logger.log("User entered year: " + std::to_string(year));
    for (const Book& book : books) {
        if (book.getYear() > year) {
            std::cout << book << std::endl;
        }
    }

    // Записати дані всіх об'єктів у файл з шифруванням
    std::ofstream file("books.txt");
    if (file.is_open()) {
        for (const Book& book : books) {
            std::string line = book.toString();
            // Просте XOR шифрування
            for (char& c : line) {
                c ^= 123;
            }
            file << line << std::endl;
        }
        file.close();
    }

    return 0;
}
