//https://www.acmicpc.net/problem/1504
//특정한 최단 경로(다익스트라)
#include "bits_stdc++.h"
#define SIZE 802
#define INF 1000000000
using namespace std;
vector<pair<int, int> > v[SIZE];
bool flag = 0;

int dijikstra(int from, int to)
{
	priority_queue<pair<int, int> > pq;
	//시작점 제외 무한대값으로 초기화
	int dist[SIZE] = { 0 };
	for (int i = 0; i < SIZE; i++)
		if (i != from)dist[i] = INF;

	pq.push(make_pair(0, from));
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
	if (dist[to] == INF)flag = 1;
	return dist[to];
}

int main()
{
	int v_num, e_num;
	cin >> v_num >> e_num;
	for (int i = 0; i < e_num; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back(make_pair(b, c));
		v[b].push_back(make_pair(a, c));
	}
	int f1, f2;
	cin >> f1 >> f2;
	int a, b;
	a = dijikstra(1, f1) + dijikstra(f1, f2) + dijikstra(f2, v_num);
	b = dijikstra(1, f2) + dijikstra(f2, f1) + dijikstra(f1, v_num);
	if (flag)cout << -1 << endl;
	else cout << min(a, b) << endl;
}