#include <iostream>

using namespace std;

void Spaceship();
void Sky();
void Forest();
void Sea();

void Travel(int i);
int myLocation;

int main()
{
	cout << "Hello traveler!\n\n";
	Spaceship();
	system("Pause");
}

void Spaceship()
{
	cout << "You are in space!\n";
	cout << "Where next, traveler?\n\n Press 2 for sky, 3 for forest, 4 for sea...\n\n";
	cin >> myLocation;
	Travel(myLocation);
}

void Sky()
{
	cout << "You are in the air!\n";
	cout << "Where next, traveler?\n\n Press 1 for spaceship, 3 for forest, 4 for sea...\n\n";
	cin >> myLocation;
	Travel(myLocation);
}

void Forest()
{
	cout << "You are in the forest!\n";
	cout << "Where next, traveler?\n\n Press 1 for spaceship, 2 for sky, 4 for sea...\n\n";
	cin >> myLocation;
	Travel(myLocation);
}

void Sea()
{
	cout << "You are in the sea!\n";
	cout << "Where next, traveler?\n\n Press 1 for spaceship, 2 for sky, 3 for forest...\n\n";
	cin >> myLocation;
	Travel(myLocation);
}

void Travel(int i)
{
	switch (i)
	{
	case 1:
		Spaceship();
		break;
	case 2:
		Sky();
		break;
	case 3:
		Forest();
		break;
	case 4:
		Sea();
		break;
	deafult:
		cout << "Please try again.\n\n";
	}
}
