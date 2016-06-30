//https://www.acmicpc.net/problem/1613
//역사(플로이드)
#include "bits_stdc++.h"
#define SIZE 402
using namespace std;

int main()
{
	int n, m;
	bool arr[SIZE][SIZE] = { 0 };
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int from, to;
		scanf("%d %d", &from, &to);
		arr[from][to] = 1;
	}
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (i == j || j == k || i == k)continue;
				if (arr[i][k] && arr[k][j]) arr[i][j] = 1;
			}
		}
	}
	int loop;
	cin >> loop;
	for (int i = 0; i < loop; i++)
	{
		int from, to;
		scanf("%d %d", &from, &to);
		if (!arr[from][to] && !arr[to][from])printf("0\n");
		else if (arr[from][to])printf("-1\n");
		else printf("1\n");
	}
	return 0;
}