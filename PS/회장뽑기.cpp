//https://www.acmicpc.net/problem/2660
//회장뽑기(플로이드)
#include"bits_stdc++.h"
#define INF 1000000000
using namespace std;

int main()
{
	int n;
	cin >> n;
	int arr[52][52] = { 0 };
	memset(arr, 0x3f, sizeof(arr));
	while (1)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		if (a == b  && b == -1)break;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (i == k || k == j || i == j)continue;
				if (arr[i][k] + arr[k][j] < arr[i][j])
					arr[i][j] = arr[i][k] + arr[k][j];
			}
		}
	}
	int min = INF;
	int temp[52] = { 0 };
	for (int i = 1; i <= n; i++)
	{
		int cnt = 0;
		for (int j = 1; j <= n; j++)
		{
			if (cnt < arr[i][j] && arr[i][j] != 1061109567)cnt = arr[i][j];
		}
		temp[i] = cnt;
		if (cnt < min)min = cnt;
	}
	int tmp[52] = { 0 };
	int z = -1;
	for (int i = 1; i <= n; i++)
	{
		if (temp[i] == min)tmp[++z] = i;
	}
	printf("%d %d\n", min, z + 1);
	for (int i = 0; i <= z; i++)
	{
		printf("%d ", tmp[i]);
	}
	printf("\n");
}