#include<iostream>
#define SIZE 502
using namespace std;
int n, m, cnt = 0, arr[SIZE][SIZE] = { 0 }, temp[SIZE][SIZE] = { 0 };
int idx[4] = { 0,0,1,-1 }, idy[4] = { 1,-1,0,0 };

int chk(int x, int y)
{
	if (x == 1 && y == 1) return 1;
	int& ret = temp[x][y];
	if (ret != 0)
		return ret;
	for (int i = 0; i < 4; i++)
	{
		if (x + idx[i] > 0 && y + idy[i] > 0 && x + idx[i] <= n && y + idy[i])
		{
			if (arr[x + idx[i]][y + idy[i]] > arr[x][y]) { 
				ret+=chk(x + idx[i], y + idy[i]); }
		}
	}
	return ret;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	cout << chk(n,m)<< endl;
}