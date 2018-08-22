//thực hiện các nhiệm vụ sau:
//1. khai báo cấu trúc dslk đơn để lưu số (Number).
	//1.1 làm việc với kiểu số
	//1.2 Làm việc với kiểu bất kỳ
//2. Nhập dữ liệu vào danh sách.
	//2.1 Thêm vào đầu.
	//2.2 Thêm vào đuôi.
	//2.3 thêm vào vị trí bất kỳ trong danh sách.
	//2.4 Thêm bằng bàn phím.
	//2.5 thêm bằng random.
//3. Duyệt danh sách
	//3.1 In toàn bộ danh sách.
	//3.2 In danh sách các số chẵn, số lẻ, số nguyên tố (theo yêu cầu)
	//3.3 Tìm kiếm giá trị x nhập từ bàn phím trong danh sách.
	//3.4 Tìm kiếm tất cả các trí trị x có trong danh sách. có bao nhiêu giá trị x trong dslk
//4. Xóa danh sách
	//4.1. xóa giá trị x khỏi danh sách
	//4.2. xóa tất cả các giá trị x khỏi danh sách.
	//4.3. Xóa phần tử đầu danh sách.
	//4.4. xóa toàn bộ danh sách.
#include <iostream>
#include <ctime>
using namespace std;

// khai báo cấu trúc danh sách liên kết đơn
typedef struct node
{
	int data;
	node* link;
}NODE;
typedef struct list
{
	NODE* first;
	NODE* last;
}LIST;

//Khởi tạo danh sách 
void Init(LIST &list)
{
	list.first = list.last = NULL;
}
NODE* GetNode(int data)
{
	NODE *p;
	p = (NODE*)malloc(sizeof(NODE));
	//p = new NODE;
	if (p == NULL)
	{
		exit(1);
	}
	p->data = data;
	p->link = NULL;
	return p;
}
//Thêm node vào đầu danh sach
void AddFirst(LIST &list, NODE *new_node)
{
	if (list.first == NULL)
	{
		list.first = new_node;
		list.last = list.first;
	}
	else
	{
		new_node->link = list.first;
		list.first = new_node;
	}
}
void AddLast(LIST &list, NODE *new_node)
{
	if (list.first == NULL)//dsanh rỗng
	{
		list.first = new_node;
		list.last = list.first;
	}
	else//dsach khác rỗng
	{
		list.last->link = new_node;
		list.last = new_node;
	}
}
//option=1 addlast
void InsertList(LIST &list, int data,int option)
{
	NODE *p;
	p = GetNode(data);
	if (p != NULL)
	{
		if (option == 1)
		{
			AddLast(list, p);
		}
		else
		{
			AddFirst(list, p);
		}
	}
}
//option 1=bằng tay
void CreateList(LIST &list,int option){
	if (option == 1){
		Init(list);
		int data;
		while (true){
			cout << "Nhap data: "; cin >> data;
			if (data != -1){
				InsertList(list, data, 0);//1. thêm vào đuôi
			}
			else{break;}}
	}
	else{
		//thêm bằng random
		Init(list);
		int n;
		cout << "so phan tu mong muon: "; cin >> n;
		int data;	
		srand(time(0));
		for (int i = 0; i < n; i++){
			data = 1 + rand() % (100 - 1 + 1); //rand();//a+rand()%(b-a+1) hàm lấy giá trị ngẫu nhiên trong khoản;
			InsertList(list, data, 0);//1. thêm vào đuôi
		}
	}

}
void PrintList(LIST list)
{
	NODE *p = list.first;
	while (p!=NULL)
	{ 
		cout << p->data<<" ";
		p = p->link;
	}
}
//hàm search đúng
NODE* Search(LIST list, int x)
{
	NODE*p = list.first;
	while (p != NULL&&p->data != x)
	{
		p = p->link;
	}
	return p;
}
//hàm search sai
NODE* SearchNotNULL(LIST list, int x)
{
	NODE*p = list.first;
	while (p != NULL)
	{
		if (p->data == x)
			return p;
		p = p->link;
	}
}
//Thêm vào một node có giá trị data sau nút có giá trị x , x và data nhập từ bàn phím
void AddAfterXValude(LIST &list,  int x,int data)
{
	//tìm ra được node có giá trị 2 
	NODE* q = Search(list,x);
	NODE *new_node = GetNode(data);
	if (q != NULL&&new_node != NULL)
	{
		new_node->link = q->link;
		q->link = new_node;
		if (q == list.last)
			list.last = new_node;
	}
	else
	{
		cout << "khong ton tai node Q";
	}
	// thực hiện thao tác thêm vào sau node so 2
}
void RemoveFirst(LIST &list)
{
	if (list.first != NULL)
	{
		NODE*p = list.first;
		list.first = p->link;
		if (list.first == NULL)
			list.last = NULL;
		free(p);
		//delete p;
	}
}
void RemoveALL(LIST &l)
{
	if (l.first != NULL)
	{
		NODE*p = l.first;
		while (p != NULL)
		{
			p = p->link;
			RemoveFirst(l);
		}
	}
	else
	{
		cout << "danh sach da rong";
	}
}
void main()
{
	LIST l;
	CreateList(l,1);
	PrintList(l);
	AddAfterXValude(l, 1, 20);
	cout << endl;
	PrintList(l);
	RemoveFirst(l);
	cout << endl;
	PrintList(l);
	RemoveALL(l);
	cout << "Danh sach dau roi"<<endl;
	PrintList(l);
	system("Pause");
}
