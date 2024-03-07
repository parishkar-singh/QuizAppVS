#include "WhateverItTakes"

namespace Model {
    class QuizSet {
    private:
        int setId;
        std::string setName;
        std::string category;

    public:
        // Public member functions
        int getSetId() const { return setId; }
        void setSetId(int id) { setId = id; }

        std::string getSetName() const { return setName; }
        void setSetName(const std::string& name) { setName = name; }

        std::string getCategory() const { return category; }
        void setCategory(const std::string& cat) { category = cat; }
    };
}
