#ifndef QUIZSET_H
#define QUIZSET_H

#include <string>

namespace Model {
    class QuizSet {
    private:
        int setId;
        std::string setName;
        std::string category;

    public:
        // Public member functions
        int getSetId() const;
        void setSetId(int id);

        std::string getSetName() const;
        void setSetName(const std::string& name);

        std::string getCategory() const;
        void setCategory(const std::string& cat);
    };
}

#endif
