// EXEC.h

#ifndef EXEC_H
#define EXEC_H

#include "Database.h"
#include "QueryExecutor.h"

namespace EXEC {
    extern Query::QueryExecutor* queryExecutor;
    void initialize();
    Query::QueryExecutor* getQueryExecutor();
}

#endif
