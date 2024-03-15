#pragma once
#include <string>
#include <vector>

namespace quiz
{
	class QuizSession
	{

	public:
		QuizSession();
		~QuizSession();

		//const std::vector<std::string> get_set();
		int ask_questions();
		const std::vector<std::string> get_result();
		void submit_test();



	};

	
}
