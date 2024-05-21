#include "Automate.h"

void Automate::create_state() {
    states.push_back(State());
}

void Automate::create_states(int n) {
    int i;
    for (i = 0; i < n; i++) {
        create_state();
    }
}

void Automate::break_reset() {
    current_state = nullptr;
}

Automate::Automate(int n_states) {
    create_states(n_states);
}

void Automate::add_transition(int from, int to, char condition) {
    states[from].add_transition(&states[to], condition);
}

void Automate::mark_state_as_final(int state_number) {
    states[state_number].mark_as_final();
}

void Automate::run_automate(int starting_state, std::string text) {
    current_state = &states[starting_state];
}

bool Automate::at_final_state() {
    return current_state->is_final();
}

bool Automate::is_broken() {
    return current_state == nullptr;
}
