#include "calculator.hpp"
#include <utility>

bool validateNumber(const std::string &expression) {
    int dotCount = countDots(expression);
    if(dotCount > 1) {
        return false;
    }

    if(!hasValidCharacters(expression)) {
        return false;
    }

    int dotIndex = -1;
    if(dotCount == 1) {
        // Find the dot in the expression
        while(expression[++dotIndex] != '.');
    } else {
        // Just set the index to the end of the string + 1
        dotIndex = expression.length();
    }

    // Make sure there are digits after decimal place
    if(dotCount == 1 && dotIndex == expression.length()-1) {
        return false;
    } 

    // Make sure a '+' or '-' only shows up at beginning
    for(int i = 1; i < expression.length(); i++) {
        if(expression[i] == '+' || expression[i] == '-') {
            return false;
        }
    }

    // Make sure that there is at least one digit
    if((expression[0] == '+' || expression[0] == '+') && expression.length() < 2) {
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


void normalize(std::string &a, std::string &b) {
    // If a not lead with +/-, add a '+' on
    char aSign = '+';
    char bSign = '+';

    // Swap sign to minus if that matches
    if(a[0] == '-') {
        aSign = '-';
    }

    // Swap sign to minus if that matches
    if(b[0] == '-') {
        bSign = '-';
    }

    // If a led with +/-
    if(a[0] == '+' || a[0] == '-') {
        // Remove sign, for now
        a.erase(0, 1);
    }

    // If b led with +/-
    if(b[0] == '+' || b[0] == '-') {
        // Remove sign, for now
        b.erase(0, 1);
    }
    // Start dot indices at end of string, as this is technically where it would
    // be in an integer, Ex: 3. and 4.
    int aDotIndex = a.length();
    int bDotIndex = b.length();
    if(countDots(a) == 1) {
        while(a[--aDotIndex] != '.');
    }
    if(countDots(b) == 1) {
        while(b[--bDotIndex] != '.');
    }

    // Calculate number of digits after decimals place
    int aDecimals = a.length() - (aDotIndex + 1);
    int bDecimals = b.length() - (bDotIndex + 1);

    // Loop and pad each string on the right side with needed zeros
    //      Only one of these two loops runs
    while (aDecimals < bDecimals) {
        a += '0'; 
        aDecimals++;
    }
    while (bDecimals < aDecimals) {
        b += '0'; 
        bDecimals++;
    }

    // Calculate number of digits before decimal place
    int aWholes = aDotIndex - 1; // A-holes? .......
    int bWholes = bDotIndex - 1;

    // Loop and pad each string on the left side with needed zeros
    //      Only one of these two loops runs
    while(aWholes < bWholes) {
        a = '0' + a;
        aWholes++;
    }
    while(bWholes < aWholes) {
        b = '0' + b;
        bWholes++;
    }

    // Add signs back on
    a = aSign + a;
    b = bSign + b;
}
