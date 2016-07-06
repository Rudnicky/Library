#ifndef BOOK_H
#define BOOK_H
#include "item.h"
#include "logging.h"

class Book : public Item
{
private:
    std::string m_author;
public:
    Book(std::string& title, int& isbnNumber, float& price, std::string& author);
    virtual void show() const override;
    virtual float getPrice() const override {return m_price;}
    ~Book();

    friend std::ostream& operator<<(std::ostream& output, const Book& book);
    friend std::istream& operator>>(std::istream& output, Book& book)
    {
        output >> book.m_title >> book.m_isbnNumber
               >> book.m_price >> book.m_author;
        return output;
    }

    bool operator < (const Book& object) const
    {
        return (m_price < object.m_price);
    }
};

#endif // BOOK_H
