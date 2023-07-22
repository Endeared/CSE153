/* Magic 8-ball starting code.
Author:  Jill Courte for CSE 153, Spring 2017
*/
#include <iostream>
#include <string>
#include <ctime>


using namespace std;


string getAnswer(string m8Ball[], int nAnswers);


int main()
{
	//define a constant that represents how many answers are in your array (at least 8)
	//declare and initialize an array of strings, representing possible answers from the magic eightball

	srand((unsigned int) time(NULL));

	//loop and ask the user to enter a question or enter "x" to stop
	//use getline to get the question
	//call getAnswer with your array and number of possible answers to get an answer
	//output the answer

}


string getAnswer(string m8Ball[], int nAnswers)
{
	int index = rand() % nAnswers;

	return m8Ball[index];
}