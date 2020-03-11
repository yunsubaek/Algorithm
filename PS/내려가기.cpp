//https://www.acmicpc.net/problem/2096
//내려가기
#include<iostream>
#include<algorithm>
#define SIZE 100002
using namespace std;
int dp[3][2];

int main()
{
	int n, a, b, c, d, e, f;
	cin >> n;
	scanf("%d %d %d", &a, &b, &c);
	d = a, e = b, f = c;
	dp[0][0] = a, dp[1][0] = b, dp[2][0] = c;
	dp[0][1] = d, dp[1][1] = e, dp[2][1] = f;
	for (int i = 1; i < n; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		d = a, e = b, f = c;
		//max
		a += max(dp[0][0], dp[1][0]);
		b += max(max(dp[0][0], dp[1][0]), dp[2][0]);
		c += max(dp[1][0], dp[2][0]);
		//save_max
		dp[0][0] = a;
		dp[1][0] = b;
		dp[2][0] = c;
		//min
		d += min(dp[0][1], dp[1][1]);
		e += min(min(dp[0][1], dp[1][1]), dp[2][1]);
		f += min(dp[1][1], dp[2][1]);
		//save_min
		dp[0][1] = d;
		dp[1][1] = e;
		dp[2][1] = f;
	}
	cout << max(max(dp[0][0], dp[1][0]), dp[2][0]) << ' ' << min(min(dp[0][1], dp[1][1]), dp[2][1]) << endl;
}