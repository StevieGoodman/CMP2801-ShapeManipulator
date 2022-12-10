/* ───────────────────────────────────────────────────────────────────────── *\

 # Program Structure
 Classes are separated into implementation and header files.
 You can find them in their respective class directories:
     
    └ src
      ├ misc      → Contains helper classes used to encapsulate functionality.
      │ ├ command   → Used to process a command into a command name and arguments.
      │ └ input     → Used to prompt for and process user input.
      └ shapes    → Contains classes used in directly in shape manipulation.
        ├ plane     → Container for shape objects on a 2D plane.
        ├ shape     → Abstract class from which non-abstract shape classes derive from.
        ├ movable   → Abstract class that provides polymorphism for shape movement.
        ├ point     → Represents a point on a 2D plane.
        ├ square    → A rectangle, but shorter.
        ├ rectangle → A square, but longer.
        └ circle    → A square, but rounder.

 # Grading
 Here's a rundown of where you can find various programming features, for your convenience 😁:

    Lambda Functions   ┬ input::Input::toLowercase()
                       └ plane::Plane::~Plane()
    Functional Prog.   ─ input::Input::toLowercase()
    Abstract Classes   ┬ shape::Shape
                       └ movable::Movable
    Access Modifiers   ─ input::Input
    Memory Manage.     ─ plane::Plane::~Plane()
    Add. Features      ─ main::main()
    Polymorphism       ┬ shape::Shape
                       ├ circle::Circle
                       ├ square::Square
                       └ rectangle::Rectangle
    Overloading        ─ shape::Shape::operator<<()
    Inheritance        ┬ circle::Circle
                       ├ square::Square
                       └ rectangle::Rectangle
    Pointers           ─ plane::Plane::_shapes
 
\* ───────────────────────────────────────────────────────────────────────── */

#include <iostream>
#include <string>
#include "src/misc/command/command.h"
#include "src/misc/input/input.h"
#include "src/shapes/shape/shape.h"
#include "src/shapes/circle/circle.h"
#include "src/shapes/rectangle/rectangle.h"
#include "src/shapes/square/square.h"
#include "src/shapes/movable/movable.h"
#include "src/shapes/plane/plane.h"

int main()
{
    // Display introduction to the user.
    const string INTRO_TEXT = 
            "=== SHAPE MANIPULATOR ==="
            "\nPlease use the \"Help\" command to familiarise yourself.";
    cout << INTRO_TEXT << endl;
    
    auto* plane = new Plane;
    while (true) // Repeats the prompt until player exits the program using the "exit" command.
    {
        // Get user input
        Input userInput;
        Command command(userInput.getProcessedInput());
        
        // Parse commands
        if (command.name == "exit") {
            // Exit the program.
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
            // Add a new square to the 2D plane.
            if (!command.hasArguments(3)) { continue; }
            float xPos = stof(command.arguments.at(0));
            float yPos = stof(command.arguments.at(1));
            float size = stof(command.arguments.at(2));
            auto* newSquare = new Square(new Point(xPos, yPos), size);
            plane->addShape(newSquare);
            cout << "Added square!" << endl;
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
        else if (command.name == "help") {
            const string HELP_OUTPUT =
                    "COMMANDS:"
                    "\n\tAddS [x] [y] [s]     │ Adds a square to position {x, y} with size {s, s}"
                    "\n\tAddR [x] [y] [w] [h] │ Adds a rectangle to position {x, y} with size {w, h}"
                    "\n\tAddC [x] [y] [r]     │ Adds a circle to position {x, y} with radius r"
                    "\n\tRemove [n]           │ Removes the nth shape from the plane"
                    "\n\tClear                │ Clears all shapes from the plane"
                    "\n\tList [n]             │ Lists each shape in the plane, alongside their index & position"
                    "\n\tInfo [n]             │ Displays information about the nth shape in the plane"
                    "\n\tHelp                 │ Displays the full list of commands"
                    "\n\tExit                 │ Quits the program";
            cout << HELP_OUTPUT << endl;
        }
        else {
            cout << "Command not recognised. Please enter a valid command." << endl;
        }

        // do any necessary postprocessing at the end of each loop...
        // yes, there is some necessary postprocessing...
        cout << endl;
    }
    delete plane;
    
    return 0;
}


