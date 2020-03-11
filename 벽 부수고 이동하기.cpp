//https://www.acmicpc.net/problem/2206
//벽 부수고 이동하기
#include "bits_stdc++.h"
#define SIZE 1002
using namespace std;
int n, m, temp[SIZE][SIZE];
char arr[SIZE][SIZE];
int idx[4] = { 0,0,1,-1 }, idy[4] = { 1,-1,0,0 };

struct now
{
	int x, y, cnt;
};

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", &arr[i]);
	queue<now> sq, eq;
	temp[0][0] = -1;
	sq.push({ 0,0,-2 });
	int xxxx = 1000000000;
	int cnt = -1;
	bool flag = 0;
	while (!sq.empty())
	{
		int x = sq.front().x;
		int y = sq.front().y;
		if (x == n - 1 && y == m - 1)
		{
			xxxx = -cnt;
			flag = 1;
		}
		cnt = sq.front().cnt;
		sq.pop();
		for (int i = 0; i < 4; i++)
		{
			int xx = x + idx[i], yy = y + idy[i];
			if (xx<0 || xx>n || yy<0 || yy>m)continue;
			if (arr[xx][yy] == '0' && temp[xx][yy] == 0)
			{
				temp[xx][yy] = cnt;
				sq.push({ xx,yy,cnt - 1 });
			}
		}
	}

	temp[n - 1][m - 1] = 1;
	eq.push({ n - 1,m - 1,2 });
	while (!eq.empty())
	{
		int x = eq.front().x;
		int y = eq.front().y;
		int cnt = eq.front().cnt;
		eq.pop();
		for (int i = 0; i < 4; i++)
		{
			int xx = x + idx[i], yy = y + idy[i];
			if (xx<0 || xx>n || yy<0 || yy>m)continue;
			if (arr[xx][yy] == '0' && temp[xx][yy] == 0)
			{
				temp[xx][yy] = cnt;
				eq.push({ xx,yy,cnt + 1 });
			}
		}
	}
	int min = xxxx;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (temp[i][j] == 0)
			{
				//곱이 0보다 작을때 
				if (temp[i][j - 1] * temp[i + 1][j] < 0)if (min > abs(temp[i][j - 1]) + abs(temp[i + 1][j]))min = abs(temp[i][j - 1]) + abs(temp[i + 1][j]), flag = 1;
				if (temp[i + 1][j] * temp[i][j + 1] < 0)if (min > abs(temp[i + 1][j]) + abs(temp[i][j + 1]))min = abs(temp[i + 1][j]) + abs(temp[i][j + 1]), flag = 1;
				if (temp[i - 1][j] * temp[i][j + 1] < 0)if (min > abs(temp[i - 1][j]) + abs(temp[i][j + 1]))min = abs(temp[i - 1][j]) + abs(temp[i][j + 1]), flag = 1;
				if (temp[i][j - 1] * temp[i - 1][j] < 0)if (min > abs(temp[i][j - 1]) + abs(temp[i - 1][j]))min = abs(temp[i][j - 1]) + abs(temp[i - 1][j]), flag = 1;
				if (temp[i][j - 1] * temp[i][j + 1] < 0)if (min > abs(temp[i][j - 1]) + abs(temp[i][j + 1]))min = abs(temp[i][j - 1]) + abs(temp[i][j + 1]), flag = 1;
				if (temp[i - 1][j] * temp[i + 1][j] < 0)if (min > abs(temp[i - 1][j]) + abs(temp[i + 1][j]))min = abs(temp[i - 1][j]) + abs(temp[i + 1][j]), flag = 1;
			}
		}
	}
	if (!flag)printf("-1\n");
	else
	{
		if (min == xxxx)printf("%d\n", min);
		else printf("%d\n", min + 1);
	}
	return 0;
}