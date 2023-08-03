/*
CSE153 - Program 17
Ross Hamey
8/3/2023
*/

// the following changes were made to the sample code below, per
// specification for p17:
// - added 3 new Fraction functions (subtract, multiple, divide)
// - added a fractionToDouble function, which takes a Fraction
// struct and returns that fraction into decimal format (double)
// - added 4 extra loops to display results of using the above funcs
// - added cout headers before each loop / spacing
// - added extra comments, but only for changes i made

/*
Sample program to read fraction data from a text file and 
store them in an array created using memory allocation.
Two structs are used.  One to define a Fraction, one to define a FractionArray.
Author:  Jill Courte for CSE 153, spring 2015
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <fstream>


using namespace std;



struct Fraction
{
	int numerator;
	int denominator;
};

struct FractionArray
{
	Fraction *fractions;   //this will point to an array of fractions
	int nFractions;        //this will contain the number of elements in the array
};


bool readDataAndShowFractions(string filename, FractionArray &fractions);
bool readDataIntoArray(ifstream *infile, Fraction fractions[], int size);
Fraction newFraction(int num, int denom);
void printFractions(FractionArray fractions);
void reduce(Fraction &f);
int gcd(int x, int y);
// added my fractionToDouble function here
double fractionToDouble(Fraction &this_fraction);

//funtions to perform fraction arithmetic
Fraction add(Fraction op1, Fraction op2);
// here is where i added my 3 fraction functions
Fraction subtract(Fraction op1, Fraction op2);
Fraction multiply(Fraction op1, Fraction op2);
Fraction divide(Fraction op1, Fraction op2);

//used to convert an integer to a string
//to_string() is defined in the latest version of C++ but is not supported by older compilers

string tostring(int number);
string tostring(Fraction f);



int main(int argc, char *argv[])
{
	//create two structs, one for each array 
	FractionArray fractions1;
	FractionArray fractions2;
	bool success;

	//initialize and output the first array of Fraction structs
	success = readDataAndShowFractions("fractiondata1.txt", fractions1);
	if (!success)
	{
		cout << "Fraction array could not be constructed from fractiondata1.txt" << endl;
		exit(-1);
	}

	//initialize and output the second array of Fraction structs
	success = readDataAndShowFractions("fractiondata2.txt", fractions2);
	if (!success)
	{
		cout << "Fraction array could not be constructed from fractiondata2.txt" << endl;
	    exit(-1);
    }

	//make sure the arrays are of equal size
	if (fractions1.nFractions != fractions2.nFractions )
	{
		cout << "Fraction arrays are not the same size" << endl;
		exit(-1);
	}

    // first loop
	//loop through the Fraction arrays and output the results of
	//adding the fractions at each position
    cout << "Corresponding fractions added" << endl;
	for (int i = 0; i < fractions1.nFractions; i++)
	{
		Fraction result = add(fractions1.fractions[i], 
			                  fractions2.fractions[i]);
		cout << tostring(fractions1.fractions[i]) << " + "
			<< tostring(fractions2.fractions[i]) << " = "
			<< tostring(result) << endl;
	}

    // couts for formatting
    cout << endl;
    cout << "Corresponding fractions subtracted" << endl;
    // second loop - we iterate again through each Fraction
    // array and output results of subtracting the corresponding
    // fractions
    for (int i = 0; i < fractions1.nFractions; i++)
	{
		Fraction result = subtract(fractions1.fractions[i], 
			                  fractions2.fractions[i]);
        // if our denominator is less than 0, the frac is negative
        // so we format it accordingly
        if (result.denominator < 0) {
            result.denominator = abs(result.denominator);
            cout << tostring(fractions1.fractions[i]) << " - "
                << tostring(fractions2.fractions[i]) << " = -"
                << tostring(result) << endl;
        // if our numerator is 0, the fraction evaluates to 0, so
        // we substitute 0 in for result
        } else if (result.numerator == 0) {
            cout << tostring(fractions1.fractions[i]) << " - "
                << tostring(fractions2.fractions[i]) << " = "
                << tostring(0) << endl;
        // otherwise, we cout as normal
        } else {
            cout << tostring(fractions1.fractions[i]) << " - "
                << tostring(fractions2.fractions[i]) << " = "
                << tostring(result) << endl;
        }
		
	}

    // couts for formatting
    cout << endl;
    cout << "Corresponding fractions multiplied" << endl;
    // third loop - we again iterate over both fraction arrays and
    // output results of multiplying corresponding fractions
    for (int i = 0; i < fractions1.nFractions; i++)
	{
		Fraction result = multiply(fractions1.fractions[i], 
			                  fractions2.fractions[i]);
		cout << tostring(fractions1.fractions[i]) << " * "
			<< tostring(fractions2.fractions[i]) << " = "
			<< tostring(result) << endl;
	}

    // couts for formatting
    cout << endl;
    cout << "Corresponding fractions divided" << endl;
    // fourth loop - we once again iterate over the fraction
    // arrays and output the results of dividing the corresponding
    // fractions
    for (int i = 0; i < fractions1.nFractions; i++)
	{
		Fraction result = divide(fractions1.fractions[i], 
			                  fractions2.fractions[i]);
		cout << tostring(fractions1.fractions[i]) << " / "
			<< tostring(fractions2.fractions[i]) << " = "
			<< tostring(result) << endl;
	}

    // couts for formatting
    cout << endl;
    cout << "All fractions converted to decimals" << endl;
    // fifth and final loop - here we iterate over the fraction arrays,
    // but instead of evaluating the two fractions together as an operation,
    // we instead call our fractionToDouble function for each corresponding
    // fraction in the arrays, and print out the results (with respect to
    // the original fraction)
    for (int i = 0; i < fractions1.nFractions; i++)
	{
		double result_one = fractionToDouble(fractions1.fractions[i]);
        double result_two = fractionToDouble(fractions2.fractions[i]);
		cout << tostring(fractions1.fractions[i]) << " = " << result_one << endl;
        cout << tostring(fractions2.fractions[i]) << " = " << result_two << endl;
	}

	cin.get();

	return 0;
}

/*
fractionToDouble function, which takes in a Fraction reference and
determines the double / decimal format of that fraction, then returns
that format
@param &this_fraction, a reference to any given Fraction struct
@return new_double, a double / decimal format representing the
original fraction numerator over the denominator
*/
double fractionToDouble(Fraction &this_fraction)
{
    double new_double;
    double numerator_double = double(this_fraction.numerator);
    double denominator_double = double(this_fraction.denominator);

    new_double = numerator_double / denominator_double;

    return new_double;
}

