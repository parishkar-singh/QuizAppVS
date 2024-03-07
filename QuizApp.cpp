#include "EXEC.h"
#include <iostream>

int main() {
    EXEC::initialize();
    EXEC::queryExecutor->executeQueryAndPrint("SELECT * from users");
;
  

    return 0;
}
