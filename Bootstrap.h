#ifndef BOOTSTRAP_H
#define BOOTSTRAP_H

#include "Database.h"
#include "QueryExecutor.h"

namespace EXEC {
    extern Query::QueryExecutor* queryExecutor;
    void Initialize();
    void Authenticate();
    void ensureDatabase();
    bool bootstrap();
    Query::QueryExecutor* getQueryExecutor();

}

#endif
