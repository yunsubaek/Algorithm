//Jennifer Soft - B(컴파일러에 따라 iostream만 쓰면 scanf,printf가 되지 않는 경우가 있어서 cstdio를 추가해서 2차 제출)
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