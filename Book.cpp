#include "Book.h"

Book::Book(const std::string& book_name, const std::string& genre, int year_of_iss, const std::string& publisher_,
    int num_of_pages_) : name_of_the_book(book_name), genre(genre), year_of_issue(year_of_iss), publisher(publisher_),
    num_of_pages(num_of_pages_) {}

bool Author::is_equal(const Author& author) const {
    // On such circumstances we check whether we have the same author or not
    auto [name_of_first_author, surname_of_first_author] = this->get_name();
    auto [name_of_second_author, surname_of_second_author] = author.get_name();

    if (name_of_first_author == name_of_second_author && surname_of_first_author == surname_of_second_author)
        return true;
    return false;
}

void BookCollection::add_a_book(Author & author, Book & book) {
    auto iter = bookshelf.begin();
    try {
        // Such author is already on the bookshelf
        while (iter != bookshelf.end()) {
            if ((iter->first).is_equal(author))
                break;
        }
        if (iter != bookshelf.end()) {
            // Here we check whether his/her book is up there
            for (const auto& book_to_compare : iter->second) {
                if (book_to_compare.is_equal(book))
                    // If such book is already there than we throw BookAlreadyExist exception
                    throw BookAlreadyExist();

            }
            // If it's not we add it
            (iter->second).push_back(book);
        }
        // Case when such author hasn't been found so we add him/her to our bookshelf
        else {
            bookshelf.insert(std::pair<Author, std::vector<Book>>(author, std::vector<Book>{book}));
        }
    }


    catch (BookAlreadyExist& ex) {
        std::cout << ex.what() << std::endl;
    }

}

void BookCollection::delete_a_book(const std::string& name) {
    
    
}

void BookCollection::Menu() {
    std::cout << "What kind of report do you need:\n"
        << "a - show all books by the same author\n"
        << "b - show all books of a given genre and publisher\n"
        << "c - show the name of the publisher with the maximum quantity of the books"
        << "d - show TOP-3 genres (popularity is determined by the number of books in the genre)"
        << "q - quit\n"
        << std::endl;
}

void BookCollection::show_by_author(const Author & author) {
    for (const auto& [author_to_check, books] : bookshelf) {
        if (author_to_check.is_equal(author)) {
            std::cout << author;
            for (const auto& book : books) {
                std::cout << book;
            }
        }
    }

}

void BookCollection::show_report() {
    Menu();
    switch (char option = getchar(); option) {
    case 'a': break;
    }
}