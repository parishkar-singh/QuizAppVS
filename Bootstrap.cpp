#include "WhateverItTakes"
// I dont know this may be responsible for the flow of execution not yet decided
namespace EXEC {

    Query::QueryExecutor* queryExecutor = nullptr;
    Query::QueryExecutor* getQueryExecutor() {
        return queryExecutor;
    }
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
    void bootstrap() {
        console::art::intro();
        Loader::startProgressBar();
        std::cout << "Press Any Key to Start";
        _getch();
        system("cls");
        Loader::startEatSleepRepeat();
        system("cls");
        Initialize();
        Authenticate();
        console::art::outro();
        std::cout << "Thank you for trying out...";
        _getch();
        system("cls");
        Loader::startEatSleepRepeat();
        system("cls");
    }

    
}
