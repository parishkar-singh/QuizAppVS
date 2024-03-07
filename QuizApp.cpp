#include "Auth.h"
#include "Database.h"
#include <iostream>
#include <cppconn/exception.h>

int main() {
    // Initialize the database connection
    MYSQL::Database* db = MYSQL::Database::getInstance(".env");
    if (!db || !db->connect()) {
        std::cerr << "Failed to connect to the database." << std::endl;
        return 1; // Exit with error code
    }
    std::cout << "Connected to the database." << std::endl;

    // Register a user
    std::string username = "user123";
    std::string password = "password123";

    if (Auth::UserManager::registerUser(username, password)) {
        std::cout << "User registered successfully." << std::endl;
    }
    else {
        std::cerr << "Failed to register user." << std::endl;
        return 1; // Exit with error code
    }

    // Authenticate the user
    std::string loginUsername = "user123";
    std::string loginPassword = "password123";

    if (Auth::UserManager::authenticateUser(loginUsername, loginPassword)) {
        std::cout << "User authenticated successfully." << std::endl;

        // Execute a query using the QueryExecutor
        Query::QueryExecutor* queryExecutor = db->getQueryExecutor();
        if (queryExecutor) {
            std::string query = "SELECT * FROM users;";
            queryExecutor->executeQueryAndPrint(query); 
        }
        else {
            std::cerr << "Failed to get query executor." << std::endl;
            return 1; // Exit with error code
        }
    }
    else {
        std::cerr << "Authentication failed." << std::endl;
        return 1; // Exit with error code
    }

    // Disconnect from the database
    db->disconnect();

    return 0;
}
