#include "bits_stdc++.h"
#define SIZE 1001
#define BIG 1000000003
using namespace std;
int n, k, dp[SIZE][SIZE];

int main()
{
	cin >> n >> k;
	long long sum = 0;
	if (k == 1)printf("%d\n", n);
	else
	{
		for (int i = 1; i < SIZE; i++)
		{
			dp[1][i] = i;
		}
		for (int i = 2; i < SIZE; i++)
		{
			dp[i][1] = 1;
			for (int j = 2; j < SIZE; j++)
			{
				dp[i][j] = (dp[i - 1][j]) % BIG + (dp[i][j - 1]) % BIG;
				dp[i][j] %= BIG;
			}
		}
		for (int i = 1, j = 2 * k; j <= n; i++, j++)
		{
			sum += dp[k - 1][i];
			sum %= BIG;
			if (j == n)
			{
				sum += dp[k - 1][i];
				sum %= BIG;
			}
		}
		cout << sum%BIG << endl;
	}
	return 0;
}