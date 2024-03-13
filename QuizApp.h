#pragma once

#include "Console.h"
#include "Entities.h"
#include "Database.h"
#include "Navigator.h"
#include "QueryExecutor.h"

class QuizApp {

private:
	entities::User* current_user = nullptr;
	query::QueryExecutor* query_executor = nullptr;
	mysql::Database* instance = nullptr;
	console::Console* IO = nullptr;
	navigation::Navigator* page = nullptr;

public:
	const static std::vector<bool>  get_stats();
	void connect_to_database();
	void start_validation_and_diagnosis();


};
