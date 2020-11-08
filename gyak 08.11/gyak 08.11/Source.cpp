#include <iostream>
using namespace std;

int main()
{
	const int ROWS = 5;
	const int COLLUMS = 3;
	for (int i = 0; i < ROWS; ++i)
	{
		for (int j = 0; j < COLLUMS; ++j)
		{
			cout << i << "," << j << " ";
		}
		cout << endl;
	}

	return 0;
}
  