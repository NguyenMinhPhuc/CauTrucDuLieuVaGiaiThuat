#include <iostream>

using namespace std;

typedef struct node
{
	int data;
	node*link;
}NODE;

typedef struct list
{
	NODE* first;
	NODE* last;
}LIST;

void InitList(LIST &list)
{
	list.first = list.last = NULL;
}

NODE* GetNode(int x)
{
	NODE*p;
	p = (NODE*)malloc(sizeof(NODE));
	if (p == NULL)
	{
		exit(1);
	}
	p->data = x;
	p->link = NULL;
	return p;
}

void ThemVaoDau(LIST &list, NODE* p)
{
	if (list.first == NULL)
	{
		//1
		list.first = p;
		//2
		list.last = list.first;
	}
	else
	{
		p->link = list.first;
		list.first = p;
	}
}
void ThemMotNODEVaoDanhSach(LIST &list,int x)
{
	NODE*p;
	p = GetNode(x);
	if (p != NULL)
		ThemVaoDau(list, p);
}
void  NhapDanhSach(LIST &list)
{
	int i=0, x;
	while (true)
	{
		cout << "Nhap pt thu " << ++i << " (nhap -1 de thoat):";
		cin >> x;
		if (x == -1)
			break;
		ThemMotNODEVaoDanhSach(list, x);
	}
}
void InDanhSach(LIST list)
{
	NODE*p = list.first;
	while (p!=NULL)
	{
		//1. xử lý dữ liệu
		cout << p->data << ", ";
		//2. tăng giá trị 
		p = p->link;
	}
}
void InDanhSachSoChan(LIST list)
{
	NODE*p = list.first;
	while (p != NULL)
	{
		//1. xử lý dữ liệu
		if (p->data%2==0)
			cout << p->data << ", ";
		//2. tăng giá trị 
		p = p->link;
	}
}
void InDanhSachSoLe(LIST list)
{
	NODE*p = list.first;
	while (p != NULL)
	{
		//1. xử lý dữ liệu
		if (p->data % 2 != 0)
			cout << p->data << ", ";
		//2. tăng giá trị 
		p = p->link;
	}
}
bool KiemTraNguyenTo(int n)
{
	int count = 0;
	for (int i = 2; i <= sqrt(n); i++){
		if (n % i == 0){
			count++;
		}
	}
	if (count == 0)
		return true;
	return false;
}

void InDanhSachSoNguyenTo(LIST list)
{
	NODE*p = list.first;
	while (p != NULL)
	{
		//1. xử lý dữ liệu
		if (KiemTraNguyenTo(p->data)==true)
			cout << p->data << ", ";
		//2. tăng giá trị 
		p = p->link;
	}
}
void InDanhSachGop(LIST list, int option)
{
	switch (option)
	{
	case 1:
		InDanhSach(list);
		break;
	case 2:
		InDanhSachSoChan(list);
		break;
	case 3:
		InDanhSachSoLe(list);
		break;
	case 4:
		InDanhSachSoNguyenTo(list);
		break;
	}
}
void TimGiaTriVuaNhap(LIST list)
{
	int x;
	cout << "Nhap gia tri can tim: "; cin >> x;
	NODE*p = list.first;
	int i = 0;
	while (p!=NULL)
	{
		//1.
		i++;
		if (p->data == x)
		{
			cout << "trong list co gia tri can tim tai vi tri "<<i;
			break;
		}
		
		//2.
		p = p->link;
	}
	if (p == NULL)
	{
		cout << "không tim thay";
	}
	

}

void TimKiemNhieuGiaTriX(LIST list)
{
	int x;
	cout << "Nhap gia tri can tim: "; cin >> x;
	NODE*p = list.first;
	LIST listnew;
	InitList(listnew);
	while (p != NULL)
	{
		if (p->data == x)
		{
			ThemMotNODEVaoDanhSach(listnew, x);
		}
		p = p->link;
	}
	if (listnew.first == NULL)
		cout << "Khong co gia tri can tim trong danh sach";
	else
		InDanhSach(listnew);
}
void main()
{
	LIST list;
	InitList(list);

	NhapDanhSach(list);
	cout << endl;
	InDanhSachGop(list,1);
	cout << endl;
	TimGiaTriVuaNhap(list);
	cout << endl;
	TimKiemNhieuGiaTriX(list);

	system("pause");
}