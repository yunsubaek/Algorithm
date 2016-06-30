//https://www.acmicpc.net/problem/1865
//웜홀(벨만포드) - 무방향인지 유방향인지 잘 인지할것
#include "bits_stdc++.h"
#define INF 1000000000
using namespace std;

struct Edge
{
	int from, to, cost;
};

int main()
{
	int tc;
	cin >> tc;
	for (int itr = 0; itr < tc; itr++)
	{
		int n, m, w, dist[502] = { 0 };
		scanf("%d %d %d", &n, &m, &w);
		vector<Edge> v(2 * m + w);
		for (int i = 0; i < 2 * m; i += 2)
		{
			scanf("%d %d %d", &v[i].from, &v[i].to, &v[i].cost);
			v[i + 1].from = v[i].to;
			v[i + 1].to = v[i].from;
			v[i + 1].cost = v[i].cost;
		}
		for (int i = 2 * m; i < 2 * m + w; i++)
		{
			int cost;
			scanf("%d %d %d", &v[i].from, &v[i].to, &v[i].cost);
			v[i].cost *= -1;
		}
		for (int i = 2; i <= n; i++)
		{
			dist[i] = INF;
		}
		bool flag = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < 2 * m + w; j++)
			{
				int from = v[j].from;
				int to = v[j].to;
				int cost = v[j].cost;
				if (dist[to] > dist[from] + cost)
				{
					dist[to] = dist[from] + cost;
					if (i == n)flag = 1;
				}
			}
		}
		if (flag)printf("YES\n");
		else printf("NO\n");
	}
}