#include "EXEC.h"
#include "Console.h"
int main() {
    console::selector::ConsoleSelector selector;
 
    std::cout << "Hey there answer this question\n";
    std::vector<std::string> options = {
        "Register user",
        "Login"
    };

    int choice = selector.selectOption("How would you like to start? ", options);

    system("cls"); // Clear the console screen
    std::cout << "You chose: " << options[choice] << std::endl;

    //EXEC::initialize();

    //EXEC::queryExecutor->executeUpdate("INSERT INTO users (username, password) VALUES ('john_doe', 'password123');");
    //EXEC::queryExecutor->executeQueryAndPrint("SELECT * from users");
  

    return 0;
}
