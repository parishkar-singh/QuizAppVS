#include "WhateverItTakes"


namespace console
{
	const std::string Console::RESET = "\033[0m";
	const std::string Console::RED = "\033[31m";
	const std::string Console::GREEN = "\033[32m";
	const std::string Console::YELLOW = "\033[33m";
	const std::string Console::BLUE = "\033[34m";
	const std::string Console::MAGENTA = "\033[35m";
	const std::string Console::CYAN = "\033[36m";

	Console::Console() :
		KEY_UP(72),
		KEY_DOWN(80),
		ENTER_KEY(13),
		choice(0),
		keyPressed(0) {};

	int Console::selector(const std::string& question, const std::vector<std::string>& values) {
		std::vector<bool> stats{ true, true, true, true };

		while (keyPressed != ENTER_KEY) {

			system("cls");

			//nav::NavBar::render_navbar(stats);
			std::cout << question + "\n" << '\n';
			for (size_t i = 0; i < values.size(); ++i) {
				if (static_cast<int>(i) == choice) {
					std::cout << "-> " << values[i] << "\n";
				}
				else {
					std::cout << "   " << values[i] << "\n";
				}
			}
			keyPressed = _getch(); // Catch the arrow key
			if (keyPressed == KEY_UP && choice > 0) {
				choice--; // going up :)
			}
			else if (keyPressed == KEY_DOWN && choice < static_cast<int>(values.size()) - 1) {
				choice++; // going down :(
			}
		}
		return choice;
	}

	std::vector<std::string> Console::input(const std::string& question, const std::vector<std::string>& values) {
		std::vector<std::string> answers;
		std::cout << question << '\n';
		for (const auto& value : values) {
			std::string temp;
			if (value == "Password:") {
				std::cin >> temp;
				// Read password securely
				//temp = getPassword();
			}
			else {
				std::cout << value;
				std::cin >> temp;
			}
			answers.push_back(temp);
		}
		return answers;
	}

	void Console::Success(const std::string& message) {
		std::cout << GREEN << "[SUCCESS] " << message << RESET;
	}

	void Console::Warning(const std::string& message) {
		std::cout << YELLOW << "[WARNING] " << message << RESET;
	}

	void Console::Info(const std::string& message) {
		std::cout << CYAN << "[INFO] " << message << RESET;
	}

	void Console::Debug(const std::string& message) {
		std::cout << BLUE << "[DEBUG] " << message << RESET;
	}

	void Console::Test(const std::string& message) {
		std::cout << MAGENTA << "[TEST] " << message << RESET;
	}

	void Console::Database(bool isConnected, const std::string& message) {
		std::cout << YELLOW << "[Database]: ";
		if (isConnected) {
			std::cout << GREEN << "Connected " << message << RESET;
		}
		else {
			std::cout << RED << "Not Connected " << message << RESET;
		}
	}

	void Console::Executor(bool is_available, const std::string& message) {
		std::cout << YELLOW << "[Query Executor]: ";
		if (is_available) {
			std::cout << GREEN << "Available " << message << RESET;
		}
		else {
			std::cout << RED << "Not Available " << message << RESET;
		}
	}

	void Console::Role(const std::string& message) {
		std::cout << YELLOW << "[ROLE]:";
		std::cout << CYAN << message << RESET;
	}

	void Console::User(const std::string& message) {
		std::cout << YELLOW << "[User]:";
		std::cout << CYAN << message << RESET;
	}

	std::string Console::setPassword() {
		const char BACKSPACE = 8;
		const char RETURN = 13;

		std::string password;
		char ch = 0;

		while ((ch = _getch()) != RETURN) {
			if (ch == BACKSPACE) {
				if (password.length() != 0) {
					std::cout << "\b \b";
					password.resize(password.length() - 1);
				}
			}
			else {
				std::cout << '*';
				password += ch;
			}
		}
		std::cout << '\n';
		return password;
	}

	std::string Console::getPassword() {
		return setPassword();
	}
}


namespace art {
	void intro() {
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
	}
	//////////////////////////////////
	void outro() {
		std::cout << R"(
 ________ ____  _____ ______    
|_   __  |_   \|_   _|_   _ `.  
  | |_ \_| |   \ | |   | | `. \ 
  |  _| _  | |\ \| |   | |  | | 
 _| |__/ |_| |_\   |_ _| |_.' / 
|________|_____|\____|______.'  
                                                                        
)" << '\n';
	}
}