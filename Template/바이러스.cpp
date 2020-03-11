//https://www.acmicpc.net/problem/2606
//바이러스
#include"bits_stdc++.h"
#define SIZE 1002
using namespace std;

int arr[SIZE][SIZE] = { 0 };
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int from, to;
		scanf("%d %d", &from, &to);
		arr[from][to] = 1;
		arr[to][from] = 1;
	}
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (i == j || j == k || i == k)continue;
				if (!arr[i][k] || !arr[k][j])continue;
				if (arr[i][k] && arr[k][j])
					arr[i][j] = 1;
			}
		}
	}
	int result = 0;
	for (int i = 1; i <= n; i++)
	{
		if (arr[1][i] == 1)result++;
	}
	printf("%d\n", result);
	return 0;
}