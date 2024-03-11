#include "WhateverItTakes"

Repair::Repair(query::QueryExecutor* executor) : query_executor(executor) {}

void Repair::fixSchema() {
    query_executor->executeUpdate("CREATE SCHEMA test");
}

void Repair::fixUserTable() {
    const std::string createUserTableQuery = "CREATE TABLE Users ("
        "user_id INT AUTO_INCREMENT PRIMARY KEY, "
        "username VARCHAR(50) NOT NULL UNIQUE, "
        "email VARCHAR(100) NOT NULL UNIQUE, "
        "password VARCHAR(50) NOT NULL, "
        "is_admin BOOLEAN NOT NULL DEFAULT 0)";
    query_executor->executeUpdate(createUserTableQuery);
}

void Repair::fixGeographyTable() {
    const std::string createGeographyTableQuery = "CREATE TABLE Geography ("
        "question_id INT AUTO_INCREMENT PRIMARY KEY, "
        "question_text TEXT NOT NULL, "
        "option_a VARCHAR(255) NOT NULL, "
        "option_b VARCHAR(255) NOT NULL, "
        "option_c VARCHAR(255) NOT NULL, "
        "option_d VARCHAR(255) NOT NULL, "
        "correct_option CHAR(1) NOT NULL)";
    query_executor->executeUpdate(createGeographyTableQuery);
}

void Repair::fixComputerScienceTable() {
    const std::string createComputerScienceTableQuery = "CREATE TABLE ComputerScience ("
        "question_id INT AUTO_INCREMENT PRIMARY KEY, "
        "question_text TEXT NOT NULL, "
        "option_a VARCHAR(255) NOT NULL, "
        "option_b VARCHAR(255) NOT NULL, "
        "option_c VARCHAR(255) NOT NULL, "
        "option_d VARCHAR(255) NOT NULL, "
        "correct_option CHAR(1) NOT NULL)";
    query_executor->executeUpdate(createComputerScienceTableQuery);
}

void Repair::fixHistoryTable() {
    const std::string createHistoryTableQuery = "CREATE TABLE History ("
        "question_id INT AUTO_INCREMENT PRIMARY KEY, "
        "question_text TEXT NOT NULL, "
        "option_a VARCHAR(255) NOT NULL, "
        "option_b VARCHAR(255) NOT NULL, "
        "option_c VARCHAR(255) NOT NULL, "
        "option_d VARCHAR(255) NOT NULL, "
        "correct_option CHAR(1) NOT NULL)";
    query_executor->executeUpdate(createHistoryTableQuery);
}

void Repair::fixQuestionsSetTable() {
    const std::string createQuestionsSetTableQuery = "CREATE TABLE QuestionsSet ("
        "set_id INT AUTO_INCREMENT PRIMARY KEY, "
        "set_name VARCHAR(50) NOT NULL, "
        "category ENUM('Geography', 'ComputerScience', 'History') NOT NULL, "
        "admin_id INT NOT NULL, "
        "FOREIGN KEY (admin_id) REFERENCES Users(user_id))";
    query_executor->executeUpdate(createQuestionsSetTableQuery);
}

void Repair::fixResultTable() {
    const std::string createResultTableQuery = "CREATE TABLE Result ("
        "result_id INT AUTO_INCREMENT PRIMARY KEY, "
        "user_id INT NOT NULL, "
        "set_id INT NOT NULL, "
        "score INT NOT NULL, "
        "FOREIGN KEY (user_id) REFERENCES Users(user_id), "
        "FOREIGN KEY (set_id) REFERENCES QuestionsSet(set_id))";
    query_executor->executeUpdate(createResultTableQuery);
}
