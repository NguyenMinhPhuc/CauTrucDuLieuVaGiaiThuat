#pragma region Mục tiêu của chương 01
/*
Những nội dung cần ôn tập trong chương này
1. Cấu trúc lập trình C++ trong Visual Studio
2. Cú pháp input, output dữ liệu lên màn hình (cout,cin)
3. Biến, khai báo biến (quy tắc đặt tên biến, kiểu dữ liệu)
	3.1. Kiểu dữ liệu số
	3.2. kiểu dữ liệu string.
	3.3. Kiểu dữ liệu cấu trúc.
	3.4. Kiểu dữ liệu mảng
4. Cấu trúc điều khiển (if ... else...; switch ...case...)
5. Cấu trúc lặp (for,while, do ...while)
6. Cách sử dụng hàm
*/
#pragma endregion


#include<iostream>
#include<string>
using namespace std;
static void DislayContent()
{
	cout << "\nBai vi du 01!";
}
#pragma region 2. Cấu trúc nhập xuất dữ liệu trên màn hình Console
static void OnTapVanDeNhapXuat()
{
	cout << "\nNhap mot gia tri N tu ban phim va in ky tu do ra" << endl;
	//Khai báo biến n kiểu số nguyên
	int n;
	//Nhập giá trị từ bàn phím và lưu vào biến n
	cin >> n;

	cout << "Gia tri n = " << n << "\n" << endl;

	cout << "Ket thuc thao tac nhap xuat mot so nguyen";
}
#pragma endregion

#pragma region 3. Biến và khai báo biến

#pragma endregion

#pragma region 4. Cấu trúc điều khiển if...else;
static void OntapCauTrucIf()
{
	//Xác định quyền được kết hôn của nam hay nữ với điều kiện
	//Nếu là nam tuổi >=20, chưa kết hôn;
	//nếu là nữ tuổi phải >=18, chưa kết hôn
	//với Nam=0; nữ =1
	//KetHon=0: chưa kết hôn; KetHon=1 đã kết hôn
	int tuoi;
	cout << "Hay nhap tuoi:"; cin >> tuoi;
	bool gioiTinh;
	cout << "Nhap gioi Tinh (1:nu - 0: nam"; cin >> gioiTinh;
	bool ketHon;
	cout << "Tinh trang ket hon (1: ket hon - 0: chua ket hon: "; cin >> ketHon;
	if (ketHon == 1)
	{
		if (gioiTinh == 1)
		{
			if (tuoi >= 18)
			{
				cout << "Nu Duoc ket hon";
			}
			else
			{
				cout << "Nu khong du tuoi";
			}
		}
		else
		{
			if (tuoi >= 20)
			{
				cout << "Nam Duoc ket hon";
			}
			else
			{
				cout << "Nam khong du tuoi";
			}
		}
	}
	else
	{
		cout << "Nam, nu da ket hon";
	}
}

static void OnTapCauTrucSwitchCase()
{
	int i;
	cout << "Nhap so: "; cin >> i;
	switch (i)
	{
	case 1:
		cout << "Vua nhap so 1";
		break;
	case 2:
		cout << "Vua nhap so 2";
		break;
	default:
		cout << "vua nhap mot so <>1 và <>2";
		break;
	}
}
#pragma endregion

#pragma region 5. Cấu trúc lặp
static void OnTapCauTrucFor()
{
	//in các số nguyên từ 1-10
	for (int i = 1; i <= 10; i++)
	{
		cout << i << ", ";
	}
	cout << endl;

}
static void OnTapCauTrucWhile()
{
	//in các số từ 1-10
	int i = 0;
	while (i<=10)
	{
		i = i + 1;
		cout << i << ", ";
	}
	cout << endl;
}
static void OnTapCauTrucDoWhile()
{
	//in các số từ 1-10
	int i = 0;
	do
	{
		i = i + 1;
		cout << i << ", ";
	} while (i<=10);
	cout << endl;
}
#pragma endregion





static int Exam_0101_Main()
{
	cout << "hello world";
	DislayContent();
	OnTapVanDeNhapXuat();
	system("pause");
	return 0;
}

