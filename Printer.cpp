#include "WhateverItTakes"

namespace Printer {
    void Table(const std::vector<std::vector<std::string>>& data) {
	    const HANDLE h_console = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(h_console, &csbi);
	    const int console_width = csbi.srWindow.Right - csbi.srWindow.Left;

	    const int num_columns = data[0].size();
	    const int column_width = console_width / num_columns;

        for (int i = 0; i < num_columns; ++i) {
            std::cout << data[0][i];
            const int padding = column_width - data[0][i].size();
            if (padding > 0) {
                std::cout << std::string(padding, ' ');
            }
            std::cout << "|";
        }
        std::cout << '\n';

        for (int i = 0; i < console_width; ++i) {
            std::cout << "-";
        }
        std::cout << '\n';

        // data here we go
        for (int row = 1; row < data.size(); ++row) {
            for (int col = 0; col < data[row].size(); ++col) {
                std::cout << data[row][col];
                const int padding = column_width - data[row][col].size();
                if (padding > 0) {
                    std::cout << std::string(padding, ' ');
                }
                std::cout << "|";
            }
            std::cout << '\n';
        }
    }
    void Questions(const std::vector<std::vector<std::string>>& data) {
        for (int i = 0; i < data.size()-1; ++i) {
            std::cout << "Question " << i + 1 << ": " << data[i+1][1] << '\n';
            std::cout << "A) " << data[i+1][2] << '\n';
            std::cout << "B) " << data[i+1][3] << '\n';
            std::cout << "C) " << data[i+1][4] << '\n';
            std::cout << "D) " << data[i+1][5] << '\n';
            std::cout << "Correct Answer: " << data[i+1][6] << '\n';
            std::cout << '\n';
        }
    }
}
