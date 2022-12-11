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
        
        // Validates user input.
        if (!command.argumentsValid()) {
            cout << "You have provided an invalid set of arguments. Please try again." << endl << endl;
            continue;
        }
        
        // Parse commands
        if (command.name == "exit") {
            // Exit the program.
            cout << "Exiting shape manipulator!" << endl;
            break;
        }
        else if (command.name == "addr") {
            cout << "Adding rectangle!" << endl;
            // TODO: Implement "addR" command.
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
            // TODO: Implement "addC" command.
        }
        else if (command.name == "scale") {
            // Move the nth shape in the plane to a given position.
            int index;
            float xMultiplier;
            float yMultiplier;
            if (command.hasArguments(2)) {
                index = stoi(command.arguments.at(0));
                xMultiplier = stof(command.arguments.at(1));
                yMultiplier = xMultiplier;
            }
            else if (command.hasArguments(3)) {
                index = stoi(command.arguments.at(0));
                xMultiplier = stof(command.arguments.at(1));
                yMultiplier = stof(command.arguments.at(2));
            }
            else { continue; }
            plane->scaleShape(index, xMultiplier, yMultiplier);
            cout << "Scaled shape!" << endl;
        }
        else if (command.name == "move") {
            // Move the nth shape in the plane to a given position.
            if (!command.hasArguments(3)) { continue; }
            int index = stoi(command.arguments.at(0));
            float xPos = stof(command.arguments.at(1));
            float yPos = stof(command.arguments.at(2));
            plane->moveShape(index, new Point(xPos, yPos));
            cout << "Moved shape!" << endl;
        }
        else if (command.name == "transform") {
            // Move the nth shape in the plane to a given position.
            if (!command.hasArguments(3)) { continue; }
            int index = stoi(command.arguments.at(0));
            float xOffset = stof(command.arguments.at(1));
            float yOffset = stof(command.arguments.at(2));
            plane->transformShape(index, Point(xOffset, yOffset));
            cout << "Transformed shape!" << endl;
        }
        else if (command.name == "list") {
            plane->printList();
        }
        else if (command.name == "remove") {
            // Remove nth shape from the plane.
            if (!command.hasArguments(1)) { continue; }
            int index = stoi(command.arguments.at(0));
            plane->removeShape(index);
            cout << "Removed shape!" << endl;
        }
        else if (command.name == "clear") {
            plane->clearList();
            cout << "Removed all shapes!" << endl;
        }
        else if (command.name == "info") {
            // Displays information about the nth shape on the plane.
            if (!command.hasArguments(1)) { continue; }
            int index = stoi(command.arguments.at(0));
            cout << plane->getInfo(index) << endl;
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

        // TODO: Perform memory management.
        
        cout << endl;
    }
    delete plane;
    
    return 0;
}


