//https://www.acmicpc.net/problem/2167
//2차원 배열의 합
#include<iostream>
#define SIZE 302
using namespace std;

int main()
{
	int arr[SIZE][SIZE];
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	int k;
	cin >> k;
	for (int z = 0; z < k; z++)
	{
		int i, j, x, y;
		long long sum = 0;
		scanf("%d %d %d %d", &i, &j, &x, &y);
		for (int a = i-1; a < x; a++)
		{
			for (int b = j-1; b < y; b++)
			{
				sum += arr[a][b];
			}
		}
		cout << sum << endl;
	}
}