/*
CSE153 - Program 14
Ross Hamey
7/28/2023
*/

/* Magic 8-ball starting code.
Author:  Jill Courte for CSE 153, Spring 2017
*/

// our includes for inputs / strings / seeding rng
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>


using namespace std;

// defining our funcs
string getAnswer(vector<string> resp, int nAnswers);
string getQuestion();


int main()
{   
    // declaring our vector
    vector<string> answer_vector;

    // storing 20 responses in an array, then iterating over that
    // array to push_back each response into our vector. i wasnt sure
    // if this is the best way to go about doing it since i couldnt
    // find a way to push multiple values into a vector at once, so
    // i chose to just keep the array to populate the vector with
    // a for loop rather than writing a push_back 20 times - not sure
    // if there is a better way to go about doing this?
    string answers[20] = {
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
    for (int i = 0; i < 20; i++) {
        answer_vector.push_back(answers[i]);
    }

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
        // otherwise, we get a response using our getAnswer func, and then
        // print out an extra line for formatting
        } else {
            cout << getAnswer(answer_vector, answer_vector.size()) << endl;
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
getAnswer function, which takes in a vector of strings and length of
the vector / number of answers, and returns a random choice in the vector
@param resp, a vector of strings
@param num_answers an int representing the number of answers / length of
input vector
@return a random element in the resp vector (resp[index])
*/
string getAnswer(vector<string> resp, int num_answers)
{
	int index = rand() % num_answers;

	return resp[index];
}