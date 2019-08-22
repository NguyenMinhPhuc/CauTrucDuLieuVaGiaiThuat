#include <iostream> // io
#include <stack> // use stack

using namespace std;

int main() {
	char num[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
	stack <char> S; // khai bao Stack voi kieu du lieu la int

	int coSo, so, du;

	cout << "Nhap so can chuyen: ";
	cin >> so;

	cout << "Nhap co so can chuyen: ";
	cin >> coSo;

	// chuyen doi bang cach dua vao Stack
	while (so) {
		du = so % coSo;
		S.push(num[du]);
		so /= coSo;
	}

	// Xuat ra
	while (!S.empty()) {
		cout << S.top();
		S.pop();
	}

	return 0;
}