//https://www.acmicpc.net/problem/11057
#include<iostream>
#include<string.h>
#define SIZE 1002
using namespace std;
int num, dp[SIZE][SIZE] = { 0 };

int chk(int n, int m)
{
	if (dp[n][m] != -1)return dp[n][m];
	if (m < 0 || m > 9)return 0;
	if (n == 1)return 1;
	int ret = 0;
	for (int i = 0; i <= 9; i++)
	{
		if (m + i < 10)
			ret += chk(n - 1, m + i) % 10007;
	}
	dp[n][m] = ret;
	return ret % 10007;
}

int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d", &num);
	int result = 0;
	for (int i = 0; i <= 9; i++)
	{
		result += (chk(num, i) % 10007) % 10007;
		result %= 10007;
	}
	printf("%d", result);
}