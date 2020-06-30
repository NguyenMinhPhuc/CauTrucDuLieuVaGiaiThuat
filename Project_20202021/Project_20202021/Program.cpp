#include<iostream>
using namespace std;

#pragma region Phần khai báo tên file
#include "Exam_0101_HelloWorld.cpp"
#pragma endregion
/// <summary>
/// Hàm menu để hiển thị menu lựa chọn bài cần mở
/// </summary>
/// <returns>giá trị lựa chọn trong menu</returns>
int Menu()
{
	system("cls");
	int option = 0;
	cout << "Select Unit: " << endl;
	cout << "0:Exit" << endl;
	cout << "1:Exam_0101_Helloword" << endl;
	cout << "Option: ";
	
	cin >> option;
	return option;
}
void main()
{
	int _option = 0;
	while (_option =Menu() != 0)
	{
		switch (_option)
		{
		case 1:
			Exam_0101_Main();
		default:
			cout << "-----------------" << endl;
		}
	}
}