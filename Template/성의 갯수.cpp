#include<iostream>
#define SIZE 54
using namespace std;
bool flag;
int cnt;

typedef struct Node
{
	int x;
	int y;
	Node *next;
}Node;

typedef struct Queue
{
	int size;
	Node *head;
	Node *tail;
}Queue;

void push(Queue *q, int x, int y)
{
	Node *newQ = new Node;
	newQ->x = x;
	newQ->y = y;
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

int idx[8] = { 1,1,1,-1,-1,-1,0,0 };
int idy[8] = { 1,-1,0,1,-1,0,1,-1 };

int main()
{
	Queue *q = new Queue;
	q->head = NULL;
	q->tail = NULL;
	q->size = 0;
	while (1)
	{
		int n, m, cnt = 1;
		int arr[SIZE][SIZE] = { 0 };
		cin >> m >> n;
		if (n == 0 && m == 0) break;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				cin >> arr[i][j];
			}
		}

		for (int x = 1; x <= n; x++)
		{
			for (int y = 1; y <= m; y++)
			{
				if (arr[x][y] == 1)
				{
					int l = x, k = y;
					cnt++;
					arr[l][k] = cnt;
					flag = 0;
					while (!flag)
					{
						for (int i = 0; i < 8; i++)
						{
							if (l + idx[i] >= 1 && l + idx[i] <= n && k + idy[i] >= 1 && k + idy[i] <= m)
							{
								if (arr[l + idx[i]][k + idy[i]] == 1)
								{
									arr[l + idx[i]][k + idy[i]] = cnt;
									push(q, l + idx[i], k + idy[i]);
								}
							}
						}
						if (q->size != 0)l = q->head->x;
						if (q->size != 0)k = q->head->y;
						pop(q);
					}
				}
			}
		}
		cout << cnt - 1 << endl;
	}
}