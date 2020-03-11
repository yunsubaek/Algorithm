//https://www.acmicpc.net/problem/9465
#include<iostream>
#define SIZE 100002
#define INF 2000000000
#define MAX(x,y) ((x)>(y)?(x):(y))
using namespace std;
int arr[2][SIZE], dp[3][SIZE], n;
//i=(0:¾È¶â,1:À§¿¡¶â,2:¾Æ·¡¶â),cnt=¶â´Â°÷ ÀÎµ¦½º
int recur(int i, int cnt)
{
	if (cnt == n)return 0;
	if (cnt > n)return -INF;
	if (dp[i][cnt] != -1)return dp[i][cnt];
	if (i == 0)
	{
		dp[i][cnt] = MAX(MAX(recur(1, cnt + 1) + arr[0][cnt], recur(2, cnt + 1) + arr[1][cnt]), dp[i][cnt]);
	}
	if (i == 1)
	{
		dp[i][cnt] = MAX(MAX(recur(0, cnt + 1), recur(2, cnt + 1) + arr[1][cnt]), dp[i][cnt]);
	}
	if (i == 2)
	{
		dp[i][cnt] = MAX(MAX(recur(0, cnt + 1), recur(1, cnt + 1) + arr[0][cnt]), dp[i][cnt]);
	}
	return dp[i][cnt];
}

int main()
{
	int tc;
	cin >> tc;
	for (int itr = 0; itr < tc; itr++)
	{
		scanf("%d", &n);
		//input
		for (int j = 0; j < 2; j++)
		{
			for (int i = 0; i < n; i++)
			{
				scanf("%d", &arr[j][i]);
			}
		}
		//initialize
		for (int j = 0; j < 3; j++)
		{
			for (int i = 0; i < n; i++)
			{
				dp[j][i] = -1;
			}
		}
		cout << recur(0, 0) << endl;
	}
}