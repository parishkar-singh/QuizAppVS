#include "WhateverItTakes"

namespace auth {
	AuthHandler::AuthHandler() {
		console::selector::ConsoleSelector selector;
		const std::vector<std::string> options = { "Login", "Register user", "Forgot Password" };
		const int choice = selector.select_options("How would you like to start? ", options);
		system("cls");
		switch (choice) {

		case 0: {
			navbar::NavBar give_me_a_name;
			std::cout << "Enter Credentials to Login: " << std::endl;
			std::string email, password;
			std::cout << "Email: ";
			std::cin >> email;
			std::cout << "Password: ";
			std::cin >> password;
			if (authenticate_user(email, password)) {
				if (const std::vector<std::string> user_data = exec::query_executor->get_user_query("SELECT userId, username, email, isAdmin FROM users WHERE email = '" + email + "'"); !user_data.empty()) {
					exec::current_user = new model::CurrentUser(user_data);
				}
				else {
					// Handle the case where user data is empty
					exec::current_user = nullptr;
				}
			}
			break;
		}
		case 1:
		{
			navbar::NavBar give_me_a_name;
			std::cout << "Enter Credentials to Register:" << '\n';
			std::string username, email, password;
			std::cout << "Username:";
			std::cin >> username;
			std::cout << "Email: ";
			std::cin >> email;
			std::cout << "Password: ";
			std::cin >> password;

			register_user(username,email, password);
			break;
		}
		case 2: {
			navbar::NavBar give_me_a_name;
			std::cout << "Enter Required Details to reset:" << '\n';
			std::string email, user_id, password;
			std::cout << "Email: ";
			std::cin >> email;
			std::cout << "UserId: ";
			std::cin >> user_id;
			std::cout << "Enter new password:";
			std::cin >> password;

			update_password(email,user_id, password);
			break;
		}
		default:std::cout << "Invalid choice." << '\n';
		}

	}
	AuthHandler::~AuthHandler() = default;


	std::string AuthHandler::hash_password(const std::string& password) {
		try {
			const size_t hashed = std::hash<std::string>{}(password);
			std::stringstream ss;
			ss << std::hex << hashed;
			return ss.str();
		}
		catch (const std::exception& e) {
			std::cerr << "Exception occurred while hashing password: " << e.what() << '\n';
			return "";
		}
	}


	bool AuthHandler::authenticate_user(const std::string& email, const std::string& password) {
		if (!exec::query_executor) {
			std::cerr << "QueryExecutor not initialized." << '\n';
			return false;
		}
		try {
			const std::string hashed_password = hash_password(password);
			exec::query_executor->user_exists(email, hashed_password);
			return true;
		}
		catch (const std::exception& e) {
			std::cerr << "Exception occurred while authenticating user: " << e.what() << '\n';
			return false;
		}
	}


	bool AuthHandler::register_user(const std::string& username,const std::string & email, const std::string& password) {
		if (!exec::query_executor) {
			std::cerr << "QueryExecutor not initialized." << '\n';
			return false;
		}
		try {
			const std::string hashed_password = hash_password(password);
			const std::string query = "INSERT INTO users (username ,email, password) VALUES ('" + username + "','" + email + "', '" + hashed_password + "')";
			exec::query_executor->execute_update(query);
			const std::string select_query = "SELECT username, userId from users WHERE email = '" + email + "' AND password = '" + hashed_password + "'";
			exec::query_executor->select_query_and_print(select_query,false);
			return true;
		}
		catch (const std::exception& e) {
			std::cerr << "Exception occurred while registering user: " << e.what() << '\n';
			return false;
		}
	}

	bool AuthHandler::user_matches_id(const std::string& username, const std::string& user_id) {
		try {
			const std::string query = "SELECT COUNT(*) FROM users WHERE username = '" + username + "' AND userId = '" + user_id + "'";
			const int count = exec::query_executor->execute_count_query(query);
			return count > 0;
		}
		catch (const std::exception& e) {
			std::cerr << "Exception occurred while checking if username and userId match: " << e.what() << '\n';
			return false;
		}
	}

	bool AuthHandler::update_password(const std::string& username, const std::string& user_id, const std::string& new_password) {
		if (!exec::query_executor) {
			std::cerr << "QueryExecutor not initialized." << '\n';
			return false;
		}
		try {
			const std::string hashed_password = hash_password(new_password);
			const std::string query = "UPDATE users SET password = '" + hashed_password + "' WHERE username = '" + username + "'";
			exec::query_executor->execute_update(query);
			std::cout << "Password Reset Success\n";
			return true;
		}
		catch (const std::exception& e) {
			std::cerr << "Exception occurred while updating password: " << e.what() << '\n';
			return false;
		}
	}

}
