#include "QueryExecutor.h"
#include <iostream>
#include <cppconn/exception.h>
#include "Console.h"

namespace Query {
    QueryExecutor::QueryExecutor(sql::Connection* conn) : connection(conn) {
        console::log::Debug("Query Executor loaded ");
    }

    QueryExecutor::~QueryExecutor() {}

    void QueryExecutor::executeQueryAndPrint(const std::string& query) {
        try {
            sql::Statement* stmt = connection->createStatement();
            sql::ResultSet* res = stmt->executeQuery(query);

            while (res->next()) {
                std::string username = res->getString("username");
                std::string password = res->getString("password");

                std::cout << "Username: " << username << ", Password: " << password << std::endl;
            }

            delete res;
            delete stmt;
        }
        catch (sql::SQLException& e) {
            std::cerr << "SQL Exception: " << e.what() << std::endl;
        }
    }

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
