////Yêu cầu:
////Một trường học cần lưu trữ danh sách sinh viên gồm những thông tin sau: Mã sinh viên (ID), tên sinh viên (Name), mã lớp (ClassID).
////Sinh viên có thể được thêm vào danh sách khi cần.
////Sinh viên có thể được tìm kiếm theo mã số và tên hay lớp. khi tìm thấy thì cho phép in thông tin sinh viên đó.
////Hãy lựa chọn cấu trúc dữ liệu thích hợp để lưu trữ danh sách trên.
//#include "iostream"
//#include "string"
//#include <iomanip>// for std::setw(n), std::setfill(ch), std::left, std::right
//using namespace std;
//
////cấu trúc sinh vien
//typedef struct sinhvien
//{
//	int ID;
//	string Name;
//	string ClassID;
//}SINHVIEN;
//
//typedef SINHVIEN dataTypeSV;
//
//static dataTypeSV InputSinhVien()
//{
//	dataTypeSV sinhVien;
//
//	cout << "Nhap ID: ";
//	cin >> sinhVien.ID;
//	cout << "Nhap Name: ";
//	cin.ignore();
//	getline(cin, sinhVien.Name);
//	cout << "Nhap ClassID: ";
//	getline(cin, sinhVien.ClassID);
//
//	return sinhVien;
//}
////Phương thức in thông tin sinh viên.
////Level =0 khi in dòng đầu tiên trong danh sách, từ dòng thứ 2 sẽ không in tiêu đề nữa.
//static void PrintSinhSien(dataTypeSV sinhVien, int Level){
//	if (Level == 0)
//	{
//		cout<< setw(5) << left << "ID";// độ rộng 5 ký tự, canh trái ID
//		cout << setw(30) << left << "Name";	// độ rộng 30 ký tự, canh trái Name
//		cout << setw(20) << right << "Address" << endl;	// độ rộng 20 ký tự, canh phải ClassID
//		cout << setfill('-');		// set fill bằng ký tự '-' thay vì ' '
//		cout << setw(55) << "-" << endl;// fill 55 ký tự '-'
//	}
//	// reset fill bằng ký tự ' '
//	cout << setfill(' ');
//	cout << setw(5) << left <<sinhVien.ID;// độ rộng 5 ký tự, canh trái ID
//	cout << setw(30) << left << sinhVien.Name;	// độ rộng 30 ký tự, canh trái Name
//	cout << setw(20) << right << sinhVien.ClassID << endl;	// độ rộng 20 ký tự, canh phải ClassID
//	
//}
////Khai báo cấu trúc node
//typedef struct nodesv{
//	dataTypeSV data;
//	nodesv * link;
//}NODESV;
//typedef NODESV* ptrNodeSV;
////Phương thức menu chọn chức năng
//static int MenuSingleList_Extend(){
//	cout << "=========================" << endl;
//	cout << "--- SINGLELIST_EXTEND ---" << endl;
//	cout << "=========================" << endl;
//
//	cout << "1. Init List"<<endl;
//	cout << "2. Create list number" << endl;
//	cout << "3. Print list number" << endl;
//	cout << "4. Exit" << endl;
//	int option;
//	cout << "Select Function: ";
//	cin >> option;
//	return option;
//}
//static void MainSingle_ListExtend(){
//	int option;//Biến chọn chức năng
//	const bool addfirst = true;//biến lựa chọn cách thêm node vào danh sách.
//	while (true)
//	{
//		option = MenuSingleList_Extend();
//		switch (option)
//		{
//		case 1:
//		PrintSinhSien(InputSinhVien(),0);
//			break;
//		case 2:
//			break;
//		case 3:
//			break;
//		case 4:
//			cout << "========The end Single Extend ===========" << endl;
//			return;
//		}
//	}
//}