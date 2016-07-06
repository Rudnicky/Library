#include "sortitems.h"

float SortItems::price() const
{
    return m_price;
}

void SortItems::setPrice(float price)
{
    m_price = price;
}

std::string SortItems::title() const
{
    return m_title;
}

void SortItems::setTitle(const std::string &title)
{
    m_title = title;
}

int SortItems::id() const
{
    return m_id;
}

void SortItems::setId(int id)
{
    m_id = id;
}

SortItems::SortItems()
{

}

SortItems::SortItems(int& id, std::string &title, std::string &name, int &isbn, float &price)
    : m_id (id)
    , m_title (title)
    , m_name (name)
    , m_isbn (isbn)
    , m_price (price)
{

}

bool operator<(const SortItems& firstObject, const SortItems& secondObject)
{
    return secondObject.price() < firstObject.price();
}

