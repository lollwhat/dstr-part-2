#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>


std::string getCurrentTimestamp();
void clearInputBuffer();
bool validateMenuChoice(int& choice, int min, int max);
void displayMenu();

#endif

