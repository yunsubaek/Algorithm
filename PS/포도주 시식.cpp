//https://www.acmicpc.net/problem/2156
#include "bits_stdc++.h"
#define SIZE 10002
using namespace std;
int n, arr[SIZE], dp[SIZE][2];

int search(int idx, int cnt)
{
	if (idx == n)return 0;
	int &ret = dp[idx][cnt];
	if (cnt == 2) ret = search(idx + 1, 0);
	if (ret != -1)return ret;
	ret = max(search(idx + 1, cnt + 1) + arr[idx], search(idx + 1, 0));
	return ret;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", search(0, 0));
	return 0;
}