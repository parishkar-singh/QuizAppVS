#include "WhateverItTakes"

namespace query {
	QueryExecutor::QueryExecutor(sql::Connection* conn) : connection(conn) {
		console::log::Debug("Query Executor loaded \n");
	}

	QueryExecutor::~QueryExecutor() = default;
	// To check if things exist already or not
	bool query::QueryExecutor::user_exists(const std::string& email, const std::string& password) const
	{
		bool exists = false;
		try {
			sql::Statement* stmt = connection->createStatement();
			const std::string query = "SELECT COUNT(*) FROM users WHERE email = '" + email + "' AND password = '" + password + "'";
			sql::ResultSet* res = stmt->executeQuery(query);
			if (res->next()) {
				const int count = res->getInt(1);
				exists = (count > 0);
			}
			delete res;
			delete stmt;
		}
		catch (sql::SQLException& e) {
			std::cerr << "SQL Exception: " << e.what() << '\n';
		}
		return exists;
	}


	bool QueryExecutor::table_exists(const std::string& table_name) const
	{
		bool exists = false;
		try {
			sql::Statement* stmt = connection->createStatement();
			const std::string query = "SELECT COUNT(*) FROM information_schema.tables WHERE table_schema = DATABASE() AND table_name = '" + table_name + "'";
			sql::ResultSet* res = stmt->executeQuery(query);
			if (res->next()) {
				const int count = res->getInt(1);
				exists = (count > 0);
			}
			delete res;
			delete stmt;
		}
		catch (sql::SQLException& e) {
			std::cerr << "SQL Exception: " << e.what() << '\n';
		}
		return exists;
	}
	bool QueryExecutor::schema_exists(const std::string& schema_name) const
	{
		bool exists = false;
		try {
			sql::Statement* stmt = connection->createStatement();
			const std::string query = "SELECT COUNT(*) FROM information_schema.schemata WHERE schema_name = '" + schema_name + "'";
			sql::ResultSet* res = stmt->executeQuery(query);
			if (res->next()) {
				const int count = res->getInt(1);
				exists = (count > 0);
			}
			delete res;
			delete stmt;
		}
		catch (sql::SQLException& e) {
			std::cerr << "SQL Exception: " << e.what() << '\n';
		}
		return exists;
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	 
	std::vector<std::string> QueryExecutor::get_user_query(const std::string& query) const
	{
		std::vector<std::string> user_data;

		try {
			sql::Statement* stmt = connection->createStatement();
			sql::ResultSet* res = stmt->executeQuery(query);
			sql::ResultSetMetaData* meta = res->getMetaData();

			const int num_columns = meta->getColumnCount();

			if (res->next()) {
				for (int i = 1; i <= num_columns; ++i) {
					std::string column_value = res->getString(i);
					user_data.push_back(column_value);
				}
			}

			delete res;
			delete stmt;
		}
		catch (sql::SQLException& e) {
			std::cerr << "SQL Exception: " << e.what() << '\n';
		}

		return user_data;
	}

	 
	//////////////////////////////////////////////////////////////////////////////////////////////////////////
	int QueryExecutor::execute_count_query(const std::string& query) const
	{
		int count = 0;
		try {
			sql::Statement* stmt = connection->createStatement();
			sql::ResultSet* res = stmt->executeQuery(query);
			if (res->next()) {
				count = res->getInt(1);
			}
			delete res;
			delete stmt;
		}
		catch (sql::SQLException& e) {
			std::cerr << "SQL Exception: " << e.what() << '\n';
		}
		return count;
	}
	bool QueryExecutor::execute_update(const std::string& query) const
	{
		try {
			sql::Statement* stmt = connection->createStatement();
			stmt->executeUpdate(query);
			delete stmt;
			return true;
		}
		catch (sql::SQLException& e) {
			std::cerr << "SQL Exception: " << e.what() << '\n';
			return false;
		}
	}
	// This does not return the headers and mostly this will be used for the DTO conversion
	std::vector<std::vector<std::string>> QueryExecutor::select_query_convert_into_dto(const std::string& query) const
	{
		std::vector<std::vector<std::string>> results;

		try {
			sql::Statement* stmt = connection->createStatement();
			sql::ResultSet* res = stmt->executeQuery(query);
			sql::ResultSetMetaData* meta = res->getMetaData();

			const int num_columns = meta->getColumnCount();

			// Right now ignore the column vector
			/*std::vector<std::string> column_names;
			for (int i = 1; i <= num_columns; ++i) {
				std::string column_name = meta->getColumnLabel(i);
				column_names.push_back(column_name);
			}
			results.push_back(column_names);*/

			while (res->next()) {
				std::vector<std::string> row;
				for (int i = 1; i <= num_columns; ++i) {
					std::string column_value = res->getString(i);
					row.push_back(column_value);
				}
				results.push_back(row);
			}

			delete res;
			delete stmt;
		}
		catch (sql::SQLException& e) {
			std::cerr << "SQL Exception: " << e.what() << '\n';
		}
		printer::Questions(results);
		return results;
		//isQuestions ? Printer::Questions(results) : Printer::Table(results);
	}
	// Prints the data using the printer module
	void QueryExecutor::select_query_and_print(const std::string& query,const bool is_question) const
	{
		std::vector<std::vector<std::string>> results;

		try {
			sql::Statement* stmt = connection->createStatement();
			sql::ResultSet* res = stmt->executeQuery(query);
			sql::ResultSetMetaData* meta = res->getMetaData();

			const int num_columns = meta->getColumnCount();

			std::vector<std::string> column_names;
			for (int i = 1; i <= num_columns; ++i) {
				std::string column_name = meta->getColumnLabel(i);
				column_names.push_back(column_name);
			}
			results.push_back(column_names);

			while (res->next()) {
				std::vector<std::string> row;
				for (int i = 1; i <= num_columns; ++i) {
					std::string column_value = res->getString(i);
					row.push_back(column_value);
				}
				results.push_back(row);
			}

			delete res;
			delete stmt;
		}
		catch (sql::SQLException& e) {
			std::cerr << "SQL Exception: " << e.what() << '\n';
		}
	
		is_question ? printer::Questions(results) : printer::Table(results);
	}
}
