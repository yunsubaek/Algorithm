#include<iostream>
using namespace std;

typedef struct Node
{
	int data;
	struct Node * next;
}Node;

typedef struct Queue
{
	int size;
	Node * head;
	Node * tail;
}Queue;

void push(Queue *q, int data)
{
	Node *newQ = new Node;
	newQ->data = data;
	newQ->next = NULL;
	if (q->size == 0)
	{
		q->head = newQ;
		q->tail = newQ;
	}
	else
	{
		q->tail->next = newQ;
		q->tail = q->tail->next;
	}
	q->size++;
}

void pop(Queue *q)
{
	Node *temp;
	if (q->size == 0)
	{
		cout << -1 << endl;
	}
	else
	{
		temp = q->head;
		cout << q->head->data << endl;
		q->head = q->head->next;
		delete temp;
		q->size--;
	}
}

int main()
{
	Queue *q = new Queue;
	q->head = NULL;
	q->size = 0;
	q->tail = NULL;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		char arr[8] = { 0 };
		cin >> arr;
		if (arr[1] == 'u')
		{
			int a;
			cin >> a;
			push(q, a);
		}
		else if (arr[1] == 'o')
		{
			pop(q);
		}
		else if (arr[1] == 'r')
		{
			if (q->size == 0)cout << -1 << '\n';
			else cout << q->head->data << '\n';
		}
		else if (arr[1] == 'a')
		{
			if (q->size == 0)cout << -1 << '\n';
			else cout << q->tail->data << '\n';
		}
		else if (arr[1] == 'i')
		{
			cout << q->size << '\n';
		}
		else
		{
			if (q->size == 0)cout << 1 << '\n';
			else cout << 0 << '\n';
		}
	}
}