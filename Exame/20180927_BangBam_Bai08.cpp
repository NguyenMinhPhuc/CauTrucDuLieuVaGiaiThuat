//Nhập N ≤ 1000 số nguyên từ bàn phím.Hãy viết chương trình lần lượt thêm N giá trị số nguyên trên vào bảng băm có kích thước m(m>0), sử dụng hàm băm H(k) = k mod m, theo phương pháp dò bậc hai.
#include <iostream>
using namespace std;
int menu()
{
	int option;
	cout << "-----Menu----";
	cout << "\n1. Init Hashtable";
	cout << "\n2. Add to Hashtable";
	cout << "\n3. Print Hashtable";
	cout << "\n4. Search Item";
	cout << "\n5. Delete item";
	cout << "\n6. Exit";
	cout << "seleted Option: "; cin >> option;
	return option;
}
//Khởi tạo bảng băm 
//typedef float item;
#define max 1001
typedef struct bangbam
{
	int data[max];
	int soPt;

}BB;
void Init(BB &b)
{
	for (int i = 0; i < max; i++)
	{
		b.data[i] = -1;
		b.soPt = 0;
	}
}
//Hàm bằm với value: giá trị cần băm, size: khích thước
int HK(int value, int size)
{
	return (value%size);
}
void Push(BB &b, int value,int size)
{
	int i = HK(value, size);
	while (b.data[i] != -1 && b.soPt<size)//&&, || b.data[i]!=value
	{
		i = ((++i)*(i)) % size;
	}
	if (b.soPt < size)
	{
		b.data[i] = value;
		b.soPt++;
	}
	else
	{
		cout << "Hashtable full";
	}
}
void NhapDuLieuChoBangBam(BB &b,int size)
{
	int x;
	do
	{
		cout << "Nhap phan tu thu: " << b.soPt + 1;
		cin >> x;
		if (x != -1)
			Push(b, x,size);
	} while (x!=-1);//Nhap -1 để kết thúc vòng lặp
}
void PrintHashtable(BB b)
{
	for (int i = 0; i < max; i++)
	{
		if (b.data[i] != -1)
			cout << b.data[i] << " ";
	}
}
int SearchHashtable(BB b, int value,int size)
{
	int i = HK(value, size);
	while (b.data[i]!=-1&&b.data[i]!=value)
	{
		i = ((++i)*(i)) % size;
	}
	if (b.data[i] == -1)
		return -1;//không tìm thấy
	return i;//thay tai vi tri i
}
int  DeleteHashtable(BB &b, int value, int size)
{
	int i = HK(value, size);
	while (b.data[i] != -1 && b.data[i] != value)
	{
		i = ((++i)*(i)) % size;
	}
	if (b.data[i] == -1)
	{
		return -1;//không tìm thấy
	}
	else//tìm thấy
	{
		b.data[i] = -1;
		b.soPt--;
		return i;
	}
}


void main()
{
	int option = 0;
	BB b;

	do
	{
		option = menu();
		switch (option)
		{
		case 1:
			Init(b);
			break;
		case 2:
			NhapDuLieuChoBangBam(b, max);
			break;
		case 3:
			PrintHashtable(b);
			break;
		case 4:
		{
			int value;
			cout << "Nhap gia tri can tim: "; cin >> value;
			int l = SearchHashtable(b, value, max);
			if (l == -1)
			{
				cout << "Khong tim thay " << value << " trong Hashtable";
			}
			else
			{
				cout << "Tim thay " << value << " tai vi tri " << l;
			}
			break;
		}
		case 5:
		{
			int value1;
			cout << "Nhap gia tri can tim: "; cin >> value1;
			int k = DeleteHashtable(b, value1, max);
			if (k == -1)
			{
				cout << "Khong tim thay " << value1 << " trong Hashtable";
			}
			else
			{
				cout << "Tim thay " << value1 << " tai vi tri " << k;
			}
			break;
		}
		}
	} while (option != 6);
}
