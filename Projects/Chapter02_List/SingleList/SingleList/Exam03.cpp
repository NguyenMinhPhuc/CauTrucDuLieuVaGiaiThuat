//cho da thức P(x)=anXn+an-1Xn-1+...+a1X+a0
//Hãy định nghĩa và xây dựng DSLK đơn lưu trữ đa thức P(x). 
//1. cài đặt cấu trúc dữ liệu
//2. Nhập đa thức
//3. In đa thức.
//4. Tính đạo hàm của đa thức
#include "iostream"

using namespace std;
//Định nghĩa kiểu dữ liệu Da Thức
typedef struct dathuc
{
	int heSo;
	int luyThua;
}DaThuc;
//Định nghĩa kiểu node cho danh sách
typedef struct node
{
	DaThuc data;
	node* link;
}NODE;
//Định nghĩa kiểu con trỏ NODE
typedef NODE* NodeType;
//Định nghĩa kiểu danh sách để lưu trữ đa thức
typedef struct list
{
	NodeType first;
	NodeType last;
}LIST;
//Phương thức tạo NODE có giá trị da thức x
NodeType GetNode(DaThuc x)
{
	NodeType p =(NodeType) malloc(sizeof(NODE));

	if (p != NULL)
	{
		p->data = x;
		p->link = NULL;
	}
	return p;
}
//Phương thức tạo danh sách rỗng
void InitList(LIST &list)
{
	list.first = NULL;
	list.last = NULL;
}
//Phương thức thêm 1 phần tử vào đầu danh sách
void AddFirst(LIST&list,NodeType new_ele)
{
	if (list.first == NULL)
	{
		list.first = new_ele;
		list.last = list.first;
	}
	else
	{
		new_ele->link = list.first;
		list.first = new_ele;
	}
}
//Phương thức thêm 1 phần tử vào đuôi danh sách phương thức nay được dùng.
void AddLast(LIST& list, NodeType new_ele)
{
	if (list.first == NULL)
	{
		list.first = new_ele;
		list.last = list.first;
	}
	else
	{
		list.last->link = new_ele;
		list.last = new_ele;
	}
}
//Thêm đa thức x vào list
void InsertList(LIST& list, DaThuc x)
{
	NodeType p = GetNode(x);
	if (p != NULL)
		AddLast(list, p);
}
//Nhập đa thức
void InputDaThuc(LIST& list)
{
	DaThuc dt;
	while (true)
	{
		cout << "Nhap he so (Nhap -1 de ket thuc.)" ;
		cin >> dt.heSo;
		if (dt.heSo == -1)
			break;
		cout << endl;
		cout << "Nhap so mu: "; cin >> dt.luyThua;
		
		InsertList(list, dt);
	}
}
//in giá trị một Node
void PrintResult(LIST list,NodeType p)
{
	if (p != list.first && p->data.heSo >= 0)
		cout << "+ ";
	cout << p->data.heSo;
	if (p->data.luyThua > 1)
		cout << "x^" << p->data.luyThua;
	else if (p->data.luyThua == 1)
		cout << "x ";
}
//Phương thức in đa thức ra màn hình
void PrintDaThuc(LIST list)
{
	NodeType p = list.first;
	while (p!=NULL)
	{
		PrintResult(list,p);
		p = p->link;
	}
	cout << endl;
}
//Phương thức tính đạo hàm
void TinhDaoHam(LIST list)
{
	NodeType p = list.first;
	LIST listnew;
	InitList(listnew);
	while (p != NULL)
	{
		DaThuc x = p->data;
		x.heSo *= x.luyThua;
		x.luyThua--;

		InsertList(listnew, x);

		p = p->link;
	}
	PrintDaThuc(listnew);
}
//Phương thức hàm main.
void main()
{
	LIST list;
	InitList(list);
	InputDaThuc(list);
	PrintDaThuc(list);
	cout << "Da thuc sau khi dao ham:";
	TinhDaoHam(list);

	system("pause");
}