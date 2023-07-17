/*
CSE153 - Program 9
Ross Hamey
7/17/2023
*/

// none of the original provided code has been modified
// (minus the required changes and added comments)

// no vod of program - housesitting for part of this
// week so using laptop instead of desktop for recording,
// and this seemed like a shorter assignment unless i'm
// missing something

// only two changes were made: 1) a second mileage constant was
// added for our boundaries, and 2) an additional if-check was
// added to make sure our odometer is within the acceptable range

/*Program to deterine if a given pollutant emission is within allowable levels.
Author:  Jill Courte for CSE 135, Spring 2015
*/

// include statements
#include <iostream>
#include <string>

// all of our constants defined below for mileage boundaries / pollutant
// options / acceptable emission values
const int FIRST_STAGE_MILEAGE = 50000;
// added second mileage constant for boundaries
const int SECOND_STAGE_MILEAGE = 100000;
const int CARBON_MONOXIDE = 1;
const int HYDROCARBON = 2;
const int NITROGEN_OXIDE = 3;
const int NONMETHANE_HYDROCARBON = 4;

const double CARBON_MONOXIDE_ALLOWED1 = 3.4;
const double CARBON_MONOXIDE_ALLOWED2 = 4.2;

const double HYDROCARBON_ALLOWED1 = 0.31;
const double HYDROCARBON_ALLOWED2 = 0.39;

const double NITROGEN_OXIDE_ALLOWED1 = 0.4;
const double NITROGEN_OXIDE_ALLOWED2= 0.5;

const double NONMETHANE_HYDROCARBON_ALLOWED1 = 0.25;
const double NONMETHANE_HYDROCARBON_ALLOWED2 = 0.31;



using namespace std;

// defining our functions for access later
void outputMenu ();
//function prototypes to get allowable level and determine if within bounds
double getAllowableLevel (double gramsPerMileAllowed1, double gramsPerMileAllowed2, int odometer);



int main (int argc, char *argv[])
{
    // defining our vars to be modified later
	int pollutant;
	double gramsPerMile;
	int odometer;
	bool compliant;
	double allowableGramsPerMile;

    // rendering menu and grabbing inputs from user
	outputMenu();
	cout << "Enter pollutant number: ";
	cin >> pollutant;
	cout << "Enter grams emitted per mile: ";
	cin >> gramsPerMile;
	cout << "Enter odometer reading: ";
	cin >> odometer;

    // checking our pollutant value and comparing it with each of our
    // polutant cases (constants) from earlier, then calling getAllowableLevel
    // with that pollutant's emission vars and assigning it to allowableGramsPerMile
	switch (pollutant)
	{
	case CARBON_MONOXIDE:
		allowableGramsPerMile = getAllowableLevel(CARBON_MONOXIDE_ALLOWED1, CARBON_MONOXIDE_ALLOWED2, odometer);
		break;
	case HYDROCARBON:
        allowableGramsPerMile = getAllowableLevel(HYDROCARBON_ALLOWED1, HYDROCARBON_ALLOWED2, odometer);
		break;
	case NITROGEN_OXIDE:
        allowableGramsPerMile = getAllowableLevel(NITROGEN_OXIDE_ALLOWED1, NITROGEN_OXIDE_ALLOWED2, odometer);
		break;
	case NONMETHANE_HYDROCARBON:
        allowableGramsPerMile = getAllowableLevel(NONMETHANE_HYDROCARBON_ALLOWED1, NONMETHANE_HYDROCARBON_ALLOWED2, odometer);
		break;
	}

    // declaring compliance string, then modifying it if the emission meets
    // the previously modified standards from our getAllowableLevel call
	string compliance;

	compliant = gramsPerMile <= allowableGramsPerMile;
	if (compliant)
	    compliance = "within";
	else
	    compliance = "exceeds";

    // added check to make sure odometer is within allowable range, if our
    // odometer is outside of this range we notify the user, otherwise we
    // notify the user if the emissions are within or exceed standards
    if (odometer > SECOND_STAGE_MILEAGE || odometer < 0) {
        cout << "Mileage " << odometer << " must be within 0-" << SECOND_STAGE_MILEAGE << " miles" << endl;
    } else {
        cout << "Emissions " << compliance << " allowable level of " << allowableGramsPerMile << " grams/mile" << endl;
    }
	
    // cin.ignore and cin.get to freeze program status after main finishes
	cin.ignore();
	cin.get();
}

/*
outputMenu function to render a menu to the user
@return none (void)
*/
void outputMenu ()
{
	cout << "(" << CARBON_MONOXIDE << ") Carbon monoxide" << endl;
	cout << "(" << HYDROCARBON << ") Hydrocarbons" << endl;
	cout << "(" << NITROGEN_OXIDE << ") Nitrogen oxides" << endl;
	cout << "(" << NONMETHANE_HYDROCARBON << ") Non-methane hydrocarbons" << endl;
}

/*
getAllowableLevel function to find the allowable level of emissions for a given
pollutant based off an odometer reading
@param gramsPerMileAllowed1, a double value representing the g/mi of emissions allowed
for a pollutant in an odometer reading less than or equal to FIRST_STAGE_MILEAGE
@param gramsPerMileAllowed2, a double value representing the g/mi of emissions allowed
for a pollutant in an odometer reading greater than FIRST_STAGE_MILEAGE
@param odometer, an int value of the odometer reading (in miles) of the vehicle in
question
@return a double value representing the acceptable emission level for that odometer
reading
*/
//Given an odometer reading, returns the allowable level
double getAllowableLevel (double gramsPerMileAllowed1, double gramsPerMileAllowed2, int odometer)
{
	if (odometer <= FIRST_STAGE_MILEAGE)
	{
		return gramsPerMileAllowed1;
	}
	else
	{
	    return gramsPerMileAllowed2;
	}
}
