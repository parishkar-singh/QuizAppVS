#include "WhateverItTakes"

namespace Query {
	QueryExecutor::QueryExecutor(sql::Connection* conn) : connection(conn) {
		console::log::Debug("Query Executor loaded \n");
	}

	QueryExecutor::~QueryExecutor() = default;

	bool Query::QueryExecutor::userExists(const std::string& email, const std::string& password) const
	{
		bool exists = false;
		try {
			sql::Statement* stmt = connection->createStatement();
			std::string query = "SELECT COUNT(*) FROM users WHERE email = '" + email + "' AND password = '" + password + "'";
			sql::ResultSet* res = stmt->executeQuery(query);
			if (res->next()) {
				int count = res->getInt(1);
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


	bool  QueryExecutor::tableExists(const std::string& tableName) const
	{
		bool exists = false;
		try {
			sql::Statement* stmt = connection->createStatement();
			std::string query = "SELECT COUNT(*) FROM information_schema.tables WHERE table_schema = DATABASE() AND table_name = '" + tableName + "'";
			sql::ResultSet* res = stmt->executeQuery(query);
			if (res->next()) {
				int count = res->getInt(1);
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
	bool QueryExecutor::schemaExists(const std::string& schemaName) {
		bool exists = false;
		try {
			sql::Statement* stmt = connection->createStatement();
			std::string query = "SELECT COUNT(*) FROM information_schema.schemata WHERE schema_name = '" + schemaName + "'";
			sql::ResultSet* res = stmt->executeQuery(query);
			if (res->next()) {
				int count = res->getInt(1);
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
	
	 
	std::vector<std::string> QueryExecutor::getUserQuery(const std::string& query) {
		std::vector<std::string> userData;

		try {
			sql::Statement* stmt = connection->createStatement();
			sql::ResultSet* res = stmt->executeQuery(query);
			sql::ResultSetMetaData* meta = res->getMetaData();

			int numColumns = meta->getColumnCount();

			if (res->next()) {
				for (int i = 1; i <= numColumns; ++i) {
					std::string columnValue = res->getString(i);
					userData.push_back(columnValue);
				}
			}

			delete res;
			delete stmt;
		}
		catch (sql::SQLException& e) {
			std::cerr << "SQL Exception: " << e.what() << '\n';
		}

		return userData;
	}

	 
	//////////////////////////////////////////////////////////////////////////////////////////////////////////
	int QueryExecutor::executeCountQuery(const std::string& query) {
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
	bool QueryExecutor::executeUpdate(const std::string& query) {
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

	void QueryExecutor::selectQuery(const std::string& query, const bool isQuestions) {
		std::vector<std::vector<std::string>> results;

		try {
			sql::Statement* stmt = connection->createStatement();
			sql::ResultSet* res = stmt->executeQuery(query);
			sql::ResultSetMetaData* meta = res->getMetaData();

			int numColumns = meta->getColumnCount();

			std::vector<std::string> columnNames;
			for (int i = 1; i <= numColumns; ++i) {
				std::string columnName = meta->getColumnLabel(i);
				columnNames.push_back(columnName);
			}
			results.push_back(columnNames);

			while (res->next()) {
				std::vector<std::string> row;
				for (int i = 1; i <= numColumns; ++i) {
					std::string columnValue = res->getString(i);
					row.push_back(columnValue);
				}
				results.push_back(row);
			}

			delete res;
			delete stmt;
		}
		catch (sql::SQLException& e) {
			std::cerr << "SQL Exception: " << e.what() << '\n';
		}

		isQuestions ? Printer::Questions(results) : Printer::Table(results);
	}
}
