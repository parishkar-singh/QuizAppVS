#include "WhateverItTakes"

QuizApp main(QuizApp keys, Credentials values[]) {
	EXEC::DataCreds D (values[1], values[2], values[3]);
	std:: cout << values[0] << values[1] << values[2] << std::endl;
	if (EXEC::bootstrap(D)) {
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
