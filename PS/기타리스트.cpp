//https://www.acmicpc.net/problem/1495
//기타리스트
#include "bits_stdc++.h"
#define INF 1000000000
using namespace std;
int n, s, m, arr[102], dp[102][1002];

int chk(int idx, int sound)
{
	if (sound > m || sound < 0)return -1;
	if (idx == n)return sound;
	int &ret = dp[idx][sound];
	if (ret != -2)return ret;
	ret = max(max(ret, chk(idx + 1, sound + arr[idx])), chk(idx + 1, sound - arr[idx]));
	return ret;
}

int main()
{
	cin >> n >> s >> m;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < 102; i++)
		for (int j = 0; j < 1002; j++)
			dp[i][j] = -2;
	printf("%d\n", chk(0, s));
	return 0;
}