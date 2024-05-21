#include "State.h"

#ifndef SYSLAB2_AUTOMATE_H
#define SYSLAB2_AUTOMATE_H
class Automate {
    std::vector<State> states;
    State* current_state;

    void create_state();

    void create_states(int n);

    void run_step(char statement);

    void break_reset();
public:
    Automate(int n_states);

    void add_transition(int from, int to, char condition);

    void mark_state_as_final(int state_number);

    void run_automate(int starting_state, std::string text);

    bool at_final_state();

    bool is_broken();
};

#endif //SYSLAB2_AUTOMATE_H
