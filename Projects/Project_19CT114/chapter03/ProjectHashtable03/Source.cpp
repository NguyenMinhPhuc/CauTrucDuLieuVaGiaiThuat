#include "iostream"
#include "string"
#include "iomanip"
#include "sstream"

using namespace std;
#define MAX 1001
//xay dung cau truc sinh vien
typedef struct sinhvien
{	
	string soBaoDanh;
	string tenSinhVien;
	string khuVucUuTien;
	float toan, ly, hoa;
}SINHVIEN;
typedef SINHVIEN item;

void NhapMotSinhVien(item &sinhVien)
{
	cin.ignore();
	cout << "Nhap SBD: ";
	getline(cin, sinhVien.soBaoDanh);
	cout << "Nhap ten SV: ";
	getline(cin, sinhVien.tenSinhVien);
	cout << "Nhap khu vuc (kv1, kv2, kv3): ";
	getline(cin, sinhVien.khuVucUuTien);
	cout << "Nhap diem toan: ";
	cin >> sinhVien.toan;
	cout << "Nhap diem ly: ";
	cin >> sinhVien.ly;
	cout << "Nhap diem hoa: ";
	cin >> sinhVien.hoa;
}
void XuatMotSinhVien(item sinhVien,int row)
{
	if (row == 0)
	{
		cout << setw(5) << left << "SBD";
		cout << setw(30) << left << "| Ten Sv";
		cout << setw(30) << left << "| Khu Vuc";
		cout << setw(10) << left << "| Toan";
		cout << setw(10) << left << "| Ly"; 
		cout << setw(10) << left << "| Hoa";
		cout << setw(10) << left << "| DTB" << endl;
		cout << setfill('-');
		cout << setw(105) << "-" << endl;
	}
	// reset fill bằng ký tự ' '
	cout << setfill(' ');
	cout << setw(5) << left << sinhVien.soBaoDanh;
	cout << setw(30) << left << sinhVien.tenSinhVien;
	cout << setw(30) << left << sinhVien.khuVucUuTien;
	cout << setw(10) << left << sinhVien.toan;
	cout << setw(10) << left << sinhVien.ly; 
	cout << setw(10) << left << sinhVien.hoa;
	cout << setw(10) << left << (sinhVien.toan + sinhVien.ly + sinhVien.hoa )/3<<endl;
}

typedef struct hashTable
{
	item data[MAX];
	int count;
}HASHTABLE;
void InitHashTable(HASHTABLE& hashTable, int size)
{
	for (int i = 0; i < size; i++)
	{
		hashTable.data[i].soBaoDanh = "";
	}
	hashTable.count = 0;
}
int ChuyenSBDToInt(string soBaoDanh)
{
	int outPut;
	stringstream str2num(soBaoDanh);

	str2num >> outPut;
	return outPut;
}
int HK(int value, int size)
{
	return value % size;
}

void XuatDanhSachSinhVien(HASHTABLE hashtable, int size)
{
	int j = 0;
	for (int i = 0; i < size; i++)
	{
		if (hashtable.data[i].soBaoDanh != "")
			XuatMotSinhVien(hashtable.data[i], j++);
	}
}
int menu()
{
	cout << "1. Nhap danh sach sinh vien"<<endl;
	cout << "2. Xuat danh sach sinh vien" << endl;
	cout << "3. Tim kiem sinh vien theo SBD" << endl;
	cout << "4. Thoat" << endl;
	int chon;
	cout << "Chon chuc nang: ";
	cin >> chon;
	return chon;
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
	while (LaSoNguyenTo(number) == false)
	{
		number++;
	}
	return number;
}
bool Push(HASHTABLE& hashtable, item value, int size)
{
	int i = HK(ChuyenSBDToInt(value.soBaoDanh), size);
	while (hashtable.data[i].soBaoDanh != "" && hashtable.count < size)
	{
		i = ++i % size;
	}
	if (hashtable.count < size)
	{
		hashtable.data[i] = value;
		hashtable.count++;
		return true;
	}
	else
	{
		cout << "hashtablt full";
		return false;
	}
}
bool SearchBySBD(HASHTABLE hashtable,item &sinhVien,string & soBaoDanh, int size)
{
	cout << "Nhap SBD";
	cin.ignore();
	getline(cin, soBaoDanh);
	int i = HK(ChuyenSBDToInt(soBaoDanh), size);
	while (hashtable.data[i].soBaoDanh != "" && hashtable.data[i].soBaoDanh!=soBaoDanh)
	{
		i = ++i % size;
	}
	if (hashtable.data[i].soBaoDanh == soBaoDanh)
	{
		sinhVien= hashtable.data[i];
		return true;
	}
	return false;
}
void NhapDanhSachSinhVien(HASHTABLE& hashtable, int size)
{
	item sinhVien;
	int check;
	do
	{
		NhapMotSinhVien(sinhVien);
		if (Push(hashtable, sinhVien, size))
		{
			cout << "Ban co tiep tuc (yes/no): ";
			string chon;
			cin.ignore();
			getline(cin, chon);
			if (chon == "no")
				break;
		}
		else
		{
			break;
		}
	} while (true);
}
void main()
{
	int chon;
	HASHTABLE hashtable;
	int size = SoNguyenToCanTim(20);
	InitHashTable(hashtable, size);
	item sinhVien;
	string soBaoDanh;
	while (true)
	{
		chon = menu();
		switch (chon)
		{
		case 1:
			NhapDanhSachSinhVien(hashtable, size);
			break;
		case 2:
			XuatDanhSachSinhVien(hashtable, size);
			break;
		case 3:
			if (SearchBySBD(hashtable, sinhVien,soBaoDanh, size))
			{
				XuatMotSinhVien(sinhVien, 0);
			}
			else
			{
				cout << "Khong tim thay sinh vien co SBD "<< soBaoDanh;
			}
			break;
		case 4:
			return;
		}
	}
}
