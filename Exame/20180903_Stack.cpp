//- xây dựng cấu trúc Stack
	//1. cài đặt bằng mảng.
	//2. cài đặt bằng danh sách (làm file riêng)
//- thực hiện các thao tác.
	//1. khởi tạo stack
	//2. kiểm tra stack rỗng, đầy
	//3. thêm phần tử vào stack
	//4. Lấy phần tử đầu stack
	//5. thực hiện input output
#include <iostream>
using namespace std;
int menu()
{
	int option;
	cout << "-----Menu----";
	cout << "\n1. Init Stack";
	cout << "\n2. Check Stack";
	cout << "\n3. Push into Stack";
	cout << "\n4. Pop out Stack";
	cout << "\n5. Get item top Stack";
	cout << "\n6. translate 10 to 2";
	cout << "\n7. Exit";
	cout << "seleted Option: "; cin >> option;
	return option;
}
//Khai báo stack bằng mảng
#define max 100
typedef int item;
struct Stack
{
	int count;
	int top;// đỉnh stack
	item data[max];//mảng chứa các phần tử của stack
};
void Init(Stack &stack)
{
	stack.top = 0;
	stack.count = 0;
}
int IsEmpty(Stack stack)
{
	if (stack.top == 0)
		return 1;
	return 0;
}
int isFull(Stack stack)
{
	if (stack.top == max)
		return 1;
	return 0;
}
void Push(Stack &stack, int x)
{
	if (isFull(stack) == 0)
	{
		stack.data[stack.top] = x;
		stack.top++;
		stack.count++;
	}
	else
	{
		cout << "Stack full";
	}
}
item Pop(Stack &stack)
{
	item data=NULL;
	if (!IsEmpty(stack))
	{
		stack.top--;
		data = stack.data[stack.top];
		stack.count--;
	}
	return data;
}


void DoiCoSo(int y)
{
	int mod;
	Stack s;
	if (y >= 0)
	{
		do
		{
			mod = y % 2;
			Push(s, mod);
			y = y / 2;

		} while (y != 0);
	}
	//lấy ra
	while (IsEmpty(s) == 0)
	{
		cout << Pop(s) << " ";
	}
}
void main()
{
	int option = 0;
	Stack stack;
	do
	{
		option = menu();
		switch (option)
		{
		case 1:
			system("clr");
			cout << "Init Stack";
			Init(stack);
			break;
		case 2:
			system("clr");
			cout << "Checked Stack";
			if (IsEmpty(stack) == 1)
				cout << "Stack empty";
			else if (isFull(stack)==1)
			{
				cout << "Stack Full";
			}
			else
			{
				cout << "Stack have "<<stack.count<<" item";
			}
			break;
		}
	} while (option!=6);
}