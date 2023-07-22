/*
CSE153 - Program 8
Ross Hamey
7/22/2023
*/

// no recordings this weekend, not home again

/* Magic 8-ball starting code.
Author:  Jill Courte for CSE 153, Spring 2017
*/

// our includes for inputs / strings / seeding rng
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>


using namespace std;

// defining our funcs
string getAnswer(string m8Ball[], int nAnswers);
string getQuestion();


int main()
{   
    // defining the length of our array, and then creating an array
    // with 20 possible responses for later
    const int num_of_answers = 20;
    string answers[num_of_answers] = {
        "It is certain.",
        "It is decidedly so.",
        "Without a doubt.",
        "Yes, definitely.",
        "You may rely on it.",
        "As I see it, yes.",
        "Most likely.",
        "Outlook good.",
        "Yes.",
        "Signs point to yes.",
        "Don't count on it.",
        "My reply is no.",
        "My sources say no.",
        "Outlook not so good.",
        "Very doubtful.",
        "Uncertain.",
        "Cannot predict now.",
        "Better not tell you now.",
        "Reply hazy; cannot determine.",
        "50/50."
    };

    // seeding our rng
	srand((unsigned int) time(NULL));

    // our main loop, we continue until the user inputs "x"
    while (true) {

        // grabbing the users input by calling our getQuestion func
        string input = getQuestion();

        // if the user input "x", then we send a goodbye prompt and break
        // out of the program
        if (input.compare("x") == 0) {
            cout << "Thanks for playing. Goodbye!" << endl;
            break;
        // otherwise, we get a response using our getAnswer funct, and then
        // print out an extra line for formatting
        } else {
            cout << getAnswer(answers, num_of_answers) << endl;
            cout << endl;
        }
    }

    cin.ignore();
    cin.get();
    return 0;
}

/*
getQuestion function, which prompts the user for a question and then
gets their response using getLine, and returns their response
@return question, a string variable containing the user's response
*/
string getQuestion()
{
    string question;

    cout << "What is your question? (Enter 'x' to exit)" << endl;
    getline(cin, question);

    return question;
}

/*
getAnswer function, which takes in an array of strings and length of
the array / number of answers, and returns a random choice in the array
@param m8Ball, an array of strings
@param nAnswers, an int representing the number of answers / length of input
array
@return a random element in the m8Ball array (m8Ball[index])
*/
string getAnswer(string m8Ball[], int nAnswers)
{
	int index = rand() % nAnswers;

	return m8Ball[index];
}