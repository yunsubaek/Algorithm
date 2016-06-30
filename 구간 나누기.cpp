//https://www.acmicpc.net/problem/2228
//���� ������
#include "bits_stdc++.h"
#define INF 1000000000
using namespace std;
int n, m, arr[102], dp[102][51][2];

//�ε���,����,�����?(0:�ƴ�,1:��)
int chk(int idx, int sector, int issep)
{
	if (idx == n && sector == m)return 0;
	if (idx == n)return -INF;
	int &ret = dp[idx][sector][issep];
	if (ret != -1)return ret;
	//�и��� ���
	if (issep == 0)
	{
		ret = max(chk(idx + 1, sector + 1, 1) + arr[idx], chk(idx + 1, sector, 0));
	}
	//����� ���
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