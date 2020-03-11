////https://www.acmicpc.net/problem/1563
////개근상(백준풀이 참고했음..ㅇㅈ)
//#include"bits_stdc++.h"
//#define MOD 1000000
//using namespace std;
//int n, dp[1002][2][3] = { 1 };
//
//int main() {
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 0; j < 2; j++)
//		{
//			for (int k = 0; k < 3; k++)
//			{
//				dp[i][j][0] += dp[i - 1][j][k];
//				dp[i][j][0] %= MOD;
//				if (j == 0)
//				{
//					dp[i][1][0] += dp[i - 1][j][k];
//					dp[i][1][0] %= MOD;
//				}
//				if (k < 2)
//				{
//					dp[i][j][k + 1] += dp[i - 1][j][k];
//					dp[i][j][k + 1] %= MOD;
//				}
//			}
//		}
//	}
//	int result = 0;
//	for (int i = 0; i < 2; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			result += dp[n][i][j];
//			result %= MOD;
//		}
//	}
//	printf("%d\n", result);
//}

//박트리 풀이
//#include "bits_stdc++.h"
//using namespace std;
//const int mod = 1000000;
//int N;
//int cache[1000][2][3];
//int search(int idx, int late, int unab) {
//	if (late == 2)
//		return 0;
//	if (unab == 3)
//		return 0;
//	if (idx == N)
//		return 1;
//	int &ret = cache[idx][late][unab];
//	if (ret != -1)
//		return ret;
//	ret = search(idx + 1, late, 0);
//	ret = (ret + search(idx + 1, late + 1, 0)) % mod;
//	ret = (ret + search(idx + 1, late, unab + 1)) % mod;
//	return ret;
//}
//int main() {
//	memset(cache, -1, sizeof(cache));
//	cin >> N;
//	printf("%d\n", search(0, 0, 0));
//	return 0;
//}