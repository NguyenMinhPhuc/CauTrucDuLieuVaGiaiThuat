//#include "iostream"
//using namespace std;
//#define MAX 100
//typedef int item;
//typedef struct stack
//{
//	int top;
//	int count;
//	item data[MAX];
//}STACK;
//void Init(STACK& stack)
//{
//	stack.top = -1;
//	stack.count = 0;
//}
//bool IsEmpty(STACK stack)
//{
//	return stack.top == -1 ? true : false;
//}
//bool IsFull(STACK stack)
//{
//	return stack.top == MAX-1 ? true : false;
//}
//void Push(STACK& stack, item x)
//{
//	if (IsFull(stack) == false)
//	{
//		/*stack.top++;*/
//		stack.data[++stack.top] = x;
//		stack.count++;
//	}
//	else
//	{
//		cout << "stack full";
//	}
//}
//item Pop(STACK& stack){
//	item outPut = NULL;
//	if (IsEmpty(stack) == false){
//		outPut = stack.data[stack.top--];
//		stack.count--;
//	}
//	else{
//		cout << "stack Empty";
//	}
//	return outPut;
//}
//void DoiCoSo(int number, int heso)
//{
//	int mod;
//	STACK stack;
//	Init(stack);
//	do
//	{
//		mod = number % heso;
//		Push(stack, mod);
//		number = number / heso;
//	} while (number!=0);
//	while (IsEmpty(stack)==false)
//	{
//		cout << Pop(stack);
//	}
//}
//void main()
//{
//	int number = 20;
//	int heSo = 8;
//	DoiCoSo(number, heSo);
//
//	system("pause");
//}