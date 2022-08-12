#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <tuple>
#include <exception>

class Author {
private:
    std::pair<std::string, std::string> whole_name;
public:
    Author() = delete;
    explicit Author(const std::string& name_, const std::string& surname_) :
       whole_name(std::make_pair(name_, surname_)) {}
    
    std::pair<std::string, std::string> get_name() const {
        return whole_name;
    }
    // This function will check if we already have such author in our book collection
    bool is_equal(const Author& author) const;
    friend std::ostream& operator<<(std::ostream& os, const Author& author) {
        auto [name, surname] = author.get_name();
        return os << name << " " << surname << std::endl;
    }
};

struct Book {

    std::string name_of_the_book;
    std::string genre;
    int year_of_issue;
    std::string publisher;
    int num_of_pages;

    Book() = delete;
    explicit Book(const std::string& book_name, const std::string & genre, int year_of_iss, const std::string& publisher_, int num_of_pages_);
    bool is_equal(const Book& book) const { return book.name_of_the_book == this->name_of_the_book; }
    friend std::ostream& operator<<(std::ostream& os, const Book& book) {
        return os << "Name: " << book.name_of_the_book << "\nGenre: " << book.genre << "\nYear of issue: " << book.year_of_issue
            << "\nPublisher: " << book.publisher << "\nNumber of pages: " << book.num_of_pages << std::endl;
    }
};


class BookAlreadyExist : public std::exception{
public:
    virtual const char* what() const throw()
    {
        return "Book is already in the bookshelf!";
    }
};

class NoSuchBook : public std::exception {
public:
    virtual const char* what() const throw()
    {
        return "Book is not found!";
    }
};

class BookCollection {
private:
    std::map<Author, std::vector<Book>> bookshelf;
    void Menu();
    void show_by_author(const Author& author);
    void show_by_genre();
    void show_by_publisher();
    void show_top_three();
public:
    explicit BookCollection() = default;
    void add_a_book(Author & author, Book& book);
    void delete_a_book(const std::string& name);
    void show_report();
};

