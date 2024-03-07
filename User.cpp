#include "WhateverItTakes"
namespace UsersNamespace {
    class User {
    private:
        int userId;
        std::string username;
        std::string password;
        bool isAdmin;

    public:
        int getUserId() const { return userId; }
        void setUserId(int id) { userId = id; }

        std::string getUsername() const { return username; }
        void setUsername(const std::string& name) { username = name; }

        std::string getPassword() const { return password; }
        void setPassword(const std::string& pass) { password = pass; }

        bool getIsAdmin() const { return isAdmin; }
        void setIsAdmin(bool admin) { isAdmin = admin; }
    };
}