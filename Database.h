#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <cppconn/connection.h>
#include "QueryExecutor.h"

namespace MYSQL {
    class Database {
    private:
        static Database* instance; 
        sql::Connection* con;
        sql::Driver* driver;
        std::string server;
        std::string username;
        std::string password;
        Query::QueryExecutor* queryExecutor;

        void readConfigFile(const std::string& filename);

    public:
        static Database* getInstance(const std::string& filename); 

        Database(const std::string& filename);
        ~Database();

        bool connect();
        void disconnect();
        Query::QueryExecutor* getQueryExecutor();
    };
}

#endif // DATABASE_H
