////https://www.acmicpc.net/problem/1238
////파티(플로이드)
//#include "bits_stdc++.h"
//#define SIZE 1002
//#define INF 1000000000
//using namespace std;
//int n, m, x, arr[SIZE][SIZE];
//int main()
//{
//	cin >> n >> m >> x;
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= n; j++)
//		{
//			arr[i][j] = INF;
//		}
//	}
//	for (int i = 0; i < m; i++)
//	{
//		int from, to, cost;
//		scanf("%d %d %d", &from, &to, &cost);
//		arr[from][to] = cost;
//	}
//	for (int k = 1; k <= n; k++)
//	{
//		for (int i = 1; i <= n; i++)
//		{
//			for (int j = 1; j <= n; j++)
//			{
//				if (arr[i][k] == INF || arr[k][j] == INF)continue;
//				if (i == j || j == k || i == k)continue;
//				if (arr[i][k] + arr[k][j] < arr[i][j])
//					arr[i][j] = arr[i][k] + arr[k][j];
//			}
//		}
//	}
//	int max = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		if (arr[i][x] == INF)arr[i][x] = 0;
//		if (arr[x][i] == INF)arr[x][i] = 0;
//		if (arr[i][x] + arr[x][i] > max)max = arr[i][x] + arr[x][i];
//	}
//	printf("%d\n", max);
//	return 0;
//}
////파티(다익스트라)
//#include "bits_stdc++.h"
//#define INF 1000000000
//#define SIZE 1002
//using namespace std;
//int n, m, x;
//vector<pair<int, int> > v[SIZE];
//
//int dijikstra(int from, int too)
//{
//	priority_queue<pair<int, int> >pq;
//	int dist[SIZE] = { 0 };
//	for (int i = 0; i < SIZE; i++)
//		if (i != from)dist[i] = INF;
//	pq.push(make_pair(0, from));
//	while (!pq.empty())
//	{
//		int now = pq.top().second;
//		int cost = -pq.top().first;
//		pq.pop();
//		if (dist[now] < cost)continue;
//		int len = v[now].size();
//		for (int i = 0; i < len; i++)
//		{
//			int to = v[now][i].first;
//			int to_cost = v[now][i].second;
//			if (dist[to] > to_cost + cost)
//			{
//				dist[to] = to_cost + cost;
//				pq.push(make_pair(-dist[to], to));
//			}
//		}
//	}
//	return dist[too];
//}
//
//int main()
//{
//	cin >> n >> m >> x;
//	for (int i = 0; i < m; i++)
//	{
//		int from, to, cost;
//		scanf("%d %d %d", &from, &to, &cost);
//		v[from].push_back(make_pair(to, cost));
//	}
//	int max = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		int sum = dijikstra(i, x) + dijikstra(x, i);
//		if (sum > max)max = sum;
//	}
//	printf("%d\n", max);
//	return 0;
//}