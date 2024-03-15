#include "WhateverItTakes"


namespace quiz
{
	QuizSession::QuizSession()
	{
		console::Console selector;
		const std::vector<std::string> options = { "Give a test", "View Past Result", "Ranking" };
		const int choice = selector.selector("What would you like to do? ", options);
		system("cls");

		/*while (!App::current_user)
		{*/
		switch (choice) {

		case 0: {
			App::ui->render_navbar(App::get_stats());
			const int marks = ask_questions();
			App::ui->render_bottombar(App::get_actions());
			std::cout << marks * 10 << "/50" << "\n";
			_getch();


		}
		case 2:
		{
			App::ui->render_navbar(App::get_stats());
			break;
		}
		}
		//}

	}QuizSession::~QuizSession() = default;

	int QuizSession::ask_questions()
	{
		//printer::Table(App::query_executor->select_query_convert_into_dto("select * from questions"));
		std::vector<std::vector<std::string>> questions = App::query_executor->select_query_convert_into_dto("SELECT * FROM Questions");
		// Iterate over each row
		//std::vector<bool> marks;
		int marks = 0;

		// Iterate over each question
		for (const auto& question : questions) {
			std::cout << "Question: " << question[1] << std::endl;

			std::vector<std::string> options;

			std::cout << "Options:" << std::endl;
			for (int i = 2; i <= 5; ++i) {
				std::cout << static_cast<char>('A' + (i - 2)) << ") " << question[i] << std::endl;
				options.push_back(question[i]);
			}

			console::Console selector;
			const int choiceIndex = selector.selector(question[1], options);

			// Convert the choice index to the character representing the option
			char choice = static_cast<char>('A' + choiceIndex - 1);

			std::cout << "Correct Option: " << question[6] << std::endl;

			if (choice == question[6][0])
			{
				marks++;
			}

			std::cout << std::endl; // Add a blank line between questions
		}

	}

}

