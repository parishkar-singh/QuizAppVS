#include "WhateverItTakes"
// I dont know this may be responsible for the flow of execution not yet decided

namespace exec {
	/*model::CurrentUser* current_user = nullptr;
	model::CurrentUser* get_current_user() {
		return current_user;
	}
	query::QueryExecutor* query_executor = nullptr;
	query::QueryExecutor* get_query_executor() {
		return query_executor;
	}*/

	/*void initialize(std::vector<std::string> creds) {
		if (mysql::Database* db_instance = mysql::Database::get_instance(creds)) {
			query_executor = db_instance->get_query_executor();
		}
	}
	*/
	void print_available() {
		
		system("cls");
		navbar::NavBar give_me_a_name;

		query_executor->select_query_and_print("select * from computerscience",true);
		_getch();
		/*system("cls");
		NAVBAR::NavBar();
		queryExecutor->selectQuery("select * from users",false);
		_getch();*/
	}
	bool bootstrap(std::vector<std::string> creds) {
		//console::art::intro();
		loader::start_progress_bar();
		std::cout << " Lets go";
		_getch();
		//system("cls");
		//Loader::startEatSleepRepeat();
		//system("cls");
		initialize(creds);
		auth::AuthHandler::AuthHandler();
		print_available();
		system("cls");
		//console::art::outro();
		std::cout << "Thank you for trying out...";
		_getch();
		system("cls");
		loader::start_eat_sleep_repeat();
		system("cls");
		return true;
	}

}
