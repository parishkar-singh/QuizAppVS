#ifndef NAVIGATOR_H
#define NAVIGATOR_H

#include <iostream>

namespace Navigator {
    struct ProgramStep {
        std::string action;
        ProgramStep* prev;
        ProgramStep* next;
    };

    class Navigator {
    private:
        ProgramStep* currentStep;

    public:
        Navigator();

        void addStep(const std::string& action);
        void nextStep();
        void prevStep();
        void executeCurrentStep();
        void branch(bool condition, ProgramStep* truePath, ProgramStep* falsePath);
        void loop(int iterations, ProgramStep* loopBody);
        void executeIf(bool condition, ProgramStep* step);
    };
}

#endif // NAVIGATOR_H
