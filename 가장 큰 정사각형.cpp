#include<iostream>
#define SIZE 1002
using namespace std;
int n, m, temp[SIZE][SIZE] = { 0 };
char arr[SIZE][SIZE] = { 0 };
//int cnt_x, cnt_y;
void chk(int x, int y)
{
	while(arr[x][y] == '1' && x>0)
	{
		x--;
	}
	while (arr[x][y] == '1' && y > 0)
	{
		y--;
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			//cnt_x = 0, cnt_y = 0;
			if (arr[i][j] == '1')
			{
				chk(i, j);
			}
		}
	}
	return 0;
}