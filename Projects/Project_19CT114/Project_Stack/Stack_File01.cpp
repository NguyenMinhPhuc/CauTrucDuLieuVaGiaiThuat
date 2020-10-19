//#include "iostream"
//using namespace std;
//#define MAX 100
//
//typedef int item;
//
//typedef struct Stack
//{
//	int count;
//	int top;
//	item data[MAX];
//}STACK;
//
//void InitStack(STACK& stack)
//{
//	stack.top = -1;
//	stack.count = 0;
//}
////
//bool IsEmpty(STACK stack)
//{
//	if (stack.top == -1)
//		return true;
//	return false;
//}
//bool isFull(STACK stack)
//{
//	if (stack.top == MAX-1)
//		return true;
//	return false;
//}
//void Push(STACK& stack, item x)
//{
//	if (isFull(stack) == false)
//	{
//		stack.data[++stack.top] = x;
//		stack.count++;
//	}
//	else
//	{
//		cout << "\nStack day";
//	}
//}
//item Pop(STACK& stack)
//{
//	item result=NULL;
//	if (IsEmpty(stack) == false) {
//		result = stack.data[stack.top--];
//		stack.count--;
//	}
//	return result;
//}
//void DoiThapPhanSangNhiPhan(STACK &stack,int number)
//{
//	int soDu;
//	if (number > 0){
//		do{
//			soDu = number % 2;
//			Push(stack, soDu);
//			number = number / 2;
//		} while (number!=0);
//	}
//
//	while (IsEmpty(stack)==false){
//		cout << Pop(stack);
//	}
//}
//void main()
//{
//	STACK stack;
//	InitStack(stack);
//	DoiThapPhanSangNhiPhan(stack,100);
//
//	system("pause");
//}