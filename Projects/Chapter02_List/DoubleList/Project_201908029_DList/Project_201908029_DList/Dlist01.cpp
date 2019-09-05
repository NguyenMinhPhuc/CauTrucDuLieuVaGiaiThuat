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

void XoaDauDanhSach(DList &dlist)
{
	DnodePtr p;
	p = dlist.head;
	if (p != NULL)
	{
		dlist.head = p->next;
		if (p == dlist.tail)
		{
			dlist.tail = NULL;
		}
		else
		{
			dlist.head->pre = NULL;
		}
		delete p;
	}
}
void XoaDuoiDanhSach(DList &dlist)
{
	if (dlist.head != NULL)
	{
		DnodePtr p;
		p = dlist.tail;
		dlist.tail = p->pre;
		if (p == dlist.head)
		{
			dlist.head = NULL;
		}
		else
		{
			dlist.tail->next = NULL;
		}
		delete p;
	}

}
void XoaTruocQ (DList &dlist, DnodePtr q)
{

}
void XoaSauQ(DList &dlist, DnodePtr q)
{
	if (q != NULL)
	{
		DnodePtr p;
		p = q->next;
		if (p != NULL)
		{
			q->next = p->next;
			if (p == dlist.tail)
			{
				dlist.tail = q;
			}
			else
			{
				p->next->pre = q;
			}
			delete p;
		}
	}
}
void DeleteX(DList &dlist, int x)
{
	DnodePtr p = dlist.head;
	while (p != NULL)
	{
		if (p->data == x)
		{
			XoaSauQ(dlist, p->pre);
			break;
		}
		p = p->next;
	}
}
void DeleteSauX(DList&dlist, int x)
{
	DnodePtr p = dlist.head;
	while (p != NULL)
	{
		if (p->data == x)
		{
			XoaSauQ(dlist, p);
		}
		p = p->next;
	}
	
}
int Menu()
{
	cout << endl;
	cout << "| -----------------------------|" << endl;
	cout << "| 1. Nhap danh sach            |" << endl;
	cout << "| 2. In danh sach              |" << endl;
	cout << "| 3. In danh sach nguoc        |" << endl;
	cout << "| 4. Xoa 1 phan tu dau         |" << endl;
	cout << "| 5. Xoa 1 phan tu duoi        |" << endl;
	cout << "| 6. Xoa 1 phan tu Sau q        |" << endl;
	cout << "| 7. Xoa 1 phan tu x            |" << endl;
	cout << "| 8. Thoat                     |" << endl;
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
		case 4:
			XoaDauDanhSach(dlist);
			PrintDlist(dlist, true);
			break;
		case 5:
			XoaDuoiDanhSach(dlist);
			PrintDlist(dlist, true);
			break;
		case 6:
			int xcanxoa;
			cout << "Nhap x: "; cin >> xcanxoa;
			DeleteSauX(dlist, xcanxoa);
			PrintDlist(dlist, true);
			break;
		case 7:
			int xcanxoa1;
			cout << "Nhap x: "; cin >> xcanxoa1;
			DeleteX(dlist, xcanxoa1);
			PrintDlist(dlist, true);
			break;
		default:
			return;
		}

	}
	
}