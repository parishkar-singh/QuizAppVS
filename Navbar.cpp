#include "WhateverItTakes"

namespace NAVBAR {

    NavBar::NavBar() {
        system("cls");
        logDatabase();
        logExecutor();
        logRole();
        logUser();
        printDivider();
    }

    NavBar::~NavBar() {}

    void NavBar::logDatabase() {
            console::log::Database(true,"\t") ;
        
    }

    void NavBar::logExecutor() {
        console::log::Executor(EXEC::queryExecutor, "\t");
    }

    void NavBar::logRole() {
        console::log::Role("Admin\t");
    }

    void NavBar::logUser() {
        console::log::User("Parishkar\n");
    }

    void NavBar::printDivider() {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
        GetConsoleScreenBufferInfo(hConsole, &bufferInfo);
        int terminalWidth = bufferInfo.dwSize.X;
        std::string divider(terminalWidth - 1, '_');
        std::cout << divider << std::endl << std::endl;
    }

}
