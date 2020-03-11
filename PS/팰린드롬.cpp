#include<iostream>
#define SIZE 2002
using namespace std;
bool dp[SIZE][SIZE] = { 0 };

int abs_(int a)
{
	return a > 0 ? a : -a;
}

int main()
{
	int n, m, arr[SIZE] = { 0 };
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &arr[i]);
	}
	cin >> m;
	{
		int a, b;
		scanf("%d %d", &a, &b);
		//
		if (abs_(b - a) == 1 && arr[a] != arr[b])
		{
			printf("0\n");
			continue;
		}
		else if (abs_(b - a) == 1 && arr[a] == arr[b])
		{
			printf("1\n");
			dp[a][b] = 1;
			continue;
		}
		bool flag = 0;
		//팰린드롬이 아닐경우 팰린드롬 확인. 팰린드롬은 이효리 거꾸로도 이효리 ㅇㅇ
		if (dp[a][b] != 1)
		{
			for (int i = a, j = b; i <= (a + b) / 2; i++, j--)
			{
				if (arr[i] != arr[j])
				{
					flag = 1;
					break;
				}
			}
			if (flag == 0)
			{
				dp[a][b] = 1;
				for (int i = a, j = b; i <= (a + b) / 2; i++, j--)
				{
					dp[i][j] = 1;
				}
				printf("1\n");
			}
			else
				printf("0\n");
		}
		else printf("1\n");
	}
	return 0;
}