#pragma once
#ifndef ENTITIES_H
#define ENTITIES_H

#include <string>

namespace entities {
	///////////// Questions
	class question_dto {
	private:
		int question_id;
		std::string question_text;
		std::string option_a;
		std::string option_b;
		std::string option_c;
		std::string option_d;
		char correct_option;
	public:
		question_dto(const std::vector<std::string>& data);
		std::vector<std::string> convert_to_vector() const;
		int ask_question_and_get_response() const;
		bool is_correct(char option) const;
	};

	///////////// Users
	class user_dto
	{
	public:
		int user_id;
		std::string username;
		std::string email;
		bool is_admin;
	};
	///////////// Question Set
	class question_set_dto
	{
	public:
		int set_id;
		std::string set_name;
		std::string category;
		int admin_id;

	};
	//////////// Result 
	class result_dto
	{
	public:
		int result_id;
		int user_id;
		int question_set_id;
		int score;
	};
}

#endif
