// output.cpp file from "Using Functions" module to be used to learn
// formatting output, etc.

#include <iostream>
#include <string>

using namespace std;



void prompt(string p)
{
	cout << p << ": " << endl;
}


int max(int x, int y)
{
	if (x > y)
		return x;
	else
		return y;
}



int main(int argc, char *argv[])
{
	int largest;
	int n1;
	int n2;

	prompt("Enter a number");
	cin >> n1;

	prompt("Enter another number");
	cin >> n2;

	largest = max(n1, n2);

	cin.ignore();
	cin.get();

	return 0;
}
