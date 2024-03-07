#pragma once
#ifndef USER_H
#define USER_H

#include <string>

namespace Model {
    class User {
    private:
        int userId;
        std::string username;
        std::string password;
        bool isAdmin;

    public:
        User();
        ~User();
        //std::vector<std::string> getUser() ;
        //std::vector<std::string> getAllUser() ;
    };
}

#endif
