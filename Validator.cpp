#include "WhateverItTakes"

using namespace vldr;

bool Validator::validate_email(const std::string& email) {
    const std::regex email_regex(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
    return std::regex_match(email, email_regex);
}

bool Validator::validate_password(const std::string& password) {
    return password.length() >= 8;
}

bool Validator::table_exists(const std::string& table_name) const {
    bool exists = false;
    try {
        sql::Statement* stmt = connection->createStatement();
        const std::string query = "SELECT COUNT(*) FROM information_schema.tables WHERE table_schema = DATABASE() AND table_name = '" + table_name + "'";
        sql::ResultSet* res = stmt->executeQuery(query);
        if (res->next()) {
            const int count = res->getInt(1);
            exists = (count > 0);
        }
        delete res;
        delete stmt;
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Exception: " << e.what() << '\n';
    }
    return exists;
}

bool Validator::schema_exists(const std::string& schema_name) const {
    bool exists = false;
    try {
        sql::Statement* stmt = connection->createStatement();
        const std::string query = "SELECT COUNT(*) FROM information_schema.schemata WHERE schema_name = '" + schema_name + "'";
        sql::ResultSet* res = stmt->executeQuery(query);
        if (res->next()) {
            const int count = res->getInt(1);
            exists = (count > 0);
        }
        delete res;
        delete stmt;
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Exception: " << e.what() << '\n';
    }
    return exists;
}
