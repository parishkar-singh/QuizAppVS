#include "Console.h"

namespace console {
    namespace log {
        void Success(const std::string& message) {
            const std::string RESET = "\033[0m";
            const std::string GREEN = "\033[32m";

            std::cout << GREEN << "[SUCCESS] " << message << RESET << std::endl;
        }

        void Warning(const std::string& message) {
            const std::string RESET = "\033[0m";
            const std::string YELLOW = "\033[33m";

            std::cout << YELLOW << "[WARNING] " << message << RESET << std::endl;
        }

        void Info(const std::string& message) {
            const std::string RESET = "\033[0m";
            const std::string CYAN = "\033[36m";

            std::cout << CYAN << "[INFO] " << message << RESET << std::endl;
        }

        void Debug(const std::string& message) {
            const std::string RESET = "\033[0m";
            const std::string BLUE = "\033[34m";

            std::cout << BLUE << "[DEBUG] " << message << RESET << std::endl;
        }

        void Test(const std::string& message) {
            const std::string RESET = "\033[0m";
            const std::string MAGENTA = "\033[35m";

            std::cout << MAGENTA << "[TEST] " << message << RESET << std::endl;
        }
    }
    namespace error {
        void Error(const std::string& message) {
            const std::string RESET = "\033[0m";
            const std::string RED = "\033[31m";

            std::cerr << RED << "[ERROR] " << message << RESET << std::endl;
        }
    }
}
