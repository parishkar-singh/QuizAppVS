#include "EXEC.h"
#include "Auth.h" 
#include "Console.h"

namespace EXEC {
    Query::QueryExecutor* queryExecutor = nullptr;

    void initialize() {
        MYSQL::Database* dbInstance = MYSQL::Database::getInstance(".env");
        if (dbInstance) {
            queryExecutor = dbInstance->getQueryExecutor();

        }
               
    }

    Query::QueryExecutor* getQueryExecutor() {
        return queryExecutor;
    }
}
