/* ------------------------------------------------------
CMP2801M: Advanced Programming
Driver program for assignment 
Fall 2019

Written by Ayse Kucukyilmaz

This file is a representative test file. 
During marking, we will use the exact same notation 
as provided in the brief, so make sure
you follow that guideline. Also make sure that you don't 
change the main body provided to you here.
Otherwise, your code may not pass the test cases...

GOOD LUCK! 

------------------------------------------------------ */

using namespace std;


#include <iostream>
#include <sstream>
#include <string>
#include <vector>
//#include "Shape.h"
//#include "Circle.h"
//#include "Rectangle.h"
//#include "Square.h"
//#include "Movable.h"


/// Takes a string and parses it into a command and command arguments. 
/// Returns a tuple, with the first element being the command, and the second being the vector of arguments.
tuple<string, vector<string>> tokenize(const string &userCommand) {
    tuple<string, vector<string>> result;
    stringstream stream(userCommand);
    string current_word;
    string command;
    vector<string> arguments;
    while (stream >> current_word) {
        arguments.push_back(current_word);
    }
    command = arguments.front();
    arguments.erase(arguments.begin()); // Removes the command from the arguments vector.
    return make_tuple(command, arguments);
}

/// Prompts user for a command and returns the user's case insensitive input.
/// Tags: lambda functions, functional programming
string &getCommand(string &userCommand) {
    cout << "Please type in your command: ";
    getline(cin, userCommand);
    transform(userCommand.begin(), userCommand.end(), userCommand.begin(), 
              [](char character){ return tolower(character); });
    return userCommand;
}

int main()
{
    cout << "=== SHAPE MANIPULATOR ===" << endl;
    
    while (true) // Repeats the prompt until player exits the program using the "exit" command.
    {
        // Get user input
        string userCommand = getCommand(userCommand);
        tuple<string, vector<string>> token_tuple = tokenize(userCommand);
        string command           = get<0>(token_tuple);
        vector<string> arguments = get<1>(token_tuple);
        
        // Parse commands
        if (command == "exit") {
            // Exits the program.
            cout << "Exiting shape manipulator!" << endl;
            break;
        }
        else if (command == "addr") {
            cout << "Adding rectangle!" << endl;
//            // get parameters in the correct order
//            // The following four lines have a type mismatch error
//            // note that the parameters vector contains ascii values
//            // HINT: stoi function converts from string to int
//
//            x = parameters[1].c_str(); // fix me! also note that x is not previously defined :(
//            // int y = ...
//            // int h = ...
//            // int w = ...
//
//
//            Rectangle* r = new Rectangle(x, y, h, w);
//            shapes.push_back(r);
//            cout << r->toString(); /* instead of this, you may implement operator overloadig and 
//									use cout << r which will give you additional points */
        }
        else if (command == "adds") {
            cout << "Adding square!" << endl;
//            // get parameters
//            // ...
//            Square* s = new Square(x, y, e);
//            shapes.push_back(s);
//            cout << s->toString();
        }
        else if (command == "addc") {
            cout << "Adding circle!" << endl;
//            // get parameters
//            // ...
//            Circle* c = new Circle(x, y, r);
//            shapes.push_back(c);
//            cout << c->toString();
        }
        else if (command == "scale") {
            cout << "Scaling shape!" << endl;
            // scale object at index... the scaling needs to be isotropic in case of circle and square 
            // you may want to check if the index exists or not!

            // Multiple inhertitance is tricky! The Shape class does nto have a scale function, the Movable does!
            // As a result all your derived classes have scale functions... 
            // You may need to use type casting wisely to use polymorphic functionality!

        }
        else if (command == "move") {
            cout << "Moving shape!" << endl;
//            // move object at index 
//            int shapeNo; // read from parameters
//            // you may want to check if the index exists or not!
//
//            // Study the following code. A Shape object is not Movable, but all derived classes are...
//            // you can't automatically type cast from a Shape to a Movable, but you can force a downcasting
//            Movable *m = dynamic_cast<Movable*>(shapes[shapeNo - 1]);
//            m->move(x, y);
//            // scale should work similarly...
//
//            // note that here you should see the corresponding toString output for the derived classes...
//            // if toString is not a virtual function, you may see the base class functionality :(
//            cout << shapes[shapeNo - 1]->toString();
        }
        else if (command == "display") {
            cout << "Displaying list of shapes!" << endl;
            // this is not given in our example, but why don't you implement a display function which shows all objects stored in shapes?
        }
        else {
            cout << "Command not recognised. Please enter a valid command." << endl;
        }

        // do any necessary postprocessing at the end of each loop...
        // yes, there is some necessary postprocessing...
        cout << endl;
    }
    
    return 0;
}


