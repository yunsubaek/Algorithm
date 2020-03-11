#include<iostream>
using namespace std;

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
	Edge *next;
	Edge *head;
	Edge *tail;
};

struct Graph
{
	Vertex *vertices;
	Vertex *tail;
	int size;
};

Graph *CreateGraph()
{
	Graph *g = new Graph;
	g->tail = NULL;
	g->size = 0;
	g->vertices = NULL;
	return g;
}

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
	e->head = NULL;
	e->next = NULL;
	e->tail = NULL;
	e->to = to;
	return e;
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

void dfs(Vertex *vertex)
{
	Vertex *v = vertex;
	Edge *e = vertex->adjlist;
	v->visit = 1;
	while (e)
	{
		if (e->to->visit == 0 && e->to != NULL)
		{
			dfs(e->to);
		}
		e = e->next;
	}
}

int main()
{
	int n, m, cnt = 0;
	cin >> n >> m;
	Graph *g = CreateGraph();
	Vertex *v_arr[1002];

	for (int i = 1; i <= n; i++)
	{
		v_arr[i] = CreateVertex(i);
	}

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		AddEdge(v_arr[a], CreateEdge(v_arr[a], v_arr[b]));
		AddEdge(v_arr[b], CreateEdge(v_arr[b], v_arr[a]));
	}

	for (int i = 1; i <= n; i++)
	{
		if (!v_arr[i]->visit)
		{
			cnt++;
			dfs(v_arr[i]);
		}
	}
	cout << cnt << endl;
}