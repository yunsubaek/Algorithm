//#include<iostream>
//#define SIZE 10002
//using namespace std;
//bool flag = 0;
//
//typedef struct Node
//{
//	int data;
//	Node *next;
//}Node;
//
//typedef struct Queue
//{
//	int size;
//	Node *head;
//	Node *tail;
//}Queue;
//
//void push(Queue *q, int data)
//{
//	Node *newQ = new Node;
//	newQ->data = data;
//	newQ->next = NULL;
//	if (q->size == 0)
//	{
//		q->head = newQ;
//		q->tail = newQ;
//	}
//	else
//	{
//		q->tail->next = newQ;
//		q->tail = q->tail->next;
//	}
//	q->size++;
//}
//
//void pop(Queue *q)
//{
//	Node * temp;
//	if (q->size == 0)
//	{
//		cout << "Queue is empty" << endl;
//		flag = 1;
//	}
//	else
//	{
//		temp = q->head;
//		q->head = q->head->next;
//		cout << temp->data << endl;
//		delete(temp);
//		q->size--;
//	}
//}
//
//int chk(int a, int n)
//{
//	//1 = d, 2 = s, 3 = l, 4 = r;
//	switch (a)
//	{
//	case 1:
//		//1¹ø(*2)
//		n = (n * 2) % 10000;
//		break;
//	case 2:
//		//2¹ø(-1)
//		if (n - 1 == 0)n = 9999;
//		else n -= 1;
//		break;
//	case 3:
//		//3¹ø(ÁÂ·Î 1Ä­)
//		n *= 10;
//		n = (n % 10000) + n / 10000;
//		break;
//	case 4:
//		//4¹ø(¿ì·Î 1Ä­)
//		int tp = n % 10;
//		n /= 10;
//		n += tp * 1000;
//		break;
//	}
//	return n;
//}
//
//int main()
//{
//	int nCount;
//	bool temp[SIZE] = { 0 };
//	cin >> nCount;
//	for (int itr = 0; itr < nCount; itr++)
//	{
//		Queue *q = new Queue;
//		q->head = NULL;
//		q->tail = NULL;
//		q->size = 0;
//		flag = 0;
//		int n, lcnt = 0, rcnt = 0;
//		int a, b;
//		cin >> a >> b;
//
//		chk(1, a);
//		int now = a;
//		while (!flag)
//		{
//			if (now == b) break;
//			
//		}
//	}
//}