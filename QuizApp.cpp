#include "Database.h"
#include <iostream>

int main() {
    // Create an instance of the Database class
    MYSQL::Database* db = MYSQL::Database::getInstance(".env");

    

    return 0;
}
