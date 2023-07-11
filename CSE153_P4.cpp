/*
CSE153 - Program 4
Ross Hamey
7/11/2023
*/

// 
// (i usually record stuff i make and upload
// it as an unlisted video, just incase i need
// it for future reference / for some reason.)

// includes statements
#include <iostream>
#include <string>

using namespace std;

int main()
{
    // declaring our initial vars
    double max_emission;
    int num_of_vehicles;
    int miles_per_car;

    // grabbing our inputs for above vars
    cout << "Please enter the carbon monoxide emission standard (in g/mi): ";
    cin >> max_emission;
    cout << "Please enter the number of vehicles to be tested: ";
    cin >> num_of_vehicles;
    cout << "Please enter the number of miles the vehicles were driven: ";
    cin >> miles_per_car;
    cout << endl;

    // our for loop, we repeat this action the same number of times
    // as our num_of_vehicles int
    for (int i = 0; i < num_of_vehicles; i++) {

        // declaring our input emission var and our vehicle number var
        double emission_recorded;
        string vehicle_num = to_string(i + 1);

        // grabbing the recorded emission for the current vehicle
        cout << "Please enter the total amount of carbon monoxide emitted (in grams) " <<
            "for vehicle no. " << vehicle_num << ": ";
        cin >> emission_recorded;

        // calculating the emission per mile, then comparing it to our max_emission
        // var and responding with the appropriate message
        double emission_per_mile = emission_recorded / miles_per_car;
        if (emission_per_mile > max_emission) {
            cout << "Carbon monoxide emission of " << emission_per_mile << " exceeds permitted emission of " <<
                    max_emission << "." << endl;
        } else if (emission_per_mile <= max_emission) {
            cout << "Carbon monoxide emission of " << emission_per_mile << " meets permitted emission of " <<
                    max_emission << "." << endl;
        }

        // endl for formatting
        cout << endl;
    }
    
    // cin.get() (for cmd window) and then return 0
    cin.get();
    return 0;
}
