#include "iostream"
using namespace std;
//khai bao cau truc node
typedef int item;
typedef struct node
{
	item data;
	node* left;
	node* right;
}NODE;
typedef NODE* ptrNode;
typedef struct tree
{
	ptrNode root;
	int count;
}TREE;
void InitTree(TREE& tree)
{
	tree.root = NULL;
	tree.count = 0;
}
ptrNode GetNode(item value)
{
	ptrNode newNode = new NODE;
	if (newNode != NULL)
	{
		newNode->data = value;
		newNode->left = NULL;
		newNode->right = NULL;
	}
	else
	{
		exit(1);
	}
	return newNode;
}
void InsertTree(ptrNode &root,ptrNode newNode)
{
	if (root == NULL)
		root = newNode;
	else{
		if (root->data > newNode->data)
			InsertTree(root->left, newNode);//goi trai
		else if (root->data < newNode->data)
			InsertTree(root->right, newNode);
		else
		{
			cout << "Gia tri " << newNode->data << " da co";
			exit(1);
		}
	}
}
void NhapDanhSachSo(TREE &tree)
{
	item value;
	int index = 0;
	do
	{
		cout << "Nhap PT[" << ++index << "]: ";
		cin >> value;
		if (value != -1)
			InsertTree(tree.root, GetNode(value));
		else
			break;
	} while (true);
}
int CountLeafNode(ptrNode root)
{
	int count = 0;
	if (root == NULL)
		return 0;
	else
	{
		count = 0;
		if (root->left == NULL && root->right == NULL)
			count++;
		return count + CountLeafNode(root->left) + CountLeafNode(root->right);
	}
}
int Count2ChildNode(ptrNode root)
{
	int count = 0;
	if (root == NULL)
		return 0;
	else
	{
		count = 0;
		if (root->left != NULL && root->right != NULL)
			count++;
		return count + CountLeafNode(root->left) + CountLeafNode(root->right);
	}
}
int Count1ChildNode(ptrNode root)
{
	int count = 0;
	if (root == NULL)
		return 0;
	else
	{
		count = 0;
		if ((root->left != NULL && root->right == NULL)|| (root->left == NULL && root->right != NULL))
			count++;
		return count + CountLeafNode(root->left) + CountLeafNode(root->right);
	}
}
void LNR(ptrNode root)
{
	if (root == NULL)
		return;
	LNR(root->left);
	cout << root->data << ", ";
	LNR(root->right);
}

void main()
{
	TREE tree;
	InitTree(tree);
	NhapDanhSachSo(tree);

	LNR(tree.root);

	system("pause");
}