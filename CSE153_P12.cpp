/*
CSE153 - Program 12
Ross Hamey
7/25/2023
*/

// once again no vod for today's assignments; will
// be back to normal by the next assignment

// include statements
#include <iostream>
#include <fstream>

using namespace std;

void printResults(int speed, int temp);

int main(int argc, char *argv[])
{
    // here we declare / initialize all the variables
    // that we will use throughout the rest of the
    int this_val;
    int total_days = 0;
    int total_speed = 0;
    int total_temp = 0;
    int current_val_num = 1;

    // we open our weatherdata file
    ifstream infile("weatherdata.txt", ios::in);

    // we iterate through each val in the file that isnt
    // whitespace
    while (infile >> this_val) {
        // here, we check the values position in the line.
        // if our current_val_num % 3 == 1, then the val is
        // in the first position (days), so we increment our
        // day count. we could also assign it to this val
        if (current_val_num % 3 == 1) {
            total_days += 1;
        // otherwise, if current_val_num % 3 == 2, then the val
        // is in the second pos (speed), so we add it to our total
        } else if (current_val_num % 3 == 2) {
            total_speed += this_val;
        // lastly, if the current_val_num % 3 == 0, the val is in
        // the third position (temp), so we add it to our total
        } else if (current_val_num % 3 == 0) {
            total_temp += this_val;
        }
        // then we increment our current_val_num to keep count
        // of what position the val is in the file
        current_val_num += 1;
    }

    // closing the file as soon as possible to release it
    infile.close();

    // calculating avg speed and temp, then calling our
    // printResults method nad passing in the two vars
    int avg_speed = total_speed / total_days;
    int avg_temp = total_temp / total_days;
    printResults(avg_speed, avg_temp);

    cin.ignore();
    cin.get();
}

/*
printResults func, which takes in an avg speed and temp value
and prints the results
@param speed, an int value representing the avg speed
@param temp, an int value representing the avg temp
@return none (void)
*/
void printResults(int speed, int temp)
{
    cout << "The average of the wind speeds in the file " << speed << "." << endl;
    cout << "The average of the temperatures in the file is " << temp << "." << endl;
}