//https://www.acmicpc.net/problem/1126
//°°ÀºÅ¾
#include "bits_stdc++.h"
#define INF 1000000000
#define SIZE 52
using namespace std;
int n, arr[SIZE], dp[SIZE][250001], sum = 0;

int chk(int idx, int far)
{
	if (idx == n)
	{
		if (far == 0) return 0;
		return -INF;
	}
	if (abs(far) > sum / 2)return -INF;
	int &ret = dp[idx][abs(far)];
	if (ret != -1)return ret;
	ret = chk(idx + 1, far);
	ret = max(ret, chk(idx + 1, far + arr[idx]) + arr[idx]);
	ret = max(ret, chk(idx + 1, far - arr[idx]) + arr[idx]);
	return ret;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]), sum += arr[i];
	memset(dp, -1, sizeof dp);
	int result = -INF;
	result = max(result,chk(0, 0));
	printf("%d\n", result > 0 ? result / 2 : -1);
	return 0;
}