#include "bits_stdc++.h"
#define SIZE 1000002
using namespace std;
int start[SIZE], finish[SIZE], n, mmax = 0;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &start[i], &finish[i]);
		if (finish[i] > mmax)mmax = finish[i];
	}
	sort(start, start + n);
	sort(finish, finish + n);
	int max = 0, cnt = 0;
	int now_f = 0;

	for (int i = 0; i < n; i++)
	{
		cnt++;
		if (start[i] >= finish[now_f])
		{
			now_f++;
			cnt--;
		}
		if (max < cnt)max = cnt;
	}
	printf("%d\n", max);
	return 0;
}