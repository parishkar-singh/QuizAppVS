#pragma once
#ifndef CONSOLE_UI_H
#define CONSOLE_UI_H

#include <vector>
#include <iostream>

namespace gui {

    class ConsoleUI {
    public:
        ConsoleUI();
        static void render_navbar(const std::vector<bool>& nav_items);
        static void render_bottombar(const std::vector<std::string>& bottom_bar_items);
        static void print_divider();
    };

}
#endif // CONSOLE_UI_H
