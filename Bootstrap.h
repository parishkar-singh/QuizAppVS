#ifndef BOOTSTRAP_H
#define BOOTSTRAP_H

#include "Database.h"
#include "QueryExecutor.h"

namespace EXEC {

    class DataCreds {
    private:
        std::string server;
        std::string username;
        std::string password;

    public:
        DataCreds(const std::string& s, const std::string& u, const std::string& p);
        std::string getServer() const;
        std::string getUsername() const;
        std::string getPassword() const;
    };
    extern Query::QueryExecutor* queryExecutor;
    void Initialize();
    void Authenticate();
    void ensureDatabase();
    bool bootstrap(DataCreds d);
    Query::QueryExecutor* getQueryExecutor();

}

#endif
