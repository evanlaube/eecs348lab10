#ifndef __CALCULATOR_HPP
#define __CALCULATOR_HPP

#include <string>

// this function should expect that `expression` has already been
// validated and thus throw no exceptions
double parse_number(const std::string &expression);

bool validateNumber(const std::string &expression);

static char validChars[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 
    '+', '-', '.'};
bool hasValidCharacters(const std::string &expression);

int countDots(const std::string &expression);

#endif // __CALCULATOR_HPP
