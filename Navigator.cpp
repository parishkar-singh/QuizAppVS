#include "WhateverItTakes"

namespace Navigator {
    Navigator::Navigator() : currentStep(nullptr) {}

    void Navigator::addStep(const std::string& action) {
        ProgramStep* newStep = new ProgramStep{ action, nullptr, nullptr };
        if (currentStep) {
            currentStep->next = newStep;
            newStep->prev = currentStep;
        }
        currentStep = newStep;
    }

    void Navigator::nextStep() {
        if (currentStep && currentStep->next) {
            currentStep = currentStep->next;
        }
    }

    void Navigator::prevStep() {
        if (currentStep && currentStep->prev) {
            currentStep = currentStep->prev;
        }
    }

    void Navigator::executeCurrentStep() {
        if (currentStep) {
            std::cout << "Executing step: " << currentStep->action << std::endl;
            _getch(); // Wait for user input to continue
        }
    }

    void Navigator::branch(bool condition, ProgramStep* truePath, ProgramStep* falsePath) {
        if (condition) {
            currentStep = truePath;
        }
        else {
            currentStep = falsePath;
        }
    }

    void Navigator::loop(int iterations, ProgramStep* loopBody) {
        for (int i = 0; i < iterations; ++i) {
            currentStep = loopBody;
            while (currentStep) {
                executeCurrentStep();
                currentStep = currentStep->next;
            }
        }
    }

    void Navigator::executeIf(bool condition, ProgramStep* step) {
        if (condition) {
            currentStep = step;
            executeCurrentStep();
        }
    }
}
