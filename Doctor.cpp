#include "WhateverItTakes"

namespace Validator {
    void validateSchemaAndTables() {
        if (!EXEC::queryExecutor->schemaExists("test")) {
            Fixer::fixSchema();
        }

        validateUserTable();
        validateGeographyTable();
        validateComputerScienceTable();
        validateHistoryTable();
        validateQuestionsSetTable();
        validateResultTable();
    }

    void validateUserTable() {
        if (!EXEC::queryExecutor->tableExists("Users")) {
            Fixer::fixUserTable();
        }
    }

    void validateGeographyTable() {
        if (!EXEC::queryExecutor->tableExists("Geography")) {
            Fixer::fixGeographyTable();
        }
    }

    void validateComputerScienceTable() {
        if (!EXEC::queryExecutor->tableExists("ComputerScience")) {
            Fixer::fixComputerScienceTable();
        }
    }

    void validateHistoryTable() {
        if (!EXEC::queryExecutor->tableExists("History")) {
            Fixer::fixHistoryTable();
        }
    }

    void validateQuestionsSetTable() {
        if (!EXEC::queryExecutor->tableExists("QuestionsSet")) {
            Fixer::fixQuestionsSetTable();
        }
    }

    void validateResultTable() {
        if (!EXEC::queryExecutor->tableExists("Result")) {
            Fixer::fixResultTable();
        }
    }
}

namespace Fixer {
    void fixSchema() {
        EXEC::queryExecutor->executeUpdate("CREATE SCHEMA test");
    }

    void fixUserTable() {
        std::string createUserTableQuery = "CREATE TABLE Users ("
            "userId INT AUTO_INCREMENT PRIMARY KEY, "
            "username VARCHAR(50) NOT NULL UNIQUE, "
            "email VARCHAR(100) NOT NULL UNIQUE, "
            "password VARCHAR(50) NOT NULL, "
            "isAdmin BOOLEAN NOT NULL DEFAULT 0)";
        EXEC::queryExecutor->executeUpdate(createUserTableQuery);
    }

    void fixGeographyTable() {
        std::string createGeographyTableQuery = "CREATE TABLE Geography ("
            "questionId INT AUTO_INCREMENT PRIMARY KEY, "
            "questionText TEXT NOT NULL, "
            "optionA VARCHAR(255) NOT NULL, "
            "optionB VARCHAR(255) NOT NULL, "
            "optionC VARCHAR(255) NOT NULL, "
            "optionD VARCHAR(255) NOT NULL, "
            "correctOption CHAR(1) NOT NULL)";
        EXEC::queryExecutor->executeUpdate(createGeographyTableQuery);
    }

    void fixComputerScienceTable() {
        std::string createComputerScienceTableQuery = "CREATE TABLE ComputerScience ("
            "questionId INT AUTO_INCREMENT PRIMARY KEY, "
            "questionText TEXT NOT NULL, "
            "optionA VARCHAR(255) NOT NULL, "
            "optionB VARCHAR(255) NOT NULL, "
            "optionC VARCHAR(255) NOT NULL, "
            "optionD VARCHAR(255) NOT NULL, "
            "correctOption CHAR(1) NOT NULL)";
        EXEC::queryExecutor->executeUpdate(createComputerScienceTableQuery);
    }

    void fixHistoryTable() {
        std::string createHistoryTableQuery = "CREATE TABLE History ("
            "questionId INT AUTO_INCREMENT PRIMARY KEY, "
            "questionText TEXT NOT NULL, "
            "optionA VARCHAR(255) NOT NULL, "
            "optionB VARCHAR(255) NOT NULL, "
            "optionC VARCHAR(255) NOT NULL, "
            "optionD VARCHAR(255) NOT NULL, "
            "correctOption CHAR(1) NOT NULL)";
        EXEC::queryExecutor->executeUpdate(createHistoryTableQuery);
    }

    void fixQuestionsSetTable() {
        std::string createQuestionsSetTableQuery = "CREATE TABLE QuestionsSet ("
            "setId INT AUTO_INCREMENT PRIMARY KEY, "
            "setName VARCHAR(50) NOT NULL, "
            "category ENUM('Geography', 'ComputerScience', 'History') NOT NULL, "
            "adminId INT NOT NULL, "
            "FOREIGN KEY (adminId) REFERENCES Users(userId))";
        EXEC::queryExecutor->executeUpdate(createQuestionsSetTableQuery);
    }

    void fixResultTable() {
        std::string createResultTableQuery = "CREATE TABLE Result ("
            "resultId INT AUTO_INCREMENT PRIMARY KEY, "
            "userId INT NOT NULL, "
            "setId INT NOT NULL, "
            "score INT NOT NULL, "
            "FOREIGN KEY (userId) REFERENCES Users(userId), "
            "FOREIGN KEY (setId) REFERENCES QuestionsSet(setId))";
        EXEC::queryExecutor->executeUpdate(createResultTableQuery);
    }
}
