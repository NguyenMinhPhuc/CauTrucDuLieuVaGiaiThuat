#include "iostream"
using namespace std;


#pragma region Phần khai báo tên file
#include "Common.cpp"
#pragma endregion


static int menu()
{
	cout << "========================" << endl;
	cout << "--- SINGLELIST_BASIC ---" << endl;
	cout << "========================" << endl;

	cout << "1. Init List" << endl;
	cout << "2. Create list number" << endl;
	cout << "3. Print list number" << endl;
	cout << "4. Exit" << endl;
	int option;
	cout << "Select Function: ";
	cin >> option;
	return option;
}

// định nghĩa kiểu dữ liệu data.
typedef int dataType;
//Định nghĩa cấu trúc node cho danh sách.
typedef struct node{
	dataType data;
	node*link;
}NODE;
//Định nghĩa kiểu dữ liệu con trỏ NODE.
typedef NODE* ptrNode;
//Định nghĩa cấu trúc danh sách liên kết
typedef struct list{
	ptrNode first;
	ptrNode last;
}LIST;
//Khởi tạo Cấu trúc LIST
static void InitList(LIST &list){
	list.first = list.last = NULL;
}
//Viết phương thức tạo một NODE cho danh sách.
static ptrNode GetNode(dataType data){
	ptrNode p = (ptrNode)malloc(sizeof(NODE));
	if (p == NULL)
		exit(1);
	p->data = data;
	p->link = NULL;

	return p;
}
//Các bước thực hiện Nhập danh sách số Nguyên.
//1. Phương thức thêm một NODE vào đầu danh sách.
static void AddFirst(LIST &list, ptrNode new_Node){
	if (list.first == NULL)	{
		new_Node = list.first;
		list.last = list.first;
	}
	else{
		new_Node->link = list.first;
		list.first = new_Node;
	}
}
//2. Phương thức thêm một NODE vào cuối danh sách
static void AddLast(LIST &list, ptrNode new_Node){
	if (list.first == NULL)	{
		new_Node = list.first;
		list.last = list.first;
	}
	else{
		new_Node->link = list.last;
		list.last = new_Node;
	}
}
//3. Phương thức insert một data vào Danh sách.
static void InsertNode(LIST &list, dataType data, bool addFirst){
	ptrNode p = GetNode(data);
	if (p != NULL){
		if (addFirst){
			AddFirst(list, p);
		} 
		else{
			AddLast(list, p);
		}
	}
}
static dataType InputData(int i)
{
	dataType data;
	cout << "Nhap gia tri PT[" << i << "]:";
	cin >> data;
	return data;
}
//4. Phương thức Create một danh sách.
static void CreateList(LIST &list, bool addFirst){
	dataType data;
	int i = 0;
	while (true)
	{
		data = InputData(++i);
		if (data != -1){
			InsertNode(list, data, addFirst);
		}
		else{
			break;
		}
	}
}
//In danh sách liên kết
static void PrintList(LIST list){
	ptrNode p = list.first;
	while (p!=NULL)
	{
		// In data
		cout << p->data << ", ";
		p = p->link;
	}
}
//Thêm một node sau Q
static void AddAfterNodeQ(LIST &list, ptrNode Q, ptrNode newNode){

}

//Xóa Node Đầu danh sách
static void DeleteFirst(LIST &list){

}
//Xóa Node cuối danh sách
static void DeleteLast(LIST &list){

}
//Xóa Node sau node Q
static void DeleteAfterQ(LIST &list, ptrNode Q){

}
//Xóa Node co giá trị sau giá trị X
static void DeleteAfterValueX(LIST &list, dataType x){

}
//Xóa Node có giá trị X.
static void DeleteValueX(LIST &list, dataType x){

}

//Đếm số node là số nguyên tố
static void SearchingPrimeNumber(LIST list)
{

}
static void Main_SingleList_Basic(){
	int option;
	LIST list;
	InitList(list);
	const bool addfirst = true;
	while (true)
	{
		option = menu();
		switch (option)
		{
		case 1:
			//CreateList(list, addfirst);
			cout << GeneralRamdom();
			cout << GeneralRamdomGroup(1, 100);
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			cout << "==============The end Single Basic ===========" << endl;
			return;
		}
	}
}