//https://www.acmicpc.net/problem/2618
//°æÂûÂ÷
#include "bits_stdc++.h"
int sec[1002][2];
int position[1001][1001];
int D[1002][1002];

int sol(int p1, int p2, int now, int end)
{
	if (now > end) return 0;

	int &ret = D[p1][p2];
	if (ret != -1)
		return ret;

	int fp1 = sol(now, p2, now + 1, end) + abs(sec[now][0] - sec[p1][0]) + abs(sec[now][1] - sec[p1][1]);
	int fp2 = sol(p1, now, now + 1, end) + abs(sec[now][0] - sec[p2][0]) + abs(sec[now][1] - sec[p2][1]);
	if (fp1 > fp2)
	{
		position[p1][p2] = 2;
		ret = fp2;
	}
	else
	{
		position[p1][p2] = 1;
		ret = fp1;
	}
	return ret;
}


void print(int p1, int p2, int now, int end)
{
	if (now > end)return;
	printf("%d\n", position[p1][p2]);
	if (position[p1][p2] == 1)
		print(now, p2, now + 1, end);
	else
		print(p1, now, now + 1, end);
}



int main()
{
	int N, W;
	scanf("%d %d", &N, &W);
	memset(D, -1, sizeof(D));
	sec[0][0] = sec[0][1] = 1;
	sec[1][0] = sec[1][1] = N;
	for (int i = 2; i <= W + 1; i++)
		scanf("%d %d", &sec[i][0], &sec[i][1]);
	printf("%d\n", sol(0, 1, 2, W + 1));

	print(0, 1, 2, W + 1);
	return 0;
}