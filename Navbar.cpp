#include "Navbar.h"

#include "WhateverItTakes"
namespace navbar {

    NavBar::NavBar()
    = default;

    void NavBar::render_navbar(const std::vector<bool>& status) {
        system("cls");
        if (status.size() >= 2) {
            console::Console::Database(status[0], "\t");
            console::Console::Executor(status[1], "\t");
            console::Console::Role("USER");
            console::Console::User("Parishkar");
            print_divider();
        }
    }
   
    void NavBar::print_divider() {
        const HANDLE h_console = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO buffer_info;
        GetConsoleScreenBufferInfo(h_console, &buffer_info);
        const int terminal_width = buffer_info.dwSize.X;
        const std::string divider(terminal_width - 1, '_');
        std::cout << divider << '\n' << '\n';
    }

} // namespace navbar
