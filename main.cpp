/* ───────────────────────────────────────────────────────────────────────── *\

 # Program Structure
 Classes are separated into implementation and header files.
 You can find them in their respective class directories:
     
    └ src
      ├ misc      → Contains helper classes used to encapsulate functionality.
      │ ├ command   → Used to process a command into a command name and arguments.
      │ └ input     → Used to prompt for and process user input.
      └ shapes    → Contains classes used in directly in shape manipulation.
        ├ plane     → Container for shape objects on a 2D plane. Replaces Shape* vector.
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
    
    // Repeat the prompt until player exits the program using the "exit" command.
    while (true) 
    {
        // Get user input
        Input userInput;
        Command command(userInput.getProcessedInput());
        
        // Validates user input.
        if (!command.argumentsValid()) {
            cout << "You have provided an invalid set of arguments. Please try again." << endl << endl;
            continue;
        }
        
        // Run commands.
        string commandName = command.getName();
        vector<string> arguments = command.getArguments();
        
        if (commandName == "exit") {
            // Exit the program.
            cout << "Exiting shape manipulator!" << endl;
            break;
        }
        
        else if (commandName == "addr") {
            // Add a new rectangle to the 2D plane.
            if (!command.hasArguments(4)) { continue; }
            float xPos = stof(arguments.at(0));
            float yPos = stof(arguments.at(1));
            float width = abs(stof(arguments.at(2)));
            float height = abs(stof(arguments.at(3)));
            auto* newRectangle = new Rectangle(new Point(xPos, yPos), height, width);
            plane->addShape(newRectangle);
            cout << "Added rectangle!" << endl;
        }
        
        else if (commandName == "adds") {
            // Add a new square to the 2D plane.
            if (!command.hasArguments(3)) { continue; }
            float xPos = stof(arguments.at(0));
            float yPos = stof(arguments.at(1));
            float size = abs(stof(arguments.at(2)));
            auto* newSquare = new Square(new Point(xPos, yPos), size);
            plane->addShape(newSquare);
            cout << "Added square!" << endl;
        }
        
        else if (commandName == "addc") {
            // Add a new circle to the 2D plane.
            if (!command.hasArguments(3)) { continue; }
            float xPos = stof(arguments.at(0));
            float yPos = stof(arguments.at(1));
            float size = abs(stof(arguments.at(2)));
            auto* newCircle = new Circle(new Point(xPos, yPos), size);
            plane->addShape(newCircle);
            cout << "Added circle!" << endl;
        }
        
        else if (commandName == "scale") {
            // Move the nth shape in the plane to a given position.
            int index;
            float xMultiplier;
            float yMultiplier;
            if (command.hasArguments(2)) {
                index = stoi(arguments.at(0));
                xMultiplier = abs(stof(arguments.at(1)));
                plane->scaleShape(index, xMultiplier);
            }
            else if (command.hasArguments(3)) {
                index = stoi(arguments.at(0));
                xMultiplier = abs(stof(arguments.at(1)));
                yMultiplier = abs(stof(arguments.at(2)));
                plane->scaleShape(index, xMultiplier, yMultiplier);
            }
            else { continue; }
            cout << "Scaled shape!" << endl;
        }
        
        else if (commandName == "move") {
            // Move the nth shape in the plane to a given position.
            if (!command.hasArguments(3)) { continue; }
            int index = stoi(arguments.at(0));
            float xPos = stof(arguments.at(1));
            float yPos = stof(arguments.at(2));
            plane->moveShape(index, new Point(xPos, yPos));
            cout << "Moved shape!" << endl;
        }
        
        else if (commandName == "transform") {
            // Move the nth shape in the plane to a given position.
            if (!command.hasArguments(3)) { continue; }
            int index = stoi(arguments.at(0));
            float xOffset = stof(arguments.at(1));
            float yOffset = stof(arguments.at(2));
            plane->transformShape(index, Point(xOffset, yOffset));
            cout << "Transformed shape!" << endl;
        }
        
        else if (commandName == "list") {
            plane->printList();
        }
        
        else if (commandName == "remove") {
            // Remove nth shape from the plane.
            if (!command.hasArguments(1)) { continue; }
            int index = stoi(arguments.at(0));
            plane->removeShape(index);
            cout << "Removed shape!" << endl;
        }
        
        else if (commandName == "clear") {
            // Clear all shapes from the plane.
            plane->clearList();
            cout << "Removed all shapes!" << endl;
        }
        
        else if (commandName == "info") {
            // Display information about the nth shape on the plane.
            if (!command.hasArguments(1)) { continue; }
            int index = stoi(arguments.at(0));
            cout << plane->getInfo(index) << endl;
        }
        
        else if (commandName == "help") {
            // Display list of commands.
            const string HELP_OUTPUT =
                    "COMMANDS:"
                    "\n\tAddS [x] [y] [s]      │ Adds a square to position {x, y} with size {s, s}"
                    "\n\tAddR [x] [y] [w] [h]  │ Adds a rectangle to position {x, y} with size {w, h}"
                    "\n\tAddC [x] [y] [r]      │ Adds a circle to position {x, y} with radius r"
                    "\n\tMove [n] [x] [y]      │ Moves the nth shape to position {x, y}"
                    "\n\tTransform [n] [x] [y] │ Offsets the nth shape's position by {x, y}"
                    "\n\tRemove [n]            │ Removes the nth shape from the plane"
                    "\n\tClear                 │ Clears all shapes from the plane"
                    "\n\tList                  │ Lists each shape in the plane, alongside their index & position"
                    "\n\tInfo [n]              │ Displays information about the nth shape in the plane"
                    "\n\tHelp                  │ Displays the full list of commands"
                    "\n\tExit                  │ Quits the program"
                    "\nAll input is case insensitive and is fully validated.";
            cout << HELP_OUTPUT << endl;
        }
        
        else {
            cout << "Command not recognised. Please enter a valid command." << endl;
        }
        
        cout << endl;
    }
    delete plane;
    
    return 0;
}


