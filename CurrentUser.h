#pragma once
#ifndef CURRENTUSER_H
#define CURRENTUSER_H

#include <string>
#include <vector>

namespace model {
    class CurrentUser {
    private:
        int user_id;
        std::string email;
        std::string username;
        bool is_admin;

    public:
        CurrentUser(const std::vector<std::string>& s);
        ~CurrentUser();

        [[nodiscard]] int get_user_id() const { return user_id; }
        [[nodiscard]] const std::string& get_email() const { return email; }
        [[nodiscard]] const std::string& get_username() const { return username; }
        [[nodiscard]] bool is_admin_user() const { return is_admin; }

        static bool get_user_information();
        static bool delete_user(const std::string& email);
    };
}

#endif
