#include "WhateverItTakes"
#include "CurrentUser.h"

namespace Model {
    CurrentUser::CurrentUser(const std::vector<std::string>& s) {
        if (s.size() >= 4) {
            this->userId = std::stoi(s[0]);
            this->username = s[1];
            this->email = s[2];
            this->isAdmin = (s[3] == "true");
        }
        else {
        }
    }

    CurrentUser::~CurrentUser() {
    }

    bool CurrentUser::getUserInformation() {
        return true; 
    }

    bool CurrentUser::deleteUser(const std::string& email) {
        return true; 
    }
}
