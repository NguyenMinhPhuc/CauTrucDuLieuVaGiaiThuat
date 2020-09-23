//Yêu cầu:
//Một trường học cần lưu trữ danh sách sinh viên gồm những thông tin sau: Mã sinh viên (ID), tên sinh viên (Name), mã lớp (ClassID).
//Sinh viên có thể được thêm vào danh sách khi cần.
//Sinh viên có thể được tìm kiếm theo mã số và tên hay lớp. khi tìm thấy thì cho phép in thông tin sinh viên đó.
//Hãy lựa chọn cấu trúc dữ liệu thích hợp để lưu trữ danh sách trên.
#include "iostream"
#include "string"
#include <iomanip>// for std::setw(n), std::setfill(ch), std::left, std::right
using namespace std;

//cấu trúc sinh vien
typedef struct sinhvien
{
	int ID;
	string Name;
	string ClassID;
}SINHVIEN;

typedef SINHVIEN dataType;
 dataType InputSinhVien()
{
	dataType sinhVien;

	cout << "Nhap ID: ";
	cin >> sinhVien.ID;
	cout << "Nhap Name: ";
	cin.ignore();
	getline(cin, sinhVien.Name);
	cout << "Nhap ClassID: ";
	getline(cin, sinhVien.ClassID);

	return sinhVien;
}
//Phương thức in thông tin sinh viên.
//Level =0 khi in dòng đầu tiên trong danh sách, từ dòng thứ 2 sẽ không in tiêu đề nữa.
 void PrintSinhSien(dataType sinhVien, int Level){
	if (Level == 0)
	{
		cout << setw(5) << left << "ID";// độ rộng 5 ký tự, canh trái ID
		cout << setw(30) << left << "Name";	// độ rộng 30 ký tự, canh trái Name
		cout << setw(20) << right << "Address" << endl;	// độ rộng 20 ký tự, canh phải ClassID
		cout << setfill('-');		// set fill bằng ký tự '-' thay vì ' '
		cout << setw(55) << "-" << endl;// fill 55 ký tự '-'
	}
	// reset fill bằng ký tự ' '
	cout << setfill(' ');
	cout << setw(5) << left << sinhVien.ID;// độ rộng 5 ký tự, canh trái ID
	cout << setw(30) << left << sinhVien.Name;	// độ rộng 30 ký tự, canh trái Name
	cout << setw(20) << right << sinhVien.ClassID << endl;	// độ rộng 20 ký tự, canh phải ClassID

}
//Khai báo cấu trúc node
typedef struct node{
	dataType data;
	node * link;
}NODE;
typedef NODE* ptrNode;
typedef struct list
{
	ptrNode first;
	NODE* last;
}LIST;
void Init(LIST &l)
{
	l.first = l.last = NULL;
}
ptrNode GetNode(dataType data)
{
	ptrNode p;
	p = new NODE;
	if (p == NULL)
		exit(1);
	p->data = data;
	p->link = NULL;
	return p;
}
void AddFirst(LIST &l, ptrNode newNode)
{
	if (l.first == NULL)
	{
		l.first = newNode;
		l.last = l.first;
	}
	else
	{
		newNode->link = l.first;
		l.first = newNode;
	}
}
void InsertList(LIST &l, dataType data,bool isFirst)
{
	ptrNode p = GetNode(data);
	if (isFirst==true)
		AddFirst(l, p);
}
void CreateList(LIST &l,bool isFirst)
{
	SINHVIEN sv;
	while (true)
	{
		sv = InputSinhVien();
		InsertList(l, sv,isFirst);
		cout << "nhap (yes/no): ";
		string chon;
		getline(cin, chon);
		if (chon == "no")
			break;
	}
}
void Print(LIST l)
{
	ptrNode p = l.first;
	int i = 0;
	while (p!=NULL)
	{
		PrintSinhSien(p->data, i++);
		p = p->link;
	}
}
//Phương thức menu chọn chức năng
 int MenuSingleList_Extend(){
	cout << "===========================" << endl;
	cout << "--- Student Managerment ---" << endl;
	cout << "===========================" << endl;

	cout << "1. Init List" << endl;
	cout << "2. Print list Student" << endl;
	cout << "3. Search by ID" << endl;
	cout << "4. Exit" << endl;
	int option;
	cout << "Select Function: ";
	cin >> option;
	return option;
}
 void main(){
	int option;//Biến chọn chức năng
	const bool ADDFIRST = true;//biến lựa chọn cách thêm node vào danh sách.
	LIST l;
	Init(l);
	while (true)
	{
		option = MenuSingleList_Extend();
		switch (option)
		{
		case 1:
			CreateList(l, ADDFIRST);
			//PrintSinhSien(InputSinhVien(), 0);
			break;
		case 2:
			Print(l);
			break;
		case 3:
			break;
		case 4:
			cout << "========The end Single Extend ===========" << endl;
			return;
		}
	}
}