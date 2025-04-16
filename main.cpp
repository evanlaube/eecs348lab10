#include <fstream>
#include <iostream>

#include "calculator.hpp"


void processInputFile(std::ifstream &inputFile) {
    std::string line;
    while(std::getline(inputFile, line)) {
        if(validateNumber(line)) {
            std::cout << "VALID" << std::endl;
        } else {
            std::cout << "NOT VALID" << std::endl;
        }
    }
}

int main() {
    std::cout << "Enter input file name: ";
    std::string fileName;
    std::cin >> fileName;
    
    std::ifstream inputFile(fileName);

    if(inputFile.is_open()) {
        processInputFile(inputFile);
    } else {
        std::cerr << "ERROR: Unable to open file: " << fileName << std::endl;
        return 1;
    }
}
