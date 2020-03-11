#include<iostream>
#define SIZE 1002
using namespace std;
int arr[SIZE][SIZE] = { 0 };
bool flag;

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

void push(Queue *q,int x, int y, int cnt)
{
	Node *newQ = new Node;
	newQ->x = x;
	newQ->y = y;
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
		//cout << "Queue is empty" << endl;
	}
	else
	{
		temp = q->head;
		q->head = q->head->next;
		delete (temp);
		q->size--;
	}
}

int idx[4] = { 0,0,1,-1 };
int idy[4] = { 1,-1,0,0 };

int main()
{
	Queue *q = new Queue;
	q->head = NULL;
	q->tail = NULL;
	q->size = 0;
	int n, m, cnt = 1;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> arr[i][j];
		}
	}

	int x = n, y = m;
	flag = 0;
	if (arr[1][1] != 0)
	{
		cout << 0 << endl;
	}
	else
	{
		while (!flag)
		{
			for (int i = 0; i < 4; i++)
			{
				if (x + idx[i] >= 1 && x + idx[i] <= n && y + idy[i] >= 1 && y + idy[i] <= m)
				{
					if (arr[x + idx[i]][y + idy[i]] == 0 && arr[x+idx[i]][y+idy[i]] != -1)
					{
						arr[x + idx[i]][y + idy[i]] = cnt;
						push(q, x + idx[i], y + idy[i], cnt + 1);
					}
				}
			}
			if (q->size != 0)x = q->head->x;
			if (q->size != 0)y = q->head->y;
			if (q->size != 0)cnt = q->head->cnt;
			pop(q);
		}
		if (arr[1][1] != 0) cout << arr[1][1] << endl;
		else cout << -1 << endl;
	}
}