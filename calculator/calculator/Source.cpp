#include <iostream>

using namespace std;

void Sub();
void Extract();
void Multi();
void Divide();

void Calculator(int i);
int myLocation;

int main()
{
	cout << "\nCALCULATOR\n";
	cout << "Please choose a function:\n\n";
	cout << "1. Substraction\n";
	cout << "2. Extraction\n";
	cout << "3. Multiplication\n";
	cout << "4. Division\n";
	cin >> myLocation;
	Calculator(myLocation);

	return main();
	
}

void Sub()
{
	int a;
	int b;
	cout << "enter two numbers: ";
	cin >> a, b;
	cout << "Outcome: "; a + b;
	return;
}

void Extract()
{
	cout << "extract";
}

void Multi()
{
	cout << "multi";
}

void Divide()
{
	cout << "divide";
}

void Calculator(int i)
{
	switch (i)
	{
		case 1:
			Sub();
			break;
		case 2:
			Extract();
			break;
		case 3:
			Multi();
			break;
		case 4:
			Divide();
			break;

	}
}