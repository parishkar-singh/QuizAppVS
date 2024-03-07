#pragma once
#ifndef COLOR_CONSOLE_H
#define COLOR_CONSOLE_H

#include <iostream>
#include <string>

namespace console {
    namespace log {
        void printError(const std::string& message);
        void printSuccess(const std::string& message);
        void printWarning(const std::string& message);
        void printInfo(const std::string& message);
        void printDebug(const std::string& message);
        void printTest(const std::string& message);
    }

    namespace error {
        void printError(const std::string& message);
    }
}

#endif // COLOR_CONSOLE_H
