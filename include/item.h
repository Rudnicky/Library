#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <iostream>
#include <memory>

class Item
{
protected:
    std::string m_title;
    int m_isbnNumber;
    float m_price;
public:
    Item();
    Item(std::string& title, int& isbnNumber, float& price);
    virtual void show() const = 0;
    virtual float getPrice() const = 0;
    virtual ~Item();

    friend std::ostream& operator<<(std::ostream& output, const Item& item);
    friend std::istream& operator>>(std::istream& output, Item& item);

};

#endif // ITEM_H
