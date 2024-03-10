#ifndef Inspector_H
#define Inspector_H

namespace Inspector {
	namespace Diagnose {
		void validateSchemaAndTables();
	}

	namespace Validator {
		// Input Related 
		bool validateEmail(const std::string& email);
		bool validatePassword(const std::string& password);
		// DB related
		void validateSchema();
		void validateUserTable();
		void validateGeographyTable();
		void validateComputerScienceTable();
		void validateHistoryTable();
		void validateQuestionsSetTable();
		void validateResultTable();
	}

	namespace Fixer {
		void fixSchema();
		void fixUserTable();
		void fixGeographyTable();
		void fixComputerScienceTable();
		void fixHistoryTable();
		void fixQuestionsSetTable();
		void fixResultTable();
	}
}

#endif // Inspector_H
