//https://www.acmicpc.net/problem/10159
//Àú¿ï
#include"bits_stdc++.h"
#define SIZE 102
using namespace std;

int main()
{
	int n, m;
	bool arr[SIZE][SIZE] = { 0 };
	cin >> n >> m;
	bool temp[SIZE][SIZE] = { 0 };
	for (int i = 0; i < m; i++)
	{
		int from, to;
		scanf("%d %d", &from, &to);
		arr[from][to] = 1;
		temp[from][to] = 1;
		temp[to][from] = 1;
	}
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				temp[k][k] = 1;
				if (i == j || j == k || k == i)continue;
				if (arr[i][k] && arr[k][j])
				{
					arr[i][j] = 1;
					temp[i][j] = 1;
					temp[j][i] = 1;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		int cnt = 0;
		for (int j = 1; j <= n; j++)
		{
			if (!temp[i][j])cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}