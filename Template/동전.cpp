//디피.. 이해가 안됨.
#include<iostream>
using namespace std;
int dp[10001], n, k;
int main() 
{
	dp[0] = 1;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);
		for (int j = a; j <= k; j++) dp[j] += dp[j - a];
	}
	printf("%d\n", dp[k]);
	return 0;
}