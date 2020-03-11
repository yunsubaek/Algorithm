#include<iostream>
#define SIZE 1002
using namespace std;

struct Vertex;
struct Edge;
int cnt;
int chk_cnt;

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
	e->head = NULL;
	e->tail = NULL;
	e->next = NULL;
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

void dfs(Vertex *vertex)
{
	Vertex *v = vertex;
	Edge *e = vertex->adjlist;
	v->visit = chk_cnt++;
	if (e->to->visit == 0 && e->to != NULL)
		dfs(e->to);
	e = e->next;
}

int main()
{
	int nCount;
	cin >> nCount;
	for (int itr = 0; itr < nCount; itr++)
	{
		chk_cnt = 1;
		int n;
		cnt = 1;
		cin >> n;
		Graph *g = CreateGraph();
		Vertex *v_arr[SIZE];
		//initialize vertex
		for (int i = 1; i <= n; i++)
		{
			v_arr[i] = CreateVertex(i);
			AddVertex(g, v_arr[i]);
		}
		//initialize edge
		for (int i = 1; i <= n; i++)
		{
			int a;
			cin >> a;
			AddEdge(v_arr[i], CreateEdge(v_arr[i], v_arr[a]));
			AddEdge(v_arr[a], CreateEdge(v_arr[a], v_arr[i]));
		}

		for (int i = 1; i <= n; i++)
		{
			chk_cnt = 1;
			if (!v_arr[i]->visit)
			{
				dfs(v_arr[i]);
			}
			else cnt++;
		}
		cout << cnt++ << endl;
	}
}