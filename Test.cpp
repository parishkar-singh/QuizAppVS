#include "WhateverItTakes"

namespace entities {
    class Test {

    private:
        std::vector<question_dto> questions;

    public:
        // Should take the questions and initialize the session
        // Do select query and get DTO and then make the DTO for each questions and then record all answer of the questions and pass it oto the result class
        Test()
        {
            exec::query_executor->select_query_convert_into_dto("select * from history;");
        }

        /*void take_test() const {
            int score = 0;
            for (const auto& question : questions) {
                question.ask_question();
                char response = question_dto::ask_question_and_get_response();
                if (question.is_correct(response)) {
                    std::cout << "Correct!" << std::endl;
                    score++;
                }
                else {
                    std::cout << "Incorrect!" << std::endl;
                }
            }
            std::cout << "Your score: " << score << " out of " << questions.size() << std::endl;
        }*/
    };
}
