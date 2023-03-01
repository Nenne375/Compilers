#pragma once

#include <string>

char Regex(char current_char) {
    bool Bool;
    if ((int(current_char) >= 97 && int(current_char) <= 121) || (int(current_char) >= 65 && int(current_char) <= 90)) {
        Bool = true;
    } else {
        Bool = false;
    }
    return Bool;
}

enum type {
    
};