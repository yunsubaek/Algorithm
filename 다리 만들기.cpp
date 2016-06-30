#include<iostream>
#define SIZE 102
using namespace std;
int arr[SIZE][SIZE];
bool flag = 0;

typedef struct Node
{
	int x;
	int y;
	int cnt;
	Node *next;
}Node;

typedef struct Queue
{
	int size;
	Node *head;
	Node *tail;
}Queue;

void push(Queue *q, int x, int y, int cnt)
{
	Node *newQ = new Node;
	newQ->next = NULL;
	newQ->x = x;
	newQ->y = y;
	newQ->cnt = cnt;
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
		cout << "Queue is empty" << endl;
	}
	else
	{
		temp = q->head;
		cout << temp->x << " " << temp->y << endl;
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
	int n;
	cin >> n;
	//input
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	//push
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (arr[i][j] == 1 && (arr[i + 1][j] != 1 && i + 1 <= n || arr[i][j + 1] != 1 && j + 1 <= n || arr[i - 1][j] != 1 && i - 1 > 0 || arr[i][j - 1] != 1 && j - 1 > 0))
				push(q, i, j, 1);
		}
	}
	int x = q->head->x, y = q->head->y, cnt = q->head->cnt;
	pop(q);
	while (!flag)
	{
		if (arr[x - 1][y] == 0 && x - 1 >= 1) { arr[x - 1][y] = 8; push(q, x - 1, y, cnt + 1); }
		if (arr[x][y - 1] == 0 && y - 1 >= 1) { arr[x][y - 1] = 8; push(q, x, y - 1, cnt + 1); }
		if (arr[x + 1][y] == 0 && x + 1 <= n) { arr[x + 1][y] = 8; push(q, x + 1, y, cnt + 1); }
		if (arr[x][y + 1] == 0 && y + 1 <= n) { arr[x][y + 1] = 8; push(q, x, y + 1, cnt + 1); }

		if (q->size != 0)x = q->head->x;
		if (q->size != 0)y = q->head->y;
		if (q->size != 0)cnt = q->head->cnt;
		pop(q);
	}
}