#include<iostream>
using namespace std;
bool flag = 0;
struct Vertex;
struct Edge;

//노드에 무슨 값을 넣을지 고민
struct Node
{
	Edge *e;
	int w;
	Node *next;
};

struct Queue
{
	int size;
	Node *head;
	Node *tail;
};

void push(Queue *q,Edge *e, int w)
{
	Node *newQ = new Node;
	newQ->e = e;
	newQ->w = w;
	newQ->next = NULL;
	if (q->size == 0)
	{
		q->head = newQ;
		q->tail = newQ;
	}
	else
	{
		q->tail->next = newQ;
		q->tail = newQ;
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
		//cout << "v_from = " << temp->v_from << ' ' << "v_to = " << temp->v_to << ' ' << "w = " << temp->w << ' ' << endl;
	}
}

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
	if (g->size == NULL)
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
		if (e->to->visit == 0 && e->to)
		{
			cout << e->to->data << ' ';
			dfs(e->to);
		}
		e = e->next;
	}
}

////bfs 어떻게 수정할지..
//void bfs(Queue * q, Vertex *v)
//{
//	Edge * e = q->head->e;
//	v->visit = 1;
//	printf("%d ", v->data);
//
//	while (e)
//	{
//		if (e->to->visit == 0 && e->to)
//			push(q,e->next,0);
//		e = e->next;
//	}
//}


int main()
{
	int n, m, v, cnt = 0;
	cin >> n >> m >> v;
	Graph *g = CreateGraph();
	Vertex *v_arr[12];

	for (int i = 1; i <= n; i++)
	{
		v_arr[i]= CreateVertex(i);
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
			cout << i << ' ';
			dfs(v_arr[i]);
		}
	}
	//방문 초기화
	for (int i = 1; i <= n; i++)
	{
		v_arr[i]->visit = 0;
	}


	cout << endl;
}