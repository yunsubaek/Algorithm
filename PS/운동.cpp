//https://www.acmicpc.net/problem/1956
//¿îµ¿
#include<iostream>
#define INF 1000000000
#define SIZE 402
using namespace std;

int main()
{
	int n, m, arr[SIZE][SIZE] = { 0 }, min = INF;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			arr[i][j] = INF;
		}
	}

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		arr[a][b] = c;
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (arr[i][j] > arr[i][k] + arr[k][j])
					arr[i][j] = arr[i][k] + arr[k][j];
			}
		}
	}
	min = INF + 1;

	for (int i = 1; i <= n; i++)
		if (arr[i][i] < min)min = arr[i][i];
	if (min == INF)cout << -1 << endl;
	else cout << min << endl;
}