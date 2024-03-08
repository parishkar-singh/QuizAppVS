#include "WhateverItTakes"

namespace Auth {
	AuthHandler::AuthHandler() {
		console::selector::ConsoleSelector selector;
		const std::vector<std::string> options = { "Login", "Register user", "Forgot Password" };
		int choice = selector.selectOptions("How would you like to start? ", options);
		system("cls");
		switch (choice) {

		case 0: {
			NAVBAR::NavBar();
			std::cout << "Enter Credentials to Login: " << std::endl;
			std::string email, password;
			std::cout << "Email: ";
			std::cin >> email;
			std::cout << "Password: ";
			std::cin >> password;
			authenticateUser(email,password);
			break;
		}
		case 1:
		{
			NAVBAR::NavBar();
			std::cout << "Enter Credentials to Register:" << std::endl;
			std::string email, password;
			std::cout << "Email: ";
			std::cin >> email;
			std::cout << "Password: ";
			std::cin >> password;

			registerUser(email, password);
			break;
		}
		case 2: {
			NAVBAR::NavBar();
			std::cout << "Enter Required Details to reset:" << std::endl;
			std::string email, userId, password;
			std::cout << "Email: ";
			std::cin >> email;
			std::cout << "UserId: ";
			std::cin >> userId;
			std::cout << "Enter new password:";
			std::cin >> password;

			updatePassword(email,userId, password);
			break;
		}
		default:std::cout << "Invalid choice." << std::endl;
		}

	}
	AuthHandler::~AuthHandler() {
	
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
			EXEC::queryExecutor->executeUpdate(query);
			std::string selectQuery = "SELECT username, userId users WHERE username = '" + username + "' AND password = '" + hashedPassword + "'";
			EXEC::queryExecutor->selectQuery(selectQuery, false); 
			return true;
		}
		catch (const std::exception& e) {
			std::cerr << "Exception occurred while registering user: " << e.what() << std::endl;
			return false;
		}
	}

	bool AuthHandler::userMatchesId(const std::string& username, const std::string& userId) {
		try {
			std::string query = "SELECT COUNT(*) FROM users WHERE username = '" + username + "' AND userId = '" + userId + "'";
			int count = EXEC::queryExecutor->executeCountQuery(query);
			return count > 0;
		}
		catch (const std::exception& e) {
			std::cerr << "Exception occurred while checking if username and userId match: " << e.what() << std::endl;
			return false;
		}
	}

	bool AuthHandler::updatePassword(const std::string& username, const std::string& userId, const std::string& newPassword) {
		if (!EXEC::queryExecutor) {
			std::cerr << "QueryExecutor not initialized." << std::endl;
			return false;
		}
		try {
			std::string hashedPassword = hashPassword(newPassword);
			std::string query = "UPDATE users SET password = '" + hashedPassword + "' WHERE username = '" + username + "'";
			EXEC::queryExecutor->executeUpdate(query);
			std::cout << "Password Reset Success\n";
			return true;
		}
		catch (const std::exception& e) {
			std::cerr << "Exception occurred while updating password: " << e.what() << std::endl;
			return false;
		}
	}

}
