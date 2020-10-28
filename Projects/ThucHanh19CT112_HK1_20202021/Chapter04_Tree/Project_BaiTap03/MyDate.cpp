#include "iostream"
#include "string"
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
	if (year <= 1900 && year >= 2999)
		return true;
	return false;
}
bool CheckMonth(int month)
{
	if (month <= 1 && month >= 12)
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
int GetDateByMonth(int month, int year)
{
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return 31;
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
	case 2:
		if (IsLeapYear(year))
			return 29;
		else
			return 28;
	}
}
bool CheckDay(DATE value)
{
	//lay gia tri ngay theo thang 
	int DayByMonth = GetDateByMonth(value.month, value.year);
	if (value.day >= 1 && value.day <= DayByMonth)
		return true;
	return false;
}
bool CheckDate(DATE inPut)
{
	if (CheckYear(inPut.year))
		if (CheckMonth(inPut.month))
			if (CheckDay(inPut))
				return true;
	return false;
}
//dd MM yyyy
static DATE NhapNgay()
{
	DATE outPut;
	int j = 0;
	do
	{
		if(j!=0)
			cout << "Sai dinh dang! Xin vui long nhap lai ngay (dd MM yyyy): ";
		j++;
		cin >> outPut.day >> outPut.month >> outPut.year;
	} while (!CheckDate(outPut));

	return outPut;
}
int StringToInt(string value)
{
	stringstream str2num(value);
	int x = 0;
	str2num >> x;
	return x;
}
//dd/MM/yyyy
static DATE NhapNgayString(string delimiter)
{
	DATE outPut;
	string date;
	int j = 0;
	do
	{
		if (j != 0)
			cout << "Sai dinh dang! Xin vui long nhap lai ngay (dd MM yyyy): ";
		j++;
		getline(cin, date);
		int pos = 0;
		string token[3];
		int i = 0;
		while ((pos = date.find(delimiter)) != string::npos)
		{
			token[i++] = date.substr(0, pos);
			date.erase(0, pos + delimiter.length());
		}
		token[i] = date;//yyyy
		outPut.day = StringToInt(token[0]);
		outPut.month = StringToInt(token[1]);
		outPut.year = StringToInt(token[2]);
		
	} while (!CheckDate(outPut));
}