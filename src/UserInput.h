#ifndef ASSESSMENT_2_USERINPUT_H
#define ASSESSMENT_2_USERINPUT_H

using namespace std;
#include <string>

class UserInput {
public:
    /// Prompts user for input and stores case insensitive response in userInput. 
    explicit UserInput();
    /// Returns the value of private member field _processedInput.
    string getProcessedInput();
private:
    /// Processed case insensitive user input with non-alphanumeric characters removed.
    string _processedInput;
    
    /// Removes non-alphanumeric characters from processedInput.
    void removeCharacters(string & input);
    /// Makes processedInput case insensitive.
    void toLowercase(string & input);
};

#endif //ASSESSMENT_2_USERINPUT_H