//adds the two fractions together, creates a new Fraction from the result and
//returns it
Fraction add(Fraction op1, Fraction op2)
{
	int num1;
	int num2;
	int denom;

	denom = op1.denominator * op2.denominator;
	num1 = (denom / op1.denominator) * op1.numerator;
	num2 = (denom / op2.denominator) * op2.numerator;

	Fraction result;
	result.numerator = num1 + num2;
	result.denominator = denom;

	reduce(result);
	return result;
}

/*
subtract function, which takes in two Fractions and determines
the result of subtracting the second fraction from the first
@param op1, a Fraction
@param op2, a Fraction
@return result, a new Fraction containing the resulting numerator
and denominator format determined by op1 and op2
*/
Fraction subtract(Fraction op1, Fraction op2)
{
    // declaring vars
	int num1;
	int num2;
	int denom;

    // calculating denominator and numerators with the
    // least common denominator
	denom = op1.denominator * op2.denominator;
	num1 = (denom / op1.denominator) * op1.numerator;
	num2 = (denom / op2.denominator) * op2.numerator;

    // declaring our new fraction, then assigning numerator
    // and denominator (same logic as in add func, but
    // instead we subtract num2 from num1)
	Fraction result;
	result.numerator = num1 - num2;
	result.denominator = denom;

    // reduce fraction then return
	reduce(result);
	return result;
}

