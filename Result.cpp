#include "WhateverItTakes"
namespace Model {
    class Result {
    private:
        int resultId;
        int userId;
        int setId;
        int score;

    public:
        // Public member functions
        int getResultId() const { return resultId; }
        void setResultId(int id) { resultId = id; }

        int getUserId() const { return userId; }
        void setUserId(int id) { userId = id; }

        int getSetId() const { return setId; }
        void setSetId(int id) { setId = id; }

        int getScore() const { return score; }
        void setScore(int scr) { score = scr; }
    };
}
