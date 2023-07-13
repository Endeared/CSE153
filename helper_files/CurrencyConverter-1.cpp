/*
Allows currency to be converted from various types to US dollars.

Author: Jill Courte for CSE 153 Spring, 2016
*/

#include <iostream>
#include <string>


using namespace std;


const int USD = 0;
const int EUR = 1;
const int GBP = 2;
const int INR = 3;
const int AUD = 4;
const int CAD = 5;
const int ZAR = 6;
const int NZD = 7;
const int JPY = 8;


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

	cout << "Enter the number of the desired currency to convert: ";

	cin >> selection;

	return selection;
}

//Converts the numeric type to a String representation.
//Use this to output a String representation of the type.
string convertTypeToString(int type)
{
	switch (type)
	{
	case USD:
		return "US Dollars";

	case EUR:
		return "Euros";

	case GBP:
		return "Great Britan Pounds";

	case INR:
		return "Indian Rupees";

	case AUD:
		return "Australian Dollars";

	case CAD:
		return "Canadian Dollars";

	case ZAR:
		return "South African Rands";

	case NZD:
		return "New Zealand Dollars";

	case JPY:
		return "Japanese Zen";
	}

	return "";
}


int main(int argc, char *argv[])
{

    int userSelection = getUserSelection();
	string selectionAsAString = convertTypeToString(userSelection);
    cout << "You entered " << selectionAsAString << endl;


	cin.ignore();
	cin.get();
}