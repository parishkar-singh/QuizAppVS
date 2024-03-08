#include "WhateverItTakes"

namespace Auth {
    AuthHandler::AuthHandler() {
        console::selector::ConsoleSelector selector;
        /*std::vector<std::string> options = {
            "Login",
            "Register user",
            "Forgot Password?"
        };*/
        const char* options[] = { "Login", "Register user", "Forgot Password" };
        int choice = selector.selectOptions("How would you like to start? ", 3, options);
        delete[] options;
        system("cls");
        switch (choice) {
        case 0:{
            const char* options[] = { "Enter User Name: ", "Enter Password" };
            std::vector<std::string>answers;
            authenticateUser(answers[0],answers[1]);
            delete[] options;
            break;
        }
        case 1:
            handleRegistration();
            break;
        case 2:
            handleForgotPassword();
            break;
        default:
            std::cout << "Invalid choice." << std::endl;
        }
        /*std::cout << "You chose: " << options[choice] << std::endl;*/

    }
    std::string AuthHandler::hashPassword(const std::string& password) {
        // Will impliment OPENSSL the moment this whole thing works 
        try {
            size_t hashed = std::hash<std::string>{}(password);
            std::stringstream ss;
            ss << std::hex << hashed;
            return ss.str();
        }
        catch (const std::exception& e) {
            std::cerr << "Exception occurred while hashing password: " << e.what() << std::endl;
            return "";
        }
    }

    bool AuthHandler::authenticateUser(const std::string& username, const std::string& password) {
        if (!EXEC::queryExecutor) {
            std::cerr << "QueryExecutor not initialized." << std::endl;
            return false;
        }
        try {
            std::string hashedPassword = hashPassword(password);
            EXEC::queryExecutor->userExists(username, hashedPassword);
            return true;
        }
        catch (const std::exception& e) {
            std::cerr << "Exception occurred while authenticating user: " << e.what() << std::endl;
            return false;
        }
    }

    bool AuthHandler::registerUser(const std::string& username, const std::string& password) {
        if (!EXEC::queryExecutor) {
            std::cerr << "QueryExecutor not initialized." << std::endl;
            return false;
        }
        try {
            std::string hashedPassword = hashPassword(password);
            std::string query = "INSERT INTO users (username, password) VALUES ('" + username + "', '" + hashedPassword + "')";
            return EXEC::queryExecutor->executeUpdate(query);
        }
        catch (const std::exception& e) {
            std::cerr << "Exception occurred while registering user: " << e.what() << std::endl;
            return false;
        }
    }

    
    bool AuthHandler::updatePassword(const std::string& username, const std::string& newPassword) {
        if (!EXEC::queryExecutor) {
            std::cerr << "QueryExecutor not initialized." << std::endl;
            return false;
        }
        try {
            std::string hashedPassword = hashPassword(newPassword);
            std::string query = "UPDATE users SET password = '" + hashedPassword + "' WHERE username = '" + username + "'";
            return EXEC::queryExecutor->executeUpdate(query);
        }
        catch (const std::exception& e) {
            std::cerr << "Exception occurred while updating password: " << e.what() << std::endl;
            return false;
        }
    }

}
