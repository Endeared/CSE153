/*
Starting code for guessing game.  

Functions introduction, getGuess, and testGuess need to be completed.
Range of numbers to guess needs to be set.
Code needs to be added to ask if user wants another game and loop control set accordingly.
Code needs to be added to track number of guesses.


*/

#include <iostream>


using namespace std;


void introduction(int high, int low);
int getGuess();
bool testGuess(int guess, int numberToGuess);



int main(int argc, char *argv[])
{
	int high = 0;
	int low = 0;

	int numberToGuess;
	bool stillPlaying = true;
	bool winner = false;

	int guess;

	while (stillPlaying)
	{
		// generate a random number between low and high value
		numberToGuess = rand() % (high - low + 1) + low;

		//tell the user about the game
		introduction(high, low);

		while (!winner)
		{
			guess = getGuess();

			winner = testGuess(guess, numberToGuess);
			if (winner)
			{
				//output a congratulatory message
			}
			else
				;
			//output the number of guesses they've made so far
		}

		//ask the user if they want to play again, and if not, change the loop control condition

	}

		cout << "Thanks for playing!" << endl;


	cin.ignore();
	cin.get();

}





//Tells the user the ruules of the game
void introduction(int high, int low)
{
	//I'm thinking of a number between high and low.....
}

//Prompts for, inputs, and returns the next guess
int getGuess()
{
	return 0;
}

// returns true if guess is correct
//if guess is not correct, outputs a high or low message and returns false
bool testGuess(int guess, int numberToGuess)
{
	return false;
}