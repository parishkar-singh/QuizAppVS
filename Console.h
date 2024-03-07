#pragma once
#ifndef COLOR_CONSOLE_H
#define COLOR_CONSOLE_H

#include <iostream>
#include <string>

namespace console {
    namespace log {
        void Success(const std::string& message);
        void Warning(const std::string& message);
        void Info(const std::string& message);
        void Debug(const std::string& message);
        void Test(const std::string& message);
    }

    namespace error {
        void Error(const std::string& message);
    }
}

#endif // COLOR_CONSOLE_H
