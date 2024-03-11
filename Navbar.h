#pragma once
#ifndef NAVBAR_H
#define NAVBAR_H

#include <iostream>
#include <string>
#include <windows.h> 

namespace navbar {

    class NavBar {
    public:
        NavBar();
        ~NavBar();

    private:
        static void log_database();
        static void log_executor();
        static void log_role();
        static void log_user();

        static void print_divider();
    };

}

#endif // NAVBAR_H
