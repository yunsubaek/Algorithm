//DP basic form
#include<iostream>
#define SIZE 1002
#define MAX(x,y) ((x)>(y)?(x):(y))
using namespace std;
int arr[SIZE], dp[SIZE][SIZE], n;

//i = ÀÎµ¦½º, cnt = »ÌÀº °¹¼ö
int chk(int i, int cnt)
{
	if (cnt == n)return 0;
	if (i >= n || cnt > n)return -200000000;
	if (dp[i][cnt] != -1)return dp[i][cnt];
	dp[i][cnt] = MAX(chk(i, cnt + i + 1) + arr[i], chk(i + 1, cnt));
	return dp[i][cnt];
}

int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			dp[i][j] = -1;
		}
	}

	cout << chk(0, 0);
}