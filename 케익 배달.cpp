#include<iostream>
#define SIZE 100002
#define ABS(a) ((a)>0?(a):-(a))
using namespace std;
bool flag = 0;

struct Map
{
	int x, y;
};

struct Node
{
	int xx, yy;
	Node *next;
};

struct Queue
{
	int size;
	Node *head;
	Node *tail;
};

void push(Queue *q, int xx, int yy)
{
	Node *newQ = new Node;
	newQ->next = NULL;
	newQ->xx = xx;
	newQ->yy = yy;
	if (q->size == 0)
	{
		q->head = newQ;
		q->tail = newQ;
	}
	else
	{
		q->tail->next = newQ;
		q->tail = newQ;
	}
	q->size++;
}

void pop(Queue *q)
{
	Node *temp;
	if (q->size == 0)
	{
		flag = 1;
	}
	else
	{
		temp = q->head;
		q->head = q->head->next;
		cout << temp->xx << '/' << temp->yy << endl;
		delete temp;
		q->size--;
	}
}

int main()
{
	int n, startx, starty;
	Queue *q = new Queue;
	q->head = NULL;
	q->tail = NULL;
	q->size = 0;
	struct Map arr[SIZE];
	cin >> n >> startx >> starty;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].x >> arr[i].y;
	}
	//cout << 123 << endl;
}