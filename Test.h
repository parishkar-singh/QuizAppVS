#ifndef TEST_H
#define TEST_H

#include <vector>

namespace test {
    class Test {
    private:
        //std::vector<entities::question_dto> questions;

    public:
        // To start the quiz session;
        Test();
        

        void take_test() const;
    };
}

#endif /* TEST_H */
