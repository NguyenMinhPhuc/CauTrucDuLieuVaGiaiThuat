#include "iostream"
using namespace std;
//xay dung cau truc node cua cay
typedef int item;
typedef struct node
{
	item data;
	node* left;
	node* right;
}NODE;
//xay dung cau truc cay
typedef struct tree
{
	int count;//so phan tu(node) co trong cay
	NODE* root;
}TREE;
void InitTree(TREE& tree)
{
	tree.count = 0;
	tree.root = NULL;
}
typedef NODE* ptrNode;
NODE* GetNode(item value)
{
	ptrNode p = new NODE;
	if (p != NULL)
	{
		p->data = value;
		p->left = NULL;
		p->right = NULL;
	}
	else
	{
		exit(1);
	}
	return p;
}
void InsertTree(ptrNode& root, ptrNode newNode)
{
	if (root == NULL)
		root = newNode;
	else
	{
		if (root->data < newNode->data)
		{
			InsertTree(root->right, newNode);
		}
		else if(root->data > newNode->data)
		{
			InsertTree(root->left, newNode);
		}
		else
		{
			cout << "Gia tri " << newNode->data << " da co." << endl;
			exit(1);
		}
	}
}
void NhapDanhSachVaoCay(TREE& tree)
{
	ptrNode newNode;
	item value;
	while (true)
	{
		cout << "Nhap value: "; cin >> value;
		newNode = GetNode(value);
		if (value != -1)
		{ 
			InsertTree(tree.root, newNode);
			tree.count++;
		}
		else
			break;
	}
}
void NLR(ptrNode root)
{
	if (root != NULL)
	{
		cout << root->data<<", ";

		NLR(root->left);
		NLR(root->right);
	}
}
void LNR(ptrNode root)
{
	if (root != NULL)
	{
		
		LNR(root->left);
		cout << root->data << ", ";
		LNR(root->right);
	}
}
void LRN(ptrNode root)
{
	if (root != NULL)
	{
		
		LRN(root->left);
		LRN(root->right);
		cout << root->data << ", ";
	}
}
void RNL(ptrNode root)
{
	if (root != NULL)
	{

		RNL(root->right);
		cout << root->data << ", ";
		RNL(root->left);
		
	}
}
void Searching(ptrNode root,item value)
{
	if (root != NULL)
	{
		Searching(root->left, value);
		if (root->data == value)
			cout << root->data;
		Searching(root->right, value);
	}
	
}
bool Search(ptrNode root, item value)
{
	if (root == NULL)
		return false;
	if (root->data == value)
		return true;
	else if (root->data < value)
	{
		Search(root->right, value);
	}
	else
	{
		Search(root->left, value);
	}
}
int menu() {
	cout << "1. them value" << endl;
	cout << "2. duyet cay NLR" << endl;
	cout << "3. duyet cay LNR" << endl;
	cout << "4. duyet cay LRN" << endl;
	cout << "5. Tim kiem value" << endl;
	cout << "6. Xoa theo value" << endl;
	cout << "7. Thoat" << endl;
	int chon;
	cout << "Chon chuc nang: ";
	cin >> chon;
	return chon;
}
void TimNodeThayThe(ptrNode& root, ptrNode& p)
{
	if (root->right == NULL)
	{
		p->data = root->data;
		root = root->left;
	}
	else
	{
		TimNodeThayThe(root->right, p);
	}
}
void DeleteNode(ptrNode& root, int value)
{
	if (root->data > value)
		DeleteNode(root->left, value);
	else if(root->data < value)
		DeleteNode(root->right, value);
	else
	{
		if (root->left == NULL)
			root = root -> right;
		else if(root->right==NULL)
			root = root->left;
		else
		{
			ptrNode p = root;
			TimNodeThayThe(root->left, p);
		}
	}
}
void DeleteTree(TREE &tree)
{
	cout << "Nhap gia tri can xoa: ";
	item value;
	cin >> value;
	DeleteNode(tree.root, value);
	cout << "Cay sau khi xoa: " << endl;
	NLR(tree.root);
}
void main()
{
	int chon;
	TREE tree;
	InitTree(tree);
	while (true)
	{
		chon = menu();
		switch (chon)
		{
		case 1:
			NhapDanhSachVaoCay(tree);
			break;
		case 2:
			NLR(tree.root);
			break;
		case 3:
			LNR(tree.root);
			break;
		case 4:
			RNL(tree.root);
			break;
		case 5:
			if (Search(tree.root, 4))
				cout << "co gia tri can tim";
			else
				cout << "khong co gia tri can tim";
			break;
		case 6:
			//Xoa
			DeleteTree(tree);
			break;
		case 7:
			return;
		}
	}
}