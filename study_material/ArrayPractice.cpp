/* Starting code for array practice.

Author:  Jill Courte for CSE 135, SPring 2015
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

#define PI 3.14159265
const int ARRAY_SIZE = 25;



void initializeArray(double arr[], int size);
void printArrays(int arrOne[], double arrTwo[], int size);


int main(int argc, char *argv[])
{
	int arrayOne[ARRAY_SIZE];
	double arrayTwo[ARRAY_SIZE];
	int index;


	for (index = 0; index < ARRAY_SIZE; index++)
	{
		arrayOne[index] = index + 1;
	}


	initializeArray(arrayTwo, ARRAY_SIZE);

	printArrays(arrayOne, arrayTwo, ARRAY_SIZE);

	cin.ignore();
	cin.get();
}

void initializeArray(double arr[], int size)
{
	for (int index = 0; index < size; index++)
	{
		arr[index] = cos((index+1) * PI / 180);
	}
}

void printArrays(int arrOne[], double arrTwo[], int size)
{
	cout << setw(6) << "degree" << setw(10) << "cosine" << endl;
	for (int index = 0; index < size; index++)
	{
		cout << setw(3) << arrOne[index] << setw(14) << arrTwo[index] << endl;
	}
}

