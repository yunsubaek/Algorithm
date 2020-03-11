//https://www.acmicpc.net/problem/1707
//이분 그래프
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
	//방문된 정점의 이전 visit이 1이면 2,아니면 1로 초기화.(아니면 1로 초기화 할 경우 이전이 0이면..아마 될듯ㅎㅎ)
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
		//정점의 갯수,간선의 갯수
		int v_num, e_num;
		scanf("%d %d", &v_num, &e_num);
		//정점 초기화
		for (int i = 1; i <= v_num; i++)
		{
			v_arr[i] = CreateVertex(i);
			AddVertex(g, v_arr[i]);
			visit[i] = 0;
		}
		//간선 초기화
		for (int i = 1; i <= e_num; i++)
		{
			//출발 정점,도착 정점
			int a, b;
			scanf("%d %d", &a, &b);
			//간선 연결 유향그래프
			AddEdge(v_arr[a], CreateEdge(v_arr[a], v_arr[b]));
			//일단 무방향으로 고쳐보자
			AddEdge(v_arr[b], CreateEdge(v_arr[b], v_arr[a]));
		}
		//모든 정점에 대해 dfs.방문한 곳을 같은 visit값으로 다시 방문할 경우 break하고 "NO"출력
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