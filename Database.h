#ifndef DATABASE_H
#define DATABASE_H

#include "QueryExecutor.h"
#include <cppconn/driver.h>
#include <string>

namespace mysql {
    class Database {
    private:
        sql::Driver* driver;
        sql::Connection* con=nullptr;
        query::QueryExecutor* query_executor;
        std::string server;
        std::string username;
        std::string password;

        bool connect();
        void disconnect();

    public:
        static Database* get_instance(std::vector<std::string> creds);
        query::QueryExecutor* get_query_executor() const;

        ~Database();

    private:
        Database(std::vector<std::string> creds);
        static Database* instance;
    };
}


#endif
