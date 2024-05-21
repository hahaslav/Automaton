#include <string>
#include <vector>

#ifndef SYSLAB2_STATE_H
#define SYSLAB2_STATE_H
class State {
    bool final = false;
    std::string name;
    std::vector<char> conditions;
    std::vector<State*> transitions;
public:
    State(unsigned long long n);

    void add_transition(State* to, char condition);

    void mark_as_final();

    bool is_final();

    State* get_transition(char condition);

    std::string get_name();
};

#endif //SYSLAB2_STATE_H
