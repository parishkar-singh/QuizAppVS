#include "WhateverItTakes"
namespace repair
{
	void fix_schema() {
		exec::query_executor->execute_update("CREATE SCHEMA test");
	}

	void fix_user_table() {
		const std::string create_user_table_query = "CREATE TABLE Users ("
			"user_id INT AUTO_INCREMENT PRIMARY KEY, "
			"username VARCHAR(50) NOT NULL UNIQUE, "
			"email VARCHAR(100) NOT NULL UNIQUE, "
			"password VARCHAR(50) NOT NULL, "
			"is_admin BOOLEAN NOT NULL DEFAULT 0)";
		exec::query_executor->execute_update(create_user_table_query);
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
		exec::query_executor->execute_update(create_geography_table_query);
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
		exec::query_executor->execute_update(create_computer_science_table_query);
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
		exec::query_executor->execute_update(create_history_table_query);
	}

	void fix_questions_set_table() {
		const std::string create_questions_set_table_query = "CREATE TABLE QuestionsSet ("
			"set_id INT AUTO_INCREMENT PRIMARY KEY, "
			"set_name VARCHAR(50) NOT NULL, "
			"category ENUM('Geography', 'ComputerScience', 'History') NOT NULL, "
			"admin_id INT NOT NULL, "
			"FOREIGN KEY (admin_id) REFERENCES Users(user_id))";
		exec::query_executor->execute_update(create_questions_set_table_query);
	}

	void fix_result_table() {
		const std::string create_result_table_query = "CREATE TABLE Result ("
			"result_id INT AUTO_INCREMENT PRIMARY KEY, "
			"user_id INT NOT NULL, "
			"set_id INT NOT NULL, "
			"score INT NOT NULL, "
			"FOREIGN KEY (user_id) REFERENCES Users(user_id), "
			"FOREIGN KEY (set_id) REFERENCES QuestionsSet(set_id))";
		exec::query_executor->execute_update(create_result_table_query);
	}

}