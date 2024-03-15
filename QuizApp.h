#pragma once

#include "Console.h"
#include "Entities.h"
#include "Database.h"
#include "Navigator.h"
#include "QueryExecutor.h"
#include "Ui.h"
#include "CurrentUser.h"

/// <summary>
/// 1. Create a separate thread for database connection
///	2. Retrieve the current page from the navigator
///	3. Create template for navigator 
/// </summary>
class App
{

public:

	static query::QueryExecutor* query_executor ;
	static mysql::Database* connection ;
	static model:: CurrentUser* current_user ;
	static navigation::Navigator* page ;
	static gui::ConsoleUI* ui ;
	static console::Console* io_ops ;
	// Constructor 
	explicit App(const std::vector<std::string>&);
	// functions
	static void start_validation_and_diagnosis();
	// non statics
	static void connect_to_database(const std::vector<std::string>& credentials);
	// library
	static void get_console_ui();
	static void get_io_library();
	[[maybe_unused]] [[nodiscard]] static  std::vector<bool> get_stats()  ;
	[[maybe_unused]] [[nodiscard]] static  std::vector<std::string>  get_actions();

};
