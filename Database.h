// Database.h
#ifndef DATABASE_H
#define DATABASE_H

#include "QueryExecutor.h"
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

        void readConfigFile(const std::string& filename);
        bool connect();
        void disconnect();

    public:
        static Database* getInstance(const std::string& filename);
        Query::QueryExecutor* getQueryExecutor();

        ~Database();

    private:
        Database(const std::string& filename);
        static Database* instance;
    };
}

#endif // DATABASE_H
