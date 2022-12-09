#include <sstream>
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

bool Command::hasArguments(const int count) {
    return this->arguments.size() == count;
}

bool Command::isValid() {
    return this->name.empty();
}