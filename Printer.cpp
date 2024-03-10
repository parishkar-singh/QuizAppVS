#include "WhateverItTakes"

namespace Printer {
    void Table(const std::vector<std::vector<std::string>>& data) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(hConsole, &csbi);
        int consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left;

        int numColumns = data[0].size();
        int columnWidth = consoleWidth / numColumns;

        for (int i = 0; i < numColumns; ++i) {
            std::cout << data[0][i];
            int padding = columnWidth - data[0][i].size();
            if (padding > 0) {
                std::cout << std::string(padding, ' ');
            }
            std::cout << "|";
        }
        std::cout << std::endl;

        for (int i = 0; i < consoleWidth; ++i) {
            std::cout << "-";
        }
        std::cout << std::endl;

        // data here we go
        for (int row = 1; row < data.size(); ++row) {
            for (int col = 0; col < data[row].size(); ++col) {
                std::cout << data[row][col];
                int padding = columnWidth - data[row][col].size();
                if (padding > 0) {
                    std::cout << std::string(padding, ' ');
                }
                std::cout << "|";
            }
            std::cout << std::endl;
        }
    }
    void Questions(const std::vector<std::vector<std::string>>& data) {
        for (int i = 0; i < data.size()-1; ++i) {
            std::cout << "Question " << i + 1 << ": " << data[i+1][1] << std::endl;
            std::cout << "A) " << data[i+1][2] << std::endl;
            std::cout << "B) " << data[i+1][3] << std::endl;
            std::cout << "C) " << data[i+1][4] << std::endl;
            std::cout << "D) " << data[i+1][5] << std::endl;
            std::cout << "Correct Answer: " << data[i+1][6] << std::endl;
            std::cout << std::endl;
        }
    }
}
