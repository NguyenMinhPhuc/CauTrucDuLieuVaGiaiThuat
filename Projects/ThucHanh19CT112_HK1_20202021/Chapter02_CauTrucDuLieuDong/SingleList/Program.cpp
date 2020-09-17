#include "iostream"
using namespace std;

#pragma region Phần khai báo tên file
//#include "Common.cpp"
#include "SingleList_Basic.cpp"
#include "SingleList_Extend.cpp"
#pragma endregion


int MenuMain()
{
	cout << "==============================" << endl;
	cout << "--- PROGRAMMING SINGLELIST ---" << endl;
	cout << "1. SingleList_Basic" << endl;
	cout << "2. SingleList_Extend" << endl;
	cout << "3. Print list number" << endl;
	cout << "4. Exit" << endl;
	cout << "==============================" << endl;
	int option;
	cout << "Select Function: ";
	cin >> option;
	return option;
}
void main(){

	int option;
	const bool addfirst = true;
	while (true)
	{
		option = MenuMain();
		switch (option)
		{
		case 1:
			Main_SingleList_Basic();
			break;
		case 2:
			MainSingle_ListExtend();
			break;
		case 3:
			break;
		case 4:
			
			return;
		}
	}
}