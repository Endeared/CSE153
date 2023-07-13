// output.cpp file from "Using Functions" module to be used to learn
// formatting output, etc.

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

	int num1 = 45;
	int num2 = 137;
	
	double num3 = 17.3;
	double num4 = 135.11;

	double num5 = 123456789.0;

	//setw sets the number of spaces that a value should occupy
	cout << setw(10) << num1 << setw(5) << num2 << endl;

	cout << setw(10) << num1 << num2 << endl;

	//'' denote a character, for example, 'a' is a, 'b' is b and so on.
	//A character with a slash before it is a special character
	cout << '\t' << num1 << endl;

	cout << setw(4) << num3 << endl;

	cout << setw(2) << num4 << endl;

	cout << num5 << endl;
	//fixed makes all floating point values display with a decimal point.
	cout << fixed << num5 << endl;

	cout << "5% of " << num4 << " is  " << num4*.05 << endl;

	//setprecision sets the number of digits after the decimal point if used after fixed. 
	cout << setprecision(2) << "5% of " << num4 << " is  " << num4*.05 << endl;

	//restore stream to default properties
	cout << resetiosflags(ios::fixed);
	cout << setprecision(2) << "5% of " << num4 << " is  " << num4*.05 << endl;


	printf("Two integers: %d and %d\n", num1, num2);

	cout << "Two integers: " << num1 << " and " << num2 << endl;


	printf("An integer and a double: %d and %f\n", num1, num3);

	printf("A double with two decimal places: %.2f\n", num3);

	printf("Setting the width: %10d \n", num1);

	//just a newline
	printf("\n");


	cin.get();
	return 0;
}