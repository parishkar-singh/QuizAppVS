#ifndef DATABASE_H
#define DATABASE_H

#include "QueryExecutor.h"
#include "Bootstrap.h" // Include the DataCreds class header
#include <cppconn/driver.h>
#include <string>

namespace MYSQL {
    class Database {
    private:
        sql::Driver* driver;
        sql::Connection* con;
        Query::QueryExecutor* queryExecutor;
        std::string server;
        std::string username;
        std::string password;

        bool connect();
        void disconnect();

    public:
        static Database* getInstance(const EXEC::DataCreds& d); // Update the getInstance method signature
        Query::QueryExecutor* getQueryExecutor();

        ~Database();

    private:
        Database(const EXEC::DataCreds& d); // Update the constructor declaration
        static Database* instance;
    };
}

#endif
