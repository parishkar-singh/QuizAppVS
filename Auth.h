#ifndef USER_MANAGER_H
#define USER_MANAGER_H

#include <string>

namespace Auth {
    class AuthHandler {
    public:
        AuthHandler();
        ~AuthHandler();

        static std::string hashPassword(const std::string& password);
        static bool registerUser(const std::string& username, const std::string& password);
        static bool authenticateUser(const std::string& username, const std::string& password);
    };
}

#endif // USER_MANAGER_H
