#include "iostream"
#include "string"
#include "windows.h"

using namespace std;

#include "Resource.cpp"

typedef struct sinhvien{
	int ID;
	string Name;
	string ClassID;
}SINHVIEN;
//Định nghĩa cấu trúc node
typedef int dataType;
typedef struct node
{
	dataType data;
	node *link;
}NODE;
//Định nghĩa danh sách (list)
typedef NODE * ptrNode;
typedef struct list
{
	NODE *first;
	ptrNode last;
}LIST;
//Hàm khởi tạo danh sách
void InitList(LIST &list)
{
	list.first = NULL;
	list.last = NULL;
}
//Hàm Tạo Cấu trúc Node
ptrNode GetNode(dataType data){
	ptrNode p = (ptrNode)malloc(sizeof(NODE));
	//ptrNode p = new NODE;
	if (p == NULL)
		exit(1);
	p->data = data;
	p->link = NULL;

	return p;
}//Hàm thêm một node vào đầu danh sách
//Thêm node vào đầu danh sách
void AddFirst(LIST &list, ptrNode new_Node)
{
	if (list.first == NULL)
	{
	 list.first=new_Node;
		list.last = list.first;
	}
	else
	{
		new_Node->link = list.first;
		list.first = new_Node;
	}
}
//Thêm node vào cuối danh sách
void AddLast(LIST &list, ptrNode new_Node)
{
	if (list.first == NULL)
	{
		list.first=new_Node;
		list.last = list.first;
	}
	else
	{
		list.last->link = new_Node;
		list.last = new_Node;
	}
}
//Insert value data vào danh sách
void InsertList(LIST &list, dataType data,bool addFirst)
{
	ptrNode p = GetNode(data);
	if (p != NULL)
	{
		if (addFirst == true)
			AddFirst(list, p);
		else
			AddLast(list, p);
	}
}
//Nhập danh sách với n phần tử
void CreateListNumber(LIST &list,bool addFirst)
{
	dataType data;
	int i= 0;
	while (true)
	{
		cout << "Nhap pt[" << ++i << "]:";
		cin >> data;
		if (data != -1)
		{
			InsertList(list, data, addFirst);
		}
		else
		{
			break;
		}
	}
}
void CreateListNumberRamdom(LIST &list, bool addFirst)
{
	dataType data;
	int i = 0;
	for (int i = 0; i < 20; i++)
	{
		data = GeneralRamdomGroup(1, 20,i);
		InsertList(list, data, addFirst);
		//Sleep(500);
	}
}
void Printdata(ptrNode node)
{
	cout << node->data << " ";
}
//Phương thức In danh sách liên kết;
void PrintList(LIST list)
{
	ptrNode p = list.first;
	while (p!=NULL)
	{ 
		//1. in data
		Printdata(p);

		p = p->link;
	}
	cout << endl;
}
void AddAfterQ(LIST &list, ptrNode q, ptrNode new_Node)
{
	if (q != NULL)
	{
		new_Node->link = q->link;
		q->link = new_Node;
		if (q==list.last)
			list.last = new_Node;
	}
}
ptrNode SearchingValueX(LIST list, dataType x)
{
	ptrNode p = list.first;
	while (p != NULL&&p->data!=x)
	{
		p = p->link;
	}
	return p;
}
void AddAfterValueX(LIST &list, dataType x, dataType data)
{
	ptrNode q = SearchingValueX(list, x);
	AddAfterQ(list, q, GetNode(data));
}

void DeleteFirst(LIST &list)
{
	if (list.first != NULL)
	{
		ptrNode p = list.first;
		list.first = p->link;
		if (list.first == NULL)
			list.last = NULL;
		free(p);
		//delete p;
	}
}
void DeleteNodeAfterQ(LIST &list, ptrNode q, ptrNode p)
{
	if (q != NULL&&p != NULL)
	{
		q->link = p->link;
		if (p == list.last)
			list.last = q;

		free(p);
	}
}
void DelectNodeAfterValueX(LIST &list, dataType x)
{
	ptrNode q = SearchingValueX(list,x);
	if (q != NULL)
	{
		ptrNode p = q->link;
		DeleteNodeAfterQ(list, q, p);
	}

}
void DeleteValueX(LIST &list, dataType x)
{
	ptrNode p = list.first;
	ptrNode q = p;
	while (p != NULL)
	{
		if (p->data == x)
		{
			if (p == list.first)
			{
				DeleteFirst(list); break;
			}
			else
			{
				DeleteNodeAfterQ(list, q, p); break;
			}
		}
		q = p;
		p = p->link;
	}
}
void DeleteAll(LIST &list)
{
	ptrNode p;
	while (list.first!=NULL)
	{
		p = list.first;
		list.first = p->link;
		free(p);
	}
	list.last = NULL;
}
void main(){
	const bool addFirst = false;
	LIST list;
	InitList(list);
	CreateListNumberRamdom(list, addFirst);
	PrintList(list);
	DeleteAll(list);
	PrintList(list);
	system("pause");
}