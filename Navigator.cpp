#include "WhateverItTakes"

namespace navigation {
    Navigator::Navigator() : current_step(nullptr) {}

    void Navigator::add_step(const std::string& action) {
        ProgramStep* new_step = new ProgramStep{ action, nullptr, nullptr };
        if (current_step) {
            current_step->next = new_step;
            new_step->prev = current_step;
        }
        current_step = new_step;
    }

    void Navigator::next_step() {
        if (current_step && current_step->next) {
            current_step = current_step->next;
        }
    }

    void Navigator::prev_step() {
        if (current_step && current_step->prev) {
            current_step = current_step->prev;
        }
    }

    void Navigator::execute_current_step() const
    {
        if (current_step) {
            std::cout << "Executing step: " << current_step->action << '\n';
            _getch(); 
        }
    }

    void Navigator::branch(const bool condition, ProgramStep* true_path, ProgramStep* false_path) {
        if (condition) {
            current_step = true_path;
        }
        else {
            current_step = false_path;
        }
    }

    void Navigator::loop(const int iterations, ProgramStep* loop_body) {
        for (int i = 0; i < iterations; ++i) {
            current_step = loop_body;
            while (current_step) {
                execute_current_step();
                current_step = current_step->next;
            }
        }
    }

    void Navigator::execute_if(const bool condition, ProgramStep* step) {
        if (condition) {
            current_step = step;
            execute_current_step();
        }
    }
}
