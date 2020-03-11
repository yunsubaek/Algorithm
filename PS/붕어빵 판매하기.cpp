//https://www.acmicpc.net/problem/11052
//DP basic form
#include<iostream>
#define SIZE 1002
#define MAX(x,y) ((x)>(y)?(x):(y))
using namespace std;
int arr[SIZE], dp[SIZE][SIZE], n;

//i = �ε���, cnt = ���� ����
int chk(int i, int cnt)
{
	if (cnt == n)return 0;
	if (i >= n || cnt > n)return -987654321;
	if (dp[i][cnt] != 0)return dp[i][cnt];
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

	cout << chk(0, 0);
}