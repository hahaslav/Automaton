#include <vector>

#ifndef SYSLAB2_STATE_H
#define SYSLAB2_STATE_H
class State {
    bool final = false;
    std::vector<char> conditions;
    std::vector<State*> transitions;
public:
    State();

    void add_transition(State* to, char condition);

    void mark_as_final();

    bool is_final();
};

#endif //SYSLAB2_STATE_H
