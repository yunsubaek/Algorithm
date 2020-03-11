#include<iostream>
#define SIZE 1002
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
	Vertex *vertcies;
	Vertex *tail;
	int size;
};

Graph *CreateGraph()
{
	Graph *g = new Graph;
	g->tail = NULL;
	g->vertcies = NULL;
	g->size = 0;
	return g;
}

Vertex *CreateVertex(int data)
{
	Vertex *v = new Vertex;
	v->visit = 0;
	v->next = NULL;
	v->data = data;
	v->adjlist = NULL;
	return v;
}

Edge *CreateEdge(Vertex *from, Vertex *to)
{
	Edge *e = new Edge;
	e->from = from;
	e->to = to;
	e->head = NULL;
	e->tail = NULL;
	e->next = NULL;
	return e;
}

void AddVertex(Graph *g, Vertex *v)
{
	if (g->size == 0)
	{
		g->vertcies = v;
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

}

int main()
{
	int n, m, v;
	cin >> n >> m >> v;
	Graph *g = CreateGraph();
	Vertex *v_arr[SIZE];
	
	for (int i = 1; i <= n; i++)
	{
		v_arr[i] = CreateVertex(i);
		AddVertex(g, v_arr[i]);
	}

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		AddEdge(v_arr[a], CreateEdge(v_arr[a], v_arr[b]));
		AddEdge(v_arr[b], CreateEdge(v_arr[b], v_arr[a]));
	}
}