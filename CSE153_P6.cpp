/*
CSE153 - Program 6
Ross Hamey
7/13/2023
*/

// https://youtu.be/ASqfKPM5hEM - VOD
// (i usually record stuff i make and upload
// it as an unlisted video, just incase i need
// it for future reference / for some reason)

// our include(s)
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    // we first declare our vars that will be modified later
    int lower_bound;
    int upper_bound;
    int i;

    // asking user for inputs and grabbing inputs
    cout << "Please enter the lower bound of your sample population in thousands (1 = 1000, 2 = 2000, etc.): ";
    cin >> lower_bound;
    cout << "Please enter the upper bound of your sample population in thousands (1 = 1000, 2 = 2000, etc.): ";
    cin >> upper_bound;
    // endl for format
    cout << endl;

    // printing out the first header line, with format
    cout << setw(20) << "Population (in thousands)" << setw(20) << "Flowrate" << endl;

    // our for loop that we repeat for all population integers through
    // our lower and upper bounds
    for (i = lower_bound; i <= upper_bound; i++) {
        // we convert our current iterator to a string to count the digits
        // in said iterator, then we use this for formatting later on
        string iterator_to_string = to_string(i);
        int digits = iterator_to_string.length();

        // calculating our flowrate with the provided equation
        double flowrate = (3.86 * sqrt(i) * (1 - 0.01 * sqrt(i)));

        // printing out our line for our population and respective flowrate
        // for each iterator value. we format the spacing according to the
        // number of digits in our iterator value
        cout << setw(12) << "" << resetiosflags(ios::fixed) << i << setw(25 - digits) << "" <<
                resetiosflags(ios::fixed) << flowrate << endl;
    }

    // our ignore / get / return for programs ran in cmd line
    cin.ignore();
    cin.get();
    return 0;
}