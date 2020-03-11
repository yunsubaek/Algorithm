//https://www.acmicpc.net/problem/1932
//숫자삼각형
#include<iostream>
#define SIZE 502
#define MAX(x,y) ((x)>(y)?(x):(y))
using namespace std;
int arr[SIZE][SIZE], max = 0;

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			scanf("%d", &arr[i][j]);
			if (j == 1)arr[i][j] += arr[i - 1][1];
			else if (j == i)arr[i][j] += arr[i - 1][j - 1];
			else arr[i][j] += MAX(arr[i - 1][j - 1], arr[i - 1][j]);
			if (i == n && max < arr[i][j])max = arr[i][j];
		}
	}
	cout << max << endl;
}