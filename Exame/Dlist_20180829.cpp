//1.Tại cấu trúc chương trình để gọi chức năng theo dạng menu
//2. Các thao tác để xử lý danh sách liên kết Đôi
//2.1

//Bài tập về nhà
// Là thêm tất cả các vị trí có ghi chú là làm bài tập về nhà.
// Kiểm ta và thông báo nếu chọn lại chức năng 1 sẽ cảnh báo người dùng. và cho phép người dùng lựa chọn khởi tạo lại danh sách hay không?.

#include <iostream>
using namespace std;
//hàm menu cho phép chọn chức năng và trả về giá trị chọn tương ứng
int menu()
{
	cout << "=============Select menu==============" << endl;
	cout << "1.Init List"<<endl;
	cout << "2.Add" << endl;
	cout << "3.Print" << endl;
	cout << "4.Delete" << endl; 
	cout << "5.Count element in List" << endl; 
	cout << "6.Clear Display" << endl;
	cout << "7.Exit" << endl; 
	cout << "=============Begin==============" << endl;
	int option;
	cout << "Select Function: "; cin >> option;
	return option;
}
//2. Init List
//khai báo cấu trúc danh sách liên kết đôi.
typedef struct dnode
{
	int data;
	dnode* pre;
	dnode* next;
}DNODE;
typedef struct dlist
{
	DNODE* head;
	DNODE* tail;

}DLIST;
void Init(DLIST &dlist)
{
	dlist.head = dlist.tail = NULL;
}
DNODE* GetNode(int data)
{
	DNODE * new_node = new DNODE;
	if (new_node == NULL)
	{
		exit(0);
	}
	new_node->data = data;
	new_node->pre = NULL;
	new_node->next = NULL;
	return new_node;
}
void AddFirst(DLIST &dlist, DNODE * new_node)
{
	if (dlist.head == NULL)//trường hợp danh sách rỗng
	{
		dlist.head = new_node;
		dlist.tail = dlist.head;
	}
	else// danh sách khác rỗng
	{
		new_node->next = dlist.head;
		dlist.head->pre = new_node;
		dlist.head = new_node;
	}
}
void InsertDList(DLIST & dlist, int data,int option)
{
	DNODE * new_node = GetNode(data);
	if (new_node != NULL)
	{
		switch (option)
		{
		case 1://addfirst
			AddFirst(dlist, new_node);
			break;
		case 2://addlast bài tập về nhà
			break;
		case 3://AfterQ bài tập về nhà
			break;
		case 4://beforeQ bài tập về nhà
			break;
		}
		
	}
}
void PrintList(DLIST dlist)
{
	DNODE *p = dlist.head;
	cout << "Current List: ";
	while (p!=NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
void DeleteList(DLIST &dlist)
{
	if (dlist.head != NULL)
	{
		DNODE * p = dlist.head;//1
		dlist.head = p->next;
		if (p == dlist.tail)
		{
			dlist.tail = NULL;
		}
		else
		{
			dlist.head->pre = NULL;
		}
		delete p;
	}

}
void main()
{
	int option=0;
	bool selected = false;//ghi nhận trạng thái chọn chức năng 1, false (chưa chọn)
	DLIST dlist;
	do
	{
		option = menu();
		//các code gọi theo từng chức năng.
		switch (option)
		{
		case 1://khởi tạo danh sách
			system("cls");
			cout << "Khoi tao danh sach rong" << endl;
			Init(dlist);
			cout << "Successfull" << endl;
			selected = true;
			break;
		case 2:
			if (selected == true)
			{
				system("cls");
				cout << "Add new node into LIST" << endl;
				int data;
				cout << "Input value: "; cin >> data;
				InsertDList(dlist, data, 1);
			}
			else
			{
				cout << "Not select 1 function";
			}
			break;
		case 3://khởi tạo danh sách
			if (selected == true)
			{
			system("cls");
			PrintList(dlist);
			}
			else
			{
				cout << "Not select 1 function";
			}
			break;
		case 4://Delete list
			if (selected == true)
			{
				system("cls");
				DeleteList(dlist);
			}
			else
			{
				cout << "Not select 1 function";
			}
			break;
		case 6://khởi tạo danh sách
			system("cls");
			break;
		default:
			system("cls");
			cout << "Chua chon chuc nang" << endl;
			break;
		}

	} while (option>=1&&option<7);
}