#include "WhateverItTakes"

namespace EXEC {
    Query::QueryExecutor* queryExecutor = nullptr;
    void Initialize() {
        MYSQL::Database* dbInstance = MYSQL::Database::getInstance(".env");

        if (dbInstance) {
            queryExecutor = dbInstance->getQueryExecutor();

        }      
    }
    void Authenticate() {
        console::selector::ConsoleSelector selector;
        std::vector<std::string> options = {
            "Register user",
            "Login"
        };
        int choice = selector.selectOption("How would you like to start? ", options);
        system("cls");
        std::cout << "You chose: " << options[choice] << std::endl;
    }

    Query::QueryExecutor* getQueryExecutor() {
        return queryExecutor;
    }
}
