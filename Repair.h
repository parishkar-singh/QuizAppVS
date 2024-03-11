#pragma once
#ifndef DATABASE_REPAIRER_H
#define DATABASE_REPAIRER_H

#include "WhateverItTakes"

class Repair {
private:
	query::QueryExecutor* query_executor;

public:
    Repair(query::QueryExecutor* executor);
    void fixSchema();
    void fixUserTable();
    void fixGeographyTable();
    void fixComputerScienceTable();
    void fixHistoryTable();
    void fixQuestionsSetTable();
    void fixResultTable();
};

#endif /* DATABASE_REPAIRER_H */
