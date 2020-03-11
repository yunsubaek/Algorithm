////https://www.acmicpc.net/submit/2666/2689466
////벽장문의 이동(베낌..)
#include"bits_stdc++.h"
#define SIZE 20
using namespace std;
int n, a, b, m, arr[SIZE], dp[SIZE][SIZE][SIZE];

int chk(int idx, int left, int right)
{
	if (idx == m)return 0;
	int &ret = dp[idx][left][right];
	if (ret != 1061109567)return ret;
	ret = min(chk(idx + 1, arr[idx], right) + abs(arr[idx] - left),chk(idx + 1, left, arr[idx]) + abs(right - arr[idx]));
	return ret;
}

int main()
{
	scanf("%d %d %d %d", &n, &a, &b, &m);
	memset(dp, 0x3f, sizeof(dp));
	for (int i = 0; i < m; i++)
		scanf("%d", &arr[i]);
	printf("%d\n", chk(0, a, b));
}