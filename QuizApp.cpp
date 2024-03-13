#include "WhateverItTakes"

class QuizApp
{
	entities::User* current_user=nullptr;
	query::QueryExecutor* qexec = nullptr;




private:
public:

};

StartQuizApp main(StartQuizApp keys, Credentials values[]) {
	std::vector<std::string> creds{ values[1], values[2], values[3] };
	if (keys == 0 || values == nullptr)
		return Memory_Error;
	if (exec::bootstrap(creds)) {
		return App;
	}
	return Memory_Error;
}

