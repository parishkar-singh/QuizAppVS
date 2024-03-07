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
    void ensureDatabase() {

        if (!queryExecutor->tableExists("Users")) {
            std::string createUserTableQuery = "CREATE TABLE Users ("
                "userId INT AUTO_INCREMENT PRIMARY KEY, "
                "username VARCHAR(50) NOT NULL UNIQUE, "
                "password VARCHAR(50) NOT NULL, "
                "isAdmin BOOLEAN NOT NULL DEFAULT 0)";
            queryExecutor->executeUpdate(createUserTableQuery);
        }

        // Check if the Geography table exists
        if (!queryExecutor->tableExists("Geography")) {
            std::string createGeographyTableQuery = "CREATE TABLE Geography ("
                "questionId INT AUTO_INCREMENT PRIMARY KEY, "
                "questionText TEXT NOT NULL, "
                "optionA VARCHAR(255) NOT NULL, "
                "optionB VARCHAR(255) NOT NULL, "
                "optionC VARCHAR(255) NOT NULL, "
                "optionD VARCHAR(255) NOT NULL, "
                "correctOption CHAR(1) NOT NULL)";
            queryExecutor->executeUpdate(createGeographyTableQuery);
        }

        // Check if the ComputerScience table exists
        if (!queryExecutor->tableExists("ComputerScience")) {
            std::string createComputerScienceTableQuery = "CREATE TABLE ComputerScience ("
                "questionId INT AUTO_INCREMENT PRIMARY KEY, "
                "questionText TEXT NOT NULL, "
                "optionA VARCHAR(255) NOT NULL, "
                "optionB VARCHAR(255) NOT NULL, "
                "optionC VARCHAR(255) NOT NULL, "
                "optionD VARCHAR(255) NOT NULL, "
                "correctOption CHAR(1) NOT NULL)";
            queryExecutor->executeUpdate(createComputerScienceTableQuery);
        }

        // Check if the History table exists
        if (!queryExecutor->tableExists("History")) {
            std::string createHistoryTableQuery = "CREATE TABLE History ("
                "questionId INT AUTO_INCREMENT PRIMARY KEY, "
                "questionText TEXT NOT NULL, "
                "optionA VARCHAR(255) NOT NULL, "
                "optionB VARCHAR(255) NOT NULL, "
                "optionC VARCHAR(255) NOT NULL, "
                "optionD VARCHAR(255) NOT NULL, "
                "correctOption CHAR(1) NOT NULL)";
            queryExecutor->executeUpdate(createHistoryTableQuery);
        }

        // Check if the QuestionsSet table exists
        if (!queryExecutor->tableExists("QuestionsSet")) {
            std::string createQuestionsSetTableQuery = "CREATE TABLE QuestionsSet ("
                "setId INT AUTO_INCREMENT PRIMARY KEY, "
                "setName VARCHAR(50) NOT NULL, "
                "category ENUM('Geography', 'ComputerScience', 'History') NOT NULL)";
            queryExecutor->executeUpdate(createQuestionsSetTableQuery);
        }

        // Check if the Result table exists
        if (!queryExecutor->tableExists("Result")) {
            std::string createResultTableQuery = "CREATE TABLE Result ("
                "resultId INT AUTO_INCREMENT PRIMARY KEY, "
                "userId INT NOT NULL, "
                "setId INT NOT NULL, "
                "score INT NOT NULL, "
                "FOREIGN KEY (userId) REFERENCES Users(userId), "
                "FOREIGN KEY (setId) REFERENCES QuestionsSet(setId))";
            queryExecutor->executeUpdate(createResultTableQuery);
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

    bool bootstrap() {
        console::art::intro();
        Loader::startProgressBar();
        std::cout << " Lets go";
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
        return true;
    }

}
