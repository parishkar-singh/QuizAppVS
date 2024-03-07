#ifndef BOOTSTRAP_H
#define BOOTSTRAP_H

#include "Database.h"
#include "QueryExecutor.h"

namespace EXEC {

    
    extern Query::QueryExecutor* queryExecutor;
    void Initialize(std::vector<std::string> creds);
    void Authenticate();
    void ensureDatabase();
    bool bootstrap(std::vector<std::string> creds);
    Query::QueryExecutor* getQueryExecutor();

}

#endif
