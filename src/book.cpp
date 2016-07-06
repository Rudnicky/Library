#include "book.h"

Book::Book(std::string& title, int& isbnNumber, float& price, std::string& author)
    : Item (title, isbnNumber, price)
    , m_author (author)
{
    std::unique_ptr<Logging> log(new Logging());
    log->loggingIntoTextFile("==> constructor of class 'Book' <== \n");
}

void Book::show() const
{
    std::cout << "Title: " << m_title << ", Author: " << m_author
              << "ISBN: " << m_isbnNumber << ", Price = " << m_price << std::endl;
}

Book::~Book()
{
    std::unique_ptr<Logging> log(new Logging());
    log->loggingIntoTextFile("==> destructor of class 'Book' <== \n");
}

std::ostream& operator<<(std::ostream& output, const Book& book)
{
    output << book.m_title << " " << book.m_author
           << " " << book.m_isbnNumber << " " << book.m_price << "\n";

    return output;
}

//std::istream& operator>>(std::istream& output, const Book& book)
//{
//    output >> book.m_title >> " " >> book.m_author >> " "
//           >> book.m_isbnNumber >> " " >> book.m_price;
//    return output;
//}
