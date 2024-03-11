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
			if (!exec::query_executor->schema_exists("test")) {
				fixer::fix_schema();
			}
		}

		void validate_user_table() {
			if (!exec::query_executor->table_exists("Users")) {
				fixer::fix_user_table();
			}
		}

		void validate_geography_table() {
			if (!exec::query_executor->table_exists("Geography")) {
				fixer::fix_geography_table();
			}
		}

		void validate_computer_science_table() {
			if (!exec::query_executor->table_exists("ComputerScience")) {
				fixer::fix_computer_science_table();
			}
		}

		void validate_history_table() {
			if (!exec::query_executor->table_exists("History")) {
				fixer::fix_history_table();
			}
		}

		void validate_questions_set_table() {
			if (!exec::query_executor->table_exists("QuestionsSet")) {
				fixer::fix_questions_set_table();
			}
		}

		void validate_result_table() {
			if (!exec::query_executor->table_exists("Result")) {
				fixer::fix_result_table();
			}
		}
	}

	namespace fixer {
		
}
