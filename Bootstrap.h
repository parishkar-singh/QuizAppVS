#ifndef BOOTSTRAP_H
#define BOOTSTRAP_H

#include "Database.h"
#include "QueryExecutor.h"

namespace exec {

    extern Model::CurrentUser* current_user;
    extern Query::QueryExecutor* query_executor;
    void initialize(std::vector<std::string> creds);
    bool bootstrap(std::vector<std::string> creds);
    Query::QueryExecutor* get_query_executor();
    void print_available();
}

#endif
