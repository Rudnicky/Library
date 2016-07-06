#ifndef LOGIN_H
#define LOGIN_H
#include <string>
#include <conio.h>
#include <memory>
#include "logging.h"

class Login
{
private:
    const std::string m_userLogin = "user";
    const std::string m_userPassword = "user";
    const std::string m_adminLogin = "admin";
    const std::string m_adminPassword = "admin";

public:
    Login();
    int run();

    enum loginCriteria { loggedAsUser = 1,
                         wrongUserPass,
                         loggedAsAdmin,
                         wrongAdminPass,
                         wrongLogin };
};

#endif // LOGIN_H
