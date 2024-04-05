// parse.cpp

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#include "../include/main.h"

// Prompt the user with dialogue and put their answer in a buffer string.
void prompt(std::string dialogue, std::string& buffer) {
    while (std::cout << dialogue && !std::getline(std::cin, buffer)) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');

        std::cout << "Please enter a valid input." << std::endl;
    }
}

// Convert a string into an integer.
int str_to_int(std::string str) {

    for (int i = 0; i < str.length(); i++) {
        if (isdigit(str.at(i)) == 0) {
            std::cout << "Input must be an integer number." << std::endl;
            return 0;
        }
    }

    return std::stoi(str);
}

std::string upper(std::string str) {
    std::transform(str.begin(), str.end(), 
        str.begin(), ::toupper);
    
    return str;
}