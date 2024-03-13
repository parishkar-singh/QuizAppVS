#pragma once

#include "Console.h"
#include "Entities.h"
#include "Database.h"
#include "QueryExecutor.h"

class QuizApp {

private:
	entities::User* current_user = nullptr;
	query::QueryExecutor* query_executor = nullptr;
	mysql::Database* instance = nullptr;
	console::Console* IO = nullptr;

public:
	const static std::vector<boolean>  get_stats();

};
