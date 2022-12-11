#include <iostream>
#include <regex>
#include <sstream>
#include "input.h"

Input::Input() {
    cout << "Please type in a command: ";
    string userInput;
    getline(cin, userInput);
    removeCharacters(userInput);
    toLowercase(userInput);
    this->_processedInput = userInput;
}

void Input::toLowercase(string &input) {
    transform(input.begin(), 
              input.end(), 
              input.begin(),
              [](char character){ return tolower(character); });
}

void Input::removeCharacters(string &input) {
    stringstream output;
    regex_replace(
            std::ostreambuf_iterator<char>(output), 
            input.begin(), 
            input.end(), 
            regex("[^a-zA-Z0-9. -]"), 
            "");
    input = output.str();
}

string Input::getProcessedInput() {
    return this->_processedInput;
}