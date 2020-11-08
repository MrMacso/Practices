#include <iostream>

using namespace std;

int day = 0;
int month = 0;
int year = 0;

int main()
{
	cout << "Tell me your date of birth:\n day:";
	cin >> day;
	cout << "\nmonth:";
	cin >> month;
	cout << "\nyear:";
	cin >> year;

	if ((3 <= month) && (month<= 5)) 
	{
		cout << "You born in the Spring.";
	}	
		else if ((6 <= month) && (month <= 8))
		{
			cout << "You born in the Summer.";
		} 
		else if ((9 <= month) && (month <= 11))
		{
			cout << "You born in Autum.";
		}

		else if (month == 12)
		{
			cout << "You born in Winter.";
		}
		else if (month == 2)
		{
		cout << "You born in Winter.";
		}
		else if (month == 1)
		{
		cout << "You born in Winter.";
		}
		else
		{
		cout << "\nType in a valid date.\n";
		return main();
		}
	return 0;
}