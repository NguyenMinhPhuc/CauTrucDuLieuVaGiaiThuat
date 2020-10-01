#include "iostream"
using namespace std;
typedef int dataType;
//Khai bao cau truc node
typedef struct dnode
{
	dataType data;
	dnode* next;
	dnode* pre;
}DNODE;
//khai bao LIST
typedef struct dlist {
	DNODE* first;
	DNODE* last;
}DLIST;
//khoi khao list
void InitDlist(DLIST &dList)
{
	dList.first = dList.last = NULL;
}
//ham tao mot DNode;
DNODE* GetDNode(dataType data)
{
	DNODE* p = new DNODE;
	if (p != NULL)
	{
		p->data = data;
		p->next = NULL;
		p->pre = NULL;
	}
	return p;
}
void AddFirst(DLIST &l, DNODE* newNode)
{
	if (l.first == NULL)
	{
		l.first = newNode;
		l.last = l.first;
	}
	else
	{
		newNode->next = l.first;//1
		l.first->pre = newNode;//2
		l.first = newNode;//3
	}
}
void AddLast(DLIST& l, DNODE* newNode) {
	if (l.first == NULL)
	{
		l.first = newNode;
		l.last = l.first;
	}
	else
	{
		l.last->next = newNode;//1
		newNode->pre = l.last;//2
		l.last = newNode;//3
	}
}
void InsertList(DLIST &l, dataType data,bool isFirst)
{
	DNODE* p = GetDNode(data);
	if (isFirst == true)
		AddFirst(l, p);
	else
		AddLast(l, p);
}
void CreateList(DLIST& l,bool isFirst)
{
	dataType data;
	int i = 0;
	do
	{
		cout << "Nhap pt[" << ++i << "]: ";
		cin >> data;
		if (data == -1)
			break;
		InsertList(l, data, isFirst);
	} while (true);
}
void PrintDList(DLIST l,bool first)
{
	if (first == true)
	{
		DNODE* p = l.first;
		while (p != NULL)
		{
			cout << p->data << " ";
			p = p->next;
		}
	}
	else
	{
		DNODE* p = l.last;
		while (p != NULL)
		{
			cout << p->data << " ";
			p = p->pre;
		}
	}
}
void AddAfterQ(DLIST& l, DNODE* q, DNODE* newNode)
{
	if (q != NULL)
	{
		DNODE* p = q->next;
		newNode->next = p;//1
		newNode->pre = q;//2
		q->next = newNode;//3
		if (q != l.last)
		{
			p->pre = newNode;//4
		}
		else
		{
			l.last = newNode;//5
		}
	}
	else
	{
		AddFirst(l, newNode);
	}
}
void AddBeforQ(DLIST& l, DNODE* q, DNODE* newNode)
{
	if (q != NULL)
	{
		DNODE* p = q->pre;
		newNode->next = q;//1
		newNode->pre = p;//2
		q->pre = newNode;//3
		if (q != l.first)
		{
			q->pre = newNode;//4
		}
		else
		{
			l.first = newNode;//5
		}
	}
	else
	{
		AddFirst(l, newNode);
	}
}
bool IsEven(dataType data)
{
	return data % 2 == 0 ? true : false;
}
void TachChanLe(DLIST l, DLIST& lChan, DLIST& lLe)
{
	DNODE* p = l.first;
	while (p != NULL)
	{
		if (IsEven(p->data))
		{
			AddFirst(lChan, p);
		}
		else
		{
			AddFirst(lLe, p);
		}
		p = p->next;
	}
}
void main()
{
	DLIST l;
	DLIST lChan, lLe;
	InitDlist(lChan);
	InitDlist(lLe);
	const bool IS_FIRST = true;
	InitDlist(l);
	CreateList(l, IS_FIRST);
	PrintDList(l, true);
	cout << endl;
	PrintDList(l, false);

	TachChanLe(l, lChan, lLe);
	PrintDList(lChan, false);
	PrintDList(lLe, false);
	system("pause");

}