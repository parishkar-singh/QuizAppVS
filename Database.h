#ifndef DATABASE_H
#define DATABASE_H

#include "QueryExecutor.h"
#include "Bootstrap.h"
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
        static Database* getInstance(std::vector<std::string> creds);
        Query::QueryExecutor* getQueryExecutor();

        ~Database();

    private:
        Database(std::vector<std::string> creds);
        static Database* instance;
    };
}


#endif
