#include "Console.h"
#include <conio.h>
#include <vector>
#include <string>

#include <windows.h>

namespace console {
    
    namespace selector {
        ConsoleSelector::ConsoleSelector() : choice(0), keyPressed(0) {}

        int ConsoleSelector::selectOption(const std::string question,const std::vector<std::string>& options) {
            while (keyPressed != ENTER_KEY) {
                system("cls"); // To get that clear view

                // Top Bar to Show the logs
                log::Success("Database Connected");

                // I think windows terminal supports css in its own fashion
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
                GetConsoleScreenBufferInfo(hConsole, &bufferInfo);

                int terminalWidth = bufferInfo.dwSize.X;
                std::string divider(terminalWidth - 1, '_');
                std::cout << divider << std::endl << std::endl;
                // Question
                std::cout << question + "\n" << std::endl;
                // choices
                for (size_t i = 0; i < options.size(); ++i) {
                    if (static_cast<int>(i) == choice) {
                        std::cout << "-> " << options[i] << "\n";
                    }
                    else {
                        std::cout << "   " << options[i] << "\n";
                    }
                }

                keyPressed = _getch(); // Catch the arrow key

                if (keyPressed == KEY_UP && choice > 0) {
                    choice--; // going up :)
                }
                else if (keyPressed == KEY_DOWN && choice < static_cast<int>(options.size()) - 1) {
                    choice++; // going down :(
                }
            }

            return choice;
        }
    }

    namespace log {
        void Success(const std::string& message) {
            const std::string RESET = "\033[0m";
            const std::string GREEN = "\033[32m";

            std::cout << GREEN << "[SUCCESS] " << message << RESET << std::endl;
        }

        void Warning(const std::string& message) {
            const std::string RESET = "\033[0m";
            const std::string YELLOW = "\033[33m";

            std::cout << YELLOW << "[WARNING] " << message << RESET << std::endl;
        }

        void Info(const std::string& message) {
            const std::string RESET = "\033[0m";
            const std::string CYAN = "\033[36m";

            std::cout << CYAN << "[INFO] " << message << RESET << std::endl;
        }

        void Debug(const std::string& message) {
            const std::string RESET = "\033[0m";
            const std::string BLUE = "\033[34m";

            std::cout << BLUE << "[DEBUG] " << message << RESET << std::endl;
        }

        void Test(const std::string& message) {
            const std::string RESET = "\033[0m";
            const std::string MAGENTA = "\033[35m";

            std::cout << MAGENTA << "[TEST] " << message << RESET << std::endl;
        }
    }
    namespace error {
        void Error(const std::string& message) {
            const std::string RESET = "\033[0m";
            const std::string RED = "\033[31m";

            std::cerr << RED << "[ERROR] " << message << RESET << std::endl;
        }
    }
}
