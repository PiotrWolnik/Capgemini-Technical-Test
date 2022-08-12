#include "Book.h"


int main()
{
    std::cout << "Hello World!\n";

    Book book{ "Hello", "Criminal", 1954, "Penguin", 344 };
    std::cout << book;

    Author author{ "Peter", "Bateman" };
    std::cout << author;


    return EXIT_SUCCESS;
}
