#include "iostream"
using namespace std;
#define MAX 100

typedef int item;

typedef struct hashtable
{
	item data[MAX];
	int count;
}HASHTABLE;

void InitHashTable(HASHTABLE& hashtable)
{
	for (int i = 0; i < MAX; i++)
	{
		hashtable.data[i] = -1;
	}
	hashtable.count = 0;
}
int HK(item value, int size)
{
	return value % size;
}

void Push(HASHTABLE& hashtable, item value, int size)
{
	int i = HK(value, size);
	//giai quyet dung do
	while (hashtable.data[i] != -1 && hashtable.count < size)
	{
		i = (++i * 2) % size;
	}
	//kiem tra de dua value vao trong hashtable
	if (hashtable.count < size)
	{
		hashtable.data[i] = value;
		hashtable.count++;
	}
	else
	{
		cout << "Hashtable full";
	}
}
bool Searching(HASHTABLE& hashtable, item value, int size)
{
	int i = HK(value, size);
	//giai quyet dung do
	while (hashtable.data[i] != -1 && hashtable.data[i] != value)
	{
		i = (++i * 2) % size;
	}
	if (hashtable.data[i] == -1)
		return false;
	else
		return true;
}
int SearchIndex(HASHTABLE& hashtable, item value, int size)
{
	int i = HK(value, size);
	//giai quyet dung do
	while (hashtable.data[i] != -1 && hashtable.data[i] != value)
	{
		i = (++i * 2) % size;
	}
	if (hashtable.data[i] == -1)
		return -1;
	else
		return i;
}
void inPut(HASHTABLE& hashtable, int size)
{
	item x;
	do {
		cout << "Nhap phan tu thu [" << hashtable.count + 1 << "]: ";
		cin >> x;
		if (x != -1)
			Push(hashtable, x, size);
		else
			break;
	} while (true);
}