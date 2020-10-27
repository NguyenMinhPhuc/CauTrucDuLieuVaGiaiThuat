//1. xay dung cau truc cay nhi phan
//2. them doc gia vao cay
//2.1.xay dung cau truc doc gia
//2.2. Nhap, xuat thong tin doc gia
//3. tim kiem doc gia co tuoi lon nhat.
//3.1 tim tuoi lon nhat
//4. dem so node 2 con va co ngay chi dinh.
#include "iostream"
#include <string>
#include <iomanip>
#include "../../chapter03/Project_BaiTap03/ProcessDate.cpp"
using namespace std;

typedef struct docgia {
	int maDG;
	string tenDG;
	DATE ngaySinh;
	string diaChi;
	DATE ngayLapThe;
}DOCGIA;
typedef struct node
{
	DOCGIA data;
	node* left;
	node* right;
}NODE;
typedef NODE* ptrNode;
typedef struct tree
{
	ptrNode root;
	int count;
}TREE;
void InitTree(TREE& tree)
{
	tree.root = NULL;
	tree.count = 0;
}
void NhapThongTinMotDocGia(DOCGIA& docGia,int index)
{
	cout << "Nhap doc gia thu [" << index << "]: "<<endl;
	cout << "Nhap maDG: "; cin >> docGia.maDG;
	cin.ignore();
	cout << "Nhap tenDG: ";
	getline(cin, docGia.tenDG);
	cout << "Nhap Dia chi: ";
	getline(cin, docGia.diaChi);
	cout << "Nhap ngaySinh (dd/mm/yyyy): ";
	docGia.ngaySinh = NhapNgayString("/");
	cout << "Nhap Lap The (dd/mm/yyyy): ";
	docGia.ngayLapThe = NhapNgayString("/");
}
void XuatThongTinMotDocGia(DOCGIA docGia,int index)
{
	if (index == 0)
	{
		cout << setw(5) <<left<< "MaDG";
		cout << setw(20) << left << "Ten DG";
		cout << setw(30) << left << "dia Chi";
		cout << setw(15) << left << "ngay sinh";
		cout << setw(15) << left << "ngay lap the"<<endl;
		cout << setfill('-');
		cout << setw(85) << "-" << endl;
	}
	cout<<setfill(' ');
	cout << setw(5) << left <<docGia.maDG;
	cout << setw(20) << left << docGia.tenDG;
	cout << setw(30) << left << docGia.diaChi;
	cout << setw(15) << right << XuatNgay(docGia.ngaySinh);
	cout << setw(15) << right << XuatNgay(docGia.ngayLapThe)  << endl;
}
void main()
{
	DOCGIA dg;
	NhapThongTinMotDocGia(dg,1);
	XuatThongTinMotDocGia(dg, 0);
	system("pause");
}