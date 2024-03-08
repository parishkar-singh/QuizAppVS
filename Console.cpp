#include "WhateverItTakes"

namespace console {
    namespace selector {
        ConsoleSelector::ConsoleSelector() : choice(0), keyPressed(0) {}
        
        int ConsoleSelector::selectOptions(const std::string question, const std::vector<std::string> values) {
            while (keyPressed != ENTER_KEY) {
                NAVBAR::NavBar();
                std::cout << question + "\n" << std::endl;
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
        
        std::vector<std::string> inputOptions(const std::string& question, const std::vector<std::string>& values) {
            std::vector<std::string> answers;
            std::cout << question << std::endl;
            for (const auto& value : values) {
                std::string temp = "";
                if (value == "Password:") {
                    std::cin >> temp;
                    // Read password securely
                    //temp = secret::getPassword();
                }
                else {
                    std::cout << value;
                    std::cin >> temp;
                }
                answers.push_back(temp);
            }
            return answers;
        }
    }

    namespace log {
        // Color Values
        const std::string RESET = "\033[0m";
        const std::string RED = "\033[31m";
        const std::string GREEN = "\033[32m";
        const std::string YELLOW = "\033[33m";
        const std::string BLUE = "\033[34m";
        const std::string MAGENTA = "\033[35m";
        const std::string CYAN = "\033[36m";
        void Success(const std::string& message) {
            std::cout << GREEN << "[SUCCESS] " << message << RESET ;
        }

        void Warning(const std::string& message) {
            std::cout << YELLOW << "[WARNING] " << message << RESET ;
        }

        void Info(const std::string& message) {
            std::cout << CYAN << "[INFO] " << message << RESET;
        }

        void Debug(const std::string& message) {
            std::cout << BLUE << "[DEBUG] " << message << RESET;
        }

        void Test(const std::string& message) {

            std::cout << MAGENTA << "[TEST] " << message << RESET;
        }
        void Database(bool isConnected, const std::string& message) {
            std::cout <<YELLOW << "[Database]: ";
            if (isConnected) {
                std::cout << GREEN << "Connected " << message << RESET;
            }
            else {
                std::cout << RED << "Not Connected " <<message<< RESET;
            }
        }

        void Executor(bool isAvailable, const std::string& message) {
            const std::string RESET = "\033[0m";
            const std::string CYAN = "\033[36m";
            const std::string RED = "\033[31m";
            const std::string GREEN = "\033[32m";
            const std::string YELLOW = "\033[33m";

            std::cout <<YELLOW << "[Query Executor]: ";
            if (isAvailable) {
                std::cout << GREEN << "Available " << message << RESET;
            }
            else {
                std::cout << RED << "Not Available "<< message << RESET;
            }
        }
        void Role(const std::string& message) {
            const std::string RESET = "\033[0m";
            const std::string CYAN = "\033[36m";
            const std::string RED = "\033[31m";
            const std::string GREEN = "\033[32m";
            const std::string YELLOW = "\033[33m";

            std::cout << YELLOW << "[ROLE]:";
            std::cout << CYAN << message << RESET;
        }
        void User(const std::string& message) {
            const std::string RESET = "\033[0m";
            const std::string CYAN = "\033[36m";
            const std::string RED = "\033[31m";
            const std::string GREEN = "\033[32m";
            const std::string YELLOW = "\033[33m";

            std::cout << YELLOW << "[User]:";
            std::cout << CYAN << message << RESET;
        }

    }
    namespace error {
        void Error(const std::string& message) {
            const std::string RESET = "\033[0m";
            const std::string RED = "\033[31m";

            std::cerr << RED << "[ERROR] " << message << RESET;
        }
    }
    namespace secret {
        std::string getPassword() {
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
            std::cout << std::endl;
            return password;
        }
    }
    namespace art {
        void intro() {
            std::cout  << R"(
 ________  ___  ___  ___  ________          ________  ________  ________   
|\   __  \|\  \|\  \|\  \|\_____  \        |\   __  \|\   __  \|\   __  \  
\ \  \|\  \ \  \\\  \ \  \\|___/  /|       \ \  \|\  \ \  \|\  \ \  \|\  \ 
 \ \  \\\  \ \  \\\  \ \  \   /  / /        \ \   __  \ \   ____\ \   ____\
  \ \  \\\  \ \  \\\  \ \  \ /  /_/__        \ \  \ \  \ \  \___|\ \  \___|
   \ \_____  \ \_______\ \__\\________\       \ \__\ \__\ \__\    \ \__\   
    \|___| \__\|_______|\|__|\|_______|        \|__|\|__|\|__|     \|__|   
          \|__|                                                            
                                                                            By Parishkar Singh                                                                       
    )" << std::endl;
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
                                                                        
)" << std::endl;
        }
    }
}
