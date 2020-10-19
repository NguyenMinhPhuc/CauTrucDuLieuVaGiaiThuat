#include "iostream"
#include "string"
#include "iomanip"
#include "math.h"
using namespace std;
//1. xay dung hashtable
//2. Nhap thong tin san pham

#define MAX 100
typedef struct sanpham {
	int MaSP;
	string TenSP;
	string DVT;
	float DonGia;
	int SoLuong;
}SANPHAM;

typedef SANPHAM item;

typedef struct hashtable {
	item data[MAX];
	int count;
}HASHTABLE;
item NhapMotSanPham(int i)
{
	item outPut;
	cout << "Nhap SP thu [" << i+ 1 << "]: ";
	cin >> outPut.MaSP;
	cin.ignore();
	cout << "Nhap ten SP: ";
	getline(cin, outPut.TenSP);
	cout << "Nhap DVT: ";
	getline(cin, outPut.DVT);
	cout << "Nhap Don Gia: ";
	cin >> outPut.DonGia;
	cout << "Nhap So luong: ";
	cin >> outPut.SoLuong;

	return outPut;
}
void XuatThongTinMotSanPham(item sanPham,int row)
{
	if (row == 0)
			{
				cout << setw(5) << left << "MaSP";
				cout << setw(30) << left << "| Ten SP";
				cout << setw(30) << left << "| DVT";
				cout << setw(20) << left << "| Don Gia";
				cout << setw(10) << left << "| SoLuong" << endl;
				cout << setfill('-');		
				cout << setw(95) << "-" << endl;
			}
			// reset fill bằng ký tự ' '
			cout << setfill(' ');
			cout << setw(5) << left << sanPham.MaSP;
			cout << setw(30) << left << sanPham.TenSP;
			cout << setw(30) << left << sanPham.DVT;
			cout << setw(20) << left  << sanPham.DonGia;
			cout << setw(10) << left  << sanPham.SoLuong << endl;
}
int HK1(int value, int size)
{
	return value % size;
}
int HK2(int value, int size)
{
	return size - 2 - (value % (size - 2));
}
void InitHashTable(HASHTABLE& hashtable,int size)
{
	for (int i = 0; i < size; i++)
	{
		hashtable.data[i].MaSP = -1;
	}
	hashtable.count = 0;
}
void Push(HASHTABLE& hashtable, item value, int size)
{
	int i = HK1(value.MaSP, size);
	int j = HK2(value.MaSP, size);
	//kiem tra 2 trường hợp phải băm lại:
	//1. i là vị trí đã có giá trị 
	//2. 2 hashtable chưa đầy
	while (hashtable.data[i].MaSP!=-1&&hashtable.count<size)
	{
		i = HK1(i + j, size);
	}
	if (hashtable.count < size)
	{
		hashtable.data[i] = value;
		hashtable.count++;
	}
	else
	{
		cout << "Hashtable full";
	}
}
void NhapDanhSachSanPham(HASHTABLE& hashtable, int size)
{
	item sanPham;
	do
	{
		sanPham = NhapMotSanPham(hashtable.count);
		Push(hashtable, sanPham, size);
		string option;
		cout << "Ban co nhap tiep (yes/no): ";
		cin.ignore();
		getline(cin, option);
		if (option == "no")
			break;
	} while (true);
}
void InDanhSachSanPham(HASHTABLE hashtable,int size)
{
	int j=0;
	for (int i = 0; i < size; i++)
	{
		if (hashtable.data[i].MaSP != -1)
		{
			XuatThongTinMotSanPham(hashtable.data[i],j++);
		}
	}
}
bool LaSoNguyenTo(int number)
{
	if (number <= 1) {
		return false;
	}
	for (int i = 2; i <= sqrt(number); i++) {
		if (number % i == 0) {
			return false;
		}
	}
	return true;
}
int SoNguyenToCanTim(int number)
{
	while (LaSoNguyenTo(number)==false)
	{
		number++;
	}
	return number;
}
void XoaSanPhamTheoMaSo(HASHTABLE& hashtable, int size)
{
	int value;
	cout << "Nhap gia tri can xoa: ";
	cin >> value;
	int i = HK1(value, size);
	int j = HK2(value, size);
	//kiem tra 2 trường hợp phải băm lại:
	//1. i là vị trí đã có giá trị 
	//2. 2 hashtable chưa đầy
	while (hashtable.data[i].MaSP != -1 && hashtable.data[i].MaSP != value)
	{
		i = HK1(i + j, size);
	}
	if (hashtable.data[i].MaSP == value)
	{
		hashtable.data[i].MaSP = -1;
		hashtable.count--;
	}
	else
	{
		cout << "khong co gia tri";
	}
}
void main()
{
	HASHTABLE hashtable;
	int size = SoNguyenToCanTim(11);
	cout << size;
	InitHashTable(hashtable, size);
	NhapDanhSachSanPham(hashtable, size);

	InDanhSachSanPham(hashtable, size);

	XoaSanPhamTheoMaSo(hashtable, size);
	system("pause");
}