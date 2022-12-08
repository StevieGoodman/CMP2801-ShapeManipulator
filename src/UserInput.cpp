using namespace std;
#include <iostream>
#include <regex>
#include <sstream>
#include "UserInput.h"

UserInput::UserInput() {
    cout << "Please type in a command: ";
    string userInput;
    getline(cin, userInput);
    removeCharacters(userInput);
    toLowercase(userInput);
    this->_processedInput = userInput;
}

void UserInput::toLowercase(string &input) {
    transform(input.begin(), 
              input.end(), 
              input.begin(),
              [](char character){ return tolower(character); });
}

void UserInput::removeCharacters(string &input) {
    stringstream output;
    regex_replace(
            std::ostreambuf_iterator<char>(output), 
            input.begin(), 
            input.end(), 
            regex("[^a-zA-Z0-9 ]"), 
            "");
    input = output.str();
}

string UserInput::getProcessedInput() {
    return this->_processedInput;
}