#include <sstream>
#include <iostream>
#include "command.h"
#include "../input/input.h"

Command::Command(const string & input) {
    stringstream stream(input);
    string current_word;
    string command;
    vector<string> arguments;
    while (stream >> current_word) {
        arguments.push_back(current_word);
    }
    this->name = arguments.front();
    arguments.erase(arguments.begin()); // Removes the command from the arguments vector.
    this->arguments = arguments;
}

bool Command::hasArguments(const int count) const {
    const bool validArgumentCount = this->arguments.size() == count;
    if (!validArgumentCount) { 
        cout << "You have not provided the correct amount of arguments. Please try again." << endl << endl; 
    }
    return validArgumentCount;
}

bool Command::argumentsValid() {
    return std::all_of(
    this->arguments.begin(), 
    this->arguments.end(), 
    [](string argument) {
        return std::all_of(
        argument.begin(), 
        argument.end(),
        [](char character){ return isdigit(character) | (character == '-'); });
    });
}