/*
multiply function, which takes in two Fractions and determines
the result of multiplying the two fractions
@param op1, a Fraction
@param op2, a Fraction
@return result, a new Fraction containing the resulting data
determined by multiplying op1 and op2
*/
Fraction multiply(Fraction op1, Fraction op2)
{
    // declaring vars
	int num1;
	int num2;
	int denom;
    int numer;

    // here we determine numerator and denominator differently;
    // we just simply multiply the denominators and numerators
	denom = op1.denominator * op2.denominator;
    numer = op1.numerator * op2.numerator;

    // declaring new fraction and assigning numerator and
    // denominator
	Fraction result;
	result.numerator = numer;
	result.denominator = denom;

    // reduce fraction then return
	reduce(result);
	return result;
}

Fraction divide(Fraction op1, Fraction op2)
{
    // declaring vars
	int num1;
	int num2;
	int denom;
    int numer;

    // again calculating our denominator and numerator for
    // our new fraction; to do this we just simply MULTIPLY
    // one fraction (in this case, op1) by the RECIPROCAL of
    // our second fraction (in this case, op2), so denominator
    // is denom of op1 * numer of op2, and numerator is numer 
    // of op1 * denom of op2
	denom = op1.denominator * op2.numerator;
    numer = op1.numerator * op2.denominator;

    // declaring result Fraction and assigning numerator
    // and denominator
	Fraction result;
	result.numerator = numer;
	result.denominator = denom;

    // reduce then return
	reduce(result);
	return result;
}


//reduces the given fraction
//the fields of the given fraction can be changed
//since it is passed by reference
void reduce(Fraction &f)
{
	int factor = gcd(f.numerator, f.denominator);

	f.numerator = f.numerator / factor;
	f.denominator = f.denominator / factor;
}

//returns the greatest common denominator of two values
//(function is recursive)
int gcd (int x, int y)
{
	if (y == 0)
		return x;
	else
		return gcd(y, x % y);


}
Fraction newFraction(int num, int denom)
{
	Fraction f;

	f.numerator = num;
	f.denominator = denom;

	return f;
}

/*
Reads fraction data from the given file into the array 
defined in the given struct.
Returns true if successful, false if any errors were encountered.
*/
bool readDataAndShowFractions(string filename, FractionArray &fractions)
{
    //read the size to make the array and create it
    ifstream *infile;
    infile = new ifstream(filename, ios::in);
    if (!infile->is_open())
        return false;

	//read the number of values into the struct variable and make
	//sure it is not 0
	if (*infile >> fractions.nFractions && fractions.nFractions > 0)
    {
		fractions.fractions = new Fraction[fractions.nFractions];
		readDataIntoArray(infile, fractions.fractions, fractions.nFractions);
    }

    infile->close();
	printFractions(fractions);

	return true;
}


/* Given a pointer to an open file and an array, reads size data from the file
 and populates the array.*/
bool readDataIntoArray(ifstream *infile, Fraction fractions[], int size)
{
	int numerator;
	int denominator;

	for (int i = 0; i < size; i++)
	{
	// read in the numerator and denominator, checking to see that we are not at
	// the end of file.  Note that this isn't perfectly safe, because if a denominator
	// is missing, our data will be off.

		*infile >> numerator;
		if (infile->eof())
			return false;

		*infile >> denominator;
		if (infile->eof())
			false;

		//Add a struct for the new fraction
		fractions[i] = newFraction(numerator, denominator);
	}

    return true;
}


void printFractions(FractionArray fractions)
{
	cout << "Fraction data from array" << endl;
	for (int i = 0; i < fractions.nFractions; i++)
	{
		cout << tostring(fractions.fractions[i]) << endl;
	}
	cout << endl;
}

// tostring() will convert an int value to a string.
// to_string() is defined in the latest version of C++ but is not supported by older compilers
string tostring(int number)
{
	const int size = sizeof(int) * 4;

	char buf[size + 1];
	sprintf_s(buf, "%d", number);
	return string(buf);
}


string tostring(Fraction f)
{
	string num = tostring(f.numerator);
	string denom = tostring(f.denominator);
	return num + "\\" + denom;
}