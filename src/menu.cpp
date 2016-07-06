#include "menu.h"

Menu::Menu()
{

}

void Menu::start()
{
    int whichItemfromMenu = 0;
    int loginChoice = 0;
    std::shared_ptr<Store> store(new Store());
    std::shared_ptr<Login> login(new Login());
    std::shared_ptr<Logging> logging(new Logging());

    do
    {
        std::cout << "\n\t--------------------------";
        std::cout << "\n\t1 ------ login -----------";
        std::cout << "\n\t2 ------ exit ------------";
        std::cout << "\n\t--------------------------\n\n";
        while(!(std::cin >> whichItemfromMenu)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Try again ;)\n";
        }
        switch(whichItemfromMenu)
        {
        case firstScreen::loginIntoSystem:
            while ((loginChoice != login->loggedAsAdmin) &&
                   (loginChoice != login->loggedAsUser)) {

                loginChoice = login->run();
            }
            /////////// -- A D M I N -- (rights) ///////////
            if (loginChoice == login->loggedAsAdmin) {
                do
                {
                    std::cout << "\n\t--------------------------------------";
                    std::cout << "\n\t1 ---- add Item to Container ---------";
                    std::cout << "\n\t2 ---- show Containers content -------";
                    std::cout << "\n\t3 ---- remove item from Container ----";
                    std::cout << "\n\t4 ---- show log file -----------------";
                    std::cout << "\n\t5 ---- clear log file ----------------";
                    std::cout << "\n\t6 ---- log out -----------------------";
                    std::cout << "\n\t--------------------------------------\n\n";
                    while(!(std::cin >> whichItemfromMenu)) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Invalid input! Try again ;)\n";
                    }
                    switch(whichItemfromMenu)
                    {
                    case adminInterface::addItemToContainer:
                        store->addItemToContainer();
                        break;
                    case adminInterface::showContainerContent:
                        store->showContainerContent();
                        break;
                    case adminInterface::removeItemFromContainer:
                        store->removeItemfromContainer();
                        break;
                    case adminInterface::showLogFile:
                        logging->openLogFile();
                        break;
                    case adminInterface::clearLogFile:
                        logging->clearLogFile();
                        break;
                    case adminInterface::logout:
                        logging->loggingIntoTextFile("==> admin has logged out <== \n");
                        break;
                    default:
                        break;
                    }
                } while(whichItemfromMenu != adminInterface::logout);

                /////////// -- U S E R -- (rights) ///////////
            } else if (loginChoice == login->loggedAsUser) {
                do
                {
                    std::cout << "\n\t---------------------------";
                    std::cout << "\n\t1 ------ show -------------";
                    std::cout << "\n\t2 ------ buy --------------";
                    std::cout << "\n\t3 ------ sort -------------";
                    std::cout << "\n\t4 ------ basket -----------";
                    std::cout << "\n\t5 ------ log out ----------";
                    std::cout << "\n\t---------------------------\n\n";
                    while(!(std::cin >> whichItemfromMenu)) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Invalid input! Try again ;)\n";
                    }
                    switch(whichItemfromMenu)
                    {
                    case userInterface::showContainersContent:
                        store->showContainerContent();
                        break;
                    case userInterface::buyItemfromContainer:
                        store->buyItemfromContainer();
                        break;
                    case userInterface::sortContainerContent:
                        store->sortContainerContent();
                        break;
                    case userInterface::basket:
                        store->clientBasket();
                        break;
                    case userInterface::logoutToMain:
                        logging->loggingIntoTextFile("==> user has logged out <== \n");
                        break;
                    default:
                        break;
                    }
                } while (whichItemfromMenu != userInterface::logoutToMain);
            }

            loginChoice = 0;

            break;
        case firstScreen::exitProgram:
            break;
        default:
            break;
        }
    } while (whichItemfromMenu != firstScreen::exitProgram);
}
