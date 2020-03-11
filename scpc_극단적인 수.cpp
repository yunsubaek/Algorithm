#include <stdio.h>
int temp[31] = { 1 };

int main()
{
	int tc;
	scanf("%d", &tc);
	for (int i = 1; i < 31; i++)
	{
		temp[i] = temp[i - 1] << 1;
	}
	for (int itr = 0; itr < tc; itr++)
	{
		int a;
		scanf("%d", &a);
		int len = 0;
		char arr[31] = { 0 };
		int z = -1;

		//길이
		for (int i = 1; i < 30; i++)
		{
			if (temp[i] - 1 <= a && a < temp[i + 1] - 1)
			{
				len = i;
				a %= temp[i];
				break;
			}
		}

		//계산
		for (int i = len - 1; i >= 0; i--)
		{
			if (temp[i] - 1 <= a && a < temp[i + 1] - 1)
			{
				arr[++z] = '7';
				a %= temp[i];
			}
			else arr[++z] = '4';
		}

		//출력
		printf("Case #%d\n", itr + 1);
		for (int i = 0; i <= z; i++)
		{
			printf("%c", arr[i]);
		}
		printf("\n");
	}
	return 0;
}