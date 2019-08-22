#include <iostream>
using namespace std;
int menu()
{
	int option;
	cout << "-----Menu----";
	cout << "\n1. Init Hashtable";
	cout << "\n2. Input Hashtable";
	cout << "\n3. Print Hashtable";
	cout << "\n4. Search by MaMH";
	cout << "\n5. Delete by MaMH";
	cout << "\n6. Exit";
	cout << "seleted Option: "; cin >> option;
	return option;
}
//tổ chức dữ liệu để lưu trữ thông tin mặt hàng cần:
typedef struct mathang
{
	int MaMH;
	char TenMH[30];
	char DVT[20];
	float DoiGia;
	int SoLuong;
}MATHANG;
MATHANG Nhap_01_MatHang(int i)
{
	MATHANG _matHang;
	cout << "Nhap Thong tin mat hang thu: " << i << endl;
	cout << "MaMH: "; cin >> _matHang.MaMH;
	cout << "Ten MH: "; fflush(stdin); cin.getline(_matHang.TenMH, 30);
	cout << "DVT: "; cin >> _matHang.DVT;
	cout << "Don gia: "; cin >> _matHang.DoiGia;
	cout << "So luong: "; cin >> _matHang.SoLuong;
	return _matHang;
}
void XuatThongTin_01_MatHang(MATHANG mathang)
{
	cout << "MaMH: " << mathang.MaMH << "\t";
	cout << "Ten MH : " << mathang.TenMH << "\t";
	cout << "DVT : " << mathang.DVT << "\t";
	cout << "So luong : " << mathang.SoLuong << "\t";
	cout << "Don gia: " << mathang.DoiGia << endl;
}
//Tạo cấu trúc bảng băm để lưu trữ thông tin mặt hàng.
//value là giá trị cần lưu trữ
//Size: kích thước bảng băm;
int HK1(int value, int size)
{
	return (value%size);
}
int HK2(int value, int size)
{
	return size - 2 - (value % (size - 2));
}
typedef struct bangbam
{
	MATHANG data[101];
	int soPT;
}BB;
void Init(BB &b, int size)
{
	for (int i = 0; i < size; i++)
	{
		b.data[i].MaMH = -1;
	}
	b.soPT = 0;

}
//Thêm 1 phẩn tử vào bảng băm
void Push(BB &b, MATHANG value, int size)
{
	int i = HK1(value.MaMH, size);
	int j = HK2(value.MaMH, size);
	while (b.data[i].MaMH != -1 && b.soPT<size)
	{
		i = (i + j) % size;
	}
	if (b.soPT < size)
	{
		b.data[i] = value;
		b.soPT++;
	}
	else
	{
		cout << "bang bam day:";
	}
}
void Nhap_DanhSach_MatHang(BB &b)
{
	MATHANG _mathang;
	char chon;
	do
	{
		_mathang = Nhap_01_MatHang(b.soPT + 1);
		Push(b, _mathang, 101);
		cout << "Ban co muon nhap tiep khong (y/n):"; cin >> chon;
	} while (chon=='y'||chon=='Y');
}
void PrintBB(BB b)
{
	for (int i = 0; i < 101; i++)
	{
		if (b.data[i].MaMH != -1)
			XuatThongTin_01_MatHang(b.data[i]);
	}
}
MATHANG SearchByID(BB b, int ID, int size)
{
	int i = HK1(ID, size);
	int j = HK2(ID, size);
	MATHANG mh;
	mh.MaMH = -1;
	while (b.data[i].MaMH!=-1)
	{
		if (b.data[i].MaMH == ID){
			mh = b.data[i];
			break;
		}
		else{
			i = (i + j) % size;
		}
	}
	return mh;
} 
void Delete(BB &b, int ID, int size)
{
	int i = HK1(ID, size);
	int j = HK2(ID, size);
	
	while (b.data[i].MaMH != -1)
	{
		if (b.data[i].MaMH == ID){
			b.data[i].MaMH = -1;
			b.soPT--;
		}
		else{
			i = (i + j) % size;
		}
	}
	
}
void main()
{
	int option = 0;
	BB b;
	do
	{
		option = menu();
		switch (option)
		{
		case 1:
			Init(b,101);
			break;
		case 2:
			cout << "Nhap danh sach:";
			cout << endl;
			Nhap_DanhSach_MatHang(b);
			break;
		case 3:
			cout << "Danh sach:";
			cout << endl;
			PrintBB(b);
			break;
		case 4:
			cout << "Search:";
			int ID;
			cout << "Nhap khoa can tim: "; cin >> ID;
			MATHANG mh = SearchByID(b, ID, 101);
			if (mh.MaMH != -1)
			{
				XuatThongTin_01_MatHang(mh);
			}
			else
			{
				cout << "khong tim thay";
			}
			cout << endl;
			//PrintBB(b);
			break;
		}
	} while (option != 6);
}