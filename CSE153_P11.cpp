/*
CSE153 - Program 11
Ross Hamey
7/22/2023
*/

// no recordings this weekend, not home again

// this program functions to take in a list of 10 names from the user,
// place those names into an array, then iterates through each name in
// that array to populate a second array of bool values indicating
// whether the name is palindromic or not. the user is then returned a
// prompt of names that are palindromic (corresponding indices)

// admittedly, this is probably a lot longer than it needed to be, but
// i wanted to practice making this as modular as possible, so things like
// openingPrompt and closingPrompt could have probably been done without
// and just thrown in the main loop...

// i also am not super well-versed with built in c++ functions from includes,
// so for things like converting a string to lowercase and reversing a string i
// just ended up making a function for them manually that i can re-use later

// our includes
#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

// defining array size constant
const int ARRAY_SIZE = 10;

// declaring our funcs
void initializeNameArray(string arr[], int arr_size);
void initializePalindromeArray(string name_arr[], bool palindrome_arr[], int arr_size);
void printResults(string name_arr[], bool palindrome_arr[], int arr_size);
void openingPrompt();
void closingPrompt();
string lowercase(string input_name);
string reversed(string input_name);

int main(int argc, char*argv[])
{
    // calling openingPrompt to display greeting to user
    openingPrompt();
    
    // our main loop, we continue until the user indicates that they do not
    // want to continue the program
    while (true) {

        // declaring our arrays
        string name_array[ARRAY_SIZE];
        bool palindromic_array[ARRAY_SIZE];

        // calling our funcs in order to populate our arrays and print results
        initializeNameArray(name_array, ARRAY_SIZE);
        initializePalindromeArray(name_array, palindromic_array, ARRAY_SIZE);
        printResults(name_array, palindromic_array, ARRAY_SIZE);

        // grabbing continue input from user
        string response = "";
        cout << "Would you like to check another list of names? ('y' to go again, anything else to exit): ";
        cin >> response;
        
        // if the user doesnt respond with 'y', we break out of the loop
        if (response != "y") {
            break;
        }   
    }

    // calling our closingPrompt before ending program
    closingPrompt();
    cin.ignore();
    cin.get();
}

/*
initializeNameArray function, which takes in an array of name strings and a length, then
iterates length times to grab name inputs from the user
@param name_arr[], an empty string array of names
@param length, an int representing the length of the array
@return none (void)
*/
void initializeNameArray(string name_arr[], int length)
{
    // iterating length times, grabbing a name input from the user, and then
    // assigning it to the array at index i
    for (int i = 0; i < length; i++) {
        string name_input = "";
        cout << "Please enter a name (" << (length - i) << " name(s) remaining): ";
        cin >> name_input;

        name_arr[i] = name_input;
    }

    cout << endl;
}

/*
initializePalindromeArray func, which takes in a string array, a bool array, and a length,
then iterates over the string array to determine if the element is palindromic and populate
our palindrome_arr accordingly
@param name_arr[], a populated string array of names
@param palindrome_arr[], an empty bool array representing palindromic status of a name
@param length, an int representing the length of the two arrays
@return none (void)
*/
void initializePalindromeArray(string name_arr[], bool palindrome_arr[], int length)
{
    // we iterate length times, grabbing the element of name_arr at the index of our
    // iterator, determining if it is palindromic, then assigning a bool val to our
    // palindrome_arr at index i
    for (int i = 0; i < length; i++) {
        // declare name_lower by calling lowercase func and passing in our element
        string name_lower = lowercase(name_arr[i]);
        // declare name_reversed by calling reversed func and passing in name_lower
        string name_reversed = reversed(name_lower);

        // if both name_lower and name_reversed are identical (palindromes), then
        // we assign our bool value at index i to true, otherwise false
        if (name_lower == name_reversed) {
            palindrome_arr[i] = true;
        } else {
            palindrome_arr[i] = false;
        }
    }
}

/*
printResults func, which takes in a string array, a bool array, and a length,
then iterates over the bool array to determine if the corresponding element at
the same index in the string array is palindromic or not, and printing out a list
of all palindromic strings
@param name_arr[], a populated string array of names
@param palindrome_arr[], a populated bool array of the palindromic status of elements
in name_arr
@param length, an int representing the size of both arrays
@return none (void)
*/
void printResults(string name_arr[], bool palindrome_arr[], int length)
{
    cout << setw(20) << "Name provided" << setw(20) << "Palindromic?" << endl;
    for (int i = 0; i < length; i ++) {
        int chars = name_arr[i].length();
        string palindromic_status = "";

        if (palindrome_arr[i] == true) {
            palindromic_status = "Yes";
        } else {
            palindromic_status = "No";
        }
        cout << setw(11) << "" << resetiosflags(ios::fixed) << name_arr[i] << setw(22 - chars) <<
                "" << resetiosflags(ios::fixed) << palindromic_status << endl;
    }

    cout << endl;
}

/*
openingPrompt func, which simply provides the user with a greeting upon starting
the program
@return none (void)
*/
void openingPrompt()
{
    cout << "This program functions to take in a list of 10 names from the user, " <<
                "and then determine which names in that list are palindromic." << endl;
    cout << endl;
}

/*
closingPrompt func, which simply provides the user with a farewell upon the user
indicating that they wish to end the program
@return none (void)
*/
void closingPrompt()
{
    cout << "Thanks for using this program. Goodbye!" << endl;
}

/*
lowercase func, which takes in a string and returns a copy of that string in
all lowercase format
@param name, a string value
@return lowercase_name, a copy of name in lowercase format
*/
string lowercase(string name)
{
    // delcaring initial string
    string lowercase_name = "";

    // iterating through our name by the length (size) of name, we grab the
    // character at each index of name, and call the built in tolower func to
    // convert the char to lowercase, then add that char to our initial string
    for (int i = 0; i < name.size(); i++) {
        char this_letter = name[i];
        this_letter = tolower(this_letter);
        lowercase_name += this_letter;
    }

    // returning final string
    return lowercase_name;
}

/*
reversed func, which takes in a string and returns a copy of that string in
a reversed format
@param name, a string value
@return reversed_name, a copy of name in reversed format
*/
string reversed(string name)
{
    // declaring our initial string
    string reversed_name = "";

    // iterating down name starting at the size of name - 1 until 0, grabbing
    // the character at each index of name and adding it to our initial string
    for (int i = (name.size() - 1); i > -1; i--) {
        char this_letter = name[i];
        reversed_name += this_letter;
    }

    // returning our final string
    return reversed_name;
}
