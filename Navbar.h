#pragma once
#ifndef NAVBAR_H
#define NAVBAR_H

#include <iostream>
#include <string>
#include <windows.h> 

namespace NAVBAR {

    class NavBar {
    public:
        NavBar();
        ~NavBar();

    private:
        void logDatabase();
        void logExecutor();
        void logRole();
        void logUser();

        void printDivider();
    };

}

#endif // NAVBAR_H
