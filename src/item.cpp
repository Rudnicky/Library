#include "item.h"

Item::Item()
{

}

Item::Item(std::string& title, int& isbnNumber, float& price)
    : m_title (title)
    , m_isbnNumber (isbnNumber)
    , m_price (price)
{
    std::cout << "==> constructor of class 'Item' <== \n";
}

Item::~Item()
{
    std::cout << "==> destructor of class 'Item' <== \n";
}

std::istream& operator>>(std::istream& output, Item& item)
{
    output >> item.m_title >> item.m_isbnNumber >> item.m_price;
    return output;
}

std::ostream& operator<<(std::ostream& output, const Item& item)
{
    output << item.m_title << " " <<  item.m_isbnNumber
           << " " << item.m_price << "\n";

    return output;
}
