//https://www.acmicpc.net/problem/2228
//구간 나누기
#include "bits_stdc++.h"
#define INF 1000000000
using namespace std;
int n, m, arr[102], dp[102][51][2];

//인덱스,구간,연결됨?(0:아뇨,1:넹)
int chk(int idx, int sector, int issep)
{
	if (idx == n && sector == m)return 0;
	if (idx == n)return -INF;
	int &ret = dp[idx][sector][issep];
	if (ret != -1)return ret;
	//분리된 경우
	if (issep == 0)
	{
		ret = max(chk(idx + 1, sector + 1, 1) + arr[idx], chk(idx + 1, sector, 0));
	}
	//연결된 경우
	else
	{
		ret = max(chk(idx + 1, sector, 1) + arr[idx], chk(idx + 1, sector, 0));
	}
	return ret;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", chk(0, 0, 0));
	return 0;
}