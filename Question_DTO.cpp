#include "WhateverItTakes"

namespace entities
{
	question_dto::question_dto(const std::vector<std::string>& data) {
		
		if (data.size() < 7) {
			throw std::invalid_argument("Insufficient data provided for question_dto ");
		}

		question_id = std::stoi(data[0]);
		question_text = data[1];
		option_a = data[2];
		option_b = data[3];
		option_c = data[4];
		option_d = data[5];
		correct_option = data[6][0]; 
	}

	
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
		//console::selector::ConsoleSelector selector;
		//const int choice = selector.select_options(question_text, convert_to_vector());
		//return choice;
		return 1;
	}

	bool question_dto::is_correct(const char option) const {
		return (std::toupper(option) == std::toupper(correct_option));
	}

}