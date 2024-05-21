#include "State.h"

State::State() {}

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
