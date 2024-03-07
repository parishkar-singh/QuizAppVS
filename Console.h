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

            int selectOption(const std::string question,const std::vector<std::string>& options);
        };
    }
    namespace log {
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
}

#endif // CONSOLE_H
