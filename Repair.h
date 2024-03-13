#pragma once
#ifndef DATABASE_REPAIRER_H
#define DATABASE_REPAIRER_H

#include "WhateverItTakes"
namespace rpr
{
	
class Repair {
private:
	query::QueryExecutor* query_executor;

public:
    Repair(query::QueryExecutor* executor);
    void fix_schema() const;
    void fix_user_table() const;
    void fix_geography_table() const;
    void fix_computer_science_table() const;
    void fix_history_table() const;
    void fix_questions_set_table() const;
    void fix_result_table() const;
};

#endif /* DATABASE_REPAIRER_H */
}