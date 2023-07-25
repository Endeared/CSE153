/*
CSE153 - Program 13
Ross Hamey
7/25/2023
*/

// once again no vod for today's assignments; will
// be back to normal by the next assignment

// include statements
#include <iostream>
#include <fstream>

using namespace std;

// our constant as needed
const int NUM_OF_DAYS = 30;

// declaring helper functions
void printResults(int speed, int temp);
int averageSpeed(int speeds[], int divisor);
int averageTemp(int temps[], int divisor);

int main(int argc, char *argv[])
{
    // declaring our arrays to store data
    int speeds[NUM_OF_DAYS];
    int temps[NUM_OF_DAYS];

    // declaring our other vals to use when reading file data
    int this_val;
    int array_position = -1;
    int total_speed = 0;
    int total_temp = 0;
    int current_val_num = 1;

    // we open our weatherdata file
    ifstream infile("weatherdata.txt", ios::in);

    // we iterate through each val in the file that isnt
    // whitespace
    while (infile >> this_val) {
        // we use 3 if checks to determine the values position in
        // the line; a remainder of 1 indicates the first position,
        // so we add 1 to our array_position value to indicate
        // what position will be filled with data
        if (current_val_num % 3 == 1) {
            array_position += 1;
        // a remainder of 2 indicates the second position, so we add
        // our value to the speeds array at the current array_position
        } else if (current_val_num % 3 == 2) {
            speeds[array_position] = this_val;
        // remainder of 3 indicates first position, so we add our
        // value to the temps array at the current array_position
        } else if (current_val_num % 3 == 0) {
            temps[array_position] = this_val;
        }
        // lastly, we increment current_val_num to keep track of the
        // vals position within the file
        current_val_num += 1;
    }

    // closing the file as soon as possible to release it
    infile.close();


    // calculating avg speed and temp by calling our two
    // helper functions (averageSpeed and averageTemp),
    // then printing results by calling printResults with
    // our avg_speed and avg_temp
    int avg_speed = averageSpeed(speeds, NUM_OF_DAYS);
    int avg_temp = averageTemp(temps, NUM_OF_DAYS);
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

/*
averageSpeed function, which takes in an array of speeds and
a divisor, then calculates and returns the average speed
@param speeds[], an array of ints representing speeds on different days
@param divisor, an int representing the number of days
@return avg, an int representing the average speed of all speeds
within the speeds[] array (with respect to divisor)
*/
int averageSpeed(int speeds[], int divisor)
{
    int running_total = 0;
    for (int i = 0; i < divisor; i++) {
        running_total += speeds[i];
    }

    int avg = running_total / divisor;
    return avg;
}

/*
averageTemp function, which takes in an array of temps and
a divisor, then calculates and returns the average temp
@param temps[], an array of ints representing temps on different days
@param divisor, an int representing the number of days
@return avg, an int representing the average temp of all temps
within the temps[] array (with respect to divisor)
*/
int averageTemp(int temps[], int divisor)
{
    int running_total = 0;
    for (int i = 0; i < divisor; i++) {
        running_total += temps[i];
    }

    int avg = running_total / divisor;
    return avg;
}