//https://www.acmicpc.net/problem/2281
//데스노트
#include "bits_stdc++.h"
#define INF 1000000000
using namespace std;
int n, m, arr[1002], dp[1002][1002];

int chk(int idx, int space)
{
	if (idx == n)return 0;
	int &ret = dp[idx][space];
	if (ret != -1)return ret;
	ret = INF;
	if (space + arr[idx] <= m) ret = chk(idx + 1, space + arr[idx] + 1);
	ret = min(ret, (m - space + 1)*(m - space + 1) + chk(idx, 0));
	return ret;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", chk(0, 0));
	return 0;
}