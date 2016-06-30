//https://www.acmicpc.net/problem/1753
//최단 경로
#include "bits_stdc++.h"
#define SIZE 20002
#define INF 2000000000
using namespace std;
vector<pair<int,int> > v[SIZE];
int dist[SIZE];
priority_queue<pair<int, int> > pq;
int main()
{
	int v_num, e_num, st;
	scanf("%d %d %d", &v_num, &e_num, &st);
	//간선정보 입력
	for (int i = 0; i < e_num; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back(make_pair(b, c));
	}
	//거리 INF로 초기화(시작정점 제외)
	for (int i = 0; i < SIZE; i++)
		if(i!=st) dist[i] = INF;
	//출발정점 및 가중치 push.
	pq.push(make_pair(0, st));
	//pq가 빌때까지 반복
	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int now = pq.top().second;
		pq.pop();
		if (dist[now] < cost)continue;
		for (int i = 0; i < v[now].size(); i++)
		{
			int to = v[now][i].first;
			int to_cost = v[now][i].second;
			if (dist[to] > cost + to_cost)
			{
				dist[to] = cost + to_cost;
				pq.push(make_pair(-dist[to], to));
			}
		}
	}
	for (int i = 1; i <= v_num; i++)
	{
		if (dist[i] != INF)printf("%d\n", dist[i]);
		else printf("INF\n");
	}
}