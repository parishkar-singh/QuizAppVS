#include "WhateverItTakes"

namespace inspector {
	namespace diagnose {
		void validate_schema_and_tables() {
			validator::validate_schema();
			validator::validate_user_table();
			validator::validate_geography_table();
			validator::validate_computer_science_table();
			validator::validate_history_table();
			validator::validate_questions_set_table();
			validator::validate_result_table();
		}
	}
	namespace validator {

		bool validate_email(const std::string& email) {
			const std::regex email_regex(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
			return std::regex_match(email, email_regex);
		}

		bool validate_password(const std::string& password) {
			return password.length() >= 8; 
		}

		void validate_schema() {
			if (!EXEC::queryExecutor->schemaExists("test")) {
				fixer::fix_schema();
			}
		}

		void validate_user_table() {
			if (!EXEC::queryExecutor->tableExists("Users")) {
				fixer::fix_user_table();
			}
		}

		void validate_geography_table() {
			if (!EXEC::queryExecutor->tableExists("Geography")) {
				fixer::fix_geography_table();
			}
		}

		void validate_computer_science_table() {
			if (!EXEC::queryExecutor->tableExists("ComputerScience")) {
				fixer::fix_computer_science_table();
			}
		}

		void validate_history_table() {
			if (!EXEC::queryExecutor->tableExists("History")) {
				fixer::fix_history_table();
			}
		}

		void validate_questions_set_table() {
			if (!EXEC::queryExecutor->tableExists("QuestionsSet")) {
				fixer::fix_questions_set_table();
			}
		}

		void validate_result_table() {
			if (!EXEC::queryExecutor->tableExists("Result")) {
				fixer::fix_result_table();
			}
		}
	}

	namespace fixer {
		void fix_schema() {
			EXEC::queryExecutor->executeUpdate("CREATE SCHEMA test");
		}

		void fix_user_table() {
			const std::string create_user_table_query = "CREATE TABLE Users ("
				"user_id INT AUTO_INCREMENT PRIMARY KEY, "
				"username VARCHAR(50) NOT NULL UNIQUE, "
				"email VARCHAR(100) NOT NULL UNIQUE, "
				"password VARCHAR(50) NOT NULL, "
				"is_admin BOOLEAN NOT NULL DEFAULT 0)";
			EXEC::queryExecutor->executeUpdate(create_user_table_query);
		}

		void fix_geography_table() {
			const std::string create_geography_table_query = "CREATE TABLE Geography ("
				"question_id INT AUTO_INCREMENT PRIMARY KEY, "
				"question_text TEXT NOT NULL, "
				"option_a VARCHAR(255) NOT NULL, "
				"option_b VARCHAR(255) NOT NULL, "
				"option_c VARCHAR(255) NOT NULL, "
				"option_d VARCHAR(255) NOT NULL, "
				"correct_option CHAR(1) NOT NULL)";
			EXEC::queryExecutor->executeUpdate(create_geography_table_query);
		}

		void fix_computer_science_table() {
			const std::string create_computer_science_table_query = "CREATE TABLE ComputerScience ("
				"question_id INT AUTO_INCREMENT PRIMARY KEY, "
				"question_text TEXT NOT NULL, "
				"option_a VARCHAR(255) NOT NULL, "
				"option_b VARCHAR(255) NOT NULL, "
				"option_c VARCHAR(255) NOT NULL, "
				"option_d VARCHAR(255) NOT NULL, "
				"correct_option CHAR(1) NOT NULL)";
			EXEC::queryExecutor->executeUpdate(create_computer_science_table_query);
		}

		void fix_history_table() {
			const std::string create_history_table_query = "CREATE TABLE History ("
				"question_id INT AUTO_INCREMENT PRIMARY KEY, "
				"question_text TEXT NOT NULL, "
				"option_a VARCHAR(255) NOT NULL, "
				"option_b VARCHAR(255) NOT NULL, "
				"option_c VARCHAR(255) NOT NULL, "
				"option_d VARCHAR(255) NOT NULL, "
				"correct_option CHAR(1) NOT NULL)";
			EXEC::queryExecutor->executeUpdate(create_history_table_query);
		}

		void fix_questions_set_table() {
			const std::string create_questions_set_table_query = "CREATE TABLE QuestionsSet ("
				"set_id INT AUTO_INCREMENT PRIMARY KEY, "
				"set_name VARCHAR(50) NOT NULL, "
				"category ENUM('Geography', 'ComputerScience', 'History') NOT NULL, "
				"admin_id INT NOT NULL, "
				"FOREIGN KEY (admin_id) REFERENCES Users(user_id))";
			EXEC::queryExecutor->executeUpdate(create_questions_set_table_query);
		}

		void fix_result_table() {
			const std::string create_result_table_query = "CREATE TABLE Result ("
				"result_id INT AUTO_INCREMENT PRIMARY KEY, "
				"user_id INT NOT NULL, "
				"set_id INT NOT NULL, "
				"score INT NOT NULL, "
				"FOREIGN KEY (user_id) REFERENCES Users(user_id), "
				"FOREIGN KEY (set_id) REFERENCES QuestionsSet(set_id))";
			EXEC::queryExecutor->executeUpdate(create_result_table_query);
		}
	}
}
