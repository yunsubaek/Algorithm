//Jennifer Soft - B(�����Ϸ��� ���� iostream�� ���� scanf,printf�� ���� �ʴ� ��찡 �־ cstdio�� �߰��ؼ� 2�� ����)
#include <iostream>
#include <cstdio>
#define SIZE 1002
using namespace std;
int n, result;
char arr[SIZE][SIZE];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%s", &arr[i]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (j + 1 < n && arr[i][j] == '.' && arr[i][j + 1] == '.')
				result++;
	printf("%d\n", result);
	return 0;
}