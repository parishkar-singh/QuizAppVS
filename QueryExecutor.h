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

		bool userExists(const std::string& username, const std::string& hashPassword);
		bool schemaExists(const std::string& schemaName);
		bool tableExists(const std::string& tableName);
		bool executeUpdate(const std::string& query);
		void selectQuery(const std::string& query, bool isQuestions);
	};
}

#endif 
