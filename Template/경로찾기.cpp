//https://www.acmicpc.net/problem/11403
//���ã��(�÷��̵�)
#include<iostream>
#define SIZE 102
#define min_(a,b) (a>b?b:a)
using namespace std;
int arr[SIZE][SIZE] = { 0 };

int main()
{
	int n;
	cin >> n;
	//��� �Է�
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	//��� üũ
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (arr[i][k] == 0)continue;
				if (arr[i][k] && arr[k][j])
					arr[i][j] = 1;
			}
		}
	}
	//���
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}