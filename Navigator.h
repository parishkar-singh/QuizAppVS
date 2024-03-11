#ifndef NAVIGATOR_H
#define NAVIGATOR_H


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
