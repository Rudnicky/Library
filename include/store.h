#ifndef STORE_H
#define STORE_H
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "item.h"
#include "book.h"
#include "magazine.h"
#include "sortitems.h"

class Store
{
private:
    std::vector<std::shared_ptr<Item>> m_items;
    std::vector<std::shared_ptr<SortItems>> m_objects;
    std::vector<std::shared_ptr<SortItems>> m_basket;
    enum basketOptions { check = 1, remove, back };
    enum selectedItem { book = 1, magazine };
public:
    Store();
    void addItemToContainer();
    void showContainerContent();
    void showSortItemsContainer() const;
    void removeItemfromContainer();
    void sortContainerContent();
    void readparsefromFile();
    void buyItemfromContainer();
    void clientBasket();
    void showBasketContent() const;
    void removeItemFromBasket();
    ~Store();
};

#endif // STORE_H
