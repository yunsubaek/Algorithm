//https://www.acmicpc.net/problem/2643
//색종이 올려 놓기
#include "bits_stdc++.h"
#define SIZE 102
using namespace std;
int n;

struct paper
{
	int x, y, xy;
};

bool cmp(const paper &a, const paper &b)
{
	return a.xy < b.xy;
}

int main()
{
	cin >> n;
	paper p[SIZE] = { 0 };
	int dp[SIZE] = { 0 };
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &p[i].x, &p[i].y);
		p[i].xy = p[i].x*p[i].y;
		if (p[i].x > p[i].y)swap(p[i].x, p[i].y);
	}
	sort(p, p + n, cmp);
	for (int i = 0; i < n; i++)
	{
		dp[i] = 1;
	}
	for (int i = n-1; i >= 0; i--)
	{
		int cnt = 1;
		for (int j = n - 1; j > i; j--)
		{
			if (p[i].x <= p[j].x && p[i].y <= p[j].y)dp[i]=max(dp[i], dp[j] + 1);
		}
	}
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		if (dp[i] > max)max = dp[i];
	}
	printf("%d\n", max);
}