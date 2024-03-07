#pragma once
#ifndef QUERYEXECUTOR_H
#define QUERYEXECUTOR_H

#include <string>
#include <cppconn/connection.h>
#include <cppconn/statement.h>

namespace Query {
    class QueryExecutor {
    private:
        sql::Connection* connection;

    public:
        QueryExecutor(sql::Connection* conn);
        ~QueryExecutor();
        sql::ResultSet* executeQuery(const std::string& query);
        bool executeUpdate(const std::string& query);
    };
}

#endif // QUERYEXECUTOR_H
