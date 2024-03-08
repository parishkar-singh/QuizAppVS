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
	void ensureDatabase() {
		if (!queryExecutor->schemaExists("test")) {
			queryExecutor->executeUpdate("CREATE SCHEMA test");
		}
		if (!queryExecutor->tableExists("Users")) {
			std::string createUserTableQuery = "CREATE TABLE Users ("
				"userId INT AUTO_INCREMENT PRIMARY KEY, "
				"username VARCHAR(50) NOT NULL UNIQUE, "
				"email VARCHAR(100) NOT NULL UNIQUE, "
				"password VARCHAR(50) NOT NULL, "
				"isAdmin BOOLEAN NOT NULL DEFAULT 0)";
			queryExecutor->executeUpdate(createUserTableQuery);
		}

		if (!queryExecutor->tableExists("Geography")) {
			std::string createGeographyTableQuery = "CREATE TABLE Geography ("
				"questionId INT AUTO_INCREMENT PRIMARY KEY, "
				"questionText TEXT NOT NULL, "
				"optionA VARCHAR(255) NOT NULL, "
				"optionB VARCHAR(255) NOT NULL, "
				"optionC VARCHAR(255) NOT NULL, "
				"optionD VARCHAR(255) NOT NULL, "
				"correctOption CHAR(1) NOT NULL)";
			queryExecutor->executeUpdate(createGeographyTableQuery);
		}
		if (!queryExecutor->tableExists("ComputerScience")) {
			std::string createComputerScienceTableQuery = "CREATE TABLE ComputerScience ("
				"questionId INT AUTO_INCREMENT PRIMARY KEY, "
				"questionText TEXT NOT NULL, "
				"optionA VARCHAR(255) NOT NULL, "
				"optionB VARCHAR(255) NOT NULL, "
				"optionC VARCHAR(255) NOT NULL, "
				"optionD VARCHAR(255) NOT NULL, "
				"correctOption CHAR(1) NOT NULL)";
			queryExecutor->executeUpdate(createComputerScienceTableQuery);
		}
		if (!queryExecutor->tableExists("History")) {
			std::string createHistoryTableQuery = "CREATE TABLE History ("
				"questionId INT AUTO_INCREMENT PRIMARY KEY, "
				"questionText TEXT NOT NULL, "
				"optionA VARCHAR(255) NOT NULL, "
				"optionB VARCHAR(255) NOT NULL, "
				"optionC VARCHAR(255) NOT NULL, "
				"optionD VARCHAR(255) NOT NULL, "
				"correctOption CHAR(1) NOT NULL)";
			queryExecutor->executeUpdate(createHistoryTableQuery);
		}

		if (!queryExecutor->tableExists("QuestionsSet")) {
			std::string createQuestionsSetTableQuery = "CREATE TABLE QuestionsSet ("
				"setId INT AUTO_INCREMENT PRIMARY KEY, "
				"setName VARCHAR(50) NOT NULL, "
				"category ENUM('Geography', 'ComputerScience', 'History') NOT NULL, "
				"adminId INT NOT NULL, " 
				"FOREIGN KEY (adminId) REFERENCES Users(userId))"; 
			queryExecutor->executeUpdate(createQuestionsSetTableQuery);
		}


		if (!queryExecutor->tableExists("Result")) {
			std::string createResultTableQuery = "CREATE TABLE Result ("
				"resultId INT AUTO_INCREMENT PRIMARY KEY, "
				"userId INT NOT NULL, "
				"setId INT NOT NULL, "
				"score INT NOT NULL, "
				"FOREIGN KEY (userId) REFERENCES Users(userId), "
				"FOREIGN KEY (setId) REFERENCES QuestionsSet(setId))";
			queryExecutor->executeUpdate(createResultTableQuery);
		}
	}

	void printAvailable() {
		system("cls");
		NAVBAR::NavBar();
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
		ensureDatabase();
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
