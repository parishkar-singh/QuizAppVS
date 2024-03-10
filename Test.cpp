#include "WhateverItTakes"

namespace entities {
    class Test {

    private:
        std::vector<question_dto> questions;

    public:
        // Constructor
        Test(const std::vector<question_dto>& questions) : questions(questions) {}

        // Method to take the test
        void take_test() const {
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
        }
    };
}
