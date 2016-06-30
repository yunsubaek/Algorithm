//https://www.acmicpc.net/problem/11404
//플로이드
#include<iostream>
#define SIZE 102
#define min_(a,b) (a>b?b:a)
using namespace std;
int arr[SIZE][SIZE] = { 0 };

int main()
{
	int n, m;
	cin >> n >> m;
	//경로 입력
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (arr[a][b] == 0)
			arr[a][b] = c;
		else
			arr[a][b] = min_(arr[a][b], c);
	}
	//경로 체크
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (i == j)continue;
				if (arr[i][k] == 0)continue;
				if (arr[i][k] && arr[k][j])
				{
					if (arr[i][j] == 0)
						arr[i][j] = arr[i][k] + arr[k][j];
					else arr[i][j] = min_(arr[i][j], arr[i][k] + arr[k][j]);
				}
			}
		}
	}
	//출력
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}