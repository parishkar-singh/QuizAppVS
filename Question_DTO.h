#pragma once
#include <string>
#include <vector>

#include "Entities.h"

namespace DTO {
    class QuestionDTO : public entities::Question {
    public:
        QuestionDTO(const std::vector<std::string>& data);
        std::vector<std::string> convert_to_vector() const;
        int ask_question_and_get_response() const;
        bool is_correct(char option) const;
    };
}
