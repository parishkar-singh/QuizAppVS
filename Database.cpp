#include "WhateverItTakes"

namespace mysql {
    Database* Database::instance = nullptr;
    Database::Database(std::vector<std::string> creds) : driver(nullptr), con(nullptr), query_executor(nullptr) {
        this->server = creds[0];
        this->username = creds[1];
        this->password = creds[2];
        connect();

    }
    Database::~Database() {
        disconnect();
        delete query_executor;
    }
    // Connections
    bool Database::connect() {
        try {
            driver = get_driver_instance();
            con = driver->connect(server, username, password);
            if (con==nullptr)
            {
                this->disconnect();
                return false;
            }
            con->setSchema("test");
            query_executor = new query::QueryExecutor(con);
            //console::Console::Debug("Database Connected\n");
            return true;
        }
        catch (sql::SQLException& e) {
            std::cerr << "Could not connect to server. Error message: " << e.what() << '\n';
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
    Database* Database::get_instance(std::vector<std::string> creds) {
        if (!instance) {
            instance = new Database(creds);
        }
        return instance;
    }
    query::QueryExecutor* Database::get_query_executor() const
    {
        return query_executor;
    }
}
