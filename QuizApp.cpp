#include <iostream>
#include "database.h"


int main() {

    MYSQL::Database db(".env");

    if (db.connect()) {
        std::cout << "Connected to the database." << std::endl;
        Query::QueryExecutor* queryExecutor = db.getQueryExecutor();
        db.disconnect();
    }
    else {
        std::cerr << "Failed to connect to the database." << std::endl;
    }

    return 0;
}
