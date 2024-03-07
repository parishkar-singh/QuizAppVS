#include "QueryExecutor.h"
#include <iostream>
#include <cppconn/exception.h>

namespace Query {
    QueryExecutor::QueryExecutor(sql::Connection* conn) : connection(conn) {}

    QueryExecutor::~QueryExecutor() {}
    //Select Queries
    sql::ResultSet* QueryExecutor::executeQuery(const std::string& query) {
        try {
            sql::Statement* stmt = connection->createStatement();
            sql::ResultSet* res = stmt->executeQuery(query); 
            delete stmt;
            return res;
        }
        catch (sql::SQLException& e) {
            std::cerr << "SQL Exception: " << e.what() << std::endl;
            return nullptr;
        }
    }
    // Insert, Update, DElete
    bool QueryExecutor::executeUpdate(const std::string& query) {
        try {
            sql::Statement* stmt = connection->createStatement();
            stmt->executeUpdate(query); 
            delete stmt;
            return true;
        }
        catch (sql::SQLException& e) {
            std::cerr << "SQL Exception: " << e.what() << std::endl;
            return false;
        }
    }
}
