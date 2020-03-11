#include<iostream>
#define SIZE 200002
using namespace std;
bool flag = 0;

typedef struct Node
{
	int data;
	Node *next;
}Node;

typedef struct Queue
{
	int size;
	Node *head;
	Node *tail;
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
		flag = 1;
		//cout << "Queue is empty" << endl;
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
	q->tail = NULL;
	q->size = 0;
	flag = 0;
}