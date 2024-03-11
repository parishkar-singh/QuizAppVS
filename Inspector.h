#ifndef Inspector_H
#define Inspector_H

namespace inspector {
	namespace diagnose {
		void validate_schema_and_tables();
	}

	namespace validator {
		// Input Related 
		bool validate_email(const std::string& email);
		bool validate_password(const std::string& password);
		// DB related
		void validate_schema();
		void validate_user_table();
		void validate_geography_table();
		void validate_computer_science_table();
		void validate_history_table();
		void validate_questions_set_table();
		void validate_result_table();
	}

	namespace fixer {
		void fix_schema();
		void fix_user_table();
		void fix_geography_table();
		void fix_computer_science_table();
		void fix_history_table();
		void fix_questions_set_table();
		void fix_result_table();
	}
}

#endif // Inspector_H
