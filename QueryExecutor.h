#ifndef QUERY_EXECUTOR_H
#define QUERY_EXECUTOR_H

#include <cppconn/connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <cppconn/driver.h>

namespace Query {
    class QueryExecutor {
    private:
        sql::Connection* connection;

    public:
        QueryExecutor(sql::Connection* conn);
        ~QueryExecutor();

        // Select Queries
        void executeQueryAndPrint(const std::string& query);

        // Insert, Update, Delete
        bool executeUpdate(const std::string& query);
    };
}

#endif // QUERY_EXECUTOR_H
