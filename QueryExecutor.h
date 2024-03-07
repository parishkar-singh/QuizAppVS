// QueryExecutor.h
#ifndef QUERYEXECUTOR_H
#define QUERYEXECUTOR_H

#include <cppconn/connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <string>

namespace Query {
    class QueryExecutor {
    private:
        sql::Connection* connection;

    public:
        QueryExecutor(sql::Connection* conn);
        ~QueryExecutor();

        void executeQueryAndPrint(const std::string& query);
        bool executeUpdate(const std::string& query);
    };
}

#endif // QUERYEXECUTOR_H
