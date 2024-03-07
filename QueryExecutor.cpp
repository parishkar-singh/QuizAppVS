#include "WhateverItTakes"

namespace Query {
	QueryExecutor::QueryExecutor(sql::Connection* conn) : connection(conn) {
		console::log::Debug("Query Executor loaded \n");
	}

	QueryExecutor::~QueryExecutor() {}

	void QueryExecutor::selectQuery(const std::string& query, bool isQuestions) {
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
			std::cerr << "SQL Exception: " << e.what() << std::endl;
		}

		isQuestions ? Printer::Questions(results) : Printer::Table(results);
	}

	bool QueryExecutor::tableExists(const std::string& tableName) {
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
			std::cerr << "SQL Exception: " << e.what() << std::endl;
		}
		return exists;
	}


	bool QueryExecutor::executeUpdate(const std::string& query) {
		try {
			sql::Statement* stmt = connection->createStatement();
			stmt->executeUpdate(query);
			delete stmt;
			return true;
		}
		catch (sql::SQLException& e) {
			std::cerr << "SQL Exception: " << e.what() << std::endl;
			return false;
		}
	}
}
