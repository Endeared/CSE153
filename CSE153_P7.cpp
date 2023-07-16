/*
CSE153 - Program 7
Ross Hamey
7/16/2023
*/

// https://youtu.be/OXCLjloAS_Q - VOD
// (i usually record stuff i make and upload
// it as an unlisted video, just incase i need
// it for future reference / for some reason)

// starting code provided as part of P7 assignment
// some of the starting code was modified

// our includes - we include cstdlib and ctime
// to fix our RNG, per chapter 9
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// initially declaring our functions
void closing(int games);
void welcome(int high, int low, string name);
int getGuess();
bool testGuess(int guess, int number_to_guess);

int main(int argc, char *argv[])
{
    // we start by seeding our RNG (chapter 9) -
    // otherwise, our RNG will always start as 2
    srand(time(NULL));

    // declaring our initial variables
    string my_name = "Ross Hamey";
	int high = 10;
	int low = 1;
	int number_to_guess;
    int number_of_guesses;
    int games_played = 0;
    int guess;
	bool still_playing = true;
	bool winner = false;

    // our welcome statement
    cout << "Welcome, " << my_name << "." << endl;
    cout << endl;

    // while loop - this continues until the user has
    // indicated that they no longer wish to play again
	while (still_playing)
	{
        // grabbing a random number, then calling our welcome func
		number_to_guess = rand() % high + low;
        welcome(high, low, my_name);

        // nested while - we repeat this until the user has guessed
        // the correct number
		while (!winner)
		{
            // grabbing our users guess by calling getGuess funct, then
            // incrementing our # of guesses
			guess = getGuess();
            number_of_guesses += 1;

            // determining our winner bool by calling testGuess
			winner = testGuess(guess, number_to_guess);

            // if winner is true (our guess was correct), then we increment
            // the # of games played, and prompt the user to play again or
            // to exit
			if (winner) {
                games_played += 1;
				string play_again;
                cout << "Congratulations! You have guessed the correct number. It took you " <<
                        number_of_guesses << " tries to guess the correct number (" << 
                        number_to_guess << ")." << endl;
                cout << "Would you like to play again? (y/n): ";
                cin >> play_again;
                cout << endl;

                // if the user selects y or Y, we play again and do not set
                // still_playing to false
                if (play_again == "y" || play_again == "Y") {
                    winner = true;
                // otherwise, we set still_playing to false and break out of
                // our loop
                } else {
                    still_playing = false;
                    break;
                }
            // if winner is false (the guess was incorrect), then we return
            // the appropriate prompt and go back to the start of our nested
            // while loop
			} else {
                cout << "That guess was incorrect. You have currently guessed " << number_of_guesses <<
                        " time(s) so far." << endl;
            }
		}

        // if we are out of our winner loop (but still_playing is still false),
        // then the user opted to play again, so we reset winner to false and
        // reset our # of guesses to 0
        winner = false;
        number_of_guesses = 0;
	}

    // if we break out of our still_playing loop, then the user has opted to
    // exit, so we call our closing func
    closing(games_played);

    // and lastly we use cin.ignore and cin.get to allow the window to remain
	cin.ignore();
	cin.get();
    return 0;
}


/*
closing function, which takes in the number of games the user played and provides
the user with a closing message
@param games, the int number of games played
@return none (void)
*/
void closing(int games)
{
    cout << "You played " << games << " games." << endl;
    cout << "Thanks for playing! Goodbye." << endl;
}

/*
our welcome function, which takes in a range of numbers and a name, and returns
a message instructing the user on the game
@param high, an int for the high end of the range
@param low, an int for the low end of the range
@param name, a string of the player's name
@return none (void)
*/
void welcome(int high, int low, string name)
{
    cout << name << " - I am thinking of a number between " << low << " and " << high <<
            " (inclusive). Try guessing my number!";
    cout << endl;
}

/*
getGuess function, which grabs a guess from the user and returns it
@return my_guess, an int provided by the user
*/
int getGuess()
{
    int my_guess;

    cout << "Please input a guess: ";
    cin >> my_guess;
    return my_guess;
}

/*
testGuess function, which takes in a guess int and a second int to compare to the guess
@param guess, an int which is the user-provided guess #
@param number_to_guess, an int which is a randomly generated number the user must guess
@return true / false, a bool to compare if the guesses are equal (true) or not (false)
*/
bool testGuess(int guess, int number_to_guess)
{
    if (guess == number_to_guess) {
        return true;
    } else {
        return false;
    }
}