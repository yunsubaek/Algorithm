////https://www.acmicpc.net/problem/2458
////Å° ¼ø¼­
//#include <bits/stdc++.h>
//using namespace std;
//
//int dist[501][501];
//int n, m;
//
//int main()
//{
//	cin >> n >> m;
//	for (int i = 0; i < m; i++)
//	{
//		int from, to;
//		scanf("%d %d", &from, &to);
//		dist[from][to] = 1;
//	}
//
//	for (int k = 1; k <= n; k++)
//	{
//		for (int i = 1; i <= n; i++)
//		{
//			for (int j = 1; j <= n; j++)
//			{
//				if (i == j || j == k || i == k)continue;
//				if (dist[i][k] && dist[k][j])
//					dist[i][j] = 1;
//			}
//		}
//	}
//
//	int result = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		bool flag = 0;
//		for (int j = 1; j <= n; j++)
//		{
//			if (dist[i][j] == 0 && dist[j][i] == 0 && i != j)
//				flag = 1;
//		}
//
//		if (!flag)
//			result++;
//	}
//	printf("%d\n", result);
//}