#pragma once

#include "Console.h"
#include "Entities.h"
#include "Database.h"
#include "Navigator.h"
#include "QueryExecutor.h"
#include "Ui.h"

/// <summary>
/// 1. Create a separate thread for database connection
///	2. Retrieve the current page from the navigator
///	3. Create template for navigator 
/// </summary>
class App
{

private:
	entities::User* current_user = nullptr;
	query::QueryExecutor* query_executor = nullptr;
	mysql::Database* connection = nullptr;
	navigation::Navigator* page = nullptr;
	gui::ConsoleUI * ui = nullptr;

public:
	console::Console* io_ops = nullptr;
	explicit App(const std::vector<std::string>&);
	static void start_validation_and_diagnosis();
	// non statics
	void connect_to_database(const std::vector<std::string>& credentials);
	// library
	void get_console_ui();
	void get_io_library();
	[[maybe_unused]] [[nodiscard]] std::vector<bool> get_stats() const;
	[[maybe_unused]] [[nodiscard]] std::vector<std::string>  get_actions() const;

};
