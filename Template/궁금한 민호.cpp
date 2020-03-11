//https://www.acmicpc.net/problem/1507
//±√±›«— πŒ»£
#include "bits_stdc++.h"
#define SIZE 22
using namespace std;

int main()
{
	int arr[SIZE][SIZE] = { 0 };
	int chk[SIZE][SIZE] = { 0 };
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	int sum = 0;
	bool flag = 0;
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (i == k || k==j || i==j)continue;
				if (arr[i][k] + arr[k][j] == arr[i][j])
				{
					chk[i][j] = 1;
				}
				else if (arr[i][k] + arr[k][j] < arr[i][j])
					flag = 1;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (chk[i][j] == 0)sum += arr[i][j];
		}
	}
	sum /= 2;
	if(flag) cout << -1 << endl;
	else cout << sum << endl;
}