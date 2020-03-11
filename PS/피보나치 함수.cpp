//https://www.acmicpc.net/problem/1003
//피보나치 함수
#include<iostream>
#define SIZE 42
using namespace std;
int dp[SIZE] = { 0,1 };

int main()
{
	int tc = 1, a;
	cin >> tc;
	for (int i = 2; i < SIZE; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	for (int i = 0; i< tc; i++)
	{
		scanf("%d", &a);
		if (a == 0)printf("1 0\n");
		else printf("%d %d\n", dp[a - 1], dp[a]);
	}
	return 0;
}