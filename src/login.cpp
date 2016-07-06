#include "login.h"

Login::Login()
{

}

int Login::run()
{
    char characterInput;
    std::string login = "";
    std::string password = "";
    std::cout << "Login: ";
    std::cin >> login;
    std::cout << "Password: ";
    characterInput = _getch();

    while (characterInput != 13) { // 13 = enter ASCII
        password.push_back(characterInput);
        std::cout << '*';
        characterInput = _getch();
    }
    std::cout << std::endl;
    if (login == m_userLogin && password == m_userPassword) {
        std::cout << "u have logged in as a 'User'\n";
        std::unique_ptr<Logging> log(new Logging());
        log->loggingIntoTextFile("==> user has logged in <== \n");
        return loginCriteria::loggedAsUser;

    } else if (login == m_userLogin && password != m_userPassword) {
        std::cout << "wrong password\n";
        return loginCriteria::wrongUserPass;

    } else if (login == m_adminLogin && password == m_adminPassword) {
        std::cout << "u have logged in as 'root'\n";
        std::unique_ptr<Logging> log(new Logging());
        log->loggingIntoTextFile("==> admin has logged in <== \n");
        return loginCriteria::loggedAsAdmin;

    } else if (login == m_adminLogin && password != m_adminPassword) {
        std::cout << "wrong password\n";
        return loginCriteria::wrongAdminPass;

    } else if (login != m_userLogin || login != m_adminLogin) {
        std::cout << "there's no such a login\n";
        return loginCriteria::wrongLogin;

    }
}
