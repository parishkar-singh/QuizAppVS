#include "WhateverItTakes"

App::App(const std::vector<std::string>& credentials)
{
	connect_to_database(credentials);
	start_validation_and_diagnosis();
	get_io_library();
	get_console_ui();
	for(;;)
	{
		this->ui->render_navbar(get_stats());
		//this->page;
		std::cout << "Hey there this is parishkar singh" << '\n';
		std::cout << "Hey there this is parishkar singh" << '\n';
		std::cout << "Hey there this is parishkar singh" << '\n';
		std::cout << "Hey there this is parishkar singh" << '\n';
		std::cout << "Hey there this is parishkar singh" << '\n';
		std::cout << "Hey there this is parishkar singh" << '\n';
		std::cout << "Hey there this is parishkar singh" << '\n';
		std::cout << "Hey there this is parishkar singh" << '\n';
		std::cout << "Hey there this is parishkar singh" << '\n';
		std::cout << "Hey there this is parishkar singh" << '\n';
		this->ui->render_bottombar(get_actions());
		_getch();
		
	}

};

std::vector<bool> App::get_stats() const
{
	std::vector<bool> stats;
	stats.push_back(this->query_executor != nullptr);
	stats.push_back(this->connection != nullptr);
	stats.push_back(this->current_user != nullptr);
	stats.push_back(this->io_ops != nullptr);
	stats.push_back(this->page != nullptr);
	return stats;

}
std::vector<std::string> App::get_actions() const
{
	std::vector<std::string> actions;
	actions.push_back(R"(Back: <)");
	actions.push_back(R"(Forward: >)");
	actions.push_back(R"(Exit: ^)");
	return actions;
}


void App::connect_to_database(const std::vector<std::string>& credentials)
{
	if ((this->connection = mysql::Database::get_instance(credentials)))
	{
		this->query_executor = this->connection->get_query_executor();
	}
	console::Console::Database(this->connection != nullptr,"\t");
	console::Console::Executor(this->query_executor != nullptr, "\t");
}

void App::get_io_library()
{
	// Later to added as a library
	this-> io_ops = new console::Console(); 
	
}

void App::start_validation_and_diagnosis()
{
}

void App::get_console_ui()
{
	this->ui = new gui::ConsoleUI();
	
}
auto main(const int keys, char* values[]) -> int
{
	const std::vector<std::string> creds{ values[1], values[2], values[3] };
	if (keys == 0 || values == nullptr)
		return -1;

	App app(creds);

	return -1;
}
