//https://www.acmicpc.net/problem/5014
#include<iostream>
#define SIZE 1000001
using namespace std;
bool flag = 0;
int chk[SIZE];

struct Node
{
	int data;
	int cnt;
	Node *next;
};

struct Queue
{
	int size;
	Node *head;
	Node *tail;
};

void push(Queue *q, int data, int cnt)
{
	Node *newQ = new Node;
	newQ->data = data;
	newQ->cnt = cnt;
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
	}
	else
	{
		temp = q->head;
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
	int f, s, g, u, d;
	cin >> f >> s >> g >> u >> d;
	int now = s, cnt = 1;
	while (!flag)
	{
		if (now == g) { cout << chk[g]; return 0; }
		if (now + u <= f && (chk[now + u] == 0 || chk[now + u] > cnt)) { chk[now + u] = cnt; push(q, now + u, cnt + 1); };
		if (now - d > 0 && (chk[now - d] == 0 || chk[now - d] > cnt)) { chk[now - d] = cnt; push(q, now - d, cnt + 1); };

		if (q->size != 0)now = q->head->data;
		if (q->size != 0)cnt = q->head->cnt;
		pop(q);
		if (chk[g] != 0)
		{
			cout << chk[g];
			return 0;
		}
	}
	cout << "use the stairs";
}