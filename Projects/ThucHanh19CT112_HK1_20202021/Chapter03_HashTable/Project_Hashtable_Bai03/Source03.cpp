#include "iostream"
#include "string"
#include "iomanip"
#include "math.h"

using namespace std;
typedef struct sinhvien
{
	int soBaoDanh;
	string tenSinhVien;
	string khuVucUuTien;
	float toan;
	float ly;
	float hoa;
}SINHVIEN;
typedef SINHVIEN item;
void NhapMotSinhVien(item& sinhVien)
{
	cout << "Nhap SBD: ";
	cin >> sinhVien.soBaoDanh;
	cin.ignore();
	cout << "Nhap ten SV: ";
	getline(cin, sinhVien.tenSinhVien);
	cout << "Nhap Khu vuc (KV1; KV2; KV3): ";
	getline(cin, sinhVien.khuVucUuTien);
	cout << "Nhap Diem toan: ";
	cin >> sinhVien.toan;
	cout << "Nhap Diem Ly: ";
	cin >> sinhVien.ly;
	cout << "Nhap Diem Hoa: ";
	cin >> sinhVien.hoa;
}
void XuatThongTinMotSinhVien(item sinhVien,int row)
{
	if (row == 0)
	{
		cout << setw(5) << left << "SBD";
		cout << setw(30) << left << "| Ten sinh vien";
		cout << setw(30) << left << "| Khu vuc";
		cout << setw(10) << left << "| Toan";
		cout << setw(10) << left << "| Ly";
		cout << setw(10) << left << "| Hoa";
		cout << setw(10) << left << "| Diem TB" << endl;
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
	cout << setw(10) << right << (sinhVien.toan+sinhVien.ly+sinhVien.hoa)/3 << endl;
}
#define MAX 100
typedef struct hashtable
{
	item data[MAX];
	int count;
}HASHTABLE;
void InitHashtable(HASHTABLE& hashTable,int size)
{
	for (int i = 0; i < size; i++)
	{
		hashTable.data[i].soBaoDanh = -1;
	}
	hashTable.count = 0;
}
int HK(int value, int size)
{
	return value % size;
}
bool Push(HASHTABLE& hashTable, item value, int size)
{
	int i = HK(value.soBaoDanh, size);
	while (hashTable.data[i].soBaoDanh != -1 && hashTable.count < size)
	{
		i = ++i % size;
	}
	if (hashTable.count < size)
	{
		hashTable.data[i] = value;
		hashTable.count++;
	}
	else
	{
		return true;
	}
	return false;
}
void NhapDanhSachSinhVien(HASHTABLE& hashtable, int size)
{
	item sinhVien;
	do
	{
		NhapMotSinhVien(sinhVien);
		if (!Push(hashtable, sinhVien, size))
		{
			cout << "ban co muon nhap tiep khong (yes/no): ";
			string chon;
			cin.ignore();
			getline(cin, chon);
			if (chon == "no")
				break;
		}
		else
		{
			cout << "Hashtable full";
			break;
		}

	} while (true);
}
void XuatToanBoDanhSachSinhVien(HASHTABLE hashTable, int size)
{
	int j = 0;
	for (int i = 0; i < size; i++)
	{
		if (hashTable.data[i].soBaoDanh != -1)
			XuatThongTinMotSinhVien(hashTable.data[i],j++);
	}
}
bool LaSoNguyenTo(int number)
{
	if (number <= 1) {
		return false;
	}
	for (int i = 2; i <=sqrt(number); i++) {
		if (number % i == 0) {
			return false;
		}
	}
	return true;
}
int TimSoNguyenToNhoNhatLonHonN(int number)
{
	while (!LaSoNguyenTo(number))
	{
		number++;
	}
	return number;
}

bool SearchBySBD(HASHTABLE hashTable,item &result, int size)
{
	int soBaoDanh;
	cout << "Nhap SBD sinh vien: ";
	cin >> soBaoDanh;
	int i = HK(soBaoDanh, size);
	while (hashTable.data[i].soBaoDanh != -1 && hashTable.data[i].soBaoDanh!=soBaoDanh)
	{
		i = ++i % size;
	}
	if (hashTable.data[i].soBaoDanh==soBaoDanh)
	{
		result= hashTable.data[i];
		return true;
	}
	return false;
}
int menu()
{
	cout << "1. Nhap danh sach"<<endl;
	cout << "2. Xuat danh sach" << endl;
	cout << "3. tim kiem sinh vien theo SBD" << endl;
	cout << "4. Thoat" << endl;
	int chon;
	cout << "Chon chuc nang: ";
	cin >> chon;
	return chon;
}
void main()
{
	HASHTABLE hashTable;
	int size = TimSoNguyenToNhoNhatLonHonN(20);
	InitHashtable(hashTable, size);
	int chon;
	item result;
	while (true)
	{
		chon = menu();
		switch (chon)
		{
		case 1:
			NhapDanhSachSinhVien(hashTable, size);
			break;
		case 2:
			XuatToanBoDanhSachSinhVien(hashTable, size);
			break;
		case 3:
			if (SearchBySBD(hashTable, result, size))
				XuatThongTinMotSinhVien(result, 0);
			else
				cout << "Khong co sinh vien can tim";
			break;
		case 4:
			return;
		}
	}
	system("pause");
}