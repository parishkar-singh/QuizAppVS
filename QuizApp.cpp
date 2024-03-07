#include "WhateverItTakes"

QuizApp main(QuizApp keys, Credentials values[]) {
	std::vector<std::string> creds{ values[1], values[2], values[3] };
	
	//EXEC::Initialize(creds);
	if (EXEC::bootstrap(creds)) {
		return App;
	}

	//return App;
	return Memory_Error;
}

