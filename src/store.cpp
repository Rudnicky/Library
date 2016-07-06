#include "store.h"

Store::Store()
{
    std::unique_ptr<Logging> log(new Logging());
    log->loggingIntoTextFile("==> constructor of class 'Store' <== \n");
}

void Store::addItemToContainer()
{
    int whichItem = 0;
    std::cout << "Which item would u like to add? Book - 1 | Magazine - 2 ?";
    std::cin >> whichItem;

    std::string title = "", author = "", publisher = "";
    int isbnNumber = 0;
    float price = 0.0;

    if (whichItem == selectedItem::book) {

        std::cout << "Title: ";
        std::cin >> title;
        std::cout << "Author: ";
        std::cin >> author;
        std::cout << "ISBN: ";
        std::cin >> isbnNumber;
        std::cout << "Price: ";
        std::cin >> price;

        std::shared_ptr<Item> book(new Book(title, isbnNumber, price, author));
        m_items.push_back(book);

    } else if (whichItem == selectedItem::magazine) {

        std::cout << "Title: ";
        std::cin >> title;
        std::cout << "Publisher: ";
        std::cin >> publisher;
        std::cout << "ISBN: ";
        std::cin >> isbnNumber;
        std::cout << "Price: ";
        std::cin >> price;

        std::shared_ptr<Item> magazine(new Magazine(title, isbnNumber, price, publisher));
        m_items.push_back(magazine);
    }

    std::fstream file;
    file.open("items.txt", std::ios::in | std::ios::app);
    if (file.good() == true) {
        for (unsigned int i=0; i < m_items.size(); i++) {
            std::shared_ptr<Book> book = std::dynamic_pointer_cast<Book> (m_items[i]);
            std::shared_ptr<Magazine> magazine = std::dynamic_pointer_cast<Magazine> (m_items[i]);

            if (book != 0) {
                file << *book;
            } else if (magazine != 0) {
                file << *magazine;
            } else {
                file << *m_items[i] << std::endl;
            }
        }
        file.close();
    } else {
        std::cout << "Could not open a file!\n";
        std::unique_ptr<Logging> log(new Logging());
        log->loggingIntoTextFile("==> failed to open txt file in store.cpp\n"
                                 " -> line 75 addItemToContainer() foo <== \n");
    }
}

void Store::showContainerContent()
{
    m_objects.clear();
    readparsefromFile();
    showSortItemsContainer();
}

void Store::removeItemfromContainer()
{
    int whichItem = 0;
    std::cout << "which item would u like to remove? ";
    std::cin >> whichItem;
    m_items.erase(m_items.begin() + whichItem - 1);
}

void Store::sortContainerContent()
{
    m_objects.clear();
    readparsefromFile();
    std::sort(m_objects.begin(), m_objects.end());
    showSortItemsContainer();
}

void Store::readparsefromFile()
{
    std::string title, name, line, isbn, price;

    int isbn_tmp = 0;
    int idCounter = 0;
    float price_tmp = 0;

    std::fstream file;
    file.open("items.txt", std::ios::in);
    if (file.good() == true) {
        while (std::getline(file, line)) {
            idCounter++;
            std::stringstream iss(line);
            std::getline(iss, title, ' ');
            std::getline(iss, name, ' ');
            std::getline(iss, isbn, ' ');
            std::getline(iss, price, ' ');
            std::istringstream issToInt(isbn);
            issToInt >> isbn_tmp;
            std::istringstream issToFloat(price);
            issToFloat >> price_tmp;
            std::shared_ptr<SortItems> object(new SortItems(idCounter, title, name, isbn_tmp, price_tmp));
            m_objects.push_back(object);
        }
        file.close();
    } else {
        std::cout << "Could not open a file!\n";
        std::unique_ptr<Logging> log(new Logging());
        log->loggingIntoTextFile("==> failed to open txt file in store.cpp\n"
                                 " -> line 114 readparsefromFile() foo <== \n");
    }
}

void Store::showSortItemsContainer() const
{
    for (auto element : m_objects)
        std::cout << *element;
}

void Store::buyItemfromContainer()
{
    readparsefromFile();
    int whichNumber = 0;
    std::cout << "Which item would u like to buy? (ID)\n";
    std::cin >> whichNumber;

    auto it = std::find_if(m_objects.begin(), m_objects.end(), [&whichNumber](const std::shared_ptr<SortItems> obj)
        { return obj->id() == whichNumber; });
    if (it != m_objects.end()) {

        auto index = std::distance(m_objects.begin(), it);
        std::cout << *m_objects.at(index) << "\n";
        m_basket.push_back(m_objects.at(index));
        m_objects.erase(it);
    }
}

void Store::clientBasket()
{
    int whichNumber = 0;
    do {
        std::cout << "\n\t--------------------";
        std::cout << "\n\t1 ----- check ------";
        std::cout << "\n\t2 ----- remove -----";
        std::cout << "\n\t3 ----- back -------";
        std::cout << "\n\t--------------------\n\n";
        std::cin >> whichNumber;
        switch(whichNumber)
        {
        case basketOptions::check:
            showBasketContent();
            break;
        case basketOptions::remove:
            removeItemFromBasket();
            break;
        case basketOptions::back:
            break;
        default:
            break;
        }
    } while (whichNumber != basketOptions::back);
}

void Store::showBasketContent() const
{
    if (m_basket.empty()) {
        std::cout << "There's no item in Your basket yet!\n";
    } else {
        for (auto element : m_basket)
            std::cout << *element;
    }
}

void Store::removeItemFromBasket()
{
    int whichNumber = 0;
    std::cout << "Which item would u like to buy? (ID)\n";
    std::cin >> whichNumber;

    auto it = std::find_if(m_basket.begin(), m_basket.end(), [&whichNumber](const std::shared_ptr<SortItems> obj)
        { return obj->id() == whichNumber; });
    if (it != m_basket.end()) {
        m_basket.erase(it);
    }
}

Store::~Store()
{
    std::unique_ptr<Logging> log(new Logging());
    log->loggingIntoTextFile("==> destructor of class 'Store' <== \n");
}
