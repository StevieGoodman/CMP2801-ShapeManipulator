#ifndef ASSESSMENT_2_INPUT_H
#define ASSESSMENT_2_INPUT_H

using namespace std;
#include <string>

class Input {
public:
    /// Prompts user for input and stores case insensitive response in userInput. 
    explicit Input();
    /// Returns the value of private member field _processedInput.
    string getProcessedInput();
private:
    /// Processed case insensitive user input with non-alphanumeric characters removed.
    string _processedInput;
    
    /// Removes non-alphanumeric characters from processedInput.
    void removeCharacters();
    /// Makes processedInput case insensitive.
    void toLowercase();
};

#endif //ASSESSMENT_2_INPUT_H