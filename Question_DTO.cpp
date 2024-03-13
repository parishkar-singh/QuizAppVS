#include "WhateverItTakes"

namespace DTO {

    QuestionDTO::QuestionDTO(const std::vector<std::string>& data) {
        if (data.size() < 7) {
            throw std::invalid_argument("Insufficient data provided for QuestionDTO");
        }

        question_id = std::stoi(data[0]);
        question_text = data[1];
        option_a = data[2];
        option_b = data[3];
        option_c = data[4];
        option_d = data[5];
        correct_option = data[6][0];
    }

    std::vector<std::string> QuestionDTO::convert_to_vector() const {
        return { option_a, option_b, option_c, option_d };
    }

    int QuestionDTO::ask_question_and_get_response() const {
        return 1; 
    }

    bool QuestionDTO::is_correct(char option) const {
        return std::toupper(option) == std::toupper(correct_option);
    }

}
