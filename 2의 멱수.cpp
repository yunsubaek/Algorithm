#include<iostream>
#include<string.h>
#define SIZE 21
using namespace std;
int temp[SIZE], n, sum = 0, dp[SIZE][1000002];
#define mod 1000000000
int chk(int i, int sum)
{
	if (sum > n || temp[i] > n)return 0;
	if (sum == n)
	{
		return 1;
	}
	if (i == 20)
		return 0;
	int &ret = dp[i][sum];
	if (ret != -1)
		return ret;
	ret = 0;
	ret = (ret + chk(i, sum + temp[i])) % mod;
	ret = (ret + chk(i + 1, sum)) % mod;

	return ret % mod;
}

int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	temp[0] = 1;
	for (int i = 1; i < SIZE; i++)
	{
		temp[i] = temp[i - 1] << 1;
	}
	printf("%d\n", chk(0, 0));
}