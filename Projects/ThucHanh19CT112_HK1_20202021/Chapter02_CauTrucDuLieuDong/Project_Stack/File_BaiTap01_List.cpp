#include "iostream"
using namespace std;
typedef char item;
typedef struct node {
	item data;
	node* link;
}NODE;
typedef struct stack
{
	NODE* top;
	int count;
}STACK;
void Init(STACK& stack)
{
	stack.top = NULL;
	stack.count = 0;
}
bool IsEmpty(STACK stack)
{
	return stack.top == NULL ? true : false;
}
void Push(STACK& stack, item x)
{
	//tao node
	NODE* p = new NODE;
	if (p != NULL)
	{
		p->data = x;
		p->link = NULL;
		//them node dau danh sach
		if (IsEmpty(stack))
		{
			stack.top = p;
		}
		else
		{
			p->link = stack.top;
			stack.top = p;
		}
		stack.count++;
	}
}
item Pop(STACK& stack)
{
	item outPut = NULL;
	if (IsEmpty(stack) == false)
	{
		NODE* p = stack.top;
		outPut = p->data;
		stack.top = p->link;
		delete p;

		stack.count--;
	}
	return outPut;
}
void DoiCoSo(int number, int heso)
{
	int mod;
	string arrayNumber[16] = { "0","1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F", };
	STACK stack;
	Init(stack);
	do
	{
		mod = number % heso;
		Push(stack, mod);
		number = number / heso;
	} while (number!=0);
	while (IsEmpty(stack)==false)
	{
		cout << arrayNumber[Pop(stack)];
	}
}
bool KiemTraBieuThuc(string bieuThuc)
{
	STACK stack;
	Init(stack);
	for each (char item in bieuThuc)
	{
		if (item == '(' || item == '{' || item == '[')
			Push(stack, item);
		else
		{
			if (item == ')')
			{
				if (Pop(stack) != '(')
					return false;
			}
			else if(item=='}')
			{
				if (Pop(stack) != '{')
					return false;
			}
			else
			{
				if (Pop(stack) != '[')
					return false;
			}
		}
	}
	return true;
}
void main()
{
	/*int number = 5436;
	int heSo = 16;
	DoiCoSo(number, heSo);
	cout << endl;*/

	KiemTraBieuThuc("{([))}")?cout<<"Dung": cout << "Sai";
	cout << endl;
		system("pause");
}