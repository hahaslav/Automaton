#include "State.h"

#ifndef SYSLAB2_AUTOMATON_H
#define SYSLAB2_AUTOMATON_H
class Automaton {
    std::vector<State> states;
    State* current_state;

    void create_state();

    void create_states(int n);

    void run_step(char statement, bool silent);

    void break_reset();
public:
    Automaton(int n_states);

    void add_transition(int from, int to, char condition);

    void mark_state_as_final(int state_number);

    void run(int starting_state, std::string text, bool silent);

    bool at_final_state();

    bool is_broken();
};

#endif //SYSLAB2_AUTOMATON_H
