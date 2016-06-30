//https://www.acmicpc.net/problem/10451
//순열 사이클
#include<iostream>
#define SIZE 1002
using namespace std;
int n;

struct Vertex;
struct Edge;

struct Vertex
{
	int data;
	int visit;
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
	v->visit = 0;
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

void dfs(Vertex *v)
{
	Edge *e = v->adjlist;
	v->visit = 1;
	while (e)
	{
		if (e->to != NULL && e->to->visit == 0)
			dfs(e->to);
		e = e->next;
	}
}

int main()
{
	int nCount;
	cin >> nCount;
	for (int itr = 0; itr < nCount; itr++)
	{
		Graph *g = CreateGraph();
		Vertex *v_arr[SIZE];
		int cnt = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			v_arr[i] = CreateVertex(i);
			AddVertex(g, v_arr[i]);
		}
		for (int i = 1; i <= n; i++)
		{
			int a;
			scanf("%d", &a);
			AddEdge(v_arr[i], CreateEdge(v_arr[i], v_arr[a]));
		}
		for (int i = 1; i <= n; i++)
		{
			if (v_arr[i]->visit == 0)
			{
				dfs(v_arr[i]);
				cnt++;
			}
		}
		cout << cnt << endl;
	}
}