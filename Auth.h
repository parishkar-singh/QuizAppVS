#ifndef AUTHHANDLER_H
#define AUTHHANDLER_H

#include <string>

namespace Auth {
    class AuthHandler {
    public:
        AuthHandler();
        ~AuthHandler();
        static std::string hashPassword(const std::string& password);
        static bool registerUser(const std::string& username,const std::string& email, const std::string& password);
        static bool authenticateUser(const std::string& email, const std::string& password);
        static bool updatePassword(const std::string& username,const std::string& userId, const std::string& newPassword);
        bool userMatchesId(const std::string& username, const std::string& userId);
    };
}

#endif 
