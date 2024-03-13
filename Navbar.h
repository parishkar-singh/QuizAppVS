#pragma once
#ifndef NAVBAR_H
#define NAVBAR_H
#include <vector>

namespace navbar {

    class NavBar {
    public:
        NavBar();
        static void render_navbar(const std::vector<bool>& status);
        static void print_divider();
       
    };

}

#endif // NAVBAR_H
