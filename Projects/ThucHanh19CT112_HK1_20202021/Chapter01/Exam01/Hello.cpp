#include "iostream";
using namespace std;

void HienThiCauChao()
{
	cout << "Hello!!"<<endl;
	cout << "Xin chao ca lop" << endl;
}
void Bai01(int number)
{
	if (number > 100)
		cout << "So " << number << "> 100" << endl;
	else
		cout << "So " << number << "<= 100" << endl;
}
int MaxNumber(int number1, int number2, int number3)
{
	int result = number1;
	if (number2 > result)
		result = number2;
	else if (number3 > result)
		result = number3;
	return result;
}
int menu()
{
	cout << "Chuc nang chuong trinh" << endl;
	cout << "1. Bai 01" << endl;
	cout << "2. Bai 02" << endl;
	cout << "3. Bai 03" << endl;
	cout << "4. Bai 04" << endl;
	cout << "5. Bai 05" << endl;
	cout << "6. Thoat" << endl;
	cout << "Vui long chon :";
	int chon;
	cin >> chon;
	return chon;
}
void main()
{
	int chon;
	while (true)
	{
		chon = menu();
		switch (chon)
		{
		case 1:
			cout << "Bai tap 01" << endl;
			int number;
			cout << "Nhap so :";
			cin >> number;
			Bai01(number);
			break;
		case 2:
			cout << "Bai tap 02" << endl;
			
			cout << MaxNumber(1, 2, 3);
			break;
		case 6:
			return;
		}
	}
	
	system("pause");//dung ket qua de xem
}

