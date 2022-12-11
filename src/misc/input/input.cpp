#include <iostream>
#include <regex>
#include <sstream>
#include "input.h"

Input::Input() {
    cout << "Please type in a command: ";
    getline(cin, this->_processedInput);
    this->removeCharacters();
    this->toLowercase();
}

void Input::toLowercase() {
    string& input =this->_processedInput;
    transform(input.begin(), 
              input.end(), 
              input.begin(),
              [](char character){ return tolower(character); });
}

void Input::removeCharacters() {
    string& input = this->_processedInput;
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