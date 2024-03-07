#include "Database.h"
#include <iostream>
#include <cppconn/exception.h>
#include <cppconn/driver.h>
#include <fstream>

#include <sstream>

namespace MYSQL {
    Database* Database::instance = nullptr; // Initialize the static member variable

    Database::Database(const std::string& filename) : con(nullptr), driver(nullptr), queryExecutor(nullptr) {
        readConfigFile(filename);
        queryExecutor = new Query::QueryExecutor(con);
    }

    Database::~Database() {
        disconnect();
        delete queryExecutor;
    }

    void Database::readConfigFile(const std::string& filename) {
        std::ifstream configFile(filename);
        std::string line;

        if (configFile.is_open()) {
            while (std::getline(configFile, line)) {
                std::istringstream iss(line);
                std::string key, value;
                std::getline(iss, key, '=');
                std::getline(iss, value);

                if (key == "server")
                    server = value;
                else if (key == "username")
                    username = value;
                else if (key == "password")
                    password = value;
            }
            configFile.close();
        }
        else {
            std::cerr << "Unable to open config file: " << filename << std::endl;
        }
    }

    bool Database::connect() {
        try {
            driver = get_driver_instance();
            con = driver->connect(server, username, password);
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

    Database* Database::getInstance(const std::string& filename) {
        if (!instance) {
            instance = new Database(filename);
        }
        return instance;
    }

    Query::QueryExecutor* Database::getQueryExecutor() {
        return queryExecutor;
    }
}
