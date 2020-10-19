#include "iostream"
using namespace std;
typedef int dataType;
typedef struct dnode
{
	dataType data;
	dnode * next;
	dnode * pre;
}DNODE;
typedef struct dlist{
	DNODE * head;
	DNODE * tail;
}DLIST;

void InitDlist(DLIST &dlist)
{
	dlist.head = dlist.tail = NULL;
}
DNODE * GetNode(dataType data)
{
	DNODE * p = new DNODE;
	if (p == NULL)
		exit(1);
	p->data = data;
	p->next = NULL;
	p->pre = NULL;
}
void AddFirst(DLIST &dlist, DNODE * newDnode)
{
	if (dlist.head == NULL)
	{
		dlist.head = newDnode;
		dlist.tail = dlist.head;
	}
	else
	{
		newDnode->next = dlist.head;//1
		dlist.head->pre = newDnode;//2
		dlist.head = newDnode;//3
	}
}
void AddLast(DLIST &dlist, DNODE * newDnode)
{
	if (dlist.head == NULL)
	{
		dlist.head = newDnode;
		dlist.tail = dlist.head;
	}
	else
	{
		newDnode->pre = dlist.tail;//1
		dlist.tail->next = newDnode;//2
		dlist.tail = newDnode;//3
	}
}
void InsertDList(DLIST &dlist, dataType data, bool isFirst)
{
	DNODE * p = GetNode(data);
	if (isFirst == true)
		AddFirst(dlist, p);
	else
		AddLast(dlist, p);
}

void CreateDList(DLIST &dlist)
{
	int data;
	int i = 0;
	while (true){
		cout << "Nhap pt[" << ++i << "]: ";
		cin >> data;
		if (data != -1){
			InsertDList(dlist, data);
		}
		else{
			break;
		}
	}
}
void InDanhSachNguoc(DLIST dlist)
{
	DNODE * p = dlist.head;
	while (p!=NULL) {
		cout << p->data;
		p = p->next;
	}
}
void InDanhSachXuoi(DLIST dlist)
{
	DNODE * p = dlist.tail;
	while (p != NULL)
	{
		cout << p->data;
		p = p->pre;
	}
}
void ThemVaoMotNodeSauQ(DLIST &dlist, DNODE *q, DNODE *newDnode)
{
	DNODE *p = q->next;
	if (q != NULL)
	{
		newDnode->next = p;//1
		newDnode->pre = q;//2
		q->next = newDnode;//3
		if (q!=dlist.tail)
			p->pre = newDnode;//4
		else
			dlist.tail = newDnode;//5
	}
}
void ThemVaoMotNodeTruocQ(DLIST &dlist, DNODE *q, DNODE *newDnode)
{
	DNODE *p = q->pre;
	if (q != NULL)
	{
		newDnode->pre = p;//1
		newDnode->next = q;//2
		q->pre = newDnode;//4
		if (q!=dlist.head)
			p->next = newDnode;//3
		else
			dlist.head = newDnode;//5
	}
}
int XoaMotNodeDauDanhSach(DLIST& dlist)
{
	DNODE* p;
	dataType x=0;
	if (dlist.head != NULL)//danh sach khac rong
	{
		p = dlist.head;//1
		x = p->data;
		dlist.head = p->next;//2
		delete p;
		if (dlist.head == NULL){
			dlist.tail = NULL;
		}
		else{
			dlist.head->pre = NULL;
		}
	}
	return x;
}
dataType XoaMotNodeCuoiDanhDanh(DLIST& dlist)
{
	DNODE* p;
	dataType x = 0;
	if (dlist.tail != NULL)
	{
		p = dlist.tail;
		x = p->data;
		dlist.tail = p->pre;
		delete p;
		if (dlist.tail == NULL)
			dlist.head = NULL;
		else
			dlist.tail->next = NULL;
	}
	return x;
} 
void XoaMotNodeSauQ(DLIST& dlist, DNODE* q)
{
	if (q != NULL)
	{
		DNODE* p = q->next;
		if (p != NULL)
		{
			q->next = p->next;//1
			if (p != dlist.tail)
			{
				p->next->pre = q;
			}
			else{
				dlist.tail = q;
			}
			delete p;
		}
	}
}
void XoaGiaTriX(DLIST& dlist, dataType x)
{
	DNODE* p = dlist.head;
	while (p != NULL)
	{
		if (p->data == x)
			XoaMotNodeSauQ(dlist, p->pre);
		p = p->next;
	}
}
void main()
{
	DLIST list;
	InitDlist(list);
	CreateDList(list);
	InDanhSachXuoi(list);

	system("pause");

}