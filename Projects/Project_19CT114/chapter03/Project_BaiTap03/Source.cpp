#include "iostream"
#include "string"
#include "sstream"
#include "iomanip"

using namespace std;

#define MAX 1001

typedef struct thisinh
{
	string soBaoDanh;
	string tenThiSinh;
	string khuVucUuTien;
	float toan=0;
	float ly=0;
	float hoa=0;

}THISINH;
void NhapThongTinMotThiSinh(THISINH& thisinh)
{
	cin.ignore();
	cout << "Nhap SBD: ";
	getline(cin,thisinh.soBaoDanh);
	cout << "Nhap ten Thi sinh: ";
	getline(cin, thisinh.tenThiSinh);
	cout << "Nhap Khu Vuc: ";
	getline(cin, thisinh.khuVucUuTien);
	cout << "Nhap diem toan: ";
	cin >> thisinh.toan;
	cout << "Nhap diem ly: ";
	cin >> thisinh.ly; 
	cout << "Nhap diem hoa: ";
	cin >> thisinh.hoa;
}
void XuatThongTinMotThiSinh(THISINH thisinh, int row)
{
	if (row == 0)
	{
		//hien thi tieu de
		cout << setw(5) << left << "SBD";
		cout << setw(30) << left << "Ten thi sinh";
		cout << setw(30) << left << "Khu vuc";
		cout << setw(10) << left << "Toan";
		cout << setw(10) << left << "Ly";
		cout << setw(10) << left << "Hoa" << endl;
		cout << setfill('-');
		cout << setw(95) << "-" << endl;	
	}
	cout << setfill(' ');
	cout << setw(5) << left << thisinh.soBaoDanh;
	cout << setw(30) << left << thisinh.tenThiSinh;
	cout << setw(30) << left << thisinh.khuVucUuTien;
	cout << setw(10) << right << thisinh.toan;
	cout << setw(10) << right << thisinh.ly;
	cout << setw(10) << right << thisinh.hoa<<endl;
}

typedef struct hashtable
{
	THISINH DATA[MAX];
	int count;

}HASHTABLE;

void InitHashtable(HASHTABLE& hashtable, int size)
{
	for (int i = 0; i < size; i++)
	{
		hashtable.DATA[i].soBaoDanh = "";
	}
	hashtable.count = 0;
}
int HK(int value, int size)
{
	return value % size;
}
int ChuyenStringThanhInt(string chuoiSo)
{
	int number;
	stringstream str2num(chuoiSo);
	str2num >> number;
	return number;
}
void Push(HASHTABLE& hashtable, THISINH value, int size)
{
	int i = HK(ChuyenStringThanhInt(value.soBaoDanh), size);
	while (hashtable.DATA[i].soBaoDanh!=""&&hashtable.count<size)
	{
		i = ++i % size;
	}
	if (hashtable.count < size)
	{
		hashtable.DATA[i] = value;
		hashtable.count++;
	}
	else
	{
		cout << "Hashtable full";
	}
}
void NhapDanhSachThiSinh(HASHTABLE& hashtable, int size)
{
	THISINH thisinh;
	do
	{
		NhapThongTinMotThiSinh(thisinh);
		Push(hashtable, thisinh, size);
		string chon;
		cout << "Ban co muon nhap tiep (yes/no): ";
		cin.ignore();
		getline(cin, chon);
		if (chon == "no")
			break;
	} while (true);
}
void XuatDanhSachThiSinh(HASHTABLE &hashtable, int size)
{
	int j = 0;
	for (int i = 0; i < size; i++)
	{
		if (hashtable.DATA[i].soBaoDanh != "")
			XuatThongTinMotThiSinh(hashtable.DATA[i],j++);
	}
}
bool XuatThongTinSinhVienTheoSoBD(HASHTABLE hashtable, THISINH &thisinh,int size)
{
	string soBaoDanh;
	cout << "Nhap SBD:";
	cin.ignore();
	getline(cin, soBaoDanh);
	
	int i= HK(ChuyenStringThanhInt(soBaoDanh), size);
	while (hashtable.DATA[i].soBaoDanh!=""&&hashtable.DATA[i].soBaoDanh!=soBaoDanh)
	{
		i = ++i % size;
	}
	if (hashtable.DATA[i].soBaoDanh==soBaoDanh)
	{
		thisinh= hashtable.DATA[i];
		return true;
	}
	return false;
}
int menu()
{
	cout << "1. Nhap Thi sinh" << endl;
	cout << "2. Xuat danh sach" << endl;
	cout << "3. Tim theo SBD" << endl;
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
int SoNguyenToNhoNhatLonHon(int number)
{
	while (LaSoNguyenTo(number) == false)
	{
		number++;
	}
	return number;
}
int main(int argc, char* argv[])
{
	int chon;
	HASHTABLE hashtable;
	int size = SoNguyenToNhoNhatLonHon(20);
	THISINH thisinh;
	while (true)
	{
		chon = menu();
		switch (chon)
		{
		case 1:
			NhapDanhSachThiSinh(hashtable, size);
			break;
		case 2:
			XuatDanhSachThiSinh(hashtable, size);
			break;
		case 3:
			if (XuatThongTinSinhVienTheoSoBD(hashtable, thisinh, size) == true)
				XuatThongTinMotThiSinh(thisinh, 0);
			else
				cout << "Khong co thi sinh can tim"<<endl;
			break;
		case 4:
			return;
		}
	}
}