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

#include <iostream>
#include <string>
#include "src/misc/command/command.h"
#include "src/misc/input/input.h"
#include "src/shapes/shape/shape.h"
#include "src/shapes/circle/circle.h"
#include "src/shapes/rectangle/rectangle.h"
#include "src/shapes/square/square.h"
#include "src/shapes/movable/movable.h"

int main()
{
    cout << "=== SHAPE MANIPULATOR ===" << endl;
    
    while (true) // Repeats the prompt until player exits the program using the "exit" command.
    {
        // Get user input
        Input userInput;
        Command command(userInput.getProcessedInput());
        
        // Parse commands
        if (command.name == "exit") {
            // Exits the program.
            cout << "Exiting shape manipulator!" << endl;
            break;
        }
        else if (command.name == "addr") {
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
        else if (command.name == "adds") {
            cout << "Adding square!" << endl;
//            // get parameters
//            // ...
//            Square* s = new Square(x, y, e);
//            shapes.push_back(s);
//            cout << s->toString();
        }
        else if (command.name == "addc") {
            cout << "Adding circle!" << endl;
//            // get parameters
//            // ...
//            Circle* c = new Circle(x, y, r);
//            shapes.push_back(c);
//            cout << c->toString();
        }
        else if (command.name == "scale") {
            cout << "Scaling shape!" << endl;
            // scale object at index... the scaling needs to be isotropic in case of circle and square 
            // you may want to check if the index exists or not!

            // Multiple inhertitance is tricky! The Shape class does nto have a scale function, the Movable does!
            // As a result all your derived classes have scale functions... 
            // You may need to use type casting wisely to use polymorphic functionality!

        }
        else if (command.name == "move") {
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
        else if (command.name == "display") {
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


