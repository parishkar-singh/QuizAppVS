#ifndef QUERYEXECUTOR_H
#define QUERYEXECUTOR_H

#include <cppconn/connection.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <string>
#include <vector>

namespace query {

	class QueryExecutor {
	private:
		sql::Connection* connection;
	public:
		explicit QueryExecutor(sql::Connection* conn);
		~QueryExecutor();

		bool user_exists(const std::string& email, const std::string& password) const;
		std::vector<std::string> get_user_query(const std::string& query) const;
		[[nodiscard]] bool execute_update(const std::string& query) const;

		[[nodiscard]] int execute_count_query(const std::string& query) const;
		[[nodiscard]] std::vector<std::vector<std::string>> select_query_convert_into_dto(const std::string& query) const;
		void select_query_and_print(const std::string& query, const bool is_question) const;
	};
}

#endif 
