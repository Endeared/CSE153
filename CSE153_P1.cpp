/* 
CSE153 - Program 1
Ross Hamey
6/29/2023
*/

// our includes
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main()
{
    // declaring our name strings
    string first_name;
    string last_name;

    // declaring our length + width ints
    int length;
    int width;

    // part A, grabbing name inputs and responding with
    // welcome message, followed by empty line for format
	cout << "Please enter your first name:" << endl;
	cin >> first_name;
    cout << "Please enter your last name:" << endl;
    cin >> last_name;
    cout << "Welcome, " << first_name << " " << last_name << "." << endl;
    cout << endl;

    // part B, grabbing length and width inputs and responding with
    // the length and width entered, followed by a new line for format
    cout << "Please enter the length of a rectangle (in inches) as a whole number:" << endl;
    cin >> length;
    cout << "Please enter the width of a rectangle (in inches) as a whole number:" << endl;
    cin >> width;
    cout << "You entered a rectangle with a length of " << length << " inches and with a width of " << width << " inches." << endl;
    cout << endl;

    // doing our math here. we calculate are and perimeter and declare them
    // to ints, as well as calculating our diagonal and length / width in millimeters
    // and assigning them to double (part C & D)
    int area = length * width;
    int perimeter = (length * 2) + (width * 2);
    double diagonal = sqrt((length * length) + (width * width));
    double length_mm = length * 25.4;
    double width_mm = width * 25.4;

    // part C and D continued, outputting our perimeter / area/ diagonal
    // variables from the user, as well as our calculated length / width in millimeters
    cout << "Your rectangle has a perimeter of " << perimeter << " inches and an area of " << area << " inches squared." << endl;
    cout << "The diagonal of the rectangle is " << diagonal << " inches." << endl;
    cout << "The length and width of the rectangle in millimeters is " << length_mm << " and " << width_mm << ", respectively." << endl;
    cout << endl;

    // lastly cin.get(); so user can properly see final messages in cmd line,
    // then return
    cin.get();
	return 0;
}