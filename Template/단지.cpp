#include<iostream>
#define SIZE 27
using namespace std;
int cnt = 1, n, sum = 0, temp[100] = { 0 };
bool flag = 0;
//탐색
void chk(int(*arr)[SIZE], int x, int y)
{
	if (x<1 || y<1 || x>n || y>n) return;
	if (arr[x][y] == -1) { arr[x][y] = cnt; sum++; flag = 1; }
	if (arr[x - 1][y] == -1) { arr[x - 1][y] = cnt; sum++; flag = 1; chk(arr, x - 1, y); }
	if (arr[x][y - 1] == -1) { arr[x][y - 1] = cnt; sum++; flag = 1; chk(arr, x, y - 1); }
	if (arr[x + 1][y] == -1) { arr[x + 1][y] = cnt; sum++; flag = 1; chk(arr, x + 1, y); }
	if (arr[x][y + 1] == -1) { arr[x][y + 1] = cnt; sum++; flag = 1; chk(arr, x, y + 1); }
}

int main()
{
	char tp[SIZE][SIZE] = { 0 };
	int arr[SIZE][SIZE] = { 0 };
	cin >> n;
	//입력
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> tp[i][j];
			if (tp[i][j] == '1') arr[i][j] = -1;
			else arr[i][j] = 0;
		}
	}
	//탐색
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			flag = 0;
			sum = 0;
			if (arr[i][j] == -1)chk(arr, i, j);
			if (flag == 1) { temp[cnt++] = sum; }
		}
	}
	//정렬
	for (int i = 1; i <= cnt - 1; i++)
	{
		for (int j = 1; j <= cnt - i - 1; j++)
		{
			int tmp;
			if (temp[j] > temp[j + 1])
			{
				tmp = temp[j];
				temp[j] = temp[j + 1];
				temp[j + 1] = tmp;
			}
		}
	}
	//출력
	cout << cnt - 1 << endl;
	for (int i = 1; i < cnt; i++)
		cout << temp[i] << endl;
}