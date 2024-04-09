// parse.cpp

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#include "../include/main.h"

// Check if a string is just whitespace.
bool is_whitespace(std::string& s) {
  return std::all_of(s.begin(), s.end(), isspace);
}

// Prompt the user with dialogue and put their answer in a buffer string.
void prompt(std::string dialogue, std::string& buffer) {
    for (;;) { 
        while (std::cout << dialogue && !std::getline(std::cin, buffer)) {
                std::cin.clear();
                std::cin.ignore(1000, '\n');

                std::cout << "Please enter a valid input." << std::endl;
            }

        if (is_whitespace(buffer)) {
            std::cout << "Blank inputs are not allowed." << std::endl;

            buffer.clear();
            continue;
        }

        break;
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

// Make all characters in a string uppercase.
std::string upper(std::string str) {
    std::transform(str.begin(), str.end(), 
        str.begin(), ::toupper);
    
    return str;
}