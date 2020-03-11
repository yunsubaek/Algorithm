//https://www.acmicpc.net/problem/9009
//�Ǻ���ġ(�Ǻ���ġ�� ���� ���� �ش� ���ڸ� ���� �� �ִ� ������ ���)
#include<iostream>
#define SIZE 45
using namespace std;
int fibo[SIZE] = { 0,1 };

int main()
{
	//�Ǻ���ġ ����
	for (int i = 2; i <= SIZE; i++)
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	int tc;
	cin >> tc;
	//�׽�Ʈ���̽�
	for (int itr = 0; itr < tc; itr++)
	{
		int n;
		scanf("%d", &n);
		int x;
		for (int i = 1;; i++)
		{
			if (fibo[i] > n)
			{
				x = i - 1;
				break;
			}
		}

		int result[SIZE] = { 0 }, m = -1;
		for (int i = x; i>0; i--)
		{
			if (n - fibo[i] >= 0)
			{
				n -= fibo[i];
				result[++m] = fibo[i];
			}
			if (n == 0)break;
		}
		for (int i = m; i >= 0; i--)
			printf("%d ", result[i]);
		printf("\n");
	}
	return 0;
}