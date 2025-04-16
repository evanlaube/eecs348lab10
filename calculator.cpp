#include "calculator.hpp"

bool validateNumber(const std::string &expression) {
    if(countDots(expression) > 1) {
        return false;
    }

    if(!hasValidCharacters(expression)) {
        return false;
    }

    return true;
}

bool hasValidCharacters(const std::string &expression) {
    for(int i = 0; i < expression.length(); i++) {
        char c = expression[i];
        bool isValid = false;
        for(int n = 0; n < sizeof(validChars) / sizeof(char); n++) {
            if(c == validChars[n]) {
                isValid = true;
                break;
            }
        }
        if(!isValid) {
            return false;
        }
    }

    return true;
}

int countDots(const std::string &expression) {
    int dotCount = 0;
    for(int i = 0; i < expression.length(); i++) {
        if(expression[i] == '.') {
            dotCount++;
        }
    }
    return dotCount;
}
