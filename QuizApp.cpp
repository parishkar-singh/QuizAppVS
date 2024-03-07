#include "Auth.h"
#include "Database.h"
#include <iostream>
#include <cppconn/exception.h>

int main() {

    MYSQL::Database* db = MYSQL::Database::getInstance(".env");
    if (!db || !db->connect()) {
        std::cerr << "Failed to connect to the database." << std::endl;
        return 1; 
    }
    std::cout << "Connected to the database." << std::endl;

 
    db->disconnect();

    return 0;
}
