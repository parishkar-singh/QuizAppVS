#include "EXEC.h"
#include "Console.h"
int main() {
    EXEC::Initialize();
    console::selector::ConsoleSelector selector;
    std::vector<std::string> options = {
        "Register user",
        "Login"
    };
    int choice = selector.selectOption("How would you like to start? ", options);

    //system("cls"); 
    std::cout << "You chose: " << options[choice] << std::endl;


    //EXEC::queryExecutor->executeUpdate("INSERT INTO users (username, password) VALUES ('john_doe', 'password123');");
    //EXEC::queryExecutor->executeQueryAndPrint("SELECT * from users");
  

    return 0;
}
