//https://www.acmicpc.net/problem/1107
//¸®¸ğÄÁ
#include "bits_stdc++.h"
using namespace std;
bool use[10];

int search(int num)
{
	if (num == 0)
	{
		if (use[0])
			return 0;
		else
			return 1;
	}

	int len = 0;

	while (true)
	{
		if (use[num % 10])
			return 0;
		len++;
		num = num / 10;

		if (num == 0)
			break;
	}

	return len;
}

int main()
{
	int n;
	int num, x;
	int result = 0;

	scanf("%d", &n);
	scanf("%d", &num);

	for (int i = 0; i < num; i++)
	{
		scanf("%d", &x);
		use[x] = true;
	}

	result = abs(n - 100);

	for (int i = 0; i < 1000000; i++)
	{
		int can = search(i);
		if (can > 0)
		{
			int press = can + abs(n - i);

			if (result > press)
				result = press;
		}
	}
	printf("%d\n", result);
	return 0;
}