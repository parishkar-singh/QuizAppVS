#include "WhateverItTakes"


namespace entities
{
	question_dto::question_dto(const int id, const std::string& text, const std::string& a,
	                           const std::string& b, const std::string& c,
	                           const std::string& d, char correct)
		: question_id(id), question_text(text), option_a(a), option_b(b),
		option_c(c), option_d(d), correct_option(correct) {}

	
	std::vector<std::string> question_dto::convert_to_vector() const
	{
			std::vector<std::string> options;
			options.push_back(option_a);
			options.push_back(option_b);
			options.push_back(option_c);
			options.push_back(option_d);
			return options;
	}


	int question_dto::ask_question_and_get_response() const
	{
		console::selector::ConsoleSelector selector;
		int choice = selector.selectOptions(question_text, convert_to_vector());
		return choice;
	}

	// Method to check if the given option is correct
	bool question_dto::is_correct(const char option) const {
		return (std::toupper(option) == std::toupper(correct_option));
	}

}