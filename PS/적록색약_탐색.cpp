#include "bits_stdc++.h"
#define SIZE 102
using namespace std;
int n, temp[SIZE][SIZE], temp_[SIZE][SIZE], idx[4] = { 0,0,1,-1 }, idy[4] = { 1,-1,0,0 };
char arr[SIZE][SIZE], arr_[SIZE][SIZE];
int count_ = 0, count__ = 0;

void chk(int x, int y,char a,int cnt)
{
	for (int i = 0; i < 4; i++)
	{
		int xx = x + idx[i], yy = y + idy[i];
		if (xx<0 || yy<0 || xx>n || yy>n)continue;
		if (arr[xx][yy] == a && temp[xx][yy] == 0) { temp[xx][yy] = cnt; chk(xx, yy, a, cnt); }
	}
}

void chk_(int x, int y, char a, int cnt)
{
	for (int i = 0; i < 4; i++)
	{
		int xx = x + idx[i], yy = y + idy[i];
		if (xx<0 || yy<0 || xx>n || yy>n)continue;
		if (arr_[xx][yy] == a && temp_[xx][yy] == 0) { temp_[xx][yy] = cnt; chk_(xx, yy, a, cnt); }
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr_[i][j] = arr[i][j];
			if (arr_[i][j] == 'G')arr_[i][j] = 'R';
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (temp[i][j] == 0) {
				temp[i][j] = ++count_;
				chk(i, j, arr[i][j], count_);
			}
			if (temp_[i][j] == 0) {
				temp_[i][j] = ++count__;
				chk_(i, j, arr_[i][j], count__);
			}
		}
	}
	printf("%d %d\n", count_, count__);
}