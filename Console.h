#ifndef CONSOLE_H
#define CONSOLE_H

#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <windows.h>

namespace console {
    namespace selector {
        class ConsoleSelector {
        private:
            const int KEY_UP = 72;
            const int KEY_DOWN = 80;
            const int ENTER_KEY = 13;

            int choice;
            int keyPressed;

        public:
            ConsoleSelector();

            int selectOptions(const std::string question, const std::vector<std::string> values);
            std::vector<std::string> inputOptions(const std::string question, const std::vector<std::string> values);
        };
    }
    namespace log {
        extern const std::string RESET;
        extern const std::string RED;
        extern const std::string GREEN;
        extern const std::string YELLOW;
        extern const std::string BLUE;
        extern const std::string MAGENTA;
        extern const std::string CYAN;
        void Success(const std::string& message);
        void Warning(const std::string& message);
        void Info(const std::string& message);
        void Debug(const std::string& message);
        void Test(const std::string& message);
        void Database(bool isConnected, const std::string& message);
        void Executor(bool isAvailable, const std::string& message);
        void Role(const std::string& message);
        void User(const std::string& message);
    }
    namespace error {
        void Error(const std::string& message);
    }
    namespace art {
        void intro();
        void outro();
    }
    namespace secret {
        std::string getPassword();
    }
}

#endif 
