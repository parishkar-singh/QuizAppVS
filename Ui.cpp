#include "WhateverItTakes"

namespace gui {

    ConsoleUI::ConsoleUI() = default;

    void ConsoleUI::render_navbar(const std::vector<bool>& status) {
        system("cls");
        if (status.size() >= 2) {
            console::Console::Database(status[0], "\t");
            console::Console::Executor(status[1], "\t");
            console::Console::Role("USER\t");
            console::Console::User("Parishkar\n");
            print_divider();
        }
    }

    void ConsoleUI::render_bottombar(const std::vector<std::string>& bottom_bar_items) {
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        const int console_width = csbi.dwSize.X;
        COORD cursorPos;

        // Calculate the length of the bottom bar content
        std::string bottom_bar_content;
        for (const auto& item : bottom_bar_items) {
            bottom_bar_content += item + "  |  ";
        }
        const int bottom_bar_length = bottom_bar_content.length();

        // Calculate the position to start printing the bottom bar content
        int start_column = (console_width - bottom_bar_length) / 2;
        if (start_column < 0) {
            start_column = 0; // Ensure the content starts at the beginning if it exceeds the console width
        }

        // Print the bottom bar content
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (SHORT)start_column, csbi.dwSize.Y - 3 });
        print_divider();
        std::cout << bottom_bar_content;

        // Move the cursor to the end of the bottom bar content
        cursorPos.X = start_column + bottom_bar_length;
        cursorPos.Y = csbi.dwSize.Y - 3;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPos);
    }



    void ConsoleUI::print_divider() {
        const HANDLE h_console = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO buffer_info;
        GetConsoleScreenBufferInfo(h_console, &buffer_info);
        const int terminal_width = buffer_info.dwSize.X;
        const std::string divider(terminal_width - 1, '_');
        std::cout << divider << '\n' << '\n';
    }

}
