#ifndef MAGAZINE_H
#define MAGAZINE_H
#include "item.h"

class Magazine : public Item
{
    std::string m_publisher;
public:
    Magazine();
    Magazine(std::string& title, int& isbnNumber, float& price, std::string& publisher);
    virtual void show() const override;
    virtual float getPrice() const override {return m_price;}
    ~Magazine();

    friend std::ostream& operator<<(std::ostream& output, const Magazine& magazine);
    friend std::istream& operator>>(std::istream& output, Magazine& magazine)
    {
        output >> magazine.m_title >> magazine.m_isbnNumber
               >> magazine.m_price >> magazine.m_publisher;
        return output;
    }

    bool operator < (const Magazine& object) const
    {
        return (m_price < object.m_price);
    }
};

#endif // MAGAZINE_H
