#ifndef CONSOLE_H
#define CONSOLE_H

#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <windows.h>

namespace console
{
    class Console
    {
    private:
        std::string password;
        int KEY_UP;
        int KEY_DOWN;
        int ENTER_KEY;
        int choice;
        int keyPressed;
        static const std::string RESET;
        static const std::string RED;
        static const std::string GREEN;
        static const std::string YELLOW;
        static const std::string BLUE;
        static const std::string MAGENTA;
        static const std::string CYAN;

    public:
        Console();
        int selector(const std::string& question, const std::vector<std::string>& values);
        std::vector<std::string> input(const std::string& question, const std::vector<std::string>& values);

        static void Success(const std::string& message);
        static void Warning(const std::string& message);
        static void Info(const std::string& message);
        static void Debug(const std::string& message);
        static void Test(const std::string& message);
        static void Database(bool isConnected, const std::string& message);
        static void Executor(bool is_available, const std::string& message);
        static void Role(const std::string& message);
        static void User(const std::string& message);

        static void ArtWork();
        static std::string setPassword();
        static std::string getPassword();
    };
}

#endif
