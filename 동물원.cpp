//https://www.acmicpc.net/problem/1309
//µ¿¹°¿ø
#include<iostream>
#define SIZE 100002
using namespace std;
int dp[SIZE][2] = { {1,1} };

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= SIZE; i++)
	{
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][0] %= 9901;
		dp[i][1] = dp[i][0] + dp[i - 1][0];
		dp[i][1] %= 9901;
	}
	cout << (dp[n - 1][0] * 2 + dp[n - 1][1])%9901 << endl;
}