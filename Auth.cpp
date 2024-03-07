#include "Auth.h"
#include "Database.h"
#include <iostream>
#include <string>
#include <functional>
#include <sstream>

namespace Auth {
    UserManager::UserManager() {}

    UserManager::~UserManager() {}

    std::string UserManager::hashPassword(const std::string& password) {
        std::hash<std::string> hasher;
        size_t hashed = hasher(password);

        std::stringstream ss;
        ss << std::hex << hashed;
        return ss.str();
    }

    bool UserManager::registerUser(const std::string& username, const std::string& password) {
        std::string hashedPassword = hashPassword(password);
        MYSQL::Database* db = MYSQL::Database::getInstance("creds.txt");

        if (db) {
            // Execute INSERT query to store username and hashed password
            Query::QueryExecutor* queryExecutor = db->getQueryExecutor();
            std::string query = "INSERT INTO users (username, password) VALUES ('" + username + "', '" + hashedPassword + "')";
            bool success = queryExecutor->executeUpdate(query);
            return success;
        }
        else {
            std::cerr << "Failed to get database instance." << std::endl;
            return false;
        }
    }

    bool UserManager::authenticateUser(const std::string& username, const std::string& password) {
        std::string hashedPassword = hashPassword(password);
        MYSQL::Database* db = MYSQL::Database::getInstance("creds.txt");

        if (db) {
            Query::QueryExecutor* queryExecutor = db->getQueryExecutor();
            std::string query = "SELECT * FROM users WHERE username = '" + username + "' AND password = '" + hashedPassword + "'";
            queryExecutor->executeQueryAndPrint(query); // Execute query and print results
            return true; // Modify return value accordingly based on authentication logic
        }
        else {
            std::cerr << "Failed to get database instance." << std::endl;
            return false;
        }
    }
}
