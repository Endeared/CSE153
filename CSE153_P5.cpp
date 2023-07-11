/*
CSE153 - Program 5
Ross Hamey
7/11/2023
*/

// 
// (i usually record stuff i make and upload
// it as an unlisted video, just incase i need
// it for future reference / for some reason.)

// our includes statements
#include <iostream>
#include <string>

using namespace std;

// global constants
const int USD = 0;
const int EUR = 1;
const int GBP = 2;
const int INR = 3;
const int AUD = 4;
const int CAD = 5;
const int ZAR = 6;
const int NZD = 7;
const int JPY = 8;
// added our sentinel value here (9)
const int TERMINATE = 9;

// our global conversion factor var for easy access
double conversion_factor;

// unmodified comment below - i added logic for our
// sentinel value to this provided function
//Outputs a menu of currency types for user, returning a constant value
// as defined above representing the selected currency.
int getUserSelection ()
{
	int selection;

	cout << "Available currencies for conversion: " << endl;

	cout << "(1) Euros" << endl;
	cout << "(2) Great Britan Pounds" << endl;
	cout << "(3) Indian Rupees" << endl;
	cout << "(4) Australian Dollars" << endl;
	cout << "(5) Canadian Dollars" << endl;
	cout << "(6) South African Rands" << endl;
	cout << "(7) New Zealand Dollars" << endl;
	cout << "(8) Japanese Zen" << endl;

    // logic for our sentinel value here
    cout << "(9) End Program" << endl;

	cout << "Enter the number of the desired currency to convert (or 9 to terminate program): ";

	cin >> selection;

    cout << endl;

	return selection;
}

// unmodified comment below - i added conversion_factor
// changes to this function
//Converts the numeric type to a String representation.
//Use this to output a String representation of the type.
string convertTypeToString(int type)
{
	switch (type)
	{
	case USD:
        conversion_factor = 1;
		return "US Dollars";

	case EUR:
        conversion_factor = 1.08611;
		return "Euros";

	case GBP:
        conversion_factor = 1.44476;
		return "Great Britan Pounds";

	case INR:
        conversion_factor = 0.01495;
		return "Indian Rupees";

	case AUD:
        conversion_factor = 0.69864;
		return "Australian Dollars";

	case CAD:
        conversion_factor = 0.70112;
		return "Canadian Dollars";

	case ZAR:
        conversion_factor = 0.05999;
		return "South African Rands";

	case NZD:
        conversion_factor = 0.65371;
		return "New Zealand Dollars";

	case JPY:
        conversion_factor = 0.00850;
		return "Japanese Zen";

    // added terminate case for our sentinel value
    case TERMINATE:
        conversion_factor = 1;
        return "END_PROGRAM";
	}

	return "";
}

// main function
int main(int argc, char *argv[])
{

    // our while loop - we repeatedly work to convert currencies
    // until the user selects 9 (our value to terminate) at the main menu
    while (true) {
        
        // grabbing user selection and determining case for the selection
        // using the provided functions of getUserSelection and convertTypeToString,
        // with slight modifications
        int userSelection = getUserSelection();
        string selectionAsAString = convertTypeToString(userSelection);

        // declaring our doubles for our base input and our usd equivalent
        double base_amount;
        double usd_amount;

        // if selectionAsAString evaluates to "END_PROGRAM", the user selected
        // 9 (our sentinel value) in the main menu, and we break out of our loop
        if (selectionAsAString == "END_PROGRAM") {
            break;
        // otherwise, we provide the user with their selection, and prompt the user
        // for an amount to convert. we grab that amount and do some math to determine
        // our new usd_amount value, then print out the converted amount to the user
        } else {
            cout << "You entered " << selectionAsAString << " as your base currency." << endl;
            cout << "Please input the number of " << selectionAsAString << " to convert to US Dollars: ";
            cin >> base_amount;
            
            usd_amount = conversion_factor * base_amount;

            cout << endl;
            cout << "Based on your provided value of " << base_amount << " " << selectionAsAString <<
                    ", your currency is worth " << usd_amount << " in US Dollars." << endl;
            // endl for formatting
            cout << endl;
        }

        
    }

    // cin.get() for cmd window, and return 0
	cin.ignore();
	cin.get();
    return 0;
}