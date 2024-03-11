#include "WhateverItTakes"
#include "CurrentUser.h"

namespace model {
    CurrentUser::CurrentUser(const std::vector<std::string>& s) {
        if (s.size() >= 4) {
            this->user_id_ = std::stoi(s[0]);
            this->username = s[1];
            this->email = s[2];
            this->is_admin = (s[3] == "true");
        }
        else {
        }
    }

    CurrentUser::~CurrentUser() = default;

    bool CurrentUser::get_user_information() {
        return true; 
    }

    bool CurrentUser::delete_user([[maybe_unused]] const std::string& email) {
        return true; 
    }
}
