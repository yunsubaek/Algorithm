//https://www.acmicpc.net/problem/1389
//케빈 베이컨의 6단계 법칙
#include<iostream>
#define SIZE 102
using namespace std;
int arr[SIZE][SIZE];

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		arr[a][b] = 1;
		arr[b][a] = 1;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (arr[i][j] != 1)arr[i][j] = SIZE;
		}
	}
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (arr[i][j]>arr[i][k]+arr[k][j])
				{
					arr[i][j] = arr[i][k] + arr[k][j];
				}
			}
		}
	}
	int sum[SIZE] = { 0 }, min = 2000000000, min_idx;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i != j)sum[i] += arr[i][j];
		}
		if (sum[i] < min)
		{
			min = sum[i];
			min_idx = i;
		}
	}
	cout << min_idx << endl;
}