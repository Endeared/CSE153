/*
CSE153 - Program 3
Ross Hamey
7/5/2023
*/

// our include(s)
#include <iostream>
#include <string>

using namespace std;

int main()
{
    // our time constants for male qualifications, in seconds
    const int male_18_34 = (3 * 3600) + (5 * 60) + 0;
    const int male_35_39 = (3 * 3600) + (10 * 60) + 0;
    const int male_40_44 = (3 * 3600) + (15 * 60) + 0;
    const int male_45_49 = (3 * 3600) + (25 * 60) + 0;
    const int male_50_54 = (3 * 3600) + (30 * 60) + 0;
    const int male_55_59 = (3 * 3600) + (40 * 60) + 0;
    const int male_60_64 = (3 * 3600) + (55 * 60) + 0;
    const int male_65_69 = (4 * 3600) + (10 * 60) + 0;
    const int male_70_74 = (4 * 3600) + (25 * 60) + 0;
    const int male_75_79 = (4 * 3600) + (40 * 60) + 0;
    const int male_80 = (4 * 3600) + (55 * 60) + 0;

    // our time constants for female qualifications, in seconds
    const int female_18_34 = (3 * 3600) + (35 * 60) + 0;
    const int female_35_39 = (3 * 3600) + (40 * 60) + 0;
    const int female_40_44 = (3 * 3600) + (45 * 60) + 0;
    const int female_45_49 = (3 * 3600) + (55 * 60) + 0;
    const int female_50_54 = (4 * 3600) + (0 * 60) + 0;
    const int female_55_59 = (4 * 3600) + (10 * 60) + 0;
    const int female_60_64 = (4 * 3600) + (25 * 60) + 0;
    const int female_65_69 = (4 * 3600) + (40 * 60) + 0;
    const int female_70_74 = (4 * 3600) + (55 * 60) + 0;
    const int female_75_79 = (5 * 3600) + (10 * 60) + 0;
    const int female_80 = (5 * 3600) + (25 * 60) + 0;

    // declaring our initial variables
    string first_name;
    string last_name;
    string gender_string;
    string time_string;
    int age;
    int gender;
    int hours;
    int minutes;
    int seconds;
    int total_time;
    bool qualifies = false;
    bool male;
    bool female;

    // grabbing inputs from the user
    cout << "Please enter a first name and a last name: ";
    cin >> first_name >> last_name;
    cout << "Please enter participant's age: ";
    cin >> age;
    cout << "Please enter participant's gender. 1 for Male, 2 for Female: ";
    cin >> gender;
    cout << "Please enter your time in the format of [hours minutes seconds], each as whole numbers (example: 4 15 57): ";
    cin >> hours >> minutes >> seconds;
    total_time = (hours * 3600) + (minutes * 60) + seconds;
    time_string = "(" + to_string(hours) + ":" + to_string(minutes) + ":" + to_string(seconds) + ")";

    // checking gender value and assigning it to
    // a string for later use
    if (gender == 1) {
        gender_string = "male";
        male = true;
    } else if (gender == 2) {
        gender_string = "female";
        female = true;
    }

    // this is as much as i could think to shorten my conditional section up.
    // i thought about maybe handling a bunch of conditionals at once with || statements
    // but thought it would get super messy and hard to read, and couldnt think of
    // a shorter way to do this without control / looping, even though this
    // still seems pretty long.
    if (male) {
        if (age < 18) {
            qualifies = false;
        } else if (age >= 18 && age < 35 && total_time <= male_18_34) {
            qualifies = true;
        } else if (age >= 35 && age < 40 && total_time <= male_35_39) {
            qualifies = true;
        } else if (age >= 40 && age < 45 && total_time <= male_40_44) {
            qualifies = true;
        } else if (age >= 45 && age < 50 && total_time <= male_45_49) {
            qualifies = true;
        } else if (age >= 50 && age < 55 && total_time <= male_50_54) {
            qualifies = true;
        } else if (age >= 55 && age < 60 && total_time <= male_55_59) {
            qualifies = true;
        } else if (age >= 60 && age < 65 && total_time <= male_60_64) {
            qualifies = true;
        } else if (age >= 65 && age < 70 && total_time <= male_65_69) {
            qualifies = true;
        } else if (age >= 70 && age < 75 && total_time <= male_70_74) {
            qualifies = true;
        } else if (age >= 75 && age < 80 && total_time <= male_75_79) {
            qualifies = true;
        } else if (age >= 80 && total_time <= male_80) {
            qualifies = true;
        } else {
            qualifies = false;
        }
    } else if (female) {
        if (age < 18) {
            qualifies = false;
        } else if (age >= 18 && age < 35 && total_time <= female_18_34) {
            qualifies = true;
        } else if (age >= 35 && age < 40 && total_time <= female_35_39) {
            qualifies = true;
        } else if (age >= 40 && age < 45 && total_time <= female_40_44) {
            qualifies = true;
        } else if (age >= 45 && age < 50 && total_time <= female_45_49) {
            qualifies = true;
        } else if (age >= 50 && age < 55 && total_time <= female_50_54) {
            qualifies = true;
        } else if (age >= 55 && age < 60 && total_time <= female_55_59) {
            qualifies = true;
        } else if (age >= 60 && age < 65 && total_time <= female_60_64) {
            qualifies = true;
        } else if (age >= 65 && age < 70 && total_time <= female_65_69) {
            qualifies = true;
        } else if (age >= 70 && age < 75 && total_time <= female_70_74) {
            qualifies = true;
        } else if (age >= 75 && age < 80 && total_time <= female_75_79) {
            qualifies = true;
        } else if (age >= 80 && total_time <= female_80) {
            qualifies = true;
        } else {
            qualifies = false;
        }
    }

    // lastly, we check if our qualifies bool is set to true or false. if it
    // is true, we return a prompt with the appropriate message
    if (qualifies == true) {
        cout << first_name << " " << last_name << " is a " << age << " year old " << gender_string
                << " with a time of " << time_string << " and they qualify!";
    // otherwise, if they do not qualify, we check to determine why they did not
    // qualify and return the respective prompt (due to age or time)
    } else if (qualifies == false) {
        if (age < 18) {
            cout << first_name << " " << last_name << " is a " << age << " year old " << gender_string
                << " with a time of " << time_string << " and they do not qualify due to age < 18.";
        } else {
            cout << first_name << " " << last_name << " is a " << age << " year old " << gender_string
                    << " with a time of " << time_string << " and they do not qualify due to time.";
        }
    }

    // our cin.get to pause cmd window if ran in cmd line, then
    // return 0
    cin.get();
    return 0;
}