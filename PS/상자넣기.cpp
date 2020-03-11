//https://www.acmicpc.net/problem/1965
//상자넣기
#include<iostream>
#include<algorithm>
#define SIZE 1002
using namespace std;
int arr[SIZE], dp[SIZE], n;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
		dp[i] = 1;
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = i; j >= 0; j--)
		{
			if (arr[i] > arr[j])dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	int max = -1;
	for (int i = 0; i < SIZE; i++)
	{
		if (dp[i] > max)max = dp[i];
	}
	cout << max << endl;
}