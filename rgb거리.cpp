//https://www.acmicpc.net/problem/1149
//rgb°Å¸®
#include<iostream>
#define SIZE 1002
#define MIN(x,y) ((x)>(y)?(y):(x))
using namespace std;
int dp[SIZE][3];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			scanf("%d", &dp[i][j]);
		}
	}

	for (int i = 1; i < n; i++)
	{
		dp[i][0] = MIN(dp[i - 1][1], dp[i - 1][2]) + dp[i][0];
		dp[i][1] = MIN(dp[i - 1][0], dp[i - 1][2]) + dp[i][1];
		dp[i][2] = MIN(dp[i - 1][0], dp[i - 1][1]) + dp[i][2];
	}
	cout << MIN(MIN(dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]) << endl;
}