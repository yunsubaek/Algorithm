#include "bits_stdc++.h"
#define MOD 1000000
using namespace std;
int dp[5002] = { 1 };
int main()
{
	string s;
	cin >> s;
	s = " " + s;
	int len = s.length();
	for (int i = 1; i <= len; i++)
	{
		int x = s[i] - '0';
		if (x >= 1 && x <= 9) {
			dp[i] += dp[i - 1];
			dp[i] %= MOD;
		}
		if (i == 1)continue;
		if (s[i - 1] == '0')continue;
		//0 이어질수있는놈, 1 안이어지는놈
		x = 10 * (s[i - 1] - '0') + (s[i] - '0');
		if (10 <= x && x <= 26) {
			dp[i] += dp[i - 2];
			dp[i] %= MOD;
		}
	}
	printf("%d\n", dp[len-1]);
}