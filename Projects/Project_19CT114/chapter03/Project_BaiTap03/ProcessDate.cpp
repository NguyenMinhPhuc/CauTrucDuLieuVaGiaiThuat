#include "iostream"
#include "sstream"
using namespace std;

typedef struct date
{
	int day;
	int month;
	int year;
}DATE;
bool CheckYear(int year)
{
	if (year >= 1900 && year <= 3000)
		return true;
	return false;
}
bool CheckMonth(int month)
{
	if (month >= 1 && month <= 12)
		return true;
	return false;
}
bool IsLeapYear(int year)
{
	if (year % 400 == 0)
		return true;
	if (year % 4 == 0 && year % 100 != 0)
		return true;
	return false;
}
int DateByMonth(int day, int month, int year)
{
	int dateByMonth = 0;
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		dateByMonth = 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		dateByMonth = 30;
		break;
	case 2:
		if (IsLeapYear(year))
			dateByMonth = 29;
		else
			dateByMonth = 28;
	}
	return dateByMonth;
}
bool CheckDay(int day, int month,int year)
{
	if (day >= 1 && day <= DateByMonth(day,month,year))
		return true;
	return false;
}
bool CheckDate(DATE value)
{
	if (CheckYear(value.year))
	{
		if (CheckMonth(value.month))
		{
			if (CheckDay(value.day, value.month,value.year))
			{
				return true;
			}
		}
	}
	return false;
}
static DATE NhapNgay()
{
	DATE outPut;
	int j = 0;
	do{
		if (j != 0)
		{
			cout << "Ngay nhap sai dinh dang (dd mm yyyy)" << endl;
			cout << "Xin vui long nhap lai: ";
		}
		j++;
		cin >> outPut.day >> outPut.month >> outPut.year;
	} while (!CheckDate(outPut));
	return outPut;
}
int ChuyenStringToInt(string value)
{
	stringstream str2num(value);
	int x = 0;
	str2num >> x;
	return x;
}
static DATE NhapNgayString(string delimiter)
{
	DATE outPut;
	string date;
	int j = 0;
	do
	{
		if (j != 0)
		{
			cout << "Ngay nhap sai dinh dang (dd/MM/yyyy)" << endl;
			cout << "Xin vui long nhap lai: ";
		}
		j++;
		getline(cin, date);
		int pos = 0;
		string token[3];
		int i = 0;
		while ((pos = date.find(delimiter)) != string::npos) {
			token[i++] = date.substr(0, pos);
			date.erase(0, pos + delimiter.length());
		}
		token[i] = date;
		outPut.day = ChuyenStringToInt(token[0]);
		outPut.month = ChuyenStringToInt(token[1]);
		outPut.year = ChuyenStringToInt(token[2]);
	} while (!CheckDate(outPut));
	return outPut;
}
static string XuatNgay(DATE value)
{
	string outPut;
	outPut.append(to_string(value.day));
	outPut.append("/");
	outPut.append(to_string(value.month));
	outPut.append("/");
	outPut.append(to_string(value.year));
	return outPut;
}
