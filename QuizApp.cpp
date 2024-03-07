#include "WhateverItTakes"

//QuizApp main() {
//    if (EXEC::bootstrap()) {
//        return App;
//    }
//    return Memory_Error;
//}

int main() {
    EXEC::Initialize();
    EXEC::ensureDatabase();
    //std::cout<<EXEC::queryExecutor->tableExists("computerscience


    //EXEC::queryExecutor->selectQuery("select * from computerscience",true);
    return 0;
}
