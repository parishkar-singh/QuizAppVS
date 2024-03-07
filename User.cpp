#include "WhateverItTakes"
namespace Model {
	User::User() {};
	User::~User() {};

    /*std::vector<std::string> getUser() {
        std::vector<std::string> users;

        try {
            sql::Statement* stmt = EXEC::queryExecutor->getConnection()->createStatement();
            sql::ResultSet* res = stmt->executeQuery("SELECT * FROM users");

            while (res->next()) {
                std::string username = res->getString("username");
                users.push_back(username);
            }

            delete res;
            delete stmt;
        }
        catch (sql::SQLException& e) {
            std::cerr << "SQL Exception: " << e.what() << std::endl;
        }

        return users;*/
    

}
//EXEC::queryExecutor->executeUpdate("INSERT INTO users (username, password) VALUES ('john_doe', 'password123');");
//EXEC::queryExecutor->executeQueryAndPrint("SELECT * from users");
