#include "EXEC.h"
#include "Auth.h" 
#include "Console.h"

namespace EXEC {
    Query::QueryExecutor* queryExecutor = nullptr;
    void Initialize() {
        MYSQL::Database* dbInstance = MYSQL::Database::getInstance(".env");

        if (dbInstance) {
            queryExecutor = dbInstance->getQueryExecutor();

        }      
    }
    void Authenticate() {
        for (;;) {

        }
    }

    Query::QueryExecutor* getQueryExecutor() {
        return queryExecutor;
    }
}
