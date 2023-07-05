/*
CSE153 - Program 2
Ross Hamey
7/5/2023
*/

// our include
#include <iostream>

using namespace std;

int main()
{

    // bools for both parts, just so i can separate them
    // easier in the source code
    bool part_A = true;
    bool part_B = true;

    // logic for part A
    if (part_A) {
        // declaring our values of length / width for each rectangle
        int length_one;
        int width_one;
        int length_two;
        int width_two;

        // grabbing inputs for the dimensions of our first rectangle
        cout << "Please enter the length (as a whole number) of your FIRST rectangle:" << endl;
        cin >> length_one;
        cout << "Please enter the width (as a whole number) of your FIRST rectangle:" << endl;
        cin >> width_one;

        // grabbing inputs for the dimensions of our second rectangle
        cout << "Please enter the length (as a whole number) of your SECOND rectangle:" << endl;
        cin >> length_two;
        cout << "Please enter the width (as a whole number) of your SECOND rectangle:" << endl;
        cin >> width_two;
        cout << endl;

        // declaring our area values for each rectangles, which we get
        // by multiplying the length and width of each rectangle's inputs,
        // respectively
        int area_one = length_one * width_one;
        int area_two = length_two * width_two;

        // we check if the two area values are equal. if they are, we return
        // a message appropriately and the area, otherwise, we return a message
        // showing that they are not equal which includes their areas
        if (area_one == area_two) {
            cout << "These two rectangles DO have an equal area. The area of each triangle is " << area_one << " units" << endl;
        } else {
            cout << "These two rectangles DO NOT have an equal area. The area of the first rectangle is "
                    << area_one << " units, while the area of the second rectangle is " << area_two << " units." << endl;;
        }
        // endl for format
        cout << endl;
    }

    // logic for part B
    if (part_B) {
        // declaring our variable to store the input pH value
        int this_ph;

        // grabbing pH value from user
        cout << "Please enter a pH value to grab the description of:" << endl;
        cin >> this_ph;

        // our conditionals. in order, we check if the value is outside of
        // the pH range and return a message appropriately.
        if (this_ph < 0 || this_ph > 14) {
            cout << "Your provided pH value is outside of the pH range!" << endl;
        } else if (this_ph < 3) {
            cout << "The solution is very acidic." << endl;
        } else if (this_ph < 7) {
            cout << "The solution is acidic." << endl;
        } else if (this_ph == 7) {
            cout << "The solution is neutral." << endl;
        } else if (this_ph < 12) {
            cout << "The solution is alkaline / basic." << endl;
        } else if (this_ph <= 14) {
            cout << "The solution is very alkaline / basic." << endl;
        }
        // new line for formatting
        cout << endl;
    }

    // wait for user to press enter at the end so they can see our messsages
    // in cmd line, then return 0
    cin.get();
    return 0;
}