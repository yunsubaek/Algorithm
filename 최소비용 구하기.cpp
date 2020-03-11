//최소비용 구하기
//https://www.acmicpc.net/problem/1916
#include "bits_stdc++.h"
#define SIZE 1002
#define INF 1000000000
using namespace std;
int n, m, start, finish, dist[SIZE];
vector<pair<int, int> >v[SIZE];
priority_queue<pair<int, int> >pq;

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int from, to, cost;
		scanf("%d %d %d", &from, &to, &cost);
		v[from].push_back(make_pair(to, cost));
	}
	scanf("%d %d", &start, &finish);
	for (int i = 1; i <= n; i++)
		if(i!=start)dist[i] = INF;
	pq.push(make_pair(0, start));
	while (!pq.empty())
	{
		int now = pq.top().second;
		int now_cost = -pq.top().first;
		int len = v[now].size();
		pq.pop();
		for (int i = 0; i < len; i++)
		{
			int to = v[now][i].first;
			int to_cost = v[now][i].second;
			if (dist[to] > now_cost + to_cost) 
			{
				dist[to] = now_cost + to_cost;
				pq.push(make_pair(-dist[to], to));
			}
		}
	}
	cout << dist[finish] << endl;
	return 0;
}