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
        if (EXEC::currentUser == nullptr) {
            console::log::Role("N/A\t ");
        }
        else if (EXEC::currentUser->isAdminUser()) {
        console::log::Role( "Admin\t");
        }
        else {
        console::log::Role( "Student\t");
        }

    }

    void NavBar::logUser() {
        if (EXEC::currentUser == nullptr) {
        console::log::User("N/A \n");
        }
        else {
        console::log::User(EXEC::currentUser->getUsername()+"\n");
        }
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
