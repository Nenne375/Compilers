#include <iostream>
#include <fstream>
#include "Common.h"

std::string Lex(std::ofstream* out, std::string line) {
    int current_pos;

    char current_char, symbol, next_symbol, prev_symbol;

    std::string token, next_token, prev_token;
    
    for(int i = 0; i < line.length(); i++) {
        current_pos = i;
        current_char = line[current_pos];
        if(Regex(current_char) == true) {
            token += current_char;
        } else {
            next_symbol = line[current_pos];
            prev_token = token;
            std::cout << token << std::endl;
            *out << token << std::endl;
            token.clear();
        }
    }
    return token;
}

std::string Parse() {
    return "Hello";
}

int main() {
    std::ifstream in;
    std::ofstream out;
    std::string file;
    std::cin >> file;
    
    in.open(file);
    if (in.fail()) {
        std::cout << "Error: " << file << std::endl;
        exit(1);
    }

    out.open(file.substr(0,file.find_last_of('.')));
    if(in.fail()) {
        std::cout << "Error: " << file.substr(0,file.find_last_of('.')) << std::endl;
        exit(1);
    }
    std::string line;
    
    while(in) {
        line.clear();
        std::getline(in, line);

        //out << line << std::endl;

        Lex(&out, line);
    }

    return 0;
}
