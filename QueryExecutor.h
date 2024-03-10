#ifndef QUERYEXECUTOR_H
#define QUERYEXECUTOR_H

#include <cppconn/connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <string>
#include <vector>

namespace Query {
	class QueryExecutor {
	private:
		sql::Connection* connection;
	public:
		QueryExecutor(sql::Connection* conn);
		~QueryExecutor();

		bool userExists(const std::string& username, const std::string& hashPassword) const;
		bool schemaExists(const std::string& schemaName);
		bool tableExists(const std::string& tableName) const;
		bool executeUpdate(const std::string& query);
		std::vector<std::vector<std::string>> selectQuery(const std::string& query);
		void select_query_and_print(const std::string& query, const bool is_question);
		int executeCountQuery(const std::string& query);
		std::vector < std::string > getUserQuery(const std::string& query);
	};
}

#endif 
