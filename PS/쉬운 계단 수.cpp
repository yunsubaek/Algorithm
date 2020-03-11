//https://www.acmicpc.net/problem/10844
#include<iostream>
using namespace std;
int num, dp[102][12];

int chk(int n, int m) // n=자릿수, m=선택하는 숫자
{
	if (dp[n][m] != 0) return dp[n][m];
	if (m < 0 || m>9) return 0;
	if (n == 1) return 1;
	int ret = 0;
	ret = chk(n - 1, m - 1) % 1000000000 + chk(n - 1, m + 1) % 1000000000;
	dp[n][m] = ret;
	return ret;
}

int main(void)
{
	scanf("%d", &num);
	int result = 0;
	for (int i = 1; i <= 9; i++)
	{
		result = result + chk(num, i) % 1000000000;
		result %= 1000000000;
	}
	printf("%d\n", result);
	return 0;
}