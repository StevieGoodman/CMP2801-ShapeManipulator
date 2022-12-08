#ifndef ASSESSMENT_2_COMMAND_H
#define ASSESSMENT_2_COMMAND_H

using namespace std;
#include <string>
#include <vector>

/// Represents a parsed user command, separated into discrete `name` and `arguments` fields.
/// Due to the const nature of its member fields, no getter or setter methods are needed.
class Command {
public:
    /// Identifier for a command.
    string name;
    /// Vector of arguments for the command.
    vector<string> arguments;
    
    /// Creates a new command object from user input. Input is processed and parsed.
    Command(const string& input);
    
    /// Checks that a command object has a given amount of arguments.
    bool hasArguments(int count);
    
    /// Returns true if the command is valid (i.e. if it's not empty).
    bool isValid();
};

#endif //ASSESSMENT_2_COMMAND_H