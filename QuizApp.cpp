#include "WhateverItTakes"

QuizApp main(QuizApp keys, Credentials values[]) {
	std::vector<std::string> creds{ values[1], values[2], values[3] };
	if (keys == 0 || values == nullptr)
		return Memory_Error;
	/*if (EXEC::bootstrap(creds)) {
		return App;
	}*/
	EXEC::Initialize(creds);
	//std::cout<<Auth::AuthHandler::registerUser("parishkar","parishkar")<<std::endl;
	std::cout << Auth::AuthHandler::authenticateUser("parishkar", "parishkar")<<std::endl;
	

	return App;
	//return Memory_Error;
}

