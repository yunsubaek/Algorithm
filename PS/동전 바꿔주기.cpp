//https://www.acmicpc.net/problem/2624
//µ¿Àü ¹Ù²ãÁÖ±â
#include "bits_stdc++.h"
using namespace std;
int t, k, arr[102][2], dp[102][10002];
//ÀÎµ¦½º, °¹¼ö

int chk(int idx, int sum)
{
	if (sum == t)return 1;
	if (idx == k)return 0;
	int &ret = dp[idx][sum];
	if (ret != -1)return ret; ret = 0;
	for (int i = 0; i <= arr[idx][1];i++)
	{
		if (sum + arr[idx][0] * i <= t)ret += chk(idx + 1, sum + arr[idx][0] * i);
	}
	return ret;
}

int main()
{
	cin >> t >> k;
	for (int i = 0; i < k; i++)
	{
		scanf("%d %d", &arr[i][0], &arr[i][1]);
	}
	memset(dp, -1, sizeof(dp));
	cout << chk(0, 0) << endl;
}