#pragma once
#ifndef ENTITIES_H
#define ENTITIES_H

#include <string>

namespace entities {
	///////////// Questions
	class Question {
	private:
		int question_id;
		std::string question_text;
		std::string option_a;
		std::string option_b;
		std::string option_c;
		std::string option_d;
		char correct_option;
	
	};

	///////////// Users
	class User
	{
	public:
		int user_id;
		std::string username;
		std::string email;
		bool is_admin;
	};
	///////////// Question Set
	class Question_Set
	{
	public:
		int set_id;
		std::string set_name;
		std::string category;
		int admin_id;

	};
	//////////// Result 
	class Result_Dto
	{
	public:
		int result_id;
		int user_id;
		int question_set_id;
		int score;
	};
}

#endif
