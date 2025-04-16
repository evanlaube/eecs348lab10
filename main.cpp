#include <fstream>
#include <iostream>

#include "calculator.hpp"


void processInputFile(std::ifstream &inputFile) {
    std::string line;
    while(std::getline(inputFile, line)) {
        if(!validateNumber(line)) {
            std::cout << "INVALID NUMBER" << std::endl;
            continue;
        }

        std::string addend = "-123.456";
        normalize(line, addend);

        std::cout << add(line, addend) << std::endl;
    }
}

int main() {
    std::cout << "Enter input file name: ";
    std::string fileName;
    std::cin >> fileName;
    
    std::ifstream inputFile(fileName);
    std::string a = "99";
    std::string b = "1";

    if(inputFile.is_open()) {
        processInputFile(inputFile);
    } else {
        std::cerr << "ERROR: Unable to open file: " << fileName << std::endl;
        return 1;
    }
}
