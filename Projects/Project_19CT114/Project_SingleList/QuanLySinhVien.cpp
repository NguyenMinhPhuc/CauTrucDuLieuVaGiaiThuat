#include "iostream"
#include "string"
#include "iomanip"
using namespace std;
int menu()
{
	int chon=0;
	cout << "1. Nhap Thong tin sinh vien" << endl;
	cout << "2. In danh sach sinh vien" << endl;
	cout << "3. Tim kiem sinh vien theo ma so" << endl;
	cout << "4. Sua thong tin sinh vien" << endl;
	cout << "5. Xoa sinh vien" << endl;
	cout << "6. lay danh sach sinh vien chua xep lop" << endl;
	cout << "7. Thoat khoi chuong trinh" << endl;
	cout << "Chon chuc nang : ";
	cin >> chon;
	return chon;
}

typedef struct sinhvien
{
	int maSo;
	string hoTen;
	string ngaySinh;
	string diaChi;
	string lop;
}SINHVIEN;
typedef SINHVIEN dataType;
//1. Phuong thuc nhap sinh vien
dataType InPut()
{
	dataType sv;
	cout << "Nhap Maso: "; cin >> sv.maSo;
	cout << "Nhap Ho va Ten: "; 
	cin.ignore();
	getline(cin, sv.hoTen);
	cout << "Nhap Ngay sinh: ";
	getline(cin, sv.ngaySinh);
	cout << "Nhap Dia chi: ";
	getline(cin, sv.diaChi);
	cout << "Nhap Lop: ";
	getline(cin, sv.lop);
	return sv;
}
//2. Phuong thuc xuat thong tin sinh vien
void OutPut(dataType sv,int row)
{
	if (row == 0)
	{
		cout << setw(5) << left << "Maso";
		cout << setw(30) << left << "| Ho va ten";
		cout << setw(30) << left << "| Ngay sinh";
		cout << setw(20) << left << "| Dia chi";
		cout << setw(10) << left << "| Lop" << endl;
		cout << setfill('-');		
		cout << setw(95) << "-" << endl;
	}
	// reset fill bằng ký tự ' '
	cout << setfill(' ');
	cout << setw(5) << left << sv.maSo;
	cout << setw(30) << left << sv.hoTen;
	cout << setw(30) << left << sv.ngaySinh;
	cout << setw(20) << left  << sv.diaChi;
	cout << setw(10) << left  << sv.lop << endl;
}
typedef struct node
{
	dataType data;
	node* link;
}NODE;
typedef NODE *ptrNode;
typedef struct list{
	ptrNode first;
	ptrNode last;
}LIST;
void InitList(LIST &list)
{
	list.first = list.last = NULL;
}
ptrNode GetNode(dataType sinhVien)
{
	ptrNode p = new NODE;
	if (p == NULL)
		exit(1);
	p->data = sinhVien;
	p->link = NULL;

	return p;
}
void AddFirst(LIST &list, ptrNode newNode)
{
	if (list.first == NULL)
	{
		list.first = newNode;
		list.last = list.first;
	}
	else
	{
		newNode->link = list.first;
		list.first = newNode;
	}
}
void InsertList(LIST &list, dataType sinhVien)
{
	ptrNode p = GetNode(sinhVien);
	AddFirst(list, p);
}
void CreateList(LIST &list)
{
	dataType sv;
	string chon;
	do{
		sv = InPut();
		InsertList(list, sv);
		cout << "Ban co muon nhap tiep (yes/no): ";
		getline(cin, chon);
	} while (chon == "yes");
}
void InDanhSachSinhVien(LIST list)
{
	ptrNode p = list.first;
	int i = 0;
	while (p!=NULL)
	{
		OutPut(p->data,i++);
		p = p->link;
	}
}
void TimKiemSinhVienTheoMaSo(LIST list)
{
	int maSo;
	cout << "Nhap maSo: "; cin >> maSo;

	ptrNode p = list.first;
	while (p != NULL)
	{
		if (p->data.maSo == maSo)
		{
			OutPut(p->data, 0);
			break;
		}
		p = p->link;
	}
}
void ChinhSuaThongTinSinhVien(LIST list)
{
	int maSo;
	cout << "Nhap maSo can sua: "; cin >> maSo;

	ptrNode p = list.first;
	while (p != NULL)
	{
		if (p->data.maSo == maSo)
		{
			cout << "Nhap lai thong tin cho sinh vien co maSo:" << maSo;
			dataType sv = InPut();
			p->data = sv;
			break;
		}
		p = p->link;
	}
}

void XoaNodeSauQ(LIST &list, ptrNode q)
{
	if (q != NULL&&q->link != NULL)
	{
		ptrNode p;
		p = q->link;

		q->link = p->link;
		if (p->link == NULL)
			list.last = q;
		delete p;
	}
}
void XoaDauDanhSach(LIST &list)
{
	ptrNode p = list.first;
	if (list.first != NULL)
	{
		list.first = p->link;
		if (list.first == NULL)
			list.last = NULL;
		
		delete p;
	}
}
void XoaSinhVienTheoMaSo(LIST &list)
{
	int maSo;
	cout << "Nhap ma can xoa: "; cin >> maSo;
	ptrNode p = list.first;
	ptrNode q = p;
	while (p != NULL)
	{
		if (p->data.maSo == maSo)
		{
			if (p == list.first)
			{
				XoaDauDanhSach(list);
				break;
			}
			else{
				XoaNodeSauQ(list, q);
				break;
			}
		}
		q = p;
		p = p->link;
	}
	
}
LIST LayDanhSachSinhVienChuaXepLop(LIST list)
{
	LIST listChuaXepLop;
	InitList(listChuaXepLop);

	ptrNode p = list.first;
	while (p != NULL)
	{
		if (p->data.lop == " ")
		{
			AddFirst(listChuaXepLop, p);
			break;
		}
		p = p->link;
	}
	return listChuaXepLop;
}

void main()
{
	int chon;
	LIST list;
	InitList(list);

	while (true)
	{
		chon = menu();
		switch (chon)
		{
		case 1:
			CreateList(list);
			break;
		case 2:
			InDanhSachSinhVien(list);
			break;
		case 3:
			TimKiemSinhVienTheoMaSo(list);
			break;
		case 4:
			ChinhSuaThongTinSinhVien(list);
			break;
		case 5:XoaSinhVienTheoMaSo(list);
			break;
		case 6:
			LIST list1;
			InitList(list1);
			list1 = LayDanhSachSinhVienChuaXepLop(list);
			InDanhSachSinhVien(list1); 
			break;
		case 7:
			return;
		}
	}system("pause");
}