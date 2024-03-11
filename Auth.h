#ifndef AUTHHANDLER_H
#define AUTHHANDLER_H

#include <string>

namespace auth {
    class AuthHandler {
    public:
        AuthHandler();
        ~AuthHandler();
        static std::string hash_password(const std::string& password);
        static bool register_user(const std::string& username,const std::string& email, const std::string& password);
        static bool authenticate_user(const std::string& email, const std::string& password);
        static bool update_password(const std::string& username,const std::string& user_id, const std::string& new_password);
        static bool user_matches_id(const std::string& username, const std::string& user_id);
    };
}

#endif 
