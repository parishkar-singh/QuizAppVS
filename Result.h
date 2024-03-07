#pragma once
#ifndef RESULT_H
#define RESULT_H

namespace Model {
    class Result {
    private:
        int resultId;
        int userId;
        int setId;
        int score;

    public:
        // Public member functions
        int getResultId() const;
        void setResultId(int id);

        int getUserId() const;
        void setUserId(int id);

        int getSetId() const;
        void setSetId(int id);

        int getScore() const;
        void setScore(int scr);
    };
}

#endif
