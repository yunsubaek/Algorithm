//https://www.acmicpc.net/problem/11657
//Ÿ�Ӹӽ�
#include "bits_stdc++.h"
#define SIZE 502
#define INF 1000000000
using namespace std;

struct Edge
{
	int from, to, cost;
};
int dist[SIZE];

int main()
{
	int n, m;
	cin >> n >> m;
	//�� �긦 �Ҵ��ϰ� �����ؾ��ϴ��� �ǹ�.. �Ƹ� ����� ���������³� Ŀ������ ������ ������ �ƴѰ� ����
	vector<Edge> v(m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &v[i].from, &v[i].to, &v[i].cost);
	}
	bool flag = 0;
	for (int i = 2; i <= n; i++)
	{
		dist[i] = INF;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < m; j++)
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
	if (flag)printf("-1\n");
	else
	{
		for (int i = 2; i <= n; i++)
		{
			if (dist[i] == INF)printf("-1\n");
			else printf("%d\n", dist[i]);
		}
	}
	return 0;
}