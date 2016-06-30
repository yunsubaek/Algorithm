////https://www.acmicpc.net/problem/1463
////for¹®
//#include<iostream>
//#define INF 2000000000
//#define MIN(x,y) ((x)>(y)?(y):(x))
//using namespace std;
//int min_ = INF, n;
//int dp[1000002] = { 0, 0, 1, 1, 2 };
//void chk(int i)
//{
//	if (i > n)return;
//	int x = dp[i - 1] + 1, y, z;
//	i % 2 == 0 ? y = dp[i / 2] + 1 : y = INF;
//	i % 3 == 0 ? z = dp[i / 3] + 1 : z = INF;
//	dp[i] = MIN(MIN(x, y), z);
//	chk(i + 1);
//}
//
//int main()
//{
//	scanf("%d", &n);
//	chk(4);
//	printf("%d", dp[n]);
//}
////Àç±Í
//#include "bits_stdc++.h"
//#define INF 1000000000
//using namespace std;
//int dp[1000001], n;
//
//int chk(int idx) {
//	if (idx == 1)return 0;
//	if (idx<0)return INF;
//	int &ret = dp[idx];
//	if (ret != 1061109567)return ret;
//	int a = INF, b = INF, c = INF;
//	if (idx % 3 == 0)a = chk(idx / 3) + 1;
//	if (idx % 2 == 0)b = chk(idx / 2) + 1;
//	if (idx - 1 >= 1)c = chk(idx - 1) + 1;
//	ret = min(c, min(a, b));
//	return ret;
//}
//
//int main() {
//	cin >> n;
//	memset(dp, 0x3f, sizeof(dp));
//	printf("%d\n", chk(n));
//}