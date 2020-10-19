//#include "iostream"
//#include "string"
//using namespace std;
//#define MAX 100
//typedef char item;
////khai bao cau truc Stack
//typedef struct stack
//{
//	item data[MAX];
//	int top;
//	int count;
//}STACK;
//void InitStack(STACK& stack)
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
//		stack.data[++stack.top] = x;
//		stack.count++;
//	}
//	else
//	{
//		cout << "Stack FULL";
//	}
//}
//item Pop(STACK& stack)
//{
//	item outPut = NULL;
//	if (IsEmpty(stack) == false)
//	{
//		outPut = stack.data[stack.top--];
//		stack.count--;
//	}
//	else
//	{
//		cout << "Stack empty";
//	}
//	return outPut;
//}
//bool KiemTraBieuThuc(string BieuThuc)
//{
//	STACK stack;
//	InitStack(stack);
//	for (int i = 0; i < BieuThuc.length(); i++)
//	{
//		if (BieuThuc[i] == '(' || BieuThuc[i] == '[' || BieuThuc[i] == '{')
//		{
//			Push(stack, BieuThuc[i]);
//		}
//		else
//		{
//			if (BieuThuc[i] == ')')
//			{
//				if (Pop(stack) != '(')
//					return false;
//			}
//			else if(BieuThuc[i] == ']')
//			{
//				if (Pop(stack) != '[')
//					return false;
//			}
//			else
//			{
//				if (Pop(stack) != '{')
//					return false;
//			}
//		}
//	}
//	return true;
//}
//void main()
//{
//	if (KiemTraBieuThuc("{[((]}"))
//	{
//		cout << "Bieu thuc nhap dung"<<endl;
//	}
//	else
//	{
//		cout << "Bieu thuc khong dung"<<endl;
//	}
//	system("pause");
//}