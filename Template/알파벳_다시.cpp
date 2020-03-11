#include<iostream>
#define SIZE 26
using namespace std;
int idx[4] = { 0,0,1,-1 };
int idy[4] = { 1,-1,0,0 };
int n, m;

void chk(char(*arr)[SIZE], bool alpha_chk[], int x, int y, int cnt)
{
	for (int i = 0; i < 4; i++)
	{
		if (x + idx[i] > 1 && x + idx[i] <= n && y + idy[i] > 1 && y + idy[i] <= m)
			if (alpha_chk[arr[x + idx[i]][y + idy[i]]] != 1)
			{
				alpha_chk[arr[x + idx[i]][y + idy[i]]] = 1;
				chk(arr, alpha_chk, x, y, cnt + 1);
				alpha_chk[arr[x + idx[i]][y + idy[i]]] = 0;
			}
	}
}

int main()
{
	char arr[SIZE][SIZE] = { 0 };
	//A~Z
	bool alpha_chk[SIZE] = { 0 };
	cin >> n >> m;
	//Input
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> arr[i][j];
		}
	}
	alpha_chk[arr[1][1]-'A'] = 1;
	//Àç±Í
	chk(arr, alpha_chk, 1, 1, 0);
}