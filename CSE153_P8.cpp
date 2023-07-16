/*
CSE153 - Program 8
Ross Hamey
7/16/2023
*/

// 
// (i usually record stuff i make and upload
// it as an unlisted video, just incase i need
// it for future reference / for some reason)

// our includes - we need iomanip for our cout and
// math.h for exponents
#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

// declaring our helper function for later
double widthAtTemperature(double width_at_standard, double temperature);

int main()
{
    // declaring our initial vars
    double standard;
    double current_temp;
    double tolerance;

    // grabbing our inputs for our standard and tolerance vars from
    // the user
    cout << "Please input the bar width at 70 degrees Fahrenheit: ";
    cin >> standard;
    cout << "Please input the tolerance for variation of bar width: ";
    cin >> tolerance;

    // outputting our first 2 header lines in our chart
    cout << setw(20) << "Temperature" << setw(20) << "Width" << endl;
    cout << setw(20) << "(degrees F)" << setw(20) << "(cm)" << endl;;

    // getting the max width and min width for our bar
    double max = standard + tolerance;
    double min = standard - tolerance;

    // our for loop, we iterate through 60-85
    for (int i = 60; i <= 85; i++) {
        // we assign the iterator as a double, then call our widthAtTemperature
        // function using our standard and iterator_double values, declaring it
        // to our current_width var
        double iterator_double = i;
        double current_width = widthAtTemperature(standard, iterator_double);

        // lastly, we print out the current temp and the width of the bar at each
        // temp between 60-85 in a clean format, setting the precision of our
        // width to 5
        cout << setw(13) << "" << resetiosflags(ios::fixed) << i << setw(26) <<
                setprecision(5) << fixed << current_width;
        // if our width value is between the acceptable min and max range from
        // earlier, we mark that line with an asterisk
        if (current_width <= max && current_width >= min) {
            cout << "  *";
        }
        // endl for formatting
        cout << endl;
    }

    // cin.ignore and cin.get so window persists after main is done
    cin.ignore();
    cin.get();
    return 0;
}

/*
widthAtTemperature function, which takes in a standard width and a temp value to
determine the current width of a bar (namely aluminum)
@param width_at_standard, a double representing the standard width @ 70 degrees Fahrenheit
@param temperature, a double representing the current temperature
@return new_width, a double representing the width of the bar at the current temperature
*/
double widthAtTemperature(double width_at_standard, double temperature)
{
    // calculating new_width from our formula for aluminum, then returning our
    // new_width
    double new_width = width_at_standard + (temperature - 70) * (pow(10, -4));
    return new_width;
}