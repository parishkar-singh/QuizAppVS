#include "WhateverItTakes"

QuizApp main(QuizApp keys, Credentials values[]) {
	std::vector<std::string> creds{ values[1], values[2], values[3] };
	for (auto e : creds) {
		std::cout << e << std::endl;
	}

	if (EXEC::bootstrap(creds)) {
		return App;
	}

	return Memory_Error;
}


//if (argc < 4) {
	//std::cerr << "Usage: " << argv[0] << " <server> <username> <password>" << std::endl;
	//return 1;
//}

//int main(int argc, char * argv[]) {
//    //EXEC::DataCreds D(argv[0], argv[1], argv[2]);
//    std::cout << argv[1] << argv[2] << argv[3] << std::endl;
//    //EXEC::Initialize();
//    //EXEC::ensureDatabase();
//    //std::cout<<EXEC::queryExecutor->tableExists("computerscience
//
//
//    //EXEC::queryExecutor->selectQuery("select * from computerscience",true);
//    return 0;
//}
