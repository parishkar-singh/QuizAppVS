#ifndef NAVIGATOR_H
#define NAVIGATOR_H

/// <summary>
/// 1.This is mainly responsible for traversing thru the application
/// 2.Data structure used is doubly linked list and the main benifit is backward and forward traversing.
/// 3. Name of the functions are self explanatory.
/// 4. There's also support for loop and execute_if help full in case of the authentication screen.
/// </summary>

namespace navigation {
    struct ProgramStep {
        std::string action;
        ProgramStep* prev;
        ProgramStep* next;
    };

    class Navigator {
    private:
        ProgramStep* current_step;

    public:
        Navigator();

        void add_step(const std::string& action);
        void next_step();
        void prev_step();
        void execute_current_step() const;
        void branch(bool condition, ProgramStep* true_path, ProgramStep* false_path);
        void loop(int iterations, ProgramStep* loop_body);
        void execute_if(bool condition, ProgramStep* step);
    };
}

#endif // NAVIGATOR_H
