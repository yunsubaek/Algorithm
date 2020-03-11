#include "bits_stdc++.h"
#define SIZE 52
using namespace std;

struct now {
	int x, y, cnt;
};

int n, idx[4] = { 0,0,1,-1 }, idy[4] = { 1,-1,0,0 }, temp[SIZE][SIZE];
char arr[SIZE][SIZE];
queue<now> q;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%s", &arr[i]);
	q.push({ 0,0,0 });
	memset(temp, 0x3f, sizeof temp);
	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		int cnt = q.front().cnt;
		q.pop();
		if (cnt < temp[x][y])
		{
			temp[x][y] = cnt;
			for (int i = 0; i < 4; i++)
			{
				int xx = x + idx[i], yy = y + idy[i];
				if (xx >= 0 && yy >= 0 && xx < n && yy < n)
				{
					if (arr[xx][yy] == '1')
						q.push({ xx,yy,cnt });
					else
						q.push({ xx,yy,cnt + 1 });
				}
			}
		}
	}
	printf("%d\n", temp[n - 1][n - 1]);
	return 0;
}