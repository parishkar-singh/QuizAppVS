#include "WhateverItTakes"

namespace MYSQL {
    Database* Database::instance = nullptr;

    Database::Database(const EXEC::DataCreds& d) : con(nullptr), driver(nullptr), queryExecutor(nullptr) {
        server = d.getServer();
        username = d.getUsername();
        password = d.getPassword();
        connect();
    }

    Database::~Database() {
        disconnect();
        delete queryExecutor;
    }

    bool Database::connect() {
        try {
            driver = get_driver_instance();
            con = driver->connect(server, username, password);
            con->setSchema("test");
            queryExecutor = new Query::QueryExecutor(con); // Initialize the query executor
            console::log::Success("Database Connected\n");
            return true;
        }
        catch (sql::SQLException& e) {
            std::cerr << "Could not connect to server. Error message: " << e.what() << std::endl;
            return false;
        }
    }

    void Database::disconnect() {
        if (con != nullptr) {
            delete con;
            con = nullptr;
        }
    }

    Database* Database::getInstance(const EXEC::DataCreds& d) {
        if (!instance) {
            instance = new Database(d);
        }
        return instance;
    }

    Query::QueryExecutor* Database::getQueryExecutor() {
        return queryExecutor;
    }
}
