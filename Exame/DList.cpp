#include <iostream>
using namespace std;

typedef struct dnode
{
	int data;
	dnode* pre;
	dnode* next;
}DNODE;
typedef struct dlist
{
	DNODE* Head;
	DNODE* Tail;
}DLIST;
DNODE* GetDNode(int data)
{
	DNODE *new_Dnode;// = (DNODE*)malloc(sizeof(DNODE));
	new_Dnode = new DNODE;
	if (new_Dnode == NULL)
	{
		exit(0);
	}
	new_Dnode->data = data;
	new_Dnode->next = NULL;
	new_Dnode->pre = NULL;//# voi dslk đơn
	return new_Dnode;
}
void AddFirst(DLIST &dlist, DNODE* new_dnode)
{
	if (dlist.Head == NULL)
	{
		dlist.Head = new_dnode;
		dlist.Tail = dlist.Head;
	}
	else//dlist khác null
	{
		new_dnode->next = dlist.Head;//1
		dlist.Head->pre = new_dnode;//2 thêm trong danh sach đôi
		dlist.Head = new_dnode;//3
	}
}
void AddLast(DLIST &dlist, DNODE* new_Dnode)
{
	if (dlist.Head == NULL)
	{
		dlist.Head = new_Dnode;
		dlist.Tail = dlist.Head;
	}
	else
	{
		dlist.Tail->next = new_Dnode;//1
		new_Dnode->pre = dlist.Tail;//2
		dlist.Tail = new_Dnode;//3
	}
}
void InsertDlist(DLIST &dlist, int data,bool isFirst)
{
	DNODE*new_Dnode = GetDNode(data);
	if (new_Dnode != NULL)
	{
		if (isFirst==true)
		{
			AddFirst(dlist, new_Dnode);
		}
		else
		{
			AddLast(dlist, new_Dnode);
		}
		
	}
}
void Init(DLIST & dlist)
{
	dlist.Head = dlist.Tail = NULL;
}
void PrintDlist(DLIST dlist,bool isFirst)
{
	DNODE *p;
	if (isFirst==true)
	{
		p = dlist.Tail;
		cout << endl;
		while (p != NULL)
		{
			cout << p->data << " ";
			p = p->pre;
		}
	}
	else
	{
		p = dlist.Head;
		cout << endl;
		while (p != NULL)
		{
			cout << p->data << " ";
			p = p->next;
		}
	}
}
//Phương thức tạo một danh sách liên kết đôi
//cho phép insert vào ds đến khi nhập -1.
//Cho in danh sách theo thứ tự nhập
void CreateDList(DLIST &dlist,bool isFirst)
{
	int data;
	do
	{
		cout << "nhap data: "; cin >> data;
		if (data != -1)
		{
			InsertDlist(dlist, data, isFirst);
		}
	} while (data != -1);
	PrintDlist(dlist, isFirst);
}
void AddAfterQ(DLIST &dlist, DNODE *q,DNODE*new_Dnode)
{
	if (q != NULL)
	{
		DNODE*p = q->next;

		new_Dnode->next = p;//1
		new_Dnode->pre = q;//2
		q->next = new_Dnode;//3
		if (q != dlist.Tail)
		{
			p->pre = new_Dnode;//4d
		}
		else
		{
			dlist.Tail = new_Dnode;
		}

	}
	else
	{
		AddLast(dlist, new_Dnode);
	}
}
void AddBeforQ(DLIST &dlist, DNODE *q, DNODE*new_Dnode)
{
	if (q != NULL)
	{
		DNODE*p = q->pre;

		new_Dnode->next = q;//1
		new_Dnode->pre = p;//2
		p->next = new_Dnode;//3
		if (q != dlist.Head)
		{
			q->pre = new_Dnode;//4d
		}
		else
		{
			dlist.Head = new_Dnode;
		}

	}
	else
	{
		AddFirst(dlist, new_Dnode);
	}
}

int RemoveHead(DLIST &dlist)
{
	DNODE *p;
	int x=NULL;
	if (dlist.Head != NULL)
	{
		p= dlist.Head;
		x = p->data;
		dlist.Head = p->next;
		delete p;
		if (dlist.Head == NULL)
			dlist.Tail = NULL;
		else
		{
			dlist.Head->pre = NULL;
		}
	}
	return x;
}
int RemoveTail(DLIST &dlist)
{
	DNODE *p;
	int x = NULL;
	if (dlist.Head != NULL)
	{
		p = dlist.Tail;
		x = p->data;
		dlist.Tail = p->pre;
		delete p;
		if (dlist.Tail == NULL)
			dlist.Head = NULL;
		else
		{
			dlist.Tail->next = NULL;
		}
	}
	return x;
}
DNODE* SearchXValude(DLIST dlist, int x)
{
	DNODE*q = dlist.Head;
	while (q!=NULL&&q->data!=x)
	{
		q = q->next;
	}
	return q;
}
void InsertAfterXValue(DLIST &dlist, int x,int data,bool isBefore)
{
	DNODE *new_dnode = GetDNode(data);
	DNODE*q = SearchXValude(dlist, x);
	if (new_dnode != NULL)
	{
		if (isBefore == true)
		{
			AddBeforQ(dlist, q, new_dnode);
		}
		else
		{
			AddAfterQ(dlist, q, new_dnode);
		}
		
	}
}
void main()
{
	DLIST list;
	Init(list);
	
	CreateDList(list, false);
	InsertAfterXValue(list, 4,20,true);
	PrintDlist(list, false);
	RemoveHead(list);
	RemoveTail(list);
	PrintDlist(list, false);
	system("pause");
}