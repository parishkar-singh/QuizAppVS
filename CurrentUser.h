#pragma once
#ifndef CURRENTUSER_H
#define CURRENTUSER_H

#include <string>
#include <vector>

namespace Model {
    class CurrentUser {
    private:
        int userId;
        std::string email;
        std::string username;
        bool isAdmin;

    public:
        CurrentUser(const std::vector<std::string>& s);
        ~CurrentUser();

        int getUserId() const { return userId; }
        const std::string& getEmail() const { return email; }
        const std::string& getUsername() const { return username; }
        bool isAdminUser() const { return isAdmin; }

        bool getUserInformation();
        bool deleteUser(const std::string& email);
    };
}

#endif
