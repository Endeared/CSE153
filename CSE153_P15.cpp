/*
CSE153 - Program 15
Ross Hamey
7/28/2023
*/

// our includes for inputs / vectors
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

// defining our funcs
string grabInputs(vector<string>& names, vector<double>& costs, vector<double>& radii, vector<double>& heights);
int displayMenu(vector<string> names, vector<double> costs, vector<double> radii, vector<double> heights);
int grabOption();
int grabAmount(string part_name);
void displayCost(int amount, string part_name, double cost, double radius, double height);
void exitProgram();

int main()
{   
    // declaring our empty vectors
    vector<string> names;
    vector<double> costs;
    vector<double> radii;
    vector<double> heights;

    // initializing our sentinel vals
    bool grabbing_inputs = true;
    bool display_menu = true;

    // first loop - we repeatedly grab inputs until the user specifies otherwise
    while (grabbing_inputs) {
        // getting user response by calling grabInputs and passing in our vectors
        string more_parts = grabInputs(names, costs, radii, heights);

        // if user inputs 1, we exit out of our first while loop
        if (more_parts != "1") {
            grabbing_inputs = false;
        }
    }

    // second loop - we repeatedly display the menu, grab an option, and show cost
    // until user specifies an exit
    while (display_menu) {
        // grabbing the value for the exit option num by calling displayMenu and
        // passing in our vectors, and grabbing the users option by calling
        // grabOption
        int exit = displayMenu(names, costs, radii, heights);
        int option = grabOption();

        // if our exit val and option val are equal (the user selected exit),
        // then we set our display_menu bool to false and do nothing else
        if (option == exit) {
            display_menu = false;
        // otherwise, we get the vector index for our option (option - 1), and
        // get the amount of parts by calling grabAmount and passing in the part name
        // we then call displayCost to calculate and display the cost by passing in
        // the amount and corresponding values for each vector
        } else {
            int vector_option = option - 1;
            int amount = grabAmount(names[vector_option]);
            displayCost(amount, names[vector_option], costs[vector_option], radii[vector_option], heights[vector_option]);
        }
    }

    // call exitProgram to display end message, then wait for input if ran in cmd
    exitProgram();
    cin.ignore();
    cin.get();
    return 0;
}

/*
grabInputs function, which takes in our ACTUAL vectors (due to referencing them
with '&' and not just getting a copy of the vectors) and grabs values to input
into each vector from the user, then return the users response to the second prompt
@param names, the reference vector of strings representing names
@param costs, the reference vector of doubles representing costs
@param radii, the reference vector of doubles representing radii
@param heights, the reference vector of doubles representing heights
@return more_parts, a string showing the users response to the "more parts" prompt
*/
string grabInputs(vector<string>& names, vector<double>& costs, vector<double>& radii, vector<double>& heights)
{
    // initializing our vars to store data
    string more_parts = "";
    string name = "";
    double cost, radius, height = 0;

    // prompting user for inputs and grabbing inputs
    cout << "Enter the name, cost, radius, and height for a part (example: Part1 5.00 2 2.5): ";
    cin >> name >> cost >> radius >> height;
    cout << "Are there any more parts to enter (enter '1' for yes, anything else for no)? ";
    cin >> more_parts;
    cout << endl;

    // pushing our inputs to their respective vector references
    names.push_back(name);
    costs.push_back(cost);
    radii.push_back(radius);
    heights.push_back(height);

    // returning user response to prompt #2
    return more_parts;
}

/*
displayMenu function, which takes in copies of our vectors and displays their values
as a cleanly formatted menu, and returns the value of the exit option
@param names, a vector copy of strings representing names
@param costs, the vector copy of doubles representing costs
@param radii, the vector copy of doubles representing radii
@param heights, the vector copy of doubles representing heights
@return (i + 1), an int representing the value of the exit option in the menu
*/
int displayMenu(vector<string> names, vector<double> costs, vector<double> radii, vector<double> heights) 
{
    // declaring iterator in this scope, then printing out header for menu
    int i = 0;
    cout << "Options" << endl;

    // iterating up until the size of our vectors, displaying info about
    // each part in a clean format
    for (i; i < names.size(); i++) {
        cout << (i + 1) << ". " << names[i] << " (" << costs[i] << ", " 
                << radii[i] << ", " << heights[i] << ")" << endl;
    }

    // displaying exit option
    cout << (i + 1) << ". Exit" << endl;
    cout << endl;

    // returning value of exit option
    return (i + 1);
}

/*
grabOption function, which prompts the user to select an option from our
menu and then returns the option selected by the user
@return my_option, an int representing the user's selected option
*/
int grabOption()
{
    // initializing option var, then prompting user to select
    // option and storing to to our var, which we return
    int my_option = 0;
    cout << "Select an option: ";
    cin >> my_option;
    return my_option;
}

/*
grabAmount function, which takes in a string representing the name of the part
(based on user's option) and prompts the user to enter the amount of parts to
calculate the cost, then return thats entered amount
@param part_name, a string representing the name of a part
@return my_amount, an int representing the user inputted amount of parts
*/
int grabAmount(string part_name)
{
    // initializing amount var, then prompting user to select number
    // of parts (amount), storing it to our var, then returning that
    // var
    int my_amount = 0;
    cout << "Enter the amount of part " << part_name << " to calculate a cost: ";
    cin >> my_amount;
    cout << endl;

    return my_amount;
}

/*
displayCost function, which takes in an amount, part name, cost, radius, and height,
and calculates the cost of the cylinder part (one open base) and displays it
@param amount, an int representing the number of parts
@param part_name, a string representing the name of the part
@param cost, a double representing the cost of the part per square unit of material
@param radius, a double representing the radius of the part
@param height, a double representing the height of the part
@return none (void)
*/
void displayCost(int amount, string part_name, double cost, double radius, double height)
{
    // declaring value for pi
    double pi = 3.141592653589793238463;

    // doing math to find our total cost (of a cylinder with 2 bases), the cost of a single
    // base, and the cost of our part model (which is a cylinder with only one base)
    double cost_total = cost * amount * ((2 * pi * radius * height) + (2 * pi * (radius * radius)));
    double cost_single_base = cost * amount * ((radius * radius) * pi);
    double cost_final = cost_total - cost_single_base;

    // displaying cost to user
    cout << "Cost of " << amount << " " << part_name << ": " << cost_final << endl;
    cout << endl;
}

/*
exitProgram func, which simply displays a parting message to the user when called
@return none (void)
*/
void exitProgram()
{
    // endl for formatting, then display exit message
    cout << endl;
    cout << "Thanks for using this program! Exiting now." << endl;
}