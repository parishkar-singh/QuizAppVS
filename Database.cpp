#include "WhateverItTakes"

namespace MYSQL {
    Database* Database::instance = nullptr;
    Database::Database(std::vector<std::string> creds) : con(nullptr), driver(nullptr), queryExecutor(nullptr) {
        this->server = creds[0];
        this->username = creds[1];
        this->password = creds[2];
        connect();
    }
    Database::~Database() {
        disconnect();
        delete queryExecutor;
    }
    // Connections
    bool Database::connect() {
        try {
            driver = get_driver_instance();
            con = driver->connect(server, username, password);
            con->setSchema("test");
            queryExecutor = new Query::QueryExecutor(con);
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
    // Getters
    Database* Database::getInstance(std::vector<std::string> creds) {
        if (!instance) {
            instance = new Database(creds);
        }
        return instance;
    }
    Query::QueryExecutor* Database::getQueryExecutor() {
        return queryExecutor;
    }
}
