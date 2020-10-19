#include "iostream"
using namespace std;
typedef struct node
{
	int data;
	node* link;
}NODE;

typedef struct stack
{
	NODE* top;
	int count;
}STACK;

void InitStack(STACK& stack)
{
	stack.top = NULL;
	stack.count = 0;
}
void Push(STACK& stack, int data)
{
	NODE* p = new NODE();
	if (p != NULL)
	{
		p->data = data;
		p->link = NULL;

		if (stack.top == NULL)
			stack.top = p;
		else
		{
			p->link = stack.top;
			stack.top = p;
		}
		stack.count++;
	}
}
int Pop(STACK& stack)
{
	int result = NULL;
	if (stack.top != NULL)
	{
		NODE* p = stack.top;
		result = p->data;
		stack.top = p->link;
		stack.count--;
		delete p;
	}
	return result;
}
void DoiThapPhanSangNhiPhan(STACK& stack, int number)
{
	int soDu;
	if (number > 0){
		do{
			soDu = number % 2;
			Push(stack, soDu);
			number = number / 2;
		} while (number!=0);
	}

	while (stack.top!=NULL){
		cout << Pop(stack);
	}
}
void DoiThapPhan(STACK& stack, int number,int heSo)
{
	int soDu;
	string arrayNumber[] = { "0","1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F" };
	if (number > 0) {
		do {
			soDu = number % heSo;
			Push(stack, soDu);
			number = number / heSo;
		} while (number != 0);
	}

	while (stack.top != NULL) {
		cout <<arrayNumber[ Pop(stack)];
	}
}
void main()
{
	STACK stack;
	InitStack(stack);
	DoiThapPhan(stack, 546525,8);

	system("pause");
}