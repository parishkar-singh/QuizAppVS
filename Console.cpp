#include "Console.h"

namespace console {
    namespace log {
        void printSuccess(const std::string& message) {
            const std::string RESET = "\033[0m";
            const std::string GREEN = "\033[32m";

            std::cout << GREEN << "[SUCCESS] " << message << RESET << std::endl;
        }

        void printWarning(const std::string& message) {
            const std::string RESET = "\033[0m";
            const std::string YELLOW = "\033[33m";

            std::cout << YELLOW << "[WARNING] " << message << RESET << std::endl;
        }

        void printInfo(const std::string& message) {
            const std::string RESET = "\033[0m";
            const std::string CYAN = "\033[36m";

            std::cout << CYAN << "[INFO] " << message << RESET << std::endl;
        }

        void printDebug(const std::string& message) {
            const std::string RESET = "\033[0m";
            const std::string BLUE = "\033[34m";

            std::cout << BLUE << "[DEBUG] " << message << RESET << std::endl;
        }

        void printTest(const std::string& message) {
            const std::string RESET = "\033[0m";
            const std::string MAGENTA = "\033[35m";

            std::cout << MAGENTA << "[TEST] " << message << RESET << std::endl;
        }
    }
    namespace error {
        void printError(const std::string& message) {
            const std::string RESET = "\033[0m";
            const std::string RED = "\033[31m";

            std::cerr << RED << "[ERROR] " << message << RESET << std::endl;
        }
    }
}
