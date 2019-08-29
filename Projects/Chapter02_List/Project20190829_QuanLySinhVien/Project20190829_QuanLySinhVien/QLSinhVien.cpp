#include "iostream"
#include "string"

using namespace std;
//Xây dựng kiểu dữ liệu cho sinh viên

typedef struct sinhvien
{
	int maSo;
	string hoVaTen;
	string ngaySinh;
	string diaChi;
	string lop;
}SinhVien;
//0. Nhập thông tin một sinh viên
void NhapMotSinhVien(SinhVien &sv,int i)
{
	cout << "Nhap sinh vien thu " << i << ":";
	
	cin >> sv.maSo;
	cin.ignore();
	cout << "Nhap ten sinh vien: ";
	getline(cin, sv.hoVaTen);
	fflush(stdin);
	cout << "Nhap ngay sinh: ";
	getline(cin, sv.ngaySinh);
	fflush(stdin);
	cout << "Nhap dia chi: ";
	getline(cin, sv.diaChi);
	fflush(stdin);
	cout << "Nhap ten lop: ";
	getline(cin, sv.lop);
	fflush(stdin);
}
//SinhVien NhapMotSinhVien()
//{
//
//}
//Xây dựng cấu trúc ds liên kết đơn
//1. Cấu trúc node
typedef struct node
{
	SinhVien data;
	node*link;
}Node;
//2. Cấu trúc danh sách
typedef struct list
{
	Node* first;
	Node* last;
	int count;
}List;

typedef Node* Nodeptr;
//3. khởi tạo node
Nodeptr GetNode(SinhVien sv)
{
	Node *p;
	p = new Node;
	if (p == NULL)
		exit(1);
	p->data = sv;
	p->link = NULL;

	return p;
}
//4. khởi tạo danh sách
void InitList(List &list)
{
	list.first = list.last = NULL;
	list.count = 0;
}
//5. Phương thức thêm 1 node vào đầu danh sách
//5.1 phương thức Addfirst
void AddFirst(List &list, Nodeptr newElement)
{
	if (list.first == NULL)
	{
		list.first = newElement;
		list.last = list.first;
	}
	else
	{
		newElement->link = list.first;
		list.first = newElement;
	}
}
void InsertList(List&list, SinhVien sv)
{
	Nodeptr p;
	p = GetNode(sv);
	if (p != NULL)
		AddFirst(list, p);
}
//6. Nhập danh sách sinh viên
void NhapDanhSachSinhVien(List &list)
{
	while (true)
	{
		SinhVien sv;
		NhapMotSinhVien(sv,list.count+1);
		InsertList(list, sv);
		list.count++;

		char chon;
		cout << "Ban co muon nhap tiep khong (y/n): ";
		cin >> chon;
		if (chon == 'n'||chon=='N')
			break;
	}
}
void InMotSinhVien(SinhVien sv)
{
	
	cout << sv.maSo << "-\t" << sv.hoVaTen << "-\t" << sv.ngaySinh << "-\t" << sv.diaChi << "-\t" << sv.lop;
}
//7. In danh sách sinh viên
void InDanhSachSinhVien(List list)
{
	Nodeptr p;
	p = list.first;
	cout << "Danh sach sinh vien";
	cout << "----------------------------------";
	cout << "MSSV |" << "-\t" << "Ho va ten |" << "-\t" << "Ngay sinh |" << "-\t" << "Dia chi |" << "-\t" << "Ten lop |";
	while (p != NULL)
	{
		//in list
		InMotSinhVien( p->data);
		p = p->link;
	}
}
//8. Tìm kiếm theo mã số
void TimKiemSinhVienTheoMaSo(List list,int maSo)
{
	Nodeptr p;
	p = list.first;
	while (p!=NULL)
	{
		if (p->data.maSo == maSo)
		{
			break;
		}
		p = p->link;
	}
	if (p != NULL)
	{
		cout << "Co sinh vien: " << endl;
		InMotSinhVien(p->data);
	}
	else
	{
		cout << "Khong co sinh vien can tim";
	}
}
//9. Sửa thông tin sinh viên theo mã số
void SuaThongTinSinhVienTheoMaSo(List &list, int maSo)
{
	Nodeptr p;
	p = list.first;
	while (p != NULL)
	{
		if (p->data.maSo == maSo)
		{
			SinhVien sv;
			NhapMotSinhVien(sv,p->data.maSo-1);
			p->data = sv;
			break;
		}
		p = p->link;
	}
	
}
//10. Xóa sinh viên theo mã số
void XoaNodeDauDanhSach(List &list)
{
	if (list.first != NULL)
	{
		Node*p = list.first;

		list.first = p->link;
		if (list.first == NULL)
			list.last;
		free(p);
	}
}
void XoaMotNutSauQ(List &list, Node*q)
{
	if (q != NULL&&q->link != NULL)
	{
		Node*p = q->link;

		q->link = p->link;
		if (p == list.last)
			list.last = q;
		free(p);
	}
}
void XoaMotNutSauGiaTriX(List &list)
{
	int x;
	cout << "Nhap gia tri x:"; cin >> x;
	Node *p = list.first;
	while (p != NULL)
	{
		if (p->data.maSo == x)
			XoaMotNutSauQ(list, p);
		p = p->link;
	}
}

void XoaMotNodeCoGiaTriX(List &list,int maSo)
{
	
	Node *p = list.first;

	while (p != NULL)
	{
		if (p->data.maSo == maSo)
		{
			if (p == list.first)
			{
				XoaNodeDauDanhSach(list);
				break;
			}
			else
			{
				Node*q = list.first;
				while (q->link != p)
				{
					q = q->link;
				}
				XoaMotNutSauQ(list, q);
				break;
			}
		}

		p = p->link;
	}
}
//11.Xây dựng menu
int Menu()
{
	cout << "1. Nhap sinh vien" << endl;
	cout << "2. In danh sach" << endl;
	cout << "3. Tim kiem sinh vien theo ma so" << endl;
	cout << "4. Sua thong tin sinh vien" << endl;
	cout << "5. Xoa sinh vien" << endl;
	
	cout << "6. Thoat" << endl;

	int chon;
	cout << "Chon chuc nang: "; cin >> chon;
	return chon;

}
void main()
{
	List list;
	InitList(list);
	int chon = 0;
	do
	{
		chon = Menu();
		switch (chon)
		{
		case 1:
			NhapDanhSachSinhVien(list);
			break;
		case 2:
			InDanhSachSinhVien(list);
			break;
		case 3:
			int maso;
			cout << "Nhap ma so:"; cin >> maso;
				TimKiemSinhVienTheoMaSo(list, maso);
			break;
		case 4:
			int maso1;
			cout << "Nhap ma so:"; cin >> maso1;
			SuaThongTinSinhVienTheoMaSo(list, maso1);
			break;
		case 5:
			int maso2;
			cout << "Nhap ma so:"; cin >> maso2;
			XoaMotNodeCoGiaTriX(list, maso2);
			break;
		default:
			break;
		}
	} while (chon < 6);
}