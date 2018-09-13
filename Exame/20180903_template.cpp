#include <iostream>
using namespace std;
int menu()
{
	int option;
	cout << "-----Menu----";
	cout << "\n1. Init Stack";
	cout << "\n2. Check Stack";
	cout << "\n3. Push into Stack";
	cout << "\n4. Pop out Stack";
	cout << "\n5. Get item top Stack";
	cout << "\n6. Exit";
	cout << "seleted Option: "; cin >> option;
	return option;
}

void main()
{
	int option = 0;
	do
	{
		option = menu();
		switch (option)
		{
		case 1:
			
			break;
		case 2:
			
			break;
		}
	} while (option != 6);
}