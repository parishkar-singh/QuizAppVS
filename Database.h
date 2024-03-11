#ifndef DATABASE_H
#define DATABASE_H

#include "QueryExecutor.h"
#include "Bootstrap.h"
#include <cppconn/driver.h>
#include <string>

namespace mysql {
    class Database {
    private:
        sql::Driver* driver;
        sql::Connection* con;
        query::QueryExecutor* queryExecutor;
        std::string server;
        std::string username;
        std::string password;

        bool connect();
        void disconnect();

    public:
        static Database* get_instance(std::vector<std::string> creds);
        query::QueryExecutor* get_query_executor();

        ~Database();

    private:
        Database(std::vector<std::string> creds);
        static Database* instance;
    };
}


#endif
