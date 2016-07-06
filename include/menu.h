#ifndef MENU_H
#define MENU_H
#include "item.h"
#include "book.h"
#include "magazine.h"
#include "store.h"
#include "login.h"

class Menu
{
private:
    enum firstScreen { loginIntoSystem = 1, exitProgram };
    enum userInterface { showContainersContent = 1,
                         buyItemfromContainer,
                         sortContainerContent,
                         basket,
                         logoutToMain};

    enum adminInterface  { addItemToContainer = 1,
                           showContainerContent,
                           removeItemFromContainer,
                           showLogFile,
                           clearLogFile,
                           logout };
public:
    Menu();
    void start();
};

#endif // MENU_H
