#include "WhateverItTakes"
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
std::vector<std::string> query::QueryExecutor::get_user_query(const std::string& query) const
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