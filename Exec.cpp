// EXEC.cpp

#include "EXEC.h"

namespace EXEC {

    Query::QueryExecutor* queryExecutor = nullptr;

    void initialize() {
        MYSQL::Database* dbInstance = MYSQL::Database::getInstance(".env");
        if (dbInstance) {
            queryExecutor = dbInstance->getQueryExecutor();
        }
        else {
            std::cerr << "Failed to initialize database instance." << std::endl;
        }
    }

    Query::QueryExecutor* getQueryExecutor() {
        return queryExecutor;
    }
}
