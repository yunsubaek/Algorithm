//https://www.acmicpc.net/problem/1707
//�̺� �׷���
#include<iostream>
#define SIZE 20002
using namespace std;
int visit[SIZE];
bool flag;

struct Vertex;
struct Edge;

struct Vertex
{
	int data;
	//int visit;
	Vertex *next;
	Edge *adjlist;
};

struct Edge
{
	Vertex *from;
	Vertex *to;
	Edge *head;
	Edge *tail;
	Edge *next;
};

struct Graph
{
	int size;
	Vertex *vertices;
	Vertex *tail;
};

Vertex *CreateVertex(int data)
{
	Vertex *v = new Vertex;
	v->adjlist = NULL;
	v->data = data;
	v->next = NULL;
	return v;
}

Edge *CreateEdge(Vertex *from, Vertex *to)
{
	Edge *e = new Edge;
	e->from = from;
	e->to = to;
	e->next = NULL;
	e->head = NULL;
	e->tail = NULL;
	return e;
}

Graph *CreateGraph()
{
	Graph *g = new Graph;
	g->size = 0;
	g->tail = NULL;
	g->vertices = NULL;
	return g;
}

void AddVertex(Graph *g, Vertex *v)
{
	if (g->size == 0)
	{
		g->vertices = v;
		g->tail = v;
	}
	else
	{
		g->tail->next = v;
		g->tail = v;
	}
	g->size++;
}

void AddEdge(Vertex *v, Edge *e)
{
	if (v->adjlist == NULL)
	{
		v->adjlist = e;
		e->head = e;
		e->tail = e;
	}
	else
	{
		v->adjlist->tail->next = e;
		v->adjlist->tail = e;
	}
}
int a = 1;
void dfs(Vertex *v)
{
	if (flag == 1)return;
	Edge *e = v->adjlist;
	//�湮�� ������ ���� visit�� 1�̸� 2,�ƴϸ� 1�� �ʱ�ȭ.(�ƴϸ� 1�� �ʱ�ȭ �� ��� ������ 0�̸�..�Ƹ� �ɵ���)
	visit[v->data] = a;
	while (e)
	{
		if (flag == 1)break;
		if (visit[e->from->data] == visit[e->to->data])flag = 1;
		
		if(visit[e->to->data]==0)
		{
			if (visit[e->from->data] == 1)
				a = 2;
			else if (visit[e->from->data] == 2)
				a = 1;
			dfs(e->to);
		}
		e = e->next;
	}
}

int main()
{
	int tc;
	cin >> tc;
	for (int itr = 0; itr < tc; itr++)
	{
		a = 1;
		flag = 0;
		Graph *g = CreateGraph();
		Vertex *v_arr[SIZE] = { 0 };
		//������ ����,������ ����
		int v_num, e_num;
		scanf("%d %d", &v_num, &e_num);
		//���� �ʱ�ȭ
		for (int i = 1; i <= v_num; i++)
		{
			v_arr[i] = CreateVertex(i);
			AddVertex(g, v_arr[i]);
			visit[i] = 0;
		}
		//���� �ʱ�ȭ
		for (int i = 1; i <= e_num; i++)
		{
			//��� ����,���� ����
			int a, b;
			scanf("%d %d", &a, &b);
			//���� ���� ����׷���
			AddEdge(v_arr[a], CreateEdge(v_arr[a], v_arr[b]));
			//�ϴ� ���������� ���ĺ���
			AddEdge(v_arr[b], CreateEdge(v_arr[b], v_arr[a]));
		}
		//��� ������ ���� dfs.�湮�� ���� ���� visit������ �ٽ� �湮�� ��� break�ϰ� "NO"���
		for (int i = 1; i <= v_num; i++)
		{
			if (!visit[i])
			{
				dfs(v_arr[i]);
			}
		}
		if (flag == 0)cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}