#include <iostream>

using namespace std;

int number;


int main()
{

	cout << "Type in a number, I'll print out the square of that number: ";
	cin >> number;
	int solution = number * number;
	cout << "There you go:"; 
	cout << solution;
	return 0;
}