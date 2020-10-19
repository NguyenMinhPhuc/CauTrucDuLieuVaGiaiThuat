#include "iostream"
#define MAX 100
using namespace std;
typedef int item;

typedef struct queue
{
	item data[MAX];
	int front;
	int rear;
	int count;
}QUEUE;
void InitQueue(QUEUE& queue)
{
	queue.front = 0;
	queue.rear = -1;
	queue.count = 0;
}
bool IsEmpty(QUEUE quere)
{
	return quere.count == 0 ? true : false;
}
bool IsFULL(QUEUE quere)
{
	return quere.count == MAX ? true : false;
}
void Push(QUEUE& queue, item x)
{
	if (IsFULL(queue) == false)
	{
		queue.data[++queue.rear] = x;
		queue.count++;
	}
	else
	{
		cout << "Queue Full";
	}
}
item Pop(QUEUE& queue)
{
	item outPut;
	if (IsEmpty(queue) == false)
	{
		outPut = queue.data[queue.front];
		for (int i = queue.front; i < queue.rear; i++)
		{
			queue.data[i] = queue.data[i + 1];
		}
		queue.rear--;
		queue.count--;
	}
	else
	{
		cout << "queue Empty";
	}
	return outPut;
}

void Push_Circular(QUEUE& queue, item x)
{
	if (IsFULL(queue) == false)
	{
		queue.data[(++queue.rear) % MAX] = x;
		queue.count++;
	}
	else
	{
		cout << "Queue full";
	}
}
item Pop(QUEUE& queue)
{
	item outPut;
	if (!IsEmpty(queue))
	{
		outPut = queue.data[queue.front];
		queue.front = (queue.front++) % MAX;
		queue.count--;
	}
	else
	{
		cout << "Queue Empty";
	}
	return outPut;
}
void main()
{

}