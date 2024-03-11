#include "WhateverItTakes"

namespace navbar {

    NavBar::NavBar() {
        system("cls");
        log_database();
        log_executor();
        log_role();
        log_user();
        print_divider();
    }

    NavBar::~NavBar() = default;

    void NavBar::log_database() {
            console::log::Database(true,"\t") ;
        
    }

    void NavBar::log_executor() {
        console::log::Executor(exec::query_executor, "\t");
    }

    void NavBar::log_role() {
        if (exec::current_user == nullptr) {
            console::log::Role("N/A\t ");
        }
        else if (exec::current_user->is_admin_user()) {
        console::log::Role( "Admin\t");
        }
        else {
        console::log::Role( "Student\t");
        }

    }

    void NavBar::log_user() {
        if (exec::current_user == nullptr) {
        console::log::User("N/A \n");
        }
        else {
        console::log::User(exec::current_user->get_username()+"\n");
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

}
