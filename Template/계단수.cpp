//https://www.acmicpc.net/problem/1562
//계단수
#include "bits_stdc++.h"
#define INF 1000000000
using namespace std;
//sum,now,visit
int n, dp[101][10][1 << 10];

int chk(int sum, int now, int visit)
{
	int &ret = dp[sum][now][visit];
	if (sum == n)
	{
		if (visit == ((1 << 10)-1))return 1;
		return 0;
	}
	if (ret != -1)
		return ret;
	
	ret = 0;
	//방문하지 않았을 경우
	if (1 <= now && now <= 8)
	{
		ret += chk(sum + 1, now - 1, visit | (1 << (now - 1)));
		ret %= INF;
		ret += chk(sum + 1, now + 1, visit | (1 << (now + 1)));
		ret %= INF;
	}

	else if (now == 0)
		ret += chk(sum + 1, now + 1, visit | (1 << (now + 1)));

	
	else
		ret += chk(sum + 1, now - 1, visit | (1 << (now - 1)));
	
	return ret%INF;
}

int main()
{
	scanf("%d", &n);
	int result = 0;
	for (int i = 1; i < 10; i++)
	{
		memset(dp, -1, sizeof(dp));
		result += chk(1, i, 1<<i);
		result %= INF;
	}
	printf("%d\n", result%INF);
	return 0;
}