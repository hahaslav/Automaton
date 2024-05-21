#include <iostream>
#include <fstream>
#include <sstream>

#include "Automaton.h"

const std::string CONST_ENDING = "3";

std::string read_file(std::string filename = "input.txt") {
    std::ifstream fin(filename);
    std::stringstream buffer;
    buffer << fin.rdbuf();
    fin.close();

    return buffer.str();
}

Automaton default_automaton() {
    Automaton automaton(3);
    automaton.add_transition(0, 1, '1');
    automaton.add_transition(1, 0, '1');
    automaton.add_transition(1, 2, '2');
    automaton.add_transition(2, 0, '3');
    automaton.mark_state_as_final(0);
    return automaton;
}

void test_automaton(Automaton* automaton, std::string text, bool silent = false) {
    automaton->run(0, text, silent);
    if (silent) {
        return;
    }

    if (automaton->is_broken()) {
        std::cout << "String read failed. Automaton is broken.\n";
    } else if (automaton->at_final_state()) {
        std::cout << "String read succeed.\n";
    } else {
        std::cout << "String read failed.\n";
    }
    std::cout << "\n";
}

int main(int argc, char *argv[]) {
    std::string text;
    if (argc > 1) {
        text = read_file(argv[1]);
    } else {
        text = read_file();
    }

    Automaton automaton = default_automaton();
    test_automaton(&automaton, text, true);
    if (automaton.is_broken() || !automaton.at_final_state()) {
        std::cout << "Warning! The automaton cannot read the initial string.\n\n";
    }

    text += CONST_ENDING;

    automaton = default_automaton();
    test_automaton(&automaton, text);
    return 0;
}
