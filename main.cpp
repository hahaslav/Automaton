#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

const std::string CONST_ENDING = "23";

std::string read_file(std::string filename = "input.txt") {
    std::ifstream fin(filename);
    std::stringstream buffer;
    buffer << fin.rdbuf();
    fin.close();

    return buffer.str();
}

bool simple_automate(std::string text) {
    int i;
    bool ending_state;
    for (i = 0; i < text.size(); i++) {
        ending_state = false;
        if (i % 3 == 0) {
            if (text[i] != '1') {
                break;
            }
        } else if (i % 3 == 1) {
            if (text[i] != '2') {
                break;
            }
        } else if (i % 3 == 2) {
            if (text[i] != '3') {
                break;
            } else {
                ending_state = true;
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
        std::cout << "String read successfully";
    } else {
        std::cout << "String read failed";
    }
    return 0;
}
