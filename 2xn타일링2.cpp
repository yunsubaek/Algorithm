//https://www.acmicpc.net/problem/11727
#include<iostream>
#define SIZE 1002
using namespace std;
int dp[SIZE] = { 1,1,3,5 };

int main()
{
	int n;
	cin >> n;
	for (int i = 4; i <= n; i++)
	{
		dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % 10007;
	}
	cout << dp[n];
}