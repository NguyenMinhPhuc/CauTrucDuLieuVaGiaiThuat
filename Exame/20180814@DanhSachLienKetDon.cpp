//1. Định nghĩa danh sách liên kết đơn lưu trữ dãy số gồn N<1000 số nguyên dương được nhập từ bản phím.
//2. Lập trình đếm số node của danh sách chứa số nguyên tố.Xuất ra màn hình kết quả.

#include <iostream>
using namespace std;
//bước 1: Định nghĩa cấu trúc dữ liệu
//Định nghĩa cấu trúc 1 node
typedef struct node
{
	int data;
	node* link;
}NODE;
//Định nghĩa kiểu dữ liệu danh sách liên kết
typedef struct list
{
	NODE* first;
	NODE* last;
}LIST;
//Bước 2: Khởi tạo
//danh sách rỗng (NULL)
void Init(LIST &list)
{
	list.first = list.last = NULL;
}
//khởi tạo 1 node
NODE* GetNode(int data)
{
	NODE* p;
	p = (NODE*)malloc(sizeof(NODE));
	//p = new NODE;
	if (p == NULL)
	{
		cout << "Chuong trinh se duoc dong lai"; exit(0);
	}
	p->data = data;
	p->link = NULL;
	return p;
}
void AddFirst(LIST &list, NODE* node)
{
	//2.Thêm NODE vừa tạo vào trong danh sách liên kết đơn list
	if (list.first == NULL)//2.1. thêm vào danh sách rỗng
	{
		list.first = node;
		list.last = list.first;
	}
	else//2.2. Thêm vào đầu danh sách
	{
		node->link = list.first;
		list.first = node;
	}
}
//Hàm sử dụng để thêm 1 giá trị kiểu int (data) vào trong danh sách liên kết đơn list
void InsertList(LIST &list, int data)
{
	//1.khởi tạo NODE mang giá trị data
	NODE* new_ele = GetNode(data);
	if (new_ele != NULL)
	{
		AddFirst(list, new_ele);
	}
}
void PrintList(LIST list)
{
	NODE* p;
	p = list.first;
	while (p!=NULL)
	{
		//1. thực hiện thao tác gì đó
		cout << p->data<<" ";
		//2. thành phần chạy
		p = p->link;
	}

}
int LaSoNguyenTo(int n)
{
	if (n < 2)
		return 0;

	for (int i = 2; i <= sqrt((float)n); i++)
	{
		if (n%i == 0)
		{
			return 0;
		}
	}
	return 1;
}
int DemSoNguyenTo(LIST list)
{
	NODE* p;
	p = list.first;
	int dem = 0;
	while (p != NULL)
	{
		//1. thực hiện thao tác gì đó
		if (LaSoNguyenTo(p->data) == 1)
			dem++;
		//2. thành phần chạy
		p = p->link;
	}
	return dem;
}
void main()
{
	LIST list;
	Init(list);
	int x = 0;
	while (x!=-1)
	{
		cout << "\nNhap gia tri: "; cin >> x;
		if (x != -1)
		{
			InsertList(list, x);
		}
		cout << " Nhap -1 de thoat ra";
	}
	PrintList(list);
	cout << endl;
	cout <<"so luong so nguyen to: "<< DemSoNguyenTo(list);
	system("pause");

}