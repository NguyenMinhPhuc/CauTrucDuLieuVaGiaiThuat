#include "iostream"

using namespace std;

typedef int DataType;
//Khai báo cấu trúc double list
typedef struct dnode
{
	DataType data;
	dnode * pre;
	dnode * next;
}Dnode;
typedef Dnode * DnodePtr;

//khai báo cấu trúc danh sách liên kết đối
typedef struct dlist
{
	DnodePtr head;
	DnodePtr tail;

	int count;//đến số phần tử
}DList;

void InitDList(DList &dlist)
{
	dlist.head = dlist.tail = NULL;
	dlist.count = 0;
}
DnodePtr GetDnode(DataType data)
{
	DnodePtr p;
	p = new Dnode;

	if (p == NULL)
		exit(1);
	p->data = data;
	p->pre = NULL;
	p->next = NULL;

	return p;
}

void AddFirst(DList &dlist, DnodePtr newElement)
{
	if (dlist.head == NULL)
	{
		dlist.head = newElement;
		dlist.tail = dlist.head;
	}
	else
	{
		newElement->next = dlist.head;
		dlist.head->pre = newElement;
		dlist.head = newElement;
	}
}
void AddLast(DList &dlist, DnodePtr newElement)
{
	if (dlist.head == NULL)
	{
		dlist.head = newElement;
		dlist.tail = dlist.head;
	}
	else
	{
		newElement->pre = dlist.tail;
		dlist.tail->next = newElement;
		
		dlist.tail = newElement;
	}
}
void InsertDlist(DList &dlist, DataType data,bool first)
{
	DnodePtr p;
	p = GetDnode(data);
	if (p != NULL)
	{
		if (first)
		{
			AddFirst(dlist, p);
		}
		else
		{
			AddLast(dlist, p);
		}
	}
}

void AddAfterQ(DList & dlist, DnodePtr q, DnodePtr newElement)
{
	DnodePtr p;
	p = q->next;

	if (dlist.head != NULL)
	{
		newElement->next = p;//1
		newElement->pre = q;//2
		q->next = newElement;//3

		if (p != NULL)
			p->pre = newElement;//4
		else
			dlist.tail = newElement;
	}
	else
	{
		AddFirst(dlist, newElement);//thêm vào đầu danh sách
	}
}

void InsertAfterQ(DList &dlist, DnodePtr q, DataType data)
{
	DnodePtr p = GetDnode(data);
	if (p != NULL)
	{
		AddAfterQ(dlist, q, p);
	}
}
void InputDlist(DList &list,bool first)
{
	while (true)
	{
		DataType data;
		cout << "Nhap data: ";
		cin >> data;
		if (data == -1)
			break;
		InsertDlist(list, data,first);
	}
}
//option =1 duyệt từ head; 0 duyệt từ tail
void PrintDlist(DList dlist,bool option)
{
	DnodePtr p;
	cout << "Danh sach vua nhap: ";
	if (option == 1)
	{
		p = dlist.head;
		while (p != NULL)
		{
			cout << p->data << ", ";
			p = p->next;
		}
	}
	else
	{
		p = dlist.tail;
		while (p != NULL)
		{
			cout << p->data << ", ";
			p = p->pre;
		}
	}
}
int Menu()
{
	cout << endl;
	cout << "| -----------------------------|" << endl;
	cout << "| 1. Nhap danh sach            |" << endl;
	cout << "| 2. In danh sach              |" << endl;
	cout << "| 3. In danh sach nguoc        |" << endl;

	cout << "| 7. Thoat                     |" << endl;
	cout << "| -----------------------------|" << endl;

	int option;
	cout << "Chon chuc nang: ";
	cin >> option;
	return option;
}

void main()
{
	DList dlist;
	InitDList(dlist);
	int option = 0;
	bool first = true;
	while (true)
	{
		option = Menu();
		switch (option)
		{
		case 1:
			InputDlist(dlist,first);
			break;
		case 2:
			PrintDlist(dlist, true);
			break;
		case 3:
			PrintDlist(dlist,false);
			break;
		default:
			return;
		}

	}
	
}