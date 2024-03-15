#include "WhateverItTakes"

model::CurrentUser* App::current_user = nullptr;
query::QueryExecutor* App::query_executor = nullptr;
mysql::Database* App::connection = nullptr;
navigation::Navigator* App::page = nullptr;
gui::ConsoleUI* App::ui = nullptr;
console::Console* App::io_ops = nullptr;

App::App(const std::vector<std::string>& credentials)
{
	/*query_executor = nullptr;
	connection = nullptr;
	current_user = nullptr;
	page = nullptr;
	ui = nullptr;
	io_ops = nullptr;*/
	
	connect_to_database(credentials);
	start_validation_and_diagnosis();
	get_io_library();
	get_console_ui();
	std::vector<std::string> answers;

	answers.emplace_back("First answer");
	answers.emplace_back("Second answer");
	answers.emplace_back("Third answer");
	std::cout << R"(
 ________  ___  ___  ___  ________          ________  ________  ________   
|\   __  \|\  \|\  \|\  \|\_____  \        |\   __  \|\   __  \|\   __  \  
\ \  \|\  \ \  \\\  \ \  \\|___/  /|       \ \  \|\  \ \  \|\  \ \  \|\  \ 
 \ \  \\\  \ \  \\\  \ \  \   /  / /        \ \   __  \ \   ____\ \   ____\
  \ \  \\\  \ \  \\\  \ \  \ /  /_/__        \ \  \ \  \ \  \___|\ \  \___|
   \ \_____  \ \_______\ \__\\________\       \ \__\ \__\ \__\    \ \__\   
    \|___| \__\|_______|\|__|\|_______|        \|__|\|__|\|__|     \|__|   
          \|__|                                                            
                                                                            By Parishkar Singh                                                                       
    )" << '\n';
	loader::start_progress_bar();
	_getch();
	auth::AuthHandler();
	quiz::QuizSession();
	_getch();
	std::cout << R"(
 ________ ____  _____ ______    
|_   __  |_   \|_   _|_   _ `.  
  | |_ \_| |   \ | |   | | `. \ 
  |  _| _  | |\ \| |   | |  | | 
 _| |__/ |_| |_\   |_ _| |_.' / 
|________|_____|\____|______.'  
                                                                        
)" << '\n';
	//quiz::QuizSession();
	//std::string questionsAsked = io_ops->input("You like using this", true);
}

std::vector<bool> App::get_stats()
{
	std::vector<bool> stats;
	stats.push_back(connection != nullptr);
	stats.push_back(query_executor != nullptr);
	stats.push_back(current_user != nullptr);
	stats.push_back(io_ops != nullptr);
	stats.push_back(page != nullptr);
	return stats;
}

std::vector<std::string> App::get_actions()
{
	std::vector<std::string> actions;
	actions.emplace_back(R"(Back: <)");
	actions.emplace_back(R"(Forward: >)");
	actions.emplace_back(R"(Exit: ^)");
	return actions;
}

void App::connect_to_database(const std::vector<std::string>& credentials)
{
	connection = mysql::Database::get_instance(credentials);
	query_executor = connection->get_query_executor();
	//console::Console::Database(connection != nullptr, "\t");
	//console::Console::Executor(query_executor != nullptr, "\t");
}

void App::get_io_library()
{
	io_ops = new console::Console();
}

void App::start_validation_and_diagnosis()
{
}

void App::get_console_ui()
{
	ui = new gui::ConsoleUI();
}

auto main(const int keys, char* values[]) -> int
{
	const std::vector<std::string> creds{ values[1], values[2], values[3] };
	if (keys == 0 || values == nullptr)
		return -1;

	App* app = new App(creds);

	return -1;
}
