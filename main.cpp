#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

const std::string CONST_ENDING = "23";

class State {
    bool final = false;
    std::vector<char> conditions;
    std::vector<State*> transitions;
public:
    State() {}

    void mark_as_final() {
        final = true;
    }

    bool is_final() {
        return final;
    }
};

class Automate {
    std::vector<State> states;
    State* current_state;

    void create_state() {
        states.push_back(State());
    }

    void create_states(int n) {
        int i;
        for (i = 0; i < n; i++) {
            create_state();
        }
    }

    void break_reset() {
        current_state = nullptr;
    }
public:
    Automate(int n_states) {
        create_states(n_states);
    }

    void mark_state_as_final(int state_number) {
        states[state_number].mark_as_final();
    }

    void run_automate(int starting_state, std::string text) {
        current_state = &states[starting_state];
    }

    bool at_final_state() {
        return current_state->is_final();
    }

    bool is_broken() {
        return current_state == nullptr;
    }
};

std::string read_file(std::string filename = "input.txt") {
    std::ifstream fin(filename);
    std::stringstream buffer;
    buffer << fin.rdbuf();
    fin.close();

    return buffer.str();
}

bool simple_automate(std::string text) {
    int i, state = 0;
    bool ending_state;
    for (i = 0; i < text.size(); i++) {
        ending_state = false;
        if (state % 3 == 0) {
            if (text[i] == '1') {
                state = 1;
                continue;
            } else {
                break;
            }
        } else if (state % 3 == 1) {
            if (text[i] == '1') {
                state = 0;
                continue;
            } else if (text[i] == '2') {
                state = 2;
                continue;
            } else {
                break;
            }
        } else if (state % 3 == 2) {
            if (text[i] == '3') {
                state = 0;
                ending_state = true;
                continue;
            } else {
                break;
            }
        }
    }

    return ending_state;
}

int main(int argc, char *argv[]) {
    std::string text;
    if (argc > 1) {
        text = read_file(argv[1]);
    } else {
        text = read_file();
    }
    text += CONST_ENDING;

    std::cout << text << "\n";
    if (simple_automate(text)) {
        std::cout << "String read successfully.\n";
    } else {
        std::cout << "String read failed.\n";
    }

    Automate automate(3);
    automate.mark_state_as_final(0);
    automate.run_automate(0, text);
    if (automate.is_broken()) {
        std::cout << "String read failed. Automate is broken.\n";
    } else if (automate.at_final_state()) {
        std::cout << "String read successfully.\n";
    } else {
        std::cout << "String read failed.\n";
    }

    return 0;
}
