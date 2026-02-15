#pragma once
#include <string>

inline void printMenu() {
    std::cout << "\nDocHelper CLI Menu:\n";
    std::cout << "1. Add document\n";
    std::cout << "2. List documents\n";
    std::cout << "3. Search by tag\n";
    std::cout << "0. Exit\n";
    std::cout << "Enter choice: ";
}

inline std::string input(const std::string& prompt) {
    std::cout << prompt;
    std::string value;
    std::getline(std::cin, value);
    return value;
}
