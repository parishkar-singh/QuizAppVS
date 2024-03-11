#pragma once
#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <regex>
#include <string>
#include <iostream>
#include "QueryExecutor.h"

class Validator {
private:
    query::QueryExecutor* query_executor = nullptr;
    sql::Connection* connection = nullptr;

public:
    static bool validate_email(const std::string& email);
    static bool validate_password(const std::string& password);
    bool table_exists(const std::string& table_name) const;
    bool schema_exists(const std::string& schema_name) const;
};

#endif /* VALIDATOR_H */
