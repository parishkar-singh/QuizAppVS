#pragma once
#include <string>
#include <vector>

#include "Entities.h"

namespace DTO {
    class QuestionDTO : public entities::Question {
    private:
        int question_id;
        std::string question_text;
        std::string option_a;
        std::string option_b;
        std::string option_c;
        std::string option_d;
        char correct_option;
    public:
        QuestionDTO(const std::vector<std::string>& data);
        std::vector<std::string> convert_to_vector() const;
        int ask_question_and_get_response() const;
        bool is_correct(char option) const;
    };
}
