#include "WhateverItTakes"
// I dont know this may be responsible for the flow of execution not yet decided

namespace EXEC {
	Model::CurrentUser* currentUser = nullptr;
	Model::CurrentUser* getCurrentUser() {
		return currentUser;
	}
	Query::QueryExecutor* queryExecutor = nullptr;
	Query::QueryExecutor* getQueryExecutor() {
		return queryExecutor;
	}

	void Initialize(std::vector<std::string> creds) {
		MYSQL::Database* dbInstance = MYSQL::Database::getInstance(creds);
		if (dbInstance) {
			queryExecutor = dbInstance->getQueryExecutor();
		}
	}
	
	void printAvailable() {
		system("cls");
		NAVBAR::NavBar give_me_a_name;
		queryExecutor->selectQuery("select * from computerscience",true);
		_getch();
		system("cls");
		NAVBAR::NavBar();
		queryExecutor->selectQuery("select * from users",false);
		_getch();
	}
	bool bootstrap(std::vector<std::string> creds) {
		console::art::intro();
		Loader::startProgressBar();
		std::cout << " Lets go";
		_getch();
		system("cls");
		Loader::startEatSleepRepeat();
		system("cls");
		Initialize(creds);
		Inspector::Diagnose::validateSchemaAndTables();
		Auth::AuthHandler::AuthHandler();
		printAvailable();
		system("cls");
		console::art::outro();
		std::cout << "Thank you for trying out...";
		_getch();
		system("cls");
		Loader::startEatSleepRepeat();
		system("cls");
		return true;
	}

}
