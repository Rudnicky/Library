#include "magazine.h"

Magazine::Magazine()
{

}

Magazine::Magazine(std::string& title, int& isbnNumber, float& price, std::string& publisher)
    : Item(title, isbnNumber, price)
    , m_publisher (publisher)
{

}

void Magazine::show() const
{
    std::cout << "Title: " << m_title << ", Publisher: " << m_publisher
              << "ISBN: " << m_isbnNumber << ", Price = " << m_price << std::endl;
}

Magazine::~Magazine()
{
    std::cout << "==> destructor of class 'Magazine' <== \n";
}

std::ostream& operator<<(std::ostream& output, const Magazine& magazine)
{
    output << magazine.m_title << " " << magazine.m_publisher
           << " " << magazine.m_isbnNumber << " " <<  magazine.m_price << '\n';

    return output;
}
