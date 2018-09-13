#include <iostream>
using namespace std;

#define Max 5 //so phan tu toi da cua Queue
typedef int item; //kieu du lieu

struct Queue
{
	int Front, Rear; //front: phan tu dau hang, rear: phan tu cuoi hang
	item Data[Max]; //Mang cac phan tu
	int count; //dem so phan tu cua Queue
};

void Init(Queue &Q); //khoi tao Queue rong
int Isempty(Queue Q); //kiem tra Queue rong
int Isfull(Queue Q); //kiem tra Queue day
void Push(Queue &Q, item x); //them phan tu vao cuoi hang doi
int Pop(Queue &Q); //Loai bo phan tu khoi dau hang doi
int Qfront(Queue Q); //xem thong tin phan tu dau hang doi 
void Push_Circular(Queue &Q, item x); //them phan tu vao cuoi hang doi vong
int Pop_Circular(Queue &Q); //Loai bo phan tu khoi dau hang doi vong
void Input(Queue &Q); //Nhap 
void Output(Queue Q); //Xuat 

void Init(Queue &Q) //khoi tao Queue rong
{
	Q.Front = 0; //phan tu dau
	Q.Rear = -1; // phan tu cuoi o -1 (khong co phan tu trong Q)
	Q.count = 0; //so phan tu bang 0
}

int Isempty(Queue Q) //kiem tra Queue rong
{
	if (Q.count == 0) //so phan tu = 0 => rong
		return 1;
	return 0;
}

int Isfull(Queue Q) //kiem tra Queue day
{
	if (Q.count == Max) //so phan tu = Max => day
		return 1;
	return 0;
}

void Push(Queue &Q, item x) //them phan tu vao cuoi Queue
{
	if (Isfull(Q)) cout<<"Hang doi day !";
	else
	{
		Q.Data[++Q.Rear] = x; //tang Rear len va gan phan tu vao
		Q.count++; //tang so phan tu len
	}
}

int Pop(Queue &Q) //Loai bo phan tu khoi dau hang doi
{
	if (Isempty(Q)) cout << "Hang doi rong !";
	else
	{
		item x = Q.Data[Q.Front];
		for (int i = Q.Front; i<Q.Rear; i++) //di chuyen cac phan tu ve dau hang
			Q.Data[i] = Q.Data[i + 1];
		Q.Rear--; // giam vi tri phan tu cuoi xuong
		Q.count--;//giam so phan tu xuong
		return x; //tra ve phan tu lay ra
	}
}

item Qfront(Queue Q) //xem thong tin phan tu dau hang
{
	if (Isempty(Q)) cout << "Hang doi rong !";
	else return Q.Data[Q.Front];
}

void Push_Circular(Queue &Q, item x) //them phan tu vao cuoi hang doi vong
{
	if (Isfull(Q)) cout << "Hang doi day !";
	else
	{
		Q.Data[(++Q.Rear) % Max] = x;
		//tang Rear len va gan phan tu vao, Neu Rear dang o vi tri Max-1 thi tang ve vi tri 0
		Q.count++; //tang so phan tu len
	}
}

int Pop_Circular(Queue &Q) //Loai bo phan tu khoi dau hang doi vong
{
	if (Isempty(Q)) cout << "Hang doi rong !";
	item x = Q.Data[Q.Front];
	Q.Front = (Q.Front++) % Max; // tang vi tri phan dau tien len, neu dang o Max-1 thi ve 0
	Q.count--;//giam so phan tu xuong
	return x; //tra ve phan tu lay ra
}


void Input(Queue &Q) //nhap hang doi
{
	int n;
	item x;
	do
	{
		cout << "Nhap so phan tu cua Queue  :"<< Max;
		cin>>n;
	} while (n>Max || n<1);
	for (int i = 0; i<n; i++)
	{
		cout<<"Nhap phan tu thu : "<< i + 1;
		cin>>x;
		Push(Q, x);
		Push_Circular(Q, x); //hang vong
	}
}

void Output(Queue Q)
{
	if (Isempty(Q)) cout << "Hang doi rong !";
	else
	{
		for (int i = Q.Front; i <= Q.Rear; i++)
			//for (int i=Q.Front, j=0; j<Q.count; j++, i = (i++) % Max) //hang vong
			cout << Q.Data[i];
		cout << endl;
	}
}

int main()
{
	Queue Q;
	Init(Q);
	Input(Q);
	Output(Q);

	int lua_chon;
	cout << "Moi ban chon phep toan voi DS LKD:";
	cout << "\n1: Kiem tra Queue rong";
	cout << "\n2: Kiem tra Queue day";
	cout << "\n3: Them phan tu vao Queue";
	cout << "\n4: Xoa phan tu trong Queue";
	cout << "\n5: Xuat Queue";
	cout << "\n6: Thoat";
	do
	{
		cout << "\nBan chon: ";
		cin>>lua_chon;
		switch (lua_chon)
		{
		case 1:
		{
			if (Isempty(Q)) cout << "Queue rong !";
			else cout << "Queue khong rong !";
			break;
		}
		case 2:
		{
			if (Isfull(Q)) cout << "Queue day !";
			else cout << "Queue chua day !";
			break;
		}
		case 3:
		{
			item x;
			cout << "Nhap phan tu can chen vao Queue: ";
			cin>>x;
			Push(Q, x);
			//Push_Circular(Q,x); hang vong
			break;
		}
		case 4:
		{
			Pop(Q);
			//Pop_Circular(Q); hang vong
			break;
		}
		case 5:
		{
			Output(Q);
			break;
		}
		case 6: break;
		}
	} while (lua_chon != 6);
	return 0;
}