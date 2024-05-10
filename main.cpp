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

int main(int argc, char *argv[]) {
    std::string text;
    if (argc > 1) {
        text = read_file(argv[1]);
    } else {
        text = read_file();
    }
    text += CONST_ENDING;

    std::cout << text;
    return 0;
}
