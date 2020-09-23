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
		if (p != NULL)
			p->pre = newDnode;//4
		if (q == dlist.tail)
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
		q->pre = newDnode;//3
		if (p != NULL)
			p->next = newDnode;//4
		if (q == dlist.head)
			dlist.head = newDnode;//5
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