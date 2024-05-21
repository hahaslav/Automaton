#include <iostream>

#include "Automate.h"

void Automate::create_state() {
    states.push_back(State(states.size()));
}

void Automate::create_states(int n) {
    int i;
    for (i = 0; i < n; i++) {
        create_state();
    }
}

void Automate::run_step(char statement) {
    std::cout << "Got '" << statement << "'. ";
    State* new_state = current_state->get_transition(statement);

    if (new_state == nullptr) {
        break_reset();
        return;
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
    std::cout << "Starting at " << current_state->get_name() << ".\n";

    int i;
    for (i = 0; i < text.size(); i++) {
        std::cout << "Moving from " << current_state->get_name() << ". ";
        run_step(text[i]);
        if (is_broken()) {
            std::cout << "Automate is broken.\n";
            return;
        }
        std::cout << "Transferred into " << current_state->get_name() << ".\n";
    }
}

bool Automate::at_final_state() {
    return current_state->is_final();
}

bool Automate::is_broken() {
    return current_state == nullptr;
}
