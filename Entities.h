#pragma once
#ifndef ENTITIES_H
#define ENTITIES_H

#include <string>

namespace entities {
	class question_dto {
	public:
		int question_id;
		std::string question_text;
		std::string option_a;
		std::string option_b;
		std::string option_c;
		std::string option_d;
		char correct_option;
	};

	class user_dto
	{
	public:
		int user_id;
		std::string username;
		std::string email;
		bool is_admin;
	};

	class question_set_dto
	{
	public:
		int set_id;
		std::string set_name;
		std::string category;
		int admin_id;

	};
}

#endif
