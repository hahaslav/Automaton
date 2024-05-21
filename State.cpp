#include "State.h"

State::State(unsigned long long n) {
    name = "S" + std::to_string(n);
}

void State::add_transition(State* to, char condition) {
    conditions.push_back(condition);
    transitions.push_back(to);
}

void State::mark_as_final() {
    final = true;
}

bool State::is_final() {
    return final;
}

State* State::get_transition(char condition) {
    return transitions[0];
}

std::string State::get_name() {
    return name;
}