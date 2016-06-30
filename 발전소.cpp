//https://www.acmicpc.net/problem/1102
//¹ßÀü¼Ò
#include "bits_stdc++.h"
#define SIZE 17
#define INF 1000000000
using namespace std;
int n, least, cost[SIZE][SIZE], dp[1 << 16];

int chk(int now)
{
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (now&(1 << i))cnt++;
	}
	if (cnt >= least)return 0;
	int &ret = dp[now];
	if (ret != -1)return ret;
	ret = INF;
	for (int i = 0; i < n; i++)
	{
		if (now&(1 << i))continue;
		int Min = INF;
		for (int j = 0; j < n; j++)
		{
			if (i != j && now&(1 << j))
				Min = min(cost[j][i], Min);
		}
		ret = min(ret, chk(now | (1 << i)) + Min);
	}
	return ret;
}

int main()
{
	int now = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &cost[i][j]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		char a;
		cin >> a;
		if (a == 'Y')now |= (1 << i);
	}
	scanf("%d", &least);
	memset(dp, -1, sizeof(dp));
	int result = chk(now);
	printf("%d\n", result >= INF ? -1 : result);
	return 0;
}