#include "WhateverItTakes"

namespace gui {

	ConsoleUI::ConsoleUI() = default;

	void ConsoleUI::render_navbar(const std::vector<bool>& status) {
		system("cls");
		if (status.size() >= 2) {
			console::Console::Database(status[0], "\t");
			console::Console::Executor(status[1], "\t");
			if (App::current_user)
			{

				console::Console::User(App::current_user->get_username() + "\t");
			}
			else
			{
				console::Console::User("N/a\t");
			}
			if (App::current_user)
			{
				if (App::current_user->is_admin_user() == true)
				{
					console::Console::Role("Admin\n");
				}
				else
				{
					console::Console::User("Student\n");
				}
			}
			else
			{
				console::Console::User("N/a\n");
			}
			print_divider();
		}
	}

	void ConsoleUI::render_bottombar(const std::vector<std::string>& bottom_bar_items) {
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
		const int console_width = csbi.dwSize.X;

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, csbi.dwSize.Y - 3 });

		std::string bottom_bar_content;
		for (const auto& item : bottom_bar_items) {
			bottom_bar_content += item + "  |  ";
		}
		print_divider();
		std::cout << bottom_bar_content;

		std::cout << std::string(console_width - bottom_bar_content.length(), ' ');
	}

	void ConsoleUI::print_divider() {
		const HANDLE h_console = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO buffer_info;
		GetConsoleScreenBufferInfo(h_console, &buffer_info);
		const int terminal_width = buffer_info.dwSize.X;
		const std::string divider(terminal_width - 1, '_');
		std::cout << divider << '\n' << '\n';
	}

}
