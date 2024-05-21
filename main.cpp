#include <iostream>
#include <fstream>
#include <sstream>

#include "Automate.h"

const std::string CONST_ENDING = "3";

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

Automate default_automate() {
    Automate automate(3);
    automate.add_transition(0, 1, '1');
    automate.add_transition(1, 0, '1');
    automate.add_transition(1, 2, '2');
    automate.add_transition(2, 0, '3');
    automate.mark_state_as_final(0);
    return automate;
}

void test_automate(Automate* automate, std::string text, bool silent = false) {
    automate->run_automate(0, text, silent);
    if (silent) {
        return;
    }

    if (automate->is_broken()) {
        std::cout << "String read failed. Automate is broken.\n";
    } else if (automate->at_final_state()) {
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

    Automate automate = default_automate();
    test_automate(&automate, text, true);
    if (automate.is_broken() || !automate.at_final_state()) {
        std::cout << "Warning! The automate cannot read the initial string.\n\n";
    }

    text += CONST_ENDING;

    if (simple_automate(text)) {
        std::cout << "String read succeed.\n\n";
    } else {
        std::cout << "String read failed.\n\n";
    }
    automate = default_automate();
    test_automate(&automate, text);
    return 0;
}
