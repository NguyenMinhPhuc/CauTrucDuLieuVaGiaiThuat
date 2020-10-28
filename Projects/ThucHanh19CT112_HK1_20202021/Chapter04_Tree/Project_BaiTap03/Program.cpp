#include "iostream"
#include "string"
#include "iomanip"
#include "MyDate.cpp"
using namespace std;

typedef struct docgia
{
	int maDocGia;
	string tenDocGia;
	string diaChi;
	DATE ngaySinh;
	DATE ngayLapThe;
}DOCGIA;
typedef struct node
{
	DOCGIA data;
	node* left;
	node* right;
}NODE;

typedef struct tree
{
	NODE* root;
	int count;
}TREE;
NODE* GetNode(DOCGIA docGia)
{
	NODE* p = new NODE;
	if (p != NULL)
	{
		p->data = docGia;
		p->left = NULL;
		p->right = NULL;
	}
	return p;
}
void InsertTree(NODE* root, NODE* newNode)
{
	if (root == NULL)
	{
		root = newNode;
	}
	else
	{
		if (root->data.maDocGia < newNode->data.maDocGia)
			InsertTree(root->right, newNode);
		else if(root->data.maDocGia < newNode->data.maDocGia)
			InsertTree(root->left, newNode);
		else {
			cout << "Gia tri " << newNode->data.maDocGia << " da co.";
			exit(1);
		}
	}
}
void NhapThongTinMotDocGia(DOCGIA& docGia,int index)
{
	cout << "Nhap doc gia thu [" << index << "]: ";
	cout << "Nhap Ma doc gia: ";
	cin >> docGia.maDocGia;
	cin.ignore();
	cout << "Nhap ten doc gia: ";
	getline(cin, docGia.tenDocGia);
	cout << "Nhap dia chi: ";
	getline(cin, docGia.diaChi);
	cout << "Nhap ngay sinh:(dd MM yyyy) ";//29 03 2000
	docGia.ngaySinh = NhapNgay();//dd MM yyyy
	cout << "Nhap ngay lap the (dd/MM/yyyy): ";
	docGia.ngayLapThe = NhapNgayString("-");
}
void NhapDanhSachDocGia(TREE& tree)
{
	NODE* newNode;
	DOCGIA value;
	while (true)
	{
		cout << " Nhap Doc gia:";
		NhapThongTinMotDocGia(value);
		newNode = GetNode(value);
		InsertTree(tree.root, newNode);
		tree.count++;
	}
}