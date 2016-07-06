#ifndef SORTITEMS_H
#define SORTITEMS_H
#include <string>
#include <iostream>

class SortItems
{
private:
    std::string m_title;
    std::string m_name;
    int m_isbn, m_id;
    float m_price;
public:
    SortItems();
    SortItems(int& id, std::string &title, std::string &name, int &isbn, float &price);

    friend std::ostream& operator<<(std::ostream& output, const SortItems& object)
    {
        output << "ID: " << object.m_id << ", Title: " << object.m_title << ", Author: " << object.m_name
               << ", ISBN: " << object.m_isbn << ", PRICE: " << object.m_price << "\n";
        return output;
    }

    float price() const;
    void setPrice(float price);
    std::string title() const;
    void setTitle(const std::string &title);
    int id() const;
    void setId(int id);
};

#endif // SORTITEMS_H
