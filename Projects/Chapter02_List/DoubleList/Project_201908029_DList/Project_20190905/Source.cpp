#include "iostream"
#include "ctime"
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
void InsertDlist(DList &dlist, DataType data, bool first)
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
			//AddLast(dlist, p);
		}
	}
}
void PrintDlist(DList dlist, bool option)
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
	cout << "| 3. Tach danh sach            |" << endl;
	
	cout << "| 8. Thoat                     |" << endl;
	cout << "| -----------------------------|" << endl;

	int option;
	cout << "Chon chuc nang: ";
	cin >> option;
	return option;
}
int Random(int a,int b)
{
	int data = a + rand() % (b - a + 1);
	return data;
}
void InputDlist(DList &list, bool first,bool autoNumber)
{
	if (autoNumber == true)
	{
		int n;
		cout << "Nhap so can them: "; cin >> n;
		//srand(time(0));
		DataType data;
		for (int i = 0; i < n; i++)
		{
			//data = 5 + rand() % (20 - 5 + 1);
			//a + rand() % (b-a+1)
			data = Random(5, 20);
			InsertDlist(list, data, first);
		}
	}
	else
	{
		while (true)
		{
			DataType data;
			cout << "Nhap data: ";
			cin >> data;
			if (data == -1)
				break;
			InsertDlist(list, data, first);
		}
	}
	
}
void TachDanhSach(DList dlist, DList &dlistChan, DList &dlistLe)
{
	DnodePtr p;
	p = dlist.head;
	while (p!=NULL)
	{
		if (p->data % 2 == 0)
		{
			InsertDlist(dlistChan, p->data,true);
		}
		else
		{
			InsertDlist(dlistLe, p->data, true);
		}
		p = p->next;
	}
}
void main()
{
	DList dlist;
	DList dlistChan;
	DList dlistLe;
	InitDList(dlist);
	InitDList(dlistChan);
	InitDList(dlistLe);
	int option = 0;
	bool first = true;
	while (true)
	{
		option = Menu();
		switch (option)
		{
		case 1:
			InputDlist(dlist, first,true);
			break;
		case 2:
			PrintDlist(dlist, true);
			break;
		case 3:
			TachDanhSach(dlist, dlistChan, dlistLe);
			PrintDlist(dlistChan, true);
			PrintDlist(dlistLe, true);
			break;
		default:
			return;
		}
	}